# CMake 최소 버전 설정
cmake_minimum_required(VERSION 3.11)

# 프로젝트 설정
project(
    DEVBASICS
    VERSION 0.1
    LANGUAGES C
)
include_directories("include/")

add_executable(
    postfixNotation 
    source/DSNA/Linear/postfixNotation.c 
    source/DSNA/Linear/notationStack.c 
    source/DSNA/Linear/postfixCalc.c
)
# add_executable(checkBracketMatch checkBracketMatch.c Stack.c)