#include "ypll.h"

int ypll::parser() {
    for (std::string token : this->tokens) {
        if (token == "retraction1") {
            continue;
        } else if (this->keywords.find(token) != this->keywords.end()) {

        } else if (this->operators.find(token) != this->operators.end()) {
            // undone
        } else if (this->delimiters.find(token) != this->delimiters.end()) {
            // undone
        } else {
            // undone
        }
    }
    // undone
    return 0;
}