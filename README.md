#LLVM Analysis And Transform Passes

#Franklin Henry Boswell


LLVM is used for many things perhaps most importantly it can help analyse and then optimise code.



## Getting Started

Clang is effectivly a front end to LLVM, it compiles C++ into LLVM bitcode also known as IR

LLVM has a variety of tools that can be used to analyse and manipulate the afformentioned bytecode. 
    Instructions for an alalysis or a transformation are called a * [pass](http://llvm.org/docs/GettingStarted.html#overview).
http://llvm.org/docs/WritingAnLLVMPass.html#introduction-what-is-a-pass

### Prerequisites

LLVM and Clang are required to compile and apply the passes.
CMake is Required to build them.

* [LLVM and Clang](http://llvm.org/docs/GettingStarted.html#overview)
* [CMake](http://llvm.org/docs/GettingStarted.html#overview)

