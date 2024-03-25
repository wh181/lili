#include <iostream>
#include "lexical_analysis/lexical_analysis.h"

using namespace std;


template <class T>
int length(T& arr)
{
    return sizeof(arr) / sizeof(arr[0]);
}


int main(int argc, char **argv){
    //词法分析
    lexical_analysis token(argv[argc - 1]);
    auto tokens = token.analysis();

    for (auto iter = tokens.begin(); iter != tokens.end(); iter++)
    {
        if (!iter->identifier_str.empty())
            cout << iter->identifier_str << "-----" << iter->type << endl;

        if (iter->num_val > 0)
            cout << iter->num_val << "-----" << iter->type << endl;
    }

    cout << "success" << endl;
}

