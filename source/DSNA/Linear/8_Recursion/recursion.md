# Recursion: 재귀 호출 이란?
- 자기 자신을 다시 호출하는 것
- 알고리즘 문제 해결을 위해 종종 사용됨 (비선형 자료구조의 탐색 등등)
- 복잡한 문제를 쉽게 해결하기 위한 문제 해결 기법으로 활용
- 큰 문제를 점차 작은 문제 단위로 축소하여 풀이하는 방법: 분할 정복(divide and conquer)
- 순환 호출이라고도 함

## 2가지 조건
> 무한 루프(infinite loop)에 빠지지 않도록 구현: 탈출 조건은 필수  
```c
int main(void)
{
    ...
    int result = my_func(10);
    ...
}

int my_func(int input_value)
{
    int ret = 0;
    ...
    ret = intput1 + my_func(input_value - 1); 
    // 재귀 호출 방식으로 구현한 함수임을 알 수 있다. 
    // 자기 자신을 호출할 때 마다 전달하는 인자값이 1감소한다. 
    // 값이 줄어들기만 할 뿐 종료 조건이 없어 무한루프에 빠질 수 있다.
    ...
    return ret;
}
```
> 호출될 때마다 문제의 범위가 줄어들어야 한다.  
- $n!$ 을 구하는 함수 factorial [링크](C_language/2_Advanced/6_Recursion_C)
```c
int factorial(int n)
{
    int ret = 0;
    if (n <= 1)
    {
        ret = 1;
    }
    else
    {
        ret = n * factorial(n - 1);
    }
    return ret;
}
```
- 더 이상 나눌 문제가 없는 가장 작은 단위가 되었을 때 호출이 뜻나도록 조건문을 설정

## 호출 과정
> 함수에서 사요되는 모든 지역 변수(local variable)와 전달된 인자(parameter)등을 저장하는 공간 "활성 레코드(activation record)"  
> 도중에 다른 함수가 호출되면 해당 함수의 활성 레코드로 변경 "문맥 변경(context switching)"  
- 운영체제에서는 스택(stack)을 이용하여 재귀 호출을 실행  
- 운영체제에서는 하나의 함수가 호출되면 호출되는 함수별로 활성 레코드에 함수 관련 정보를 저장한다.  
- 함수가 여러 번 호출되더라도 모두 별계의 함수로 처리된다.  
- 운영체제 관점에서 재귀 호출되는 함수별로 활성 레코드를 호출의 역순(스택)으로 독립 처리한다.

### 단점
- 상대적으로 속도가 느리다: 문맥 변경에 추가적인 시간이 필요
- 함수 호출 횟수에 제한이 있다: 운영체제의 스택 크기에 제한이 있다. "스택 오버플로우 위험"
> 처음에는 재귀 호출로 구현된 시스템을 안정화 이후 반복 호출을 이용하는 방법으로 소스를 수정하기도 한다.  

# 재귀 호출과 반복 호출
- 반복 호출(for, while)은 프로그램 속도 혹은 메모리 측면에서 재귀 호출보다 선능이 우수하다.
- 재귀로 구현된 함수는 반복을 이용해서도 구현할 수 있다. (서로 대체 가능)

## 팩토리얼 함수
```c
// isRecursion
int factorial(int n)
{
    int ret = 0;
    if (n <= 1)
    {
        ret = 1;
    }
    else
    {
        ret = n * factorial(n - 1);
    }
    return ret;
}
// isLoop
int factorial(int n)
{
    int ret = 1;
    int i = 1;
    for (i = n; i > 1; i--)
    {
        ret = ret * i;
    }
    return ret;
}
```
## 피보나치 수열
- 첫 번째 항과 두 번째 항에 대해서는 각각 값이 0, 1이지만, 세 번째 항 이상에 대해서는 이전 두 항을 더한 값으로 정의되는 수열
- 0, 1, 1, 2, 3, 5, 8, 13 ...
- $n = 4, fib(4) = fib(3) + fib(2) = 2 + 1 = 3$

### 코드
```c
// isRecursion
int fib(int n)
{
    int ret = 0;

    if (n == 0)
    {
        ret = 0;
    }
    else if (n == 1)
    {
        ret = 1;
    }
    else
    {
        ret = fib(n - 1) + fib(n - 2);
    }
    return ret;
}
// isLoop
int fib(int n)
{
    int nLast = 0;
    int nCurrent = 1;
    int nTemp = 0;
    int nCount = 0;

    if (n <= 1)
        return n;
    for (nCount = 2; nCount <= n; nCount++)
    {
        nTemp = nCurrent;
        nCurrent += nLast;
        nLast = nTemp;
    }
    return nCurrent;
}
```
- isRecursion 의 fib 의 경우 시간복잡도는 $O(n^2)$으로 $n = 30$ 일 때 fib()이 대략 300만 번 호출되기에 매우 비효율적이다.
- isLoop 의 fib 의 경우 시간복잡도는 $O(n)$으로 재귀 호출 방식으로 구현한 것 보다 매우 효율적임을 알 수 있다.
- 다만, 직접 디버깅하지 않는 한 피보나치 수열을 구하는 함수임을 이해하기 코드만 보고는 어렵다는 단점이 있다.
## 하노이의 탑
```c
// isRecursion
int hanoi(int n, char from, char temp, char to)
{
    if (n == 1)
    {
        printf("원판 1을 %c에서 %c로 옮겼습니다.\n", from, to);
    }
    else
    {
        hanoi(n - 1, from, to, temp);
        printf("원판 %i을 %c에서 %c로 옮겼습니다.\n", n, from, to);
        hanoi(n - 1, temp, from, to);
    }
}
// isLoop
int hanoi(int n, char from, char temp, char to)
{
    // TODO: Solving the Tower of Hanoi problem using loops
}
```
- 하노이 탑 문제는 알고리즘 문제들 중에서 재귀 함수 문제로 풀이했을 때 가장 쉽게 해결되는 예제로 종종 쓰인다.
