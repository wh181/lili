//
// Created by 王航 on 2024/3/26.
//

#ifndef LILI_VARIABLEEXPRAST_H
#define LILI_VARIABLEEXPRAST_H
#include <iostream>
#include "grammar_analysis/expression/expression.h"

class VariableExprAST : public ExprAST {
    std::string Name;
public:
    VariableExprAST(const std::string &name) : Name(name) {}
};





#endif //LILI_VARIABLEEXPRAST_H
