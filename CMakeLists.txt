# CMake 최소 버전 설정
cmake_minimum_required(VERSION 3.11)

# 프로젝트 설정
project(DEVBASICS VERSION 0.1 LANGUAGES C)

#c/c++ 표준 설정
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# 소스 파일의 경로를 변수에 설정
set(SOURCE_DIR source/DSNA/non-Linear)

# 소스 파일 지정
add_executable(ArrayGraph ${SOURCE_DIR}/mainGraph.c ${SOURCE_DIR}/includeArrayGraph.c)

# 추가 라이브러리 링크 혹은 옵션 지정
include_directories(include)

if(WIN32)
    # windows 설정

elseif(APPLE)
    # mac 설정

endif()
