//
// Created by myself on 2/15/20.
//

#ifndef TRANSLATOR_LEXER_H
#define TRANSLATOR_LEXER_H


#include <fstream>
#include <vector>
#include <vector>
#include <set>
#include <map>
#include "Text/Lexem.h"
#include "Text/Variable.h"

class Lexer {
public:
    Lexer(std::string inputFilePath);
    void process();
    void printResults();

    std::vector<Lexem*> getLexems();


private:
    static int DEFAULT_LEXEM_TABLE_SIZE;

    CharacterTypes characters[sizeof(char) * 256];
    std::string inputFilePath;

    //  todo lexem pool
    std::vector<Lexem*> lexems;

    void initCharacters();
    std::string wordExtraction(const char* line);
    std::string unsignedExtraction(const char* line);

    std::set<Lexem*> keywords;
    std::set<Lexem*> variables;

    bool setContains(std::set<Lexem*> set, std::string key);
    Lexem* getLexemThatMatches(std::set<Lexem*>set, std::string key);
};


#endif //TRANSLATOR_LEXER_H
