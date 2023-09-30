#include <fstream>
#include <vector>
#include <string>
#include <iostream>

#include "ypll.h"

int ypll::lexer() {
    std::ifstream file(this->target);
    std::string input = "";

    for (std::string line; std::getline(file, line);) {
        input += ("\n" + line);
    }

    // for debug: print the file
    // std::cout << input << std::endl;

    std::vector<std::string> tokens = {};
    std::string buffer = "";
    int space = 0;
    bool in_string = false;

    for (char c : input) {
        // for debug: print the char
        // std::cout << c << " " << buffer << " " << space << std::endl;
        if (in_string) {
            buffer += c;
            continue;
        }

        if (c == ' ') {
            space++;
        } else if (c == '\n') {
            space = 0;
        } else if (c == '(') {
            buffer += c;
        } else if (c == ')') {
            buffer += c;
        } else if (c == '"') {
            in_string = !in_string;
        } else if (c == '\'') {
            buffer += c;
        } else {
            if (space == 4) {
                this->tokens.push_back("retraction1");
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
    for (std::string token : this->tokens) {
        std::cout << token << std::endl;
    }

    return 0;
}