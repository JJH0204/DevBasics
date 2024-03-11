//FP.c
//Understanding the concept of function pointers file

#include <stdio.h>
#include <stdlib.h> // for qsort()

/*문법*/
// 반환값 (*포인터 변수명)(인자값);
// void (*pf)(int); // Define a function pointer that receives int type data as an argument and returns void type data
// void* (*pf)(int*); // Define a function pointer that receives int * type data as an argument and returns void * type data

void ExFunction(int arg)
{
    printf("ExFunction 함수를 호출해 출력한 값: %d\n", arg);
    printf("함수 종료\n");
}

int compare(const void* left, const void* right)
{
    return (*(int*)right - *(int*)left);
}

int main (void)
{
    // void (*pf)(int) = &ExFunction;
    
    // pf(5);

    // Example of sorting array values ​​in descending order
    int (*cmp) (const void*, const void*) = &compare;

    int i_Array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("%d %d\n", sizeof(i_Array), sizeof(*i_Array));

    qsort(i_Array, sizeof(i_Array)/sizeof(*i_Array), sizeof(*i_Array), cmp);
    //void qsort(void *__base, size_t __nel, size_t __width, int (* _Nonnull __compar)(const void *, const void *));
    //void qsort(__base = &i_Array[0], __nel = 36/4 = 9, __width = 4, __compar = &compare);

    for (int c = 0; c < sizeof(i_Array)/sizeof(*i_Array); c++)
        printf("%d \t", i_Array[c]);
    
    return 0;
}
/*qsort() 함수에 대해
stdlib.h 라이브러리에 정의된 함수로 다양한 자료형의 배열을 정렬하기 위해 사용.
퀵 정렬 알고리즘을 기반으로 하지만, 표준 라이브러리에서는 내부적으로 최적화를 통해 다양한 상황에 대응할 수 있도록 설계됨.
함수의 원형은 36번 줄과 같다.

각 인자의 의미
- base: 정렬할 배열의 시작 주소
- nmemb: 배열에 있는 요소의 총 개수
- size: 배열의 각 요소의 크기 (sizeof 연산자를 통해 구함)
- compar: 비교 함수 포인터(함수를 인자로 전달),
    이 함수는 두 요소를 비교하여 첫 번째 인수가 두번째 인수보다 작으면 0 보다 작은 값을, 같으면 0을, 크면 0보다 큰 값을 반환해야 한다.

**비교 함수를 사용하여 배열을 정렬하기에 비교 함수는 사용자가 정의하여 함수에 인자로 전달해야 한다.
이를 통해 오름차순, 내림차순 등 사용자가 원하는 정렬 기준을 적용 할 수 있다.

int, double, sturct 등 다양한 자료형의 배열을 사용할 수 있으며, 비교 함수를 통해 조정된다.
비교 함수 내에는 'const void*' 타입의 인자를 적절한 타입으로 형 변환한 후에 값이나 멤버 변수 등을 비교하여 정렬 기준으로 정의할 수 있다.
*/