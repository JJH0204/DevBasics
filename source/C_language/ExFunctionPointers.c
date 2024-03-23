// Exercise_Function_Pointers.c
// 함수에 대한 포인터 배열을 완성하고 배열의 포인터를 사용하여 각 함수를 호출합니다.
#include <stdio.h>

void f1(int var)
{
    printf("this is f1 and var is: %d\n", var);
}

void f2(int var)
{
    printf("this is f2 and var is: %d\n", var);
}

void f3(int var)
{
    printf("this is f3 and var is: %d\n", var);
}

int main()
{
    /* define an array full of function pointers
    to the above functions, that take an `int` as
    their only argument */
    // 반환형 (*포인터배열이름[배열길이])(매개변수 타입);
    void (*p_Func[3]) (int) = {&f1, &f2, &f3};

    int c = 0;
    while (c < 3)
    {
        /* call the functions using the function pointers
        of the array at index `c` with `c` as an argument */
        p_Func[c] (c);

        ++c;
    }

    return 0;
}