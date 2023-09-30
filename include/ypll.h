#ifndef YPLL_H
#define YPLL_H

#include <string>
#include <vector>
#include <filesystem>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <fstream>

#include "ast.h"

class ypll {
public:
    ypll();
    int set_target(std::filesystem::path target);
    int compile();
    // ~ypll() = default;

private:
    std::filesystem::path target;
    std::vector<std::string> tokens;

    int preprocesser();
    int lexer();
    int parser();
    int IRgen();
    int codegen();

    const std::unordered_set<std::string> keywords = {
        "i32",
        "i64",
        "f32",
        "f64",
        "bool",
        "main",
        "if",
        "else",
        "while",
        "for",
        "return",
        "true",
        "false",
        "null",
        "void",
    };

    const std::unordered_set<std::string> operators = {
        "+",
        "-",
        "*",
        "/",
        "%",
        "=",
        "==",
        "!=",
        ">",
        "<",
        ">=",
        "<=",
        "&&",
        "||",
    };

    const std::unordered_set<std::string> delimiters = {
        "(",
        ")",
        "{",
        "}",
        "[",
        "]",
        ",",
        ":",
        ".",
        "'",
        "\"",
    };

    friend class AST;
};


#endif