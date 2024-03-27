//
// Created by 王航 on 2024/3/26.
//

#ifndef LILI_NUMBER_H
#define LILI_NUMBER_H
#include "grammar_analysis/expression/expression.h"

class NumberExprAST : public ExprAST {
    double Val;
public:
    NumberExprAST(double val) : Val(val) {}
};


#endif //LILI_NUMBER_H
