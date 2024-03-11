//PArithmetics.c
//C file for Pointer Arithmetics practice

#include <stdio.h>

void _practice1_(void);

int main(void)
{
    _practice1_();
    return 0;
}

void _practice1_(void)
{
    // ++, -- 연산자를 사용한 포인터 증가
    int i_Array[5] = {10, 20, 30, 40, 50};

    int i = 0;

    for (; i < 5; i++)
    {
        // 일반적인 메모리의 배열 접근 방식
        printf("iArray[%d]: val = %d, address = @ %x\n", i, i_Array[i], &i_Array[i]);
    }

    // 포인터를 사용한 배열 메모리 참조 방식 (배열의 4번째 메모리를 참조)
    int *i_Pointer = &i_Array[3];
    printf("val = %d, address = @ %x\n", *i_Pointer, i_Pointer);    // val = 40, address = @ 6d47716c

    // ++ 연산자를 사용해 배열의 5번째 메모리에 포인터 변수로 접근 및 참조
    i_Pointer++;
    printf("val = %d, address = @ %x\n", *i_Pointer, i_Pointer);    // val = 50, address = @ 6d477170

    // -- 연산자를 사용해 배열의 4번째 메모리에 포인터 변수로 접근 및 참조
    i_Pointer--;
    printf("val = %d, address = @ %x\n", *i_Pointer, i_Pointer);    // val = 40, address = @ 6d47716c

    // +, - 연산자를 사용해 배열의 원하는 위치로 이동
    // - 연산자 예제
    i_Pointer -= 2;
    printf("val = %d, address = @ %x\n", *i_Pointer, i_Pointer);    // val = 20, address = @ 6d477164

    // + 연산자 예제
    i_Pointer += 1;
    printf("val = %d, address = @ %x\n", *i_Pointer, i_Pointer);    // val = 30, address = @ 6d477168

    return;
}