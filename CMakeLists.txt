# CMake 최소 버전 설정
cmake_minimum_required(VERSION 3.11)

# 프로젝트 설정
project(
    DEVBASICS
    VERSION 0.1
    LANGUAGES C
)

add_executable(
    postfixNotation 
    source/DSNA/Linear/6_usingStack/postfix/postfixNotation.c 
    source/DSNA/Linear/6_usingStack/postfix/notationStack.c 
    source/DSNA/Linear/6_usingStack/postfix/postfixCalc.c
)
# add_executable(checkBracketMatch checkBracketMatch.c Stack.c)