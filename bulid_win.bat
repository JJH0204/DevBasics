@echo off
mkdir -p build/build_win
cd build/build_win
cmake -G "MinGW Makefiles" ../../
cmake --build .
pause