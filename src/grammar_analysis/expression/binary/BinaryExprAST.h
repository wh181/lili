//
// Created by 王航 on 2024/3/26.
//

#ifndef LILI_BINARY_H
#define LILI_BINARY_H
#include "grammar_analysis/expression/expression.h"

class BinaryExprAST : public ExprAST{
    char Op;
    ExprAST *LHS, *RHS;
public:
    BinaryExprAST(char op, ExprAST *lhs, ExprAST *rhs)
            : Op(op), LHS(lhs), RHS(rhs) {}
};


#endif //LILI_BINARY_H
