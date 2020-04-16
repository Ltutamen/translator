//
// Created by myself on 2/15/20.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include "Lexer.h"
#include "Text/Constant.h"
#include "Text/SingleElm.h"
#include "Text/Keyword.h"

int Lexer::DEFAULT_LEXEM_TABLE_SIZE = 1000;


std::map<LexemTypes, std::string> LexemType::names = {
                    {LexemTypes::CONSTANT_VAR, "constant_variable"},
                    {LexemTypes::OPERAND, "operand"},
                    {LexemTypes::DEFINED_VAR, "defined_variable"},
                    {LexemTypes::COMMENT, "comment"}};


Lexer::Lexer(std::string _inputFilePath) : lexems(0), inputFilePath(std::move(_inputFilePath)) {
    //  this->variables.push_front(new Variable("asasd"));

    this->keywords.insert(new Keyword("begin"));
    this->keywords.insert(new Keyword("defunc"));
    this->keywords.insert(new Keyword("program"));
    this->keywords.insert(new Keyword("end"));

    //  initLexems();
    initCharacters();

}

bool Lexer::setContains(std::set<Lexem*> set, std::string key) {
    for (auto it = set.begin(); it != set.end(); ++it) {
        if((*it)->name == key) {
            return true;
        }
    }
    return false;
}

Lexem*  Lexer::getLexemThatMatches(std::set<Lexem*>set, std::string key) {
    for (auto it = set.begin(); it != set.end(); ++it) {
        if((*it)->name == key) {
            return (*it);
        }
    }
    return nullptr;
}


void Lexer::initCharacters() {
    for (int i = 0; i <= 7; ++i) {
        characters[i] = CharacterTypes::FORBIDDEN;
    }
    for (int i = 8; i < 40; ++i) {
        characters[i] = CharacterTypes::WHITESPACE;
    }
    for(int i = 48; i < 58; ++i) {
        characters[i] = CharacterTypes::DIGIT;
    }
    for(int i = 65; i <= 122; ++i) {
        characters[i] = CharacterTypes::LETTER;
    }
    for (int i = 124; i <= 127; ++i) {
        characters[i] = CharacterTypes::FORBIDDEN;
    }

    characters['='] = CharacterTypes::SINGLED_DIV;
    characters['\\'] = CharacterTypes::SINGLED_DIV;
    characters[','] = CharacterTypes::SINGLED_DIV;
    characters[';'] =CharacterTypes:: SINGLED_DIV;

    characters['/'] = CharacterTypes::SINGLED_OP;
    characters['*'] = CharacterTypes::SINGLED_OP;
    characters['>'] = CharacterTypes::SINGLED_OP;
    characters['<'] = CharacterTypes::SINGLED_OP;

}

void Lexer::process() {
    std::string line;
    std::string currLex;

    std::ifstream input;
    input.open(inputFilePath);
    if(!input.is_open()) {
        perror("Error open");
        exit(EXIT_FAILURE);
    }

    for(int lineN = 1; std::getline(input, line) ; ++lineN) {
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);

        std::cout << lineN << " : "<<line  << '\n';

        try {
            for (int i = 0; i < line.size(); ++i) {
                if (characters[line[i]] == CharacterTypes::FORBIDDEN) {
                    std::cerr << line[i] << "@" << (int)line[i] << "@@";
                    throw lineN;

                } else if(characters[line[i]] == CharacterTypes::WHITESPACE) {
                    //  skip whitespace
                    //  lexems.push_back(new Constant(currLex, ConstantPosition(i - currLex.length(), lineN, i, lineN), constants));
                } else if (characters[line[i]] == CharacterTypes::LETTER) {
                    //  words, constants
                    std::string word = wordExtraction(&line[i]);
                    if(setContains(keywords, word)) {
                        lexems.push_back(getLexemThatMatches(keywords, word));
                    } else {
                        auto* var = new Constant(word, LexemTypes::CONSTANT_VAR, ConstantPosition(i, lineN, i + word.length(), lineN));
                        lexems.push_back(var);
                        variables.insert(var);
                    }

                    i += word.length() - 1;
                } else if(characters[line[i]] == CharacterTypes::DIGIT) {
                    std::string sunsigned = unsignedExtraction(&line[i]);
                    lexems.push_back(new Constant(sunsigned, LexemTypes::UNSIGNED, ConstantPosition(lineN, i, lineN, i + sunsigned.length())));
                    i += sunsigned.length() - 1;
                } else if(characters[line[i]] == CharacterTypes::SINGLED_DIV) {
                    lexems.push_back(SingleElm::getSingleElm(std::string(1,  line[i])));
                } else if(characters[line[i]] == CharacterTypes::SINGLED_OP) {
                    //  COMMENTS
                    if(line[i] == '*' && line[i + 1] == '<') {
                        while(!(line[i] == '>' && line[i + 1] == '*')) {
                            //  std::cerr << line[i] << "@" << line.size();
                            //  consume next line AND read new line, if EOL
                            //  increment line counter!
                            if(i <= line.size()) {
                                //  not an EOL, read next character  from the line
                                i++;
                            } else {
                                lineN++;
                                std::getline(input, line);
                                i = 0;
                            }
                        }
                        ++i;
                    }
                    //  "/" sign
                    else {
                        lexems.push_back(
                                new Constant(
                                        "/",
                                        LexemTypes::OPERAND,
                                        ConstantPosition(lineN, i, lineN, i)));
                    }
                }
            }
        } catch (int positionInLine) {
            std::cerr << "Forbidden symbol [" << line[positionInLine] << "::" << (int)line[positionInLine] << "] at line " << lineN << " at pos " << positionInLine << ":{";
            std::cerr << line << "}\n";
        } catch (...) {
            std::cerr << "General exception on line " [ lineN] << ';';
            exit(2);
        }
    }

    input.close();
}

std::string Lexer::unsignedExtraction(const char* line) {
    char buffer[128] {' '};

    int i;
    for( i = 0; characters[line[i]] == CharacterTypes::DIGIT; ++i) {
        buffer[i] = line[i];
    }

    return std::string(buffer, i);

}

std::string Lexer::wordExtraction(const char* line) {
    char buffer[128] {' '};

    int i;
    for( i = 0; characters[line[i]] == CharacterTypes::LETTER || characters[line[i]] == CharacterTypes::DIGIT; ++i) {
        buffer[i] = line[i];
    }

    return std::string(buffer, i);
}

void Lexer::printResults() {
    std::cout << "\n Lexems: " << lexems.size() << '\n';
    for(auto it : lexems) {
        std::cout << *it->toString() << '\n';
    }

    std::cout << "\n Variables table: " << this->variables.size() << '\n';
    for(auto it : variables) {
        std::cout << *it->toString() << '\n';
    }

    //  std::for_each(constants.begin(), constants.end(), [](Lexem* l) -> void { std::cout <<  l->toString(); });

}

std::vector<Lexem *> Lexer::getLexems() {
    return lexems;
}

