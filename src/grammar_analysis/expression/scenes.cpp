//
// Created by 王航 on 2024/3/26.
//

#ifndef LILI_SCENES_H
#include "grammar_analysis/expression/scenes.h"
#endif

#include "grammar_analysis/customize_operator/customize_operator.h"
#include "grammar_analysis/expression/binary/BinaryExprAST.h"

ExprAST *scenes::ParseNumberExpr() {
    ExprAST *Result = new NumberExprAST(grammar->current_token.num_val);
    grammar->getNextToken(); // consume the number
    return Result;
}

ExprAST *scenes::ParseParenExpr() {
    grammar->getNextToken();
    ExprAST *V = ParseExpression();
    if (!V){
        return nullptr;
    }
    if (grammar->current_token.identifier_str != ")"){
        return err::Error("expected ')'");
    }
    grammar->getNextToken();
    return V;
}

ExprAST *scenes::ParseIdentifierExpr() {
    std::string IdName = grammar->current_token.identifier_str;
    grammar->getNextToken();
    if (grammar->current_token.identifier_str != "("){
        return new VariableExprAST(IdName);
    }
    grammar->getNextToken(); //eat (
    std::vector<ExprAST*> Args;
    if (grammar->current_token.identifier_str != "("){
        while (1){
            ExprAST *Arg = ParseExpression();
            if (!Arg) return 0;
            Args.push_back(Arg);

            if (grammar->current_token.identifier_str == ")") break;
            if (grammar->current_token.identifier_str != ",")
                return err::Error("Expected ')' or ',' in argument list");
            grammar->getNextToken();
        }
    }
    return nullptr;
}

ExprAST *scenes::ParseExpression() {
    ExprAST *LHS = grammar_analysis::ParsePrimary(grammar);
    if (!LHS) return 0;
    return ParseBinOpRHS(0, LHS);
}

ExprAST *scenes::ParseBinOpRHS(int ExprPrec, ExprAST *LHS) {
    // If this is a binop, find its precedence.
    while (1) {
        int TokPrec = customize_operator::getCustomizeOperatorGrade(grammar->current_token.identifier_str);

        if (TokPrec < ExprPrec)
            return LHS;

        int BinOp = grammar->current_token.num_val;
        grammar->getNextToken();  // eat binop

        // Parse the primary expression after the binary operator.
        ExprAST *RHS = grammar_analysis::ParsePrimary(grammar);
        if (!RHS) return nullptr;

        int NextPrec = customize_operator::getCustomizeOperatorGrade(grammar->current_token.identifier_str);
        if (TokPrec < NextPrec) {
            RHS = ParseBinOpRHS(TokPrec+1, RHS);
            if (RHS == nullptr) return nullptr;
        }

        // Merge LHS/RHS.
        LHS = new BinaryExprAST(BinOp, LHS, RHS);
    }
}

//  ::= id '(' id* ')'
PrototypeAST *scenes::ParsePrototype() {
    if (grammar->current_token.type != tok_identifier)
        return err::ErrorP("Expected function name in prototype");

    std::string FnName = grammar->current_token.identifier_str;
    grammar->getNextToken();

    if (grammar->current_token.identifier_str != "(")
        return err::ErrorP("Expected '(' in prototype");

    std::vector<std::string> ArgNames;
    grammar->getNextToken();
    while (grammar->current_token.type == tok_identifier) {
        ArgNames.push_back(grammar->current_token.identifier_str);
        grammar->getNextToken();
    }
    if (grammar->current_token.identifier_str != ")")
        return err::ErrorP("Expected ')' in prototype");

    // success.
    grammar->getNextToken();  // eat ')'.

    return new PrototypeAST(FnName, ArgNames);
}

FunctionAST *scenes::ParseDefinition() {
    grammar->getNextToken();  // eat def.
    PrototypeAST *Proto = ParsePrototype();
    if (Proto == 0) return 0;

    if (ExprAST *E = ParseExpression())
        return new FunctionAST(Proto, E);
    return 0;
}

PrototypeAST *scenes::ParseExtern() {
    grammar->getNextToken();  // eat extern.
    return ParsePrototype();
}

FunctionAST *scenes::ParseTopLevelExpr() {
    if (ExprAST *E = ParseExpression()) {
        // Make an anonymous proto.
        PrototypeAST *Proto = new PrototypeAST("", std::vector<std::string>());
        return new FunctionAST(Proto, E);
    }
    return 0;
}

