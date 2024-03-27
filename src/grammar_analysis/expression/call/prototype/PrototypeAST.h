//
// Created by 王航 on 2024/3/26.
//

#ifndef LILI_PROTOTYPEAST_H
#define LILI_PROTOTYPEAST_H
#include <iostream>
#include <vector>

class PrototypeAST {
    std::string Name;
    std::vector<std::string> Args;
public:
    PrototypeAST(const std::string &name, const std::vector<std::string> &args)
            : Name(name), Args(args) {}
};


#endif //LILI_PROTOTYPEAST_H
