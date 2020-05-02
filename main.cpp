#include <stack>
#include "lexer/Lexer.h"
#include "syntax-an/Analyzer.h"

int main(int argc, char* argv[]) {
    std::string fpath("../lexer/program.txt");
    if(argc == 2) {
        fpath = std::string(argv[1]);
    }

    Lexer lexer(fpath);
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
