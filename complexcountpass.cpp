

#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/IR/InstrTypes.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Support/raw_ostream.h"

#define DEBUG_TYPE ""

STATISTIC(TotalFunctions, "Functions");
STATISTIC(TotalInstructions, "Instructions");
STATISTIC(TotalAlloc, "Allocations");
STATISTIC(TotalBinaryOperators, "Binary Operators");

using namespace llvm;


namespace {
    
    struct CountStats : public ModulePass {
        static char ID;
        CountStats() : ModulePass(ID) {}
        bool runOnModule(Module &M);
        bool runOnFunction(Function &F, Module &M);
    };
    
}

char CountStats::ID = 0;


static RegisterPass<CountStats>
X("hello", "Count Statistics", false, false);

//Module
bool CountStats::runOnModule(Module &M) {
    for(Module::iterator F = M.begin(), E = M.end(); F != E; ++F) {
        ++TotalFunctions;
        runOnFunction(*F, M);
    }
    return false; // ir not modified
}

//Function
bool CountStats::runOnFunction(Function &F, Module &M) {
    
    for (auto& B : F) {
        for (auto& I : B) {
            if (auto* AllocInst = dyn_cast<AllocaInst>(&I)) {
                ++TotalAlloc;
            }
            if (auto* op = dyn_cast<BinaryOperator>(&I)) {
                ++TotalBinaryOperators;
                errs() << "Instruction: ";
                //errs().write_escaped(op->getName()) << '\n';

                //op->dump();
            }
            errs().write_escaped(I.getOpcodeName()) << '\n';
            
                    }
    }
    for(Function::iterator BB = F.begin(), E = F.end(); BB != E; ++BB) {
        
        TotalInstructions += BB->getInstList().size();
    }
    return false; // ir not modified
}





