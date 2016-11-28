


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
    
    Constant *loadLog = F.getParent()->getOrInsertFunction("LOAD", Type::getVoidTy(Context), NULL);
    
    Constant *storeLog = F.getParent()->getOrInsertFunction("STORE", Type::getVoidTy(Context), NULL);
    
    Constant *callLog = F.getParent()->getOrInsertFunction("CALL", Type::getVoidTy(Context), NULL);
    
    Constant *instLog = F.getParent()->getOrInsertFunction("INST", Type::getVoidTy(Context), NULL);
    
    
    for (auto& B : F) {
        for (auto& I : B) {
            
             //errs().write_escaped(I.getOpcodeName()) << '\n';
          
           
            if (auto* op = dyn_cast<AllocaInst>(&I)) {
                
                IRBuilder<> builder(op);
                builder.SetInsertPoint(&B, ++builder.GetInsertPoint());
                builder.CreateCall(allLog);
                
                
                
                
                
            }else if (auto* op = dyn_cast<BinaryOperator>(&I)) {
                
                IRBuilder<> builder(op);
                builder.SetInsertPoint(&B, ++builder.GetInsertPoint());
                builder.CreateCall(BOLog);
                
                
                
                
            } else  if (auto* op = dyn_cast<StoreInst>(&I)) {
                
                IRBuilder<> builder(op);
                builder.SetInsertPoint(&B, ++builder.GetInsertPoint());
                builder.CreateCall(storeLog);
                
                
            } else  if (auto* op = dyn_cast<LoadInst>(&I)) {
                
                IRBuilder<> builder(op);
                builder.SetInsertPoint(&B, ++builder.GetInsertPoint());
                builder.CreateCall(loadLog);
                

            } else  if (auto* op = dyn_cast<BranchInst>(&I)) {
                
                IRBuilder<> builder(op);
                builder.SetInsertPoint(&B, --builder.GetInsertPoint());
                builder.CreateCall(branLog);
                
                
            }


           
           
            /*
             
            
             if (auto* op = dyn_cast<BranchInst>(&I)) {
             
             IRBuilder<> builder(op);
             builder.SetInsertPoint(&B, --builder.GetInsertPoint());
             builder.CreateCall(branLog);
             
             
             }
             
             
             if (auto* op = dyn_cast<BinaryOperator>(&I)) {
             
             IRBuilder<> builder(op);
             builder.SetInsertPoint(&B, ++builder.GetInsertPoint());
             builder.CreateCall(BOLog);
             
             
             
             
             }
             
             if (auto* op = dyn_cast<BranchInst>(&I)) {
             
             IRBuilder<> builder(op);
             builder.SetInsertPoint(&B, ++builder.GetInsertPoint());
             builder.CreateCall(branLog);
             
             
             }
             
             if (auto* op = dyn_cast<StoreInst>(&I)) {
             
             IRBuilder<> builder(op);
             builder.SetInsertPoint(&B, ++builder.GetInsertPoint());
             builder.CreateCall(storeLog);
             
             
             }
            const char * test1 = I.getOpcodeName();
            const char * test2 = "add";
            
            if(strcmp (test1,test2) != 0){
             
                
            }
             
            
            IRBuilder<> builder(&I);
            builder.SetInsertPoint(&I);
            builder.CreateCall(logFunc);
             
             
             if (auto* op = dyn_cast<Instruction>(&I)) {
             
             IRBuilder<> builder(&B);
             builder.SetInsertPoint(&B, ++builder.GetInsertPoint());
             builder.CreateCall(instLog);
             
             
             
             
             }
             
             */
            
            
            
        }
    }
        return false;
}
