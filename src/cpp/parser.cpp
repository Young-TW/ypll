#include <vector>

#include "ypll.h"

int ypll::parser() {
    std::vector<std::string> retraction = {};
    for (std::string token : this->tokens) {
        if (token.starts_with("keyword_")) {
        } else if (token.starts_with("operator_")) {
        } else if (token.starts_with("delimiter_")) {
        } else if (token.starts_with("builtin_functions_")) {
        }
    }

    // undone
    return 0;
}