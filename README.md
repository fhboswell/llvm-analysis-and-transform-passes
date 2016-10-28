#LLVM Analysis And Transform Passes


This project uses Clang and LLVM to alayse and optimise C++ source code.

### How It Works

Clang is a front end to LLVM, it compiles C++ into IR. Intermediate Representation is far simpler then C++, making it easier analyse.

LLVM has a variety of librarys that can be used to analyse and manipulate IR. Instructions for an alalysis or a transformation are called a [pass](http://llvm.org/docs/GettingStarted.html#overview).


### Prerequisites

LLVM and Clang are required to compile and apply the passes.
CMake is Required to build LLVM and Clang.

* [LLVM](http://llvm.org/docs/GettingStarted.html#overview)
* [Clang](http://clang.llvm.org/get_started.html)
* [CMake](http://llvm.org/docs/GettingStarted.html#overview)


