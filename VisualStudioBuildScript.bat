@echo off
@if EXIST "setenv.bat" (
echo "calling setenv"
call "setenv.bat"
)

IF NOT EXIST build_vs mkdir build_vs
cd build_vs
del /Q *

rem echo Generating MSVC workspace
%CMAKE_TOOL_BIN%\cmake -G "Visual Studio 12 2013" ..

echo Building solution
%CMAKE_TOOL_BIN%\cmake --build "D:\PrivateDocuments\cppHandOn\CPPSelfLearning\build_vs"
