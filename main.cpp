#include <iostream>
#ifndef LILI_LEXICAL_ANALYSIS_H
#include "lexical_analysis/lexical_analysis.h"
#endif
#ifndef LILI_GRAMMAR_ANALYSIS_H
#include "grammar_analysis/grammar_analysis.h"
#endif
using namespace std;


template <class T>
int length(T& arr)
{
    return sizeof(arr) / sizeof(arr[0]);
}


int main(int argc, char **argv){
    lexical_analysis token(argv[argc - 1]);
    auto tokens = token.analysis();

    grammar_analysis grammar(tokens);
    grammar.analysis();


    cout << "success" << endl;
}

