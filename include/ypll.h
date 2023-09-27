#ifndef YPLL_H
#define YPLL_H

#include <string>

class ypll {
public:
    std::string preprocesser();
    int lexer(std::string input);
    int parser();
    int IRgen();
};


#endif