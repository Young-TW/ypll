#include "ypll.h"

int ypll::codegen() {
    using namespace llvm;
    // Initialize LLVM
    InitializeAllTargets();
    InitializeAllTargetMCs();
    InitializeAllAsmPrinters();
    InitializeAllAsmParsers();
    LLVMInitializeNativeTarget();
    LLVMInitializeNativeAsmPrinter();
    LLVMInitializeNativeAsmParser();

    // Create an LLVM module
    LLVMContext Context;
    std::unique_ptr<Module> module = std::make_unique<Module>("my_module", Context);

    // Create a function
    FunctionType *funcType = FunctionType::get(Type::getInt32Ty(Context), false);
    Function *mainFunc = Function::Create(funcType, Function::ExternalLinkage, "main", module.get());

    // Create a basic block
    BasicBlock *entryBlock = BasicBlock::Create(Context, "entry", mainFunc);

    // Your LLVM code here to add instructions to the basic block

    // Create a pass manager for optimization
    legacy::PassManager passManager;

    // Add optimization passes
    // passManager.add(createPromoteMemoryToRegisterPass());
    // passManager.add(createInstructionCombiningPass());
    // passManager.add(createReassociatePass());
    // Add more passes as needed

    // passManager.run(*mainFunc);

    // Set up a JIT engine
    // 創建 TargetMachine 指標
    llvm::TargetMachine* targetMachine = EngineBuilder().selectTarget();

    // 將 TargetMachine 指標轉換為 std::unique_ptr<TargetMachine>
    std::unique_ptr<llvm::TargetMachine> uniqueTargetMachine(targetMachine);

    // 創建 ExecutionEngine 使用 EngineBuilder
    EngineBuilder builder(std::move(module));
    builder.setEngineKind(EngineKind::JIT);

    ExecutionEngine* executionEngine = builder.create();

    // JIT the module
    // GenericValue result = executionEngine->runFunction(mainFunc, {});

    // Your code to use the result
    // std::cout << result.IntVal << std::endl;

    // undone
    return 0;
}