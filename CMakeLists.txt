
project(ArgsParserLib)
cmake_minimum_required (VERSION 2.6)
include(CTest)
#set the version
set (ArgsParserLib_VERSION_MAJOR 0)
set (ArgsParserLib_VERSION_MINOR 1)
#set output txt file directory
set (ArgsParserLib_OUTPUT_FILE_DIR "${PROJECT_BINARY_DIR}/ouput.txt")


# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
    "${PROJECT_SOURCE_DIR}/ArgsParserLibConfig.h.in"
    "${PROJECT_SOURCE_DIR}/ArgsParserLibConfig.h"
    )
    
# add the binary tree to the search path for include files
# so that we will find ArgsParserLib.h
include_directories("${PROJECT_SOURCE_DIR}")
include_directories("test")
include_directories("include")
include_directories("src")

set (SRC_DIR "src")

#Cruise Control module
include_directories("${SRC_DIR}")

add_subdirectory(${SRC_DIR})

file(GLOB_RECURSE ArgsParserLibSourceFiles
                  ${SRC_DIR}/*.cpp
                  )
                  
add_library(ArgsParserLib ${ArgsParserLibSourceFiles})

#Cruise Control Executable         
add_executable(ArgsParserLib_test
               test/ArgsParserLib_test.cpp)
target_link_libraries(ArgsParserLib_test ArgsParserLib)


#set generator
if(MSVC10)
  set(CMAKE_GENERATOR "Visual Studio 10 2010")
endif()