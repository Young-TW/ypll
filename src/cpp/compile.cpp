#include "ypll.h"

int ypll::compile() {
    lexer();
    parser();
    IRgen();
    codegen();
    return 0;
}