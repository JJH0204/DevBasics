# CMake 최소 버전 설정
cmake_minimum_required(VERSION 3.11)

# 프로젝트 설정
project(DEVBASICS VERSION 0.1 LANGUAGES C)

#c/c++ 표준 설정
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# UTF-8 인코딩을 위한 컴파일러 옵션 설정
add_compile_options(
    $<$<CXX_COMPILER_ID:GNU>:-finput-charset=UTF-8>
    $<$<CXX_COMPILER_ID:Clang>:-finput-charset=UTF-8>
)

# 소스 파일의 경로를 변수에 설정
set(SOURCE_DIR  # 소스코드 경로
    source/Algorithm/Hashing
)

# 소스 파일 지정
add_executable(ChainHashing
    ${SOURCE_DIR}/main.c
    ${SOURCE_DIR}/includeMember.c
    ${SOURCE_DIR}/includeChainHash.c
    ${SOURCE_DIR}/includeClosedHash.c
)

# 추가 라이브러리 링크 혹은 옵션 지정
include_directories(include)

if(WIN32)
    # windows 설정

elseif(APPLE)
    # mac 설정

endif()
