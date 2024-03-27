//
// Created by 王航 on 2024/3/25.
//

#ifndef LILI_GRAMMAR_ANALYSIS_H
#include "grammar_analysis.h"
#endif

#ifndef LILI_SCENES_H
#include "grammar_analysis/expression/scenes.h"
#endif

AST grammar_analysis::analysis() {
    while (1) {
        switch (current_token.type) {
            case tok_eof:    return nullptr;
            case tok_symbol:
                if (current_token.identifier_str == ";"){
                    getNextToken(); break;  // ignore top-level semicolons.
                }
            case tok_def:    HandleDefinition(); break;
            case tok_extern: HandleExtern(); break;
            default:         HandleTopLevelExpression(); break;
        }
    }
}

bool grammar_analysis::getNextToken() {
    current_token = *index;
    if (index != tokens.end()) {
        preview_token = *(index++);
    } else{
        return false;
    }
    return true;
}

AST grammar_analysis::ParsePrimary(grammar_analysis *grammar) {
    scenes cueernt_scenes(grammar);
    switch (grammar->current_token.type) {
        default:
            return err::Error("unknown token when expecting an expression");
        case tok_identifier:
            return cueernt_scenes.ParseIdentifierExpr();
        case tok_number:     return cueernt_scenes.ParseNumberExpr();
        case tok_symbol:
            if (grammar->current_token.identifier_str == "(") {
                return cueernt_scenes.ParseParenExpr();
            }
            break;
    }
    return nullptr;
}

void grammar_analysis::HandleDefinition() {
    scenes current_scenes(this);
    if (current_scenes.ParseDefinition()) {
        fprintf(stderr, "Parsed a function definition.\n");
    } else {
        // Skip token for error recovery.
        getNextToken();
    }
}

void grammar_analysis::HandleExtern() {
    scenes current_scenes(this);
    if (current_scenes.ParseExtern()) {
        fprintf(stderr, "Parsed an extern\n");
    } else {
        // Skip token for error recovery.
        getNextToken();
    }
}

void grammar_analysis::HandleTopLevelExpression() {
    scenes current_scenes(this);
    if (current_scenes.ParseTopLevelExpr()) {
        fprintf(stderr, "Parsed a top-level expr\n");
    } else {
        // Skip token for error recovery.
        getNextToken();
    }
}