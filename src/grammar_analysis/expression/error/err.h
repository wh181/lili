//
// Created by 王航 on 2024/3/26.
//

#ifndef LILI_ERR_H
#define LILI_ERR_H
#include "grammar_analysis/expression/call/prototype/PrototypeAST.h"
#include "grammar_analysis/expression/expression.h"
#include "grammar_analysis/expression/call/function/FunctionAST.h"

class err {
public:
    static ExprAST *Error(const char *Str) { fprintf(stderr, "Error: %s\n", Str);return 0;}
    static PrototypeAST *ErrorP(const char *Str) { Error(Str); return 0; }
    static FunctionAST *ErrorF(const char *Str) { Error(Str); return 0; }
};


#endif //LILI_ERR_H
