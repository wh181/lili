//
// Created by 王航 on 2024/3/26.
//

#ifndef LILI_CUSTOMIZE_OPERATOR_H
#define LILI_CUSTOMIZE_OPERATOR_H

#include <iostream>
#include <algorithm>

struct Grade{
    std::string my_operator;
    unsigned int grade;
};

template <class T>
 int getlength(T& array)
{
    return (sizeof(array) / sizeof(array[0]));
}

Grade operator_grade_table[] = {
        Grade{.my_operator="<",.grade = 10},
        Grade{.my_operator="+",.grade = 20},
        Grade{.my_operator="-",.grade = 20},
        Grade{.my_operator="*",.grade = 40},
        Grade{.my_operator="/",.grade = 40},
};

class customize_operator {
public:
    static unsigned int getCustomizeOperatorGrade(std::string customize_operator){
        for (int i = 0; i < getlength(operator_grade_table); ++i) {
            Grade current_operator = operator_grade_table[i];
            if (customize_operator == current_operator.my_operator){
                return current_operator.grade;
            }
        }
        return 0;
    }
};




#endif //LILI_CUSTOMIZE_OPERATOR_H
