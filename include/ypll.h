#ifndef YPLL_H
#define YPLL_H

#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/Module.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/MC/MCStreamer.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/TargetParser/Host.h>
#include <llvm/Transforms/Scalar.h>

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "ast.h"

class ypll {
public:
    ypll();
    ~ypll();
    int set_target(std::filesystem::path target);
    int compile();
    // ~ypll() = default;

private:
    std::filesystem::path target;
    std::string source;
    std::vector<std::string> tokens;
    std::string IR;

    int lexer();
    int parser();
    int IRgen();
    int codegen();

    const std::unordered_map<std::string, std::string> keywords = {
        {"i32", "int_32"},          {"i64", "int_64"},
        {"f32", "float_32"},        {"f64", "float_64"},
        {"bool", "boolean"},        {"main", "entry_point"},
        {"if", "if_control"},       {"else", "else_control"},
        {"while", "while_loop"},    {"for", "for_loop"},
        {"return", "return"},       {"true", "boolean_true"},
        {"false", "boolean_false"}, {"null", "null_value"},
        {"void", "void_value"},
    };

    const std::unordered_map<std::string, std::string> operators = {
        {"+", "add"},
        {"-", "sub"},
        {"*", "mul"},
        {"/", "div"},
        {"%", "mod"},
        {"=", "assign"},
        {"==", "equal"},
        {"!=", "not_equal"},
        {">", "greater_than"},
        {"<", "less_than"},
        {">=", "greater_than_or_equal"},
        {"<=", "less_than_or_equal"},
        {"&&", "and"},
        {"||", "or"},
    };

    const std::unordered_map<std::string, std::string> delimiters = {
        {"(", "left_parenthese"},
        {")", "right_parenthese"},
        {"{", "left_brace"},
        {"}", "right_brace"},
        {"[", "left_bracket"},
        {"]", "right_bracket"},
        {",", "comma"},
        {":", "colon"},
        {".", "dot"},
        {"'", "single_quote"},
        {"\"", "double_quote"},
    };

    const std::unordered_map<std::string, std::string> builtin_functions = {
        {"print", "builtin_print"},
        {"println", "builtin_println"},
        {"input", "builtin_input"},
        {"inputln", "builtin_inputln"},
    };

    friend class AST;
};

#endif