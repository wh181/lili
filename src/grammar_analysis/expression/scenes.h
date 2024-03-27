//
// Created by 王航 on 2024/3/26.
//

#ifndef LILI_SCENES_H
#define LILI_SCENES_H
#include "grammar_analysis/expression/expression.h"
#ifndef LILI_LEXICAL_ANALYSIS_H
#include "lexical_analysis/lexical_analysis.h"
#endif
#include "grammar_analysis/expression/call/prototype/PrototypeAST.h"
#include "grammar_analysis/expression/call/function/FunctionAST.h"
#include "grammar_analysis/expression/number/NumberExprAST.h"
#include "grammar_analysis/expression/variable/VariableExprAST.h"

#ifndef LILI_GRAMMAR_ANALYSIS_H
#include "grammar_analysis/grammar_analysis.h"
#endif

class scenes {
    grammar_analysis* grammar;
public:
    scenes(grammar_analysis* grammar) : grammar(grammar){}
    //数字AST
    ExprAST *ParseNumberExpr();

    //括号AST
    ExprAST *ParseParenExpr();

    // identifierexpr
    // ::= identifier
    // ::= identifier '(' expression* ')'
    ExprAST *ParseIdentifierExpr();

    ExprAST *ParseExpression();

    ExprAST *ParseBinOpRHS(int ExprPrec, ExprAST *LHS);

    PrototypeAST *ParsePrototype();

    FunctionAST *ParseDefinition();

    PrototypeAST *ParseExtern();

    FunctionAST *ParseTopLevelExpr();
};
#endif //LILI_SCENES_H
