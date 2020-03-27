//
// Created by myself on 2/15/20.
//

#ifndef TRANSLATOR_LEXER_H
#define TRANSLATOR_LEXER_H


#include <fstream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include "Text/Lexem.h"

class Lexer {
public:
    Lexer(std::string inputFilePath);
    void process();
    void printResults();

private:
    static int DEFAULT_LEXEM_TABLE_SIZE;

    CharacterTypes characters[sizeof(char) * 256];
    std::string inputFilePath;

    //  todo lexem pool
    std::list<Lexem*> lexems;

    void initToStringMaps();
    void initLexems();
    void initCharacters();
    std::string wordExtraction(const char* line);
    std::string unsignedExtraction(const char* line);

    std::set<Lexem*> keywords;
    std::set<Lexem*> constants;
    //  std::list<Variable*> variables;
};


#endif //TRANSLATOR_LEXER_H
