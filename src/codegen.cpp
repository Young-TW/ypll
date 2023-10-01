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

    // Create an LLVM module from IR string
    LLVMContext Context;
    SMDiagnostic Err;
    std::unique_ptr<Module> module = parseIR(MemoryBufferRef(this->IR, "IR"), Err, Context);

    if (!module) {
        // Handle parsing error
        errs() << "Error parsing LLVM IR: " << Err.getMessage() << "\n";
        return 1; // Return an error code
    }

    // Add a main function if needed
    FunctionType* funcType = FunctionType::get(Type::getInt32Ty(Context), false);
    Function* mainFunc = Function::Create(funcType, Function::ExternalLinkage, "main", module.get());

    // Add a basic block if needed
    BasicBlock* entryBlock = BasicBlock::Create(Context, "entry", mainFunc);

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
    llvm::TargetMachine* targetMachine = EngineBuilder().selectTarget();

    // Convert the TargetMachine pointer to std::unique_ptr<TargetMachine>
    std::unique_ptr<llvm::TargetMachine> uniqueTargetMachine(targetMachine);

    // Create an ExecutionEngine using EngineBuilder
    EngineBuilder builder(std::move(module));
    builder.setEngineKind(EngineKind::JIT);

    // Generate the native code with default code model
    builder.setCodeModel(CodeModel::Small);
    builder.setOptLevel(CodeGenOpt::Default);
    std::unique_ptr<ExecutionEngine> executionEngine(builder.create());

    // Get a pointer to the main function
    void* mainPtr = executionEngine->getPointerToFunction(mainFunc);

    // Return success (or an error code if needed)
    return 0;
}
