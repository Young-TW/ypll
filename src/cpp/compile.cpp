#include "ypll.h"

int ypll::compile() {
    lexer();
    parser();
    IRgen();
    return 0;
}
