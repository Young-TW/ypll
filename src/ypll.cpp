#include "ypll.h"

#include <cxxopts.hpp>
#include <filesystem>
#include <iostream>
#include <string>
#include <unordered_set>

std::ifstream fin;
std::ofstream fout;

ypll::ypll() {}

ypll::~ypll() {
    std::cout << std::filesystem::current_path() << std::endl;
    fout.open("./llvm-ir/output.ll");
    fout << this->IR;
    fout.close();
}

int ypll::set_target(std::filesystem::path target) {
    this->target = target;
    return 0;
}

int main(int argc, char* argv[]) {
    cxxopts::Options options("ypll",
                             "A compiler for Young's Programming Language");
    options.allow_unrecognised_options();

    options.add_options()("h,help", "print help page", cxxopts::value<bool>());

    cxxopts::ParseResult result = options.parse(argc, argv);

    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        return 0;
    }

    ypll y;

    if (result.unmatched().size() == 0) {
        std::cerr << "ypll: fatal error: no input files" << std::endl;
        return 1;
    } else if (result.unmatched().size() == 1) {
        y.set_target(result.unmatched()[0]);
    } else if (result.unmatched().size() > 1) {
        std::cerr << "ypll: fatal error: too many input files" << std::endl;
        std::cerr << "ypll: note: only one input file is allowed" << std::endl;
        return 1;
    }

    y.compile();

    return 0;
}
