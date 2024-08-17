use inkwell::context::Context;
use inkwell::targets::{InitializationConfig, Target};
use inkwell::OptimizationLevel;
use crate::grammar::Expr;

pub fn generate_code(ast: &Expr) {
    let context = Context::create();
    let module = context.create_module("my_module");
    let builder = context.create_builder();

    // 生成 LLVM IR...
}
