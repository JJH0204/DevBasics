cmake_minimum_required(VERSION 3.10)
project(postfix)
add_executable(postfixNotation postfixNotation.c notationStack.c postfixCalc.c)
# add_executable(checkBracketMatch checkBracketMatch.c Stack.c)