#include "ypll.h"

int ypll::compile() {
    // preprocesser();
    lexer();
    parser();
    IRgen();
    codegen();
    return 0;
}