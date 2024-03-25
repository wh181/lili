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

void dd(char c){
    std::cout << isalpha(c) << std::endl;
    std::cout << isspace(c) << std::endl;
    std::cout << c << std::endl;
    std::exit(0);
}

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

char all_symbol[] = {
        '+',
        '-',
        '*',
        '/',
        '(',
        ')',
        '{',
        '}',
        '[',
        ']',
        '>',
        '<',
        '=',
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
};

std::vector<Token>  lexical_analysis::analysis() {
    std::ifstream infilel;
    infilel.open(file);
    char LastChar;
    std::vector<Token> tokens;
    while (!infilel.eof()){
        LastChar = getNext(infilel);
        Token token{.type=TokenType::tok_empty};

        //空格
        while (isspace(LastChar)) {
            LastChar = getNext(infilel);
        }
        //字符
        if (isalpha(LastChar)) { // identifier: [a-zA-Z][a-zA-Z0-9]*
            std::string identifier_str;
            identifier_str.push_back(LastChar);
            LastChar = getNext(infilel);
            while ((isalnum((LastChar)) || isalpha(LastChar)) && !isspace(LastChar)) {
                identifier_str += LastChar;
                LastChar = getNext(infilel);
            }

            if (identifier_str == "def"){
                token.type = TokenType::tok_def;
                token.identifier_str = identifier_str;
            }else if(identifier_str == "extern"){
                token.type = TokenType::tok_extern;
                token.identifier_str = identifier_str;
            } else{
                token.type = TokenType::tok_identifier;
                token.identifier_str = identifier_str;
            }
            goto my_continue;
        }

        //数字
        if (isdigit(LastChar) || LastChar == '.') {   // Number: [0-9.]+
            std::string NumStr;
            do {
                NumStr += LastChar;
                LastChar = getNext(infilel);
            } while (isdigit(LastChar) || LastChar == '.');

            double NumVal = strtod(NumStr.c_str(), 0);
            token.type = TokenType::tok_number;
            token.num_val = NumVal;
            goto my_continue;
        }

        //注释
        if (LastChar == '#') {
            token.type = TokenType::tok_comment;
            getline(infilel,token.identifier_str);
            LastChar = getNext(infilel);
            goto my_continue;
        }


        my_continue:

        //符号
        if (std::find(std::begin(all_symbol), std::end(all_symbol), LastChar) != std::end(all_symbol)){
            tokens.push_back(Token{
                    .type = TokenType::tok_symbol,
                    .identifier_str =  std::string{LastChar}
            });
        }

        if (token.type != TokenType::tok_empty) {
            tokens.push_back(token);
        }

    }
    infilel.close();
    tokens.push_back(Token{
            type :TokenType::tok_eof,
    });
    return tokens;
}

char lexical_analysis::getNext(std::ifstream &file) {
    auto c = file.get();
//    std::cout << c << std::endl;
    return c;
}

#endif //LILI_LEXICAL_ANALYSIS_H
