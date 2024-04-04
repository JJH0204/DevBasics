# 1. CMake?
- VSCode에는 링커를 관리하는 기능이 따로 없다.
- windows 나 Mac 을 옮겨가며 프로젝트를 진행하다 보면 하나의 세팅으로 두 운영체제에 적용이 가능해야 한다.
- 프로젝트 빌드를 위해 빌드 프로그램을 사용해야 하는데 대표적으로 make 또는 Ninja 같은 프로그램을 사용해 빌드를 한다.
- 대부분 make를 사용하는데 make로 빌드 할 수 있도록 프로젝트를 관리해야 하는데 이를 도와주는 프로그램이 CMake를 사용한다.
- make와 같이 "러닝 커브"가 있고, 긴 역사 만큼 바른 사용법(Best practice)이 버전에 따라 많이 바뀐다.

# 2. Install
## 2.1. Windows
- 설치 경로: https://cmake.org/download/
- 윈도우 버전 선택 후 다운로드
- "Add CMake to the system PATH for all users" 선택하고 다운로드(CMake를 어디서든 이용할 수 있도록 하기 위해서 시스템 경로(System Path)에 추가)
- Cmd에서 cmake 명령어 실행하여 Usage 내용 출력되면 설치 성공
## 2.2. Mac
- 터미널에 ```brew install cmake```를 실행하면 CMake를 설치할 수 있다.
- 설치가 끝나면 ```cmake --version```를 실행해서 설치 여부 확인할 수 있다.

# 3. Basic
- CMake를 사용하는 모든 프로젝트에는 **반드시** 프로젝트 최상위 디렉토리에 [[CMakeList.txt]] 파일이 있어야 한다.
- CMakeLists.txt > CMake > Makefile > make > 실행파일 순으로 컴파일된다.
- 최상위 CMakeLists.txt 에는 반드시 아래 두 내용이 들어가야 된다.
```
# CMake 프로그램 최소 버전
cmake_minimum_required(VERSION 3.11)

# 프로젝트 정보
project(
	ProjectName
	VERSION 0.1
	DESCRIPTION "예제 프로젝트"
	LANGUAGES CXX
)
```
- 주석은 (#)을 사용하면 된다.
- CMake 버전별 지원 기능의 차이가 커 최소 버전을 3.0 이상으로 설정해 놓는다.
- [[project()]]에 프로젝트 정보를 간단히 명시 (프로젝트 이름은 필수)
- 실행 파일을 빌드하기 위해서 CMakeLists.txt 와 소스코드 파일은 같은 경로에 있어야 한다.
- CMake에서 권장하는 빌드 파일 생성 방법으로 빌드 파일과 작업하는 디렉토리는 서로 분리한다.
  build 라는 별도의 폴더를 만들어 사용

# 참조
- [What_CMake](https://growing-dev101.tistory.com/entry/%EA%B0%9C%EB%B0%9C%ED%99%98%EA%B2%BD-CMake)
- [sup_CMake_GIT](https://gist.github.com/luncliff/6e2d4eb7ca29a0afd5b592f72b80cb5c?permalink_comment_id=2831356)
- [CMake_SET](https://growingdev.blog/entry/%EA%B0%9C%EB%B0%9C-%ED%99%98%EA%B2%BD-CMake-%EA%B8%B0%EB%B3%B8-%EC%84%A4%EC%A0%95-%EB%94%B0%EB%9D%BC%ED%95%98%EA%B8%B0-feat-VS-Code)
- [CMake 설치 for windows](https://ndb796.tistory.com/365)
- [모두의 코드](https://modoocode.com/332)
- [Mac os에서 CMake 사용하기](https://popcorn16.tistory.com/31)
- https://answer-me.tistory.com/87
- https://gist.github.com/luncliff/6e2d4eb7ca29a0afd5b592f72b80cb5c
- https://chat.openai.com/share/a9766652-c2f0-4db1-9c2e-a2dd1c61d38b