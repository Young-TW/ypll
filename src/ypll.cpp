#include <iostream>
#include <string>

#include <cxxopts.hpp>

#include "ypll.h"

int ypll::IRgen() {
    return 0;
}

int main(int argc, char* argv[]) {
    cxxopts::Options options("ypll", "A compiler for Young's Programming Language");

    options.add_options()
        ("h,help", "print help page", cxxopts::value<bool>())
        ;

    cxxopts::ParseResult result = options.parse(argc, argv);


    std::cout << "Hello Young!";
    return 0;
}