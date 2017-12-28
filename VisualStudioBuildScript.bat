IF NOT EXIST build_vs mkdir build_vs
cd build_vs
del /Q *

cmake -G "Visual Studio 12 2013" ..
cmake --build .
