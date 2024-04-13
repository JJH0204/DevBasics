# 1. 알고리즘 기초
## 1.1. 소스코드
- [(링크)](../../source/DSNA/Algorithm_Practice/mainBasics.c)
## 1.2. 필기
- 위에서 아래로 코드(프로세스)가 순서대로 실행되는 구조를 '순자적(concatenation)구조'라고 한다.
- 괄호'()'안의 식의 평가 결과에 따라 프로그램의 실행 흐름이 변경되는 if문을  '선택(selection)구조'라고 한다.
- 3개의 피연산자를 갖는 3항 연산자 ? : 를 조건 연산자(conditional operator)라고 한다. $min = a < b ? a : b;$
- 사전 판단 반복문: for, while
- 사후 판단 반복문: do~while (while 끝에는 ;이 붙는다.)
- 단축 평가(short circuit evaluation): 논리 연사의 식 전체를 평가한 결과가 왼쪽 피연산자의 평가 결과만으로 정확해지는 경우 오른쪽 피연자의 평가를 수행하지 않는다.
- 드모르간 법칙(De Morgan's laws): 각 조건을 부정하고 논리곱을 논리합으로 논리합을 논리곱으로 바꾸고 다시 전체를 부정하면 원래의 조건과 같다.