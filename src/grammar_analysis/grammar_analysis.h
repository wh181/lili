
#ifndef LILI_GRAMMAR_ANALYSIS_H
#define LILI_GRAMMAR_ANALYSIS_H
#include <vector>

#ifndef LILI_LEXICAL_ANALYSIS_H
#include "lexical_analysis/lexical_analysis.h"
#endif

#include "grammar_analysis/expression/expression.h"
#include "grammar_analysis/expression/error/err.h"
typedef ExprAST* AST;

class grammar_analysis {
public:
    std::vector<Token> tokens;
    std::vector<Token>::iterator index;
    Token current_token;
    Token preview_token;
    Token outlook_token;

    explicit grammar_analysis(std::vector<Token> &tokens) :tokens(tokens){
        index = tokens.begin();
    }

    AST analysis();

    static AST ParsePrimary(grammar_analysis* grammar);

    bool getNextToken();

    void HandleDefinition();

    void HandleExtern();

    void HandleTopLevelExpression();
};



#endif //LILI_GRAMMAR_ANALYSIS_H
