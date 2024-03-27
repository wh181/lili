//
// Created by 王航 on 2024/3/25.
//

#ifndef LILI_LEXICAL_ANALYSIS_H
#define LILI_LEXICAL_ANALYSIS_H
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
void dd(char c);
extern const char all_symbol[13];
enum TokenType{
    tok_empty = -1,
    tok_eof = -2,
    tok_def = -3,
    tok_extern = -4,
    tok_identifier = -5,
    tok_number = -6,
    tok_comment = -7,
    tok_symbol = 1
};

struct Token{
    TokenType type;
    std::string identifier_str;
    double num_val;
};


class lexical_analysis {
public:
    char *file;
    lexical_analysis(char* file) :file(file){}

    std::vector<Token> analysis();
    char getNext(std::ifstream &file);
    static void printToken(Token &token);
};


#endif //LILI_LEXICAL_ANALYSIS_H
