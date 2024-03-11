# 포인터 연산자
포인터가 무엇인지, 포인터를 활용하는 방법을 이전에 배웠습니다. 이 튜토리얼에서는 포인터에 대한 산술 연산을 배우게 됩니다. C 포인터에 적용할 수 있는 산술 연산은 여러 가지가 있습니다: ++, --, -, +

## (++)를 사용하여 포인터 증가
다른 변수들과 마찬가지로 ++연산은 그 변수의 값을 증가시킨다. 이런 경우 여기서 변수는 포인터이므로 값을 늘리면 포인터가 가리키는 메모리의 주소가 증가합니다. 예제에서는 이 작업을 배열과 결합해 보겠습니다.

    #include <stdio.h>

    int main()
    {
        int intarray[5] = {10,20,30,40,50};

        int i;
        for(i = 0; i < 5; i++)
            printf("intarray[%d] has value %d - and address @ %x\n", i, intarray[i], &intarray[i]);

        int *intpointer = &intarray[3]; //point to the 4th element in the array
        printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 4th element

        intpointer++; //now increase the pointer's address so it points to the 5th elemnt in the array
        printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 5th element

        return 0;
    }
## (--)를 사용하여 포인터 감소
이전 예제와 마찬가지로 연산자를 사용하여 포인터가 가리키는 주소를 1만큼 늘렸고, 감소 연산자(--)를 사용하여 가리키는 주소를 1만큼 줄일 수 있습니다.
    #include <stdio.h>

    int main()
    {
        int intarray[5] = {10,20,30,40,50};

        int i;
        for(i = 0; i < 5; i++)
            printf("intarray[%d] has value %d - and address @ %x\n", i, intarray[i], &intarray[i]);

        int *intpointer = &intarray[4]; //point to the 5th element in the array
        printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 5th element

        intpointer--; //now decrease the point's address so it points to the 4th element in the array
        printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 4th element

        return 0;
    }
## (+)로 포인터 추가하기
이전에는 포인터가 가리키는 주소를 1만큼 늘렸습니다. 다음과 같이 정수 값으로 늘릴 수도 있습니다.

    #include <stdio.h>

    int main()
    {
        int intarray[5] = {10,20,30,40,50};

        int i;
        for(i = 0; i < 5; i++)
            printf("intarray[%d] has value: %d - and address @ %x\n", i, intarray[i], &intarray[i]);

        int *intpointer = &intarray[1]; //point to the 2nd element in the array
        printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 2nd element

        intpointer += 2; //now shift by two the point's address so it points to the 4th element in the array
        printf("address: %x - has value %d\n", intpointer, *intpointer); //print the addres of the 4th element

        return 0;
    }
출력에서 주소가 메모리에서 8단계만큼 이동한 방법에 유의하세요. 포인터가 int 포인터이고 int 변수의 크기가 4바이트이기 때문에 메모리는 4블록만큼 이동할 수 있습니다. 우리 코드에서는 초기 주소에 2(2를 더함)만큼 이동하여 2 x 4 바이트 = 8이 되었습니다.

## (-) 포인터 빼기 
마찬가지로 다음을 뺄 수 있습니다.

    #include <stdio.h>

    int main()
    {
        int intarray[5] = {10,20,30,40,50};

        int i;
        for(i = 0; i < 5; i++)
            printf("intarray[%d] has value: %d - and address @ %x\n", i, intarray[i], &intarray[i]);

        int *intpointer = &intarray[4]; //point to the 5th element in the array
        printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 5th element

        intpointer -= 2; //now shift by two the point's address so it points to the 3rd element in the array
        printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 3rd element

        return 0;
    }
다시 한번 주소가 4바이트 블록만큼 이동됩니다(int의 경우).

## 기타 연산자
비교 >, <, == 등의 연산이 더 있습니다. 아이디어는 변수를 비교하는 것과 매우 유사하지만 이 경우에는 메모리 주소를 비교합니다.