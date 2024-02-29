// Unions.c
// Practice file to understand the concept of Unions in C language

#include <stdio.h>

/*Unions*/
union uniontype
{
    int intval;
    char charval;
} uniontype;

/*질문 1: 크기가 작은 멤버 변수로 메모리에 접근하면 어디를 가리킬까?*/
void _practice1_(void)
{
    union uniontype val;

    val.intval = 1000000;

    printf("%d", val.charval);      // print 64
    printf("%d", val.intval);       // print 1000000
    /* 한글 설명
    왜? 출력 내용이 다를까?

    union 정의는 할당한 메모리에 참조하는 방식을 자유롭게 정의할 수 있게할 때 사용한다.

    유니온 변수는 여러 멤버들이 메모리의 같은 위치를 공유합니다. 
    이는 모든 멤버들이 같은 메모리 주소를 시작점으로 사용한다는 것을 의미합니다. 
    따라서, int 타입으로 1000000을 저장한 후, char 타입 멤버를 통해 해당 메모리에 접근하면, int 값 1000000을 구성하는 바이트 중 하나에 접근하게 됩니다.
    
    int 타입이 4바이트(32비트)를 사용하고, char 타입이 1바이트(8비트)를 사용하는 것을 고려할 때, 1000000의 이진수 표현은 00001111 01000010 01000000입니다. 
    (int 자료형은 4byte를 사용하지만 그중 가장 앞 1byte는 부호를 표현할 때 사용한다. 그래서 3byte에 해당하는 2진 표현만 진행)
    여기서 char 타입으로 접근하면 int 값의 가장 낮은 바이트에 해당하는 부분에 접근하게 됩니다.
    
    하지만, 특정 시스템에서 char가 해당 int 값의 어느 부분을 가리키는지(가장 낮은 바이트인지, 아니면 다른 바이트인지)는 해당 시스템의 엔디언(endian)에 따라 달라집니다. 
    대부분의 시스템은 리틀 엔디언을 사용하므로, 1000000의 가장 낮은 바이트에 접근하게 됩니다.
    
    결론은 이 경우 01000000에 해당하는 값에 접근하게 되어, 십진수로 64가 출력된다.
    */

   /* English explanation
    why? Will the output be different?

    The union definition is used to freely define the method of referencing the allocated memory.

    A union variable has multiple members sharing the same location in memory.
    This means that all members use the same memory address as their starting point.
    Therefore, if you store 1000000 as an int type and then access the memory through a char type member, you will access one of the bytes that make up the int value 1000000.

    Considering that the int type uses 4 bytes (32 bits) and the char type uses 1 byte (8 bits), the binary representation of 1000000 is 00001111 01000010 01000000.
    (The int data type uses 4 bytes, but the first 1 byte is used to express the sign. Therefore, only binary expression corresponding to 3 bytes is used)
    Here, when accessing the char type, you access the part corresponding to the lowest byte of the int value.

    However, on a particular system, which part of the int value the char points to (the lowest byte or another byte) depends on the endianness of that system.
    Most systems use little endian, so they access the lowest byte of 1000000.

    The conclusion is that in this case, the value corresponding to 01000000 is approached, and 64 is output as a decimal number.
    */
    return;
}

int main(void)
{
    _practice1_();
    return 0;
}

// 새롭게 안 사실
// 1. 메모리 참조는 아래에서 위로 진행된다. (낮은 값부터 참조)
// 2. unsigned ~ 로 정의(선언)하지 않은 변수는 메모리 할당 시 가장 높은 1byte 를 +(-) 표현에 사용한다.
//     따라서, union 사용 시 저장하는 데이터의 데이터 타입에 따라 1byte 값에 의해 값이 변질 될 수 있다.