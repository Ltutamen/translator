#include <iostream>
#include "lexer/Lexer.h"

int main() {
    Lexer lexer("../lexer/program.txt");
    lexer.process();
    lexer.printResults();
    return 0;
}
