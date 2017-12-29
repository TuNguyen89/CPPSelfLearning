project(ArgsParserLib)
cmake_minimum_required (VERSION 2.6)

#set the version
set (ArgsParserLib_VERSION_MAJOR 0)
set (ArgsParserLib_VERSION_MINOR 1)
#set output txt file directory
set (ArgsParserLib_OUTPUT_FILE_DIR "${PROJECT_BINARY_DIR}/ouput.txt")

# set (CMAKE_BINARY_DIR "D:/PrivateDocuments/cppHandOn/CPPSelfLearning/build_vs")
# set (CMAKE_GENERATOR "Visual Studio 12 2013")

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

set (SRC_DIR "src/ArgsParser")

include_directories("${SRC_DIR}")

#add_subdirectory(${SRC_DIR})

file(GLOB_RECURSE ArgsParserLibSourceFiles
                  ${SRC_DIR}/*.cpp
                  )
                  
add_library(ArgsParserLib ${ArgsParserLibSourceFiles})

#Cruise Control Executable         
#add_executable(ArgsParserLib_test
#               test/ArgsParserLib_test.cpp)
#target_link_libraries(ArgsParserLib_test ArgsParserLib)


# Include google test into project
configure_file(CMakeLists.txt.in googletest-temp/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-temp )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-temp )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${PROJECT_SOURCE_DIR}/unittestframework/googletest-release-1.8.0/googletest
                 ${CMAKE_BINARY_DIR}/googletest-release-1.8.0-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

add_executable(ArgsParserLib_test test/ArgsParserLib_test.cpp)
target_link_libraries(ArgsParserLib_test ArgsParserLib gtest_main)
add_test(NAME ArgsParser COMMAND CoDestructor)


#set generator
#if(MSVC10)
#  set(CMAKE_GENERATOR "Visual Studio 10 2010")
#endif()

