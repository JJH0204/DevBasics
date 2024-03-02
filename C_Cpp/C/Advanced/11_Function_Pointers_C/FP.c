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