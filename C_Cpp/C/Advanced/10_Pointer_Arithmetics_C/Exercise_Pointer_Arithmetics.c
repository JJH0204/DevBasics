// Exercise_Pointer_Arithmetics.c
// Copy last three addresses of intarray into parray which is an array of pointers to an int.
// intarray의 마지막 세 주소를 int에 대한 포인터 배열인 parray에 복사합니다.
#include <stdio.h>

int main()
{
    int intarray[5] = {10, 20, 30, 40, 50};
    //-----------------------^
    int *pointer = &intarray[2];

    // Array of 3 pointers
    int *parray[3];

    // printf("%d ", *pointer);
    
    // Copy last three addresses of intarray into parray
    // Use parray and pointer
    int i;
    for (i = 0; i < 3; i++)
    {
        // Insert code here
        parray[i] = pointer + i;
    }

    // Test code
    for (i = 0; i < 3; i++)
    {
        if (parray[i] == &pointer[i])
        {
            printf("Matched!\n");
        }
        else
        {
            printf("Fail\n");
        }
    }

    return 0;
}