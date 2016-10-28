#LLVM Analysis And Transform Passes


This project uses Clang and LLVM to alayse and optimise C++ source code.

### How It Works

Clang is a front end to LLVM, it compiles C++ into IR. Intermediate Representation is far simpler then C++, making it easier to analyse and transform.
LLVM has a variety of librarys that can be used to analyse and transform IR. Instructions for an alalysis or a transformation are called a [pass](http://llvm.org/docs/GettingStarted.html#overview).


### Requirements

LLVM and Clang are required to compile and apply the passes.
CMake is required to build LLVM and Clang.

* [LLVM](http://llvm.org/docs/GettingStarted.html#overview)
* [Clang](http://clang.llvm.org/get_started.html)
* [CMake](http://llvm.org/docs/GettingStarted.html#overview)


### Milestones

1. Static Analysis of basic blocks                
2. Dynamic Analysis of basic blocks              
3. Dynamic Analysis of memory allocation
4. Write Travis-Ci tests for The Analysis passes
5. Transformation which converts doubles to floats





