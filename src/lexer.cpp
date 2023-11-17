#include <fstream>
#include <vector>
#include <string>
#include <iostream>

#include "ypll.h"

int ypll::lexer() {
    enum Token {
        keyword = 0,
        operator_ = 1,
        delimiter = 2,
        identifier = 3,
        literal = 4,
        comment = 5,
        error = 6,
    };

    std::ifstream file(this->target);
    this->source = "";

    for (std::string line; std::getline(file, line);) {
        this->source += ("\n" + line);
    }

    std::string file_contents((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));

    // for debug: print the file
    std::cout << source << std::endl;

    std::vector<std::string> tokens = {};
    std::string buffer = "";
    int space = 0;
    bool in_string = false;

    for (char c : this->source) {
        // for debug: print the char
        // std::cout << c << " " << buffer << " " << space << std::endl;
        if (in_string) {
            if (c == '"') {
                in_string = false;
                continue;
            }

            buffer += c;
            continue;
        }

        if (c == ' ') {
            space++;
        } else if (c == '\n') {
            space = 0;
            buffer.clear();
        } else if (c == '(') {
            if (buffer != "") {
                this->tokens.push_back(buffer);
                buffer.clear();
            }

            this->tokens.push_back("(");
        } else if (c == ')') {
            if (buffer != "") {
                this->tokens.push_back(buffer);
                buffer.clear();
            }

            this->tokens.push_back(")");
        } else if (c == '"') {
            in_string = true;
        } else if (c == '\'') {
            buffer += c;
        } else if (c == ':') {
            if (buffer != "") {
                this->tokens.push_back(buffer);
                buffer.clear();
            }

            this->tokens.push_back(":");
        } else {
            if (space == 4) {
                this->tokens.push_back("retraction-4");
            }

            space = 0;
            buffer += c;
            continue;
        }

        if (buffer != "") {
            this->tokens.push_back(buffer);
            buffer.clear();
        }
    }

    // for debug: print the tokens
    // for (std::string token : this->tokens)
    std::string token;
    for (int i=0;i<this->tokens.size();i++) {
        token = this->tokens[i];
        auto token_keywords = this->keywords.find(token);
        if (token_keywords != keywords.cend()) {
            token = "keyword_" + keywords.at(token);
        }

        auto token_operators = this->operators.find(token);
        if (token_operators != operators.cend()) {
            token = "operator_" + operators.at(token);
        }

        auto token_delimiters = this->delimiters.find(token);
        if (token_delimiters != delimiters.cend()) {
            token = "delimiters_" + delimiters.at(token);
        }

        auto token_builtin_functions = this->builtin_functions.find(token);
        if (token_builtin_functions != builtin_functions.cend()) {
            token = "builtin_functions_" + builtin_functions.at(token);
        }

        this->tokens[i] = token;
    }

    // for debug: print the untranslate tokens
    /*
    for (std::string token : this->tokens) {
        std::cout << token << std::endl;
    }
    */

    return 0;
}
