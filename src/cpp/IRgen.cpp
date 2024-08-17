#include "ypll.h"

int ypll::IRgen() {
    using namespace llvm;
    // 創建 LLVM 上下文（Context）和模塊（Module）
    LLVMContext Context;
    std::unique_ptr<Module> module =
        std::make_unique<Module>("my_module", Context);

    // 創建函數類型，這個例子中是無參數的整數函數
    FunctionType* funcType =
        FunctionType::get(Type::getInt32Ty(Context), false);

    // 在模塊中創建一個函數
    Function* myFunc = Function::Create(funcType, Function::ExternalLinkage,
                                        "my_function", module.get());

    // 創建基本區塊
    BasicBlock* entryBlock = BasicBlock::Create(Context, "entry", myFunc);

    // 在基本區塊中創建 IRBuilder
    IRBuilder<> builder(entryBlock);

    // 添加 IR 指令
    Value* constant = builder.getInt32(42);
    Value* result = builder.CreateAdd(constant, constant, "addresult");

    // 在基本區塊中添加返回語句
    builder.CreateRet(result);

    // 輸出模塊
    module->print(outs(), nullptr);

    // 使用 raw_string_ostream 將 IR 輸出到字串
    std::string irStr;
    raw_string_ostream irStream(irStr);
    module->print(irStream, nullptr);

    // 將 IR 存儲在 this->IR 中
    this->IR = irStream.str();

    // for debug: print IR
    // std::cout << this->IR << std::endl;
    return 0;
}
