#LLVM Analysis And Transform Passes


This project uses Clang and LLVM to alayse and optimise C++ source code.

### How It Works

Clang is a front end to LLVM, it compiles C++ into IR. Intermediate Representation is far simpler then C++, making it easier to analyse and transform.

LLVM has a variety of librarys that can be used to analyse and transform IR. Instructions for an alalysis or a transformation are called a [pass](http://llvm.org/docs/GettingStarted.html#overview).




### Milestones

1. Static Analysis                              -11.12.16
    * Get a count of each type of instruction in the IR bitcode.
    * Write an explination and directions about how to use the pass.
2.  Dynamic Analysis Using Transformation        -11.20.16 
    * Compile a program down to IR using Clang.
    * Add instrumentation to the program using a LLVM pass which modifies the IR.
    * The added instrumentation will print out each instruction encountered at runtime.
    * Write an explination and directions about how to use the pass.
3. Travis-Ci                                    -11/25/16
    * Write tests to compile and run the pass using Travis-Ci.
    * This may require compiling a pass out of source.
4. Dynamic Analysis Using an External Module    -11.30.16        
    * Get a count of each type of instruction as excecuted at runtime.
    * This pass will add instrumentation to the program that sums up the number of instructions at runtime.
    * The instrumentation in the pass will call an external module which will do the actual counting of the information sent to it.
    * Write an explination and directions about how to use the pass.
5. Transformation Pass                          -12.21.16
    * Convert all doubles in a program into floats.


## Requirements

LLVM and Clang are required to compile and apply the passes.
CMake is required to build LLVM and Clang.

* [LLVM](http://llvm.org/docs/GettingStarted.html#overview)
* [Clang](http://clang.llvm.org/get_started.html)
* [CMake](http://llvm.org/docs/GettingStarted.html#overview)






