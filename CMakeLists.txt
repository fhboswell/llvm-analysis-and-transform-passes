cmake_minimum_required(VERSION 3.6)
project(llvm_analysis_and_transform_passes)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    DynCount/CMakeFiles/3.6.2/CompilerIdC/CMakeCCompilerId.c
    DynCount/CMakeFiles/3.6.2/CompilerIdCXX/CMakeCXXCompilerId.cpp
    DynCount/CMakeFiles/feature_tests.c
    DynCount/CMakeFiles/feature_tests.cxx
    DynCount/DynCount.cpp
    heaptime/main.cpp
    HeapTimeTestProgram/main.cpp
    smalltest/print.c
    smalltest/smallProgram.c
    SmallTestProgram/print.c
    SmallTestProgram/smallProgram.c
    StaticCount/CMakeFiles/3.6.2/CompilerIdC/CMakeCCompilerId.c
    StaticCount/CMakeFiles/3.6.2/CompilerIdCXX/CMakeCXXCompilerId.cpp
    StaticCount/CMakeFiles/feature_tests.c
    StaticCount/CMakeFiles/feature_tests.cxx
    StaticCount/StaticCount.cpp)

add_executable(llvm_analysis_and_transform_passes ${SOURCE_FILES})