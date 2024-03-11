// Bitmasks.c
// Summary of concepts about bit masks

/*비트 마스크란?
각 비트(bit)를 독립적인 플래그(?)로 사용하여 여러 조건을 한 번에 저장하거나 확인할 수 있는 기능.
주로 설정이나 속성 등을 효율적으로 저장하고 처리하기 위해 사용.
여러 boolean 값을 하나의 정수에 저장하여 공간을 절약, 비트 연산자를 통해 빠르게 데이터를 처리할 수 있다.

비트 연산자 종류
- AND(&): 두 비트 모두 1일 경우에만 결과가 1이 되는 연산자
    특정 비트를 지우거나 특정 비트가 켜져있는 지 확인할 때 사용
- OR(|): 두 비트 중 하나라도 1이면 결과가 1이 되는 연산자
    특정 비트를 켜는 데 사용
- XOR(^): 두 비트가 서로 다를 때 결과가 1이 되는 연산자
    특정 비트를 토글(반전)시킬 때 사용
- NOT(~): 모든 비트를 반전 시키는 연산자 (1 > 0, 0 > 1)
    비트의 보수를 구할 때 사용
- Left shift(<<): 비트를 왼쪽으로 이동시키며, 빈자리는 0으로 채움
    값을 곱하기 위해 사용될 수 있다. (2의 거듭제곱 배로)
- Right shift(>>):  비트를 오른쪽으로 이동시키며, 부호 있는 정수의 경우에는 최상위 비트(부호 비트)가 빈 자리를 채우고, 부호가 없는 정수의 경우 0으로 채워진다.
    값을 나누기 위해 사용 될 수 있다. (2의 거듭제곱 배로)

권한 관리 시스템에서 사용자의 권한을 비트 단위로 표현, 특정 권한 여부를 빠르게 확인할 수 있게 함
(에제: 읽기, 쓰기, 실행 권한을 각각 1번, 2번, 3번 비트로 할당하여 사용자의 권한을 한 개의 정루로 표현하고 관리할 수 있게 됨)

성능이 중요한 시스템이나 메모리 사용량을 최소화해야 하는 시스템(위성 시스템 등)에서 유용하게 사용
단, 코드의 가독성이 떨어지기에 사용 시에는 적절한 주석이나 문서화가 필요하다.
*/

#include <stdio.h>
#include <stdlib.h> // for malloc()

// AND(&) 예제
int Ex_AND (int val_A, int val_B);
// OR(|) 예제
int Ex_OR(int val_A, int val_B);
// XOR(^) 예제
int Ex_XOR(int val_A, int val_B);
// NOT(~) 예제
int Ex_NOT(int val_A);
// Left shift(<<) 예제
int Ex_LeftShift(int val_A, int val_C);
// Right shift(>>) 예제
int Ex_RightShift(int val_A, int val_C);
// 2진 출력 함수
void print_Binary(int val_A, int data_Size);

int main(void)
{
    // AND(&) 예제
    Ex_AND(1, 2);
    // 1 & 2 = 000000001 & 000000010 = 0 (000000000)

    // OR(|) 예제
    Ex_OR(10, 4);
    // 1 | 2 = 000000001 | 000000010 = 3 (000000011)

    // XOR(^) 예제
    Ex_XOR(10, 2);
    // 10 ^ 2 = 000001010 ^ 000000010 = 8 (000001000)

    // NOT(~) 예제
    Ex_NOT(10);
    // ~10 (000001010) = -11 (111110101)

    // Left shift(<<) 예제
    Ex_LeftShift(4, 2);
    // 4 << 2 = 000000100 << 2 = 16 (000010000)

    // Right shift(>>) 예제
    Ex_RightShift(16, 1);
    // 16 >> 1 = 000010000 >> 1 = 8 (000001000)

    return 0;
}

void print_Binary(int val_A, int data_Size)
{
    // C에는 2진수 출력을 위한 별도의 라이브러리나 함수를 지원하지 않는다.
    // 따라서 직접 구현하는 방법 밖에 없다.
    // 이번 2진수 출력 함수는 비트 마스크(비트 연산)를 활용한다.
    
    for (int i = data_Size * 2; i >= 0; i--)
    {
        int result  = val_A >> i & 1;
        printf("%d", result);
    }
}

int Ex_AND(int val_A, int val_B)
{
    int result = val_A & val_B;

    printf("%d & %d = ", val_A, val_B);
    print_Binary(val_A, sizeof(int));
    printf(" & ");
    print_Binary(val_B, sizeof(int));
    printf(" = %d (", result);
    print_Binary(result, sizeof(int));
    printf(")\n");
    return 0;
}

int Ex_OR(int val_A, int val_B)
{
    int result = val_A | val_B;

    printf("%d | %d = ", val_A, val_B);
    print_Binary(val_A, sizeof(int));
    printf(" | ");
    print_Binary(val_B, sizeof(int));
    printf(" = %d (", result);
    print_Binary(result, sizeof(int));
    printf(")\n");
    return 0;
}

int Ex_XOR(int val_A, int val_B)
{
    int result = val_A ^ val_B;

    printf("%d ^ %d = ", val_A, val_B);
    print_Binary(val_A, sizeof(int));
    printf(" ^ ");
    print_Binary(val_B, sizeof(int));
    printf(" = %d (", result);
    print_Binary(result, sizeof(int));
    printf(")\n");
    return 0;
}

int Ex_NOT(int val_A)
{
    int result = ~val_A;

    printf("~%d (", val_A);
    print_Binary(val_A, sizeof(int));
    printf(") = %d (", result);
    print_Binary(result, sizeof(int));
    printf(")\n");
    return 0;
}

int Ex_LeftShift(int val_A, int val_C)
{
    int result = val_A << val_C;

    printf("%d << %d = ", val_A, val_C);
    print_Binary(val_A, sizeof(int));
    printf(" << %d = %d (", val_C, result);
    print_Binary(result, sizeof(int));
    printf(")\n");
    return 0;
}

int Ex_RightShift(int val_A, int val_C)
{
    int result = val_A >> val_C;

    printf("%d >> %d = ", val_A, val_C);
    print_Binary(val_A, sizeof(int));
    printf(" >> %d = %d (", val_C, result);
    print_Binary(result, sizeof(int));
    printf(")\n");
    return 0;
}