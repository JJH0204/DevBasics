# C/Cpp 개발 준비를 위한 준비
## 1. VSCode
- 마이크로 소프트에서 개발한 소스 코드 편집기
- 디버깅, git, 구문 강조기능 등이 기본적으로 포함되고 테마, 단축기, 설정 등 포함되어 있는 에디터
- 다양한 프로그래밍 언어를 지원하며 각 언어와 함께 사용할 수 있는 편의 기능을 지원
- 다양한 기능의 상당수는 명령어 팔레트, .json파일(사용자 설정)을 통해 사용해야 한다.
- 플러그인을 통해 편집 기능 추가 및 프로그래밍 언어 지원 등 새로운 확장 기능을 추가 할 수 있다.

## 2. Windows Setup
### 2.1. MinGW-W64 install (직접 압축 해제)
- 윈도우 환경에서 vscode로 c/c++ 개발을 진행하려면 MinGW-w64 설치가 필수이지만 어쩐지 .exe 파일로 설치를 진행하면 오류가 발생한다.
- 직접 구성 파일들을 .zip 파일로 내려받아 세팅을 진행하려 한다.
- [공식 누리집](https://www.mingw-w64.org/), [.zip 파일 다운 링크](https://sourceforge.net/projects/mingw-w64/files/)
- **.zip 파일 다운 링크** 로 들어가서 원하는 버전의 파일을 설치한다. (.exe 제외)
- 파일 이름 구성: Architecture(아키텍쳐)-Threads(쓰레드)-Exception(예외) 순으로 구성되어 필요한 버전을 찾기 쉽다.
  - Architecture(아키텍쳐): 32bit(x86) 컴파일러가 필요하면 i686, 64bit(x64, x86_64, AMD64) 컴파일러가 필요하면 x86_64
  - Threads(쓰레드): C++11/C11 멀티스레팅 기능이 필요하면 posix, 필요 없다면 win32 [자세한 내용](https://stackoverflow.com/questions/17242516/mingw-w64-threads-posix-vs-win32)
  - Exception(예외): Handling에 관한 내용 [자세한 내용](https://stackoverflow.com/questions/30739099/what-is-the-difference-between-mingw-seh-and-mingw-sjlj)
- 원하는 버전의 파일을 선택해 다운로드 받고 압축을 해제한다.
- 압축 해제 후 나온 mingw64 폴더를 C:\program files에 복사/이동(64bit 운영체제에 32bit 컴파일러 설치 시 C:\program files(x86)에 복사/이동)
### 2.2. 환경변수 설정
- 인터넷에서 환경변수 편집 방법을 검색 한다.
- 시스템 변수에서 Path를 선택하여 편집을 진행한다.
- 새로 만들기를 누른 후 **MinGW-w64 폴더 경로\bin** 입력한 후 추가 선택
- 확인 버튼을 눌러 지금까지 연 창들을 모두 닫는다.
### 2.3. 설치 확인
- 터미널 실행
- ```gcc -v```, ```g++ -v``` 명령어 실행 시 버전 출력되면 성공, 안된다면 처음부터 다시 진행
### 2.4. VSCode install
- [VSCode 설치 링크](https://code.visualstudio.com/download)
- 확장에서 C/C++ 검색 후 마이크로소프트에서 배포하는 확장 설치
- 폴더 생성 후 .c 또는 .cpp 파일 생성 후 코딩 시작~

## 3. Mac Setup
### 3.1. GCC 컴파일러 설치
- 터미널 실행 후 ```xdoe-select --install```명령어 실행
- "도구를 지금 설치하겠습니까?"에서 설치 선택
- "동의"를 누르고 설치가 끝날때까지 기다린다.
### 3.2. 설치 확인
- 터미널에 ```gcc -v``` 또는 ```gcc --version``` 실행
- 버전을 확인할 수 있다면 성공
### 3.3. VSCode install
- [VSCode 설치 링크](https://code.visualstudio.com/download)
- 확장에서 C/C++ 검색 후 마이크로소프트에서 배포하는 확장 설치
- 폴더 생성 후 .c 또는 .cpp 파일 생성 후 코딩 시작~

## 4. 추천 확장
- [한글](https://marketplace.visualstudio.com/items?itemName=MS-CEINTL.vscode-language-pack-ko)
- [번역기](https://marketplace.visualstudio.com/items?itemName=sculove.translator)
- [Git 테마](https://marketplace.visualstudio.com/items?itemName=GitHub.github-vscode-theme)
- [아이콘 테마](https://marketplace.visualstudio.com/items?itemName=PKief.material-icon-theme)
- [TODO 하이라이트](https://marketplace.visualstudio.com/items?itemName=wayou.vscode-todo-highlight)
- [마크다운 팩](https://marketplace.visualstudio.com/items?itemName=yzhang.markdown-all-in-one)
- [들여쓰기 구분](https://marketplace.visualstudio.com/items?itemName=oderwat.indent-rainbow)
- [Git 그래프](https://marketplace.visualstudio.com/items?itemName=mhutchie.git-graph)
- [Code 맞춤법](https://marketplace.visualstudio.com/items?itemName=streetsidesoftware.code-spell-checker)

## 5. 참조
* [수성컴전자방 블로그](https://sooseongcom.com/post/MinGW-w64-HowToInstall)
* [전문 해커의 vscode 세팅](https://www.youtube.com/watch?v=r750vOVbS9M)
* [JetBrains Mono 폰트 설정](https://gyuha.tistory.com/534)
* [VSCode C/C++ 환경 세팅](https://m.blog.naver.com/dorergiverny/221889473340)