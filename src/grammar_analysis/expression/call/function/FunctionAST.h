//
// Created by 王航 on 2024/3/26.
//

#ifndef LILI_FUNCTIONAST_H
#define LILI_FUNCTIONAST_H
#include "grammar_analysis/expression/call/prototype/PrototypeAST.h"
#include "grammar_analysis/expression/expression.h"

class FunctionAST {
    PrototypeAST *Proto;
    ExprAST *Body;
public:
    FunctionAST(PrototypeAST *proto, ExprAST *body)
            : Proto(proto), Body(body) {}

};


#endif //LILI_FUNCTIONAST_H
