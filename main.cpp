#include <stack>
#include "lexer/Lexer.h"
#include "syntax-an/Analyzer.h"

int main() {
    Lexer lexer("../lexer/program.txt");
    lexer.process();
    lexer.printResults();

    std::vector<Lexem*> lexems = lexer.getLexems();

    std::stack<Lexem*> lexStack;
    for(int i = 0; i < lexems.size(); i++) {
        lexStack.push(lexems[i]);
    }

    Analyzer analyzer;
    analyzer.analyze(lexStack);

    return 0;
}
