//
// Created by 王航 on 2024/3/26.
//

#ifndef LILI_CALLEXPRAST_H
#define LILI_CALLEXPRAST_H
#include <iostream>
#include <vector>
#include "grammar_analysis/expression/expression.h"

class CallExprAST :ExprAST{
    std::string Callee;
    std::vector<ExprAST*> Args;
public:
    CallExprAST(const std::string &callee, std::vector<ExprAST*> &args)
            : Callee(callee), Args(args) {}
};


#endif //LILI_CALLEXPRAST_H
