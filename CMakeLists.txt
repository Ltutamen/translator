cmake_minimum_required(VERSION 3.15)
project(Translator)

set(CMAKE_CXX_STANDARD 17)

add_executable(Translator main.cpp lexer/Lexer.cpp lexer/Lexer.h lexer/Text/Constant.cpp lexer/Text/Constant.h lexer/Text/Lexem.h lexer/Text/Variable.cpp lexer/Text/Variable.h lexer/Text/SingleElm.cpp lexer/Text/SingleElm.h lexer/Text/Keyword.cpp lexer/Text/Keyword.h)