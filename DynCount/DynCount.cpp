

#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/GlobalVariable.h"

#include "llvm/IR/IRBuilder.h"



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

#define DEBUG_TYPE "Franklin's Static Count"



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
X("DynCount", "Count Statistics", false, false);

//Module
bool CountStats::runOnModule(Module &M) {
    for(Module::iterator F = M.begin(), E = M.end(); F != E; ++F) {
        
        runOnFunction(*F, M);
    }
    return false; // ir not modified
}

//Function
bool CountStats::runOnFunction(Function &F, Module &M) {
    
    LLVMContext &Context = F.getContext();
    
    Constant *BOLog = F.getParent()->getOrInsertFunction("BO", Type::getVoidTy(Context), NULL);
    
    Constant *allLog = F.getParent()->getOrInsertFunction("ALL", Type::getVoidTy(Context), NULL);
    
    Constant *branLog = F.getParent()->getOrInsertFunction("BRAN", Type::getVoidTy(Context), NULL);
    
    
    for (auto& B : F) {
        for (auto& I : B) {
            
            
          
          
           
            
            
            if (auto* op = dyn_cast<BinaryOperator>(&I)) {
                
                IRBuilder<> builder(op);
                builder.SetInsertPoint(&B, ++builder.GetInsertPoint());
                builder.CreateCall(BOLog);
                
               
                
                
            }
            if (auto* op = dyn_cast<AllocaInst>(&I)) {
                
                IRBuilder<> builder(op);
                builder.SetInsertPoint(&B, ++builder.GetInsertPoint());
                builder.CreateCall(allLog);
                
                
                
                
            }
            
            if (auto* op = dyn_cast<  BranchInst>(&I)) {
                
                IRBuilder<> builder(op);
                builder.SetInsertPoint(&B, ++builder.GetInsertPoint());
                builder.CreateCall(branLog);
                
                
                
                
            }
            
            
           
            /*
            if (auto* op = dyn_cast<Instruction>(&I)) {
                
                IRBuilder<> builder(&B);
                builder.SetInsertPoint(&B, ++builder.GetInsertPoint());
                builder.CreateCall(logFunc);
                
                return true;
                
                
            }
            
            const char * test1 = I.getOpcodeName();
            const char * test2 = "add";
            
            if(strcmp (test1,test2) != 0){
             
                
            }
             
            //errs().write_escaped(I.getOpcodeName()) << '\n';
            IRBuilder<> builder(&I);
            builder.SetInsertPoint(&I);
            builder.CreateCall(logFunc);
             
             */
            
        }
    }
        return false;
}
