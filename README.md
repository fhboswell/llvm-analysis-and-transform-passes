#LLVM Analysis And Transform Passes

This project uses Clang and LLVM to analyze and transform C++ source code.

### How It Works

Clang is a front end to LLVM, it compiles C++ into IR. Intermediate Representation is far simpler then C++, making it easier to analyze and transform.

LLVM has a variety of libraries that can be used to analyze and transform IR. Instructions for an analysis or a transformation are called a [pass](http://llvm.org/docs/GettingStarted.html#overview).



[Video Demo of The Passes](https://youtu.be/gS9D2PHjrmM)



### Milestones

1. Static Analysis `Done See Below`                        
    * 11.12.16
    * Compile a program down to IR using Clang.
    * Get a count of each type of instruction in the IR bitcode.
    * Write an explanation and directions about how to use the pass.
2.  Dynamic Analysis Using Transformation  `Done See Below`        
    * 11.20.16 
    * Compile a program down to IR using Clang.
    * Add instrumentation to the program using a LLVM pass which modifies the IR.
    * The added instrumentation will print out each instruction encountered at runtime.
    * Write an explanation and directions about how to use the pass.
3. Travis-Ci                                    
    * 11/25/16
    * Write tests to compile and run the passes using Travis-Ci.
    * This may require compiling a pass out of source.
4. Dynamic Analysis Using an External Module    
    * 11.30.16        
    * Get a count of each type of instruction as executed at runtime.
    * This pass will add instrumentation to the program IR.
    * the instrumentation will call an external function in a module that I will write.
    * This external function which will do the actual counting using the information sent to it by the transformed IR.
    * Write an explanation and directions about how to use the pass.
5. Transformation or Optimization Pass
    * 12.21.16
    * Convert all doubles in a program into floats.
    * I am still learning a lot about LLVM and optimization so I may change this.


## Requirements

LLVM and Clang are required to compile and apply the passes.
CMake is required to build LLVM and Clang.

* [LLVM](http://llvm.org/docs/GettingStarted.html#overview)
* [Clang](http://clang.llvm.org/get_started.html)
* [CMake](http://llvm.org/docs/GettingStarted.html#overview)



## Directions and Explanation for Milestone 1

CLang is used to compile c++ to bytecode
LLVM is used to implment an analysis pass
The `StaticCount` pass goes through every instruction in the byetecode and prints out what type it is. It also uses LLVM to keep track of certian statistics which it prints out at the end of the analysis.


Before following this guide you should have downloaded and built LLVM.

This project and guide were made using macOS.

In order to apply a pass to some c code there are a number of steps that must be tacken, they are as follows.

1. Clone the project to your computer.
2. Navigate to `<LLVM_Source_Directory>/lib/Transforms`.
3. Copy the folder `StaticCount` from the cloned repository into the directory listed above.
4. Inside the `Transforms` directory there should be a number of directorys and only one file `CMakeLists.txt`.
5. Open `CMakeLists.txt` and add the line `add_subdirectory(StaticCount)`.
6. In terminal navigate to the root of your `<LLVM_Build_Directory>` and run `cmake --build .` this will build all of LLVM including the pass we just added.
7. Now navigate into the `HeapTimeTestProgram` directory inside the cloned repository.
8. Run `clang -O0 -emit-llvm -c main.cpp -o bctest.bc` this uses clang to compile our c++ file down to bytecode that llvm can work with.
9. Run `opt -load <LLVM_Build_Directory>/lib/llvmstaticcount.dylib  -StaticCount -stats< bctest.bc > /dev/null` The printed statments are a result of the static analysis using llvm.


![Screenshot](/images/milestone1.jpg)
Note - This is not the complete output of the pass. It is reduced it so that the commands above are visible.


Trouble? Please contact me.

## Directions and Explanation for Milestone 2

CLang is used to compile c++ to bytecode
LLVM is used to implment an analysis pass
The `DynCount` pass goes through every Basic Block in the byetecode and adds a call to a runtime library. The functions in the library are only output statments for this milestone. 

First the pass is compiled just like the first one, next we compile the test program into bytecode. After that the runtime library is compiled into bytecode. These two bytecode files are then linked into a single bytecode file using llvm. After this the pass is applied, unlike in The first pass there will be no output at that point. since this is a dynamic pass we will get the results at runtime. Finally we run the program and get our result, there will be output statments at every occorence of several different Basic Block types.

Before following this guide you should have downloaded and built LLVM.

This project and guide were made using macOS.

In order to apply a pass to C code there are a number of steps that must be tacken, they are as follows.

1. Clone the project to your computer.
2. Navigate to `<LLVM_Source_Directory>/lib/Transforms`.
3. Copy the folder `DynCount` from the cloned repository into the directory listed above.
4. Inside the `Transforms` directory there should be a number of directorys and only one file `CMakeLists.txt`.
5. Open `CMakeLists.txt` and add the line `add_subdirectory(DynCount)`.
6. In terminal navigate to the root of your `<LLVM_Build_Directory>` and run `cmake --build .` this will build all of LLVM including the pass we just added.
7. Now navigate into the `SmallTestProgram` directory inside the cloned repository.
8. Run `clang -O0 -emit-llvm -c smallProgram.c -o sp.bc` this uses clang to compile our c file down to bytecode that llvm can work with.
9. Run `clang -O0 -emit-llvm -c print -o p.bc` this uses clang to compile our runtime library down to bytecode that can be linked with the program we compiled above.
10. Run `llvm-link p.bc sp.bc -S -o smallprogramandprint.bc` this links our program to be analysed and our runtime library.
11. Run `opt -load <LLVM_Build_Directory>/lib/llvmDynCount.dylib  -DynCount <smallprogramandprint.bc> instrumentedprogram.bc` This applys the pass to the program, modifying the bytecode with calls to the runtime library that we linked to it.
12. Run `lli instrumentedprogram.bc` This runs the instrumented program so that we can see the result of the pass.


![Screenshot](/images/milestone2.jpg)
![Screenshot](/images/milestone2_2.jpg)
Note - This is not the complete output of the pass. It is reduced it so that the commands above are visible.

Trouble? Please contact me.










