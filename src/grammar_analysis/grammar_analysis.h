
#ifndef LILI_GRAMMAR_ANALYSIS_H
#define LILI_GRAMMAR_ANALYSIS_H
#include <vector>
#include "lexical_analysis/lexical_analysis.h"


struct Grade{
    char my_operator;
    unsigned char grade;
};

Grade operator_grade_table[] = {
        Grade{.my_operator='<',.grade = 10},
        Grade{.my_operator='+',.grade = 20},
        Grade{.my_operator='-',.grade = 20},
        Grade{.my_operator='*',.grade = 40},
        Grade{.my_operator='/',.grade = 40},
};



class grammar_analysis {
public:
    std::vector<Token> tokens;
    grammar_analysis(std::vector<Token> &tokens) :tokens(){}


};




#endif //LILI_GRAMMAR_ANALYSIS_H
