// Unions.c
// Practice file to understand the concept of Unions in C language

#include <stdio.h>

/*Unions of practice_1*/
typedef union practice_1
{
    int intval;
    char charval;
} practice_1;

/*질문 1: 크기가 작은 멤버 변수로 메모리에 접근하면 어디를 가리킬까?*/
void _practice1_(void)
{
    practice_1 val;

    val.intval = 1000000;

    printf("print from char: %d\n", val.charval);      // print 64
    printf("print from int: %d\n", val.intval);       // print 1000000
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

/*Unions of practice_2*/
typedef union practice_2
{
    unsigned int unsignedintval;
    int intval;
    char chararray[sizeof(int)];    // same as: char chararray[4];
} practice_2;

void _practice2_(void)
{
    practice_2 val;

    val.intval = 1000000;

    printf("print from int: %d\n", val.unsignedintval);     // print 1000000
    
    printf("print from char: %d\n", val.chararray[0]);      // print 64
    printf("print from char: %d\n", val.chararray[1]);      // print 66
    printf("print from char: %d\n", val.chararray[2]);      // print 15
    printf("print from char: %d\n", val.chararray[3]);      // print 0
    
    val.chararray[3] = 255;

    printf("print from int: %d\n", val.intval);             // print -15777216
    printf("print from int: %d\n", val.unsignedintval);     // print -15777216

    val.chararray[3] = 1;

    printf("print from int: %d\n", val.intval);             // print 17777216
    printf("print from int: %d\n", val.unsignedintval);     // print 17777216
    /*
    union 멤버 변수로 배열을 정의하면 배열 방식으로 메모리를 탐색할 수 있다.

    Union 변수 사용을 조심해야 하는 이유.
    chararray[3]으로 int 데이터 타입의 4번째 byte에 접근해 값을 저장했다.
    그 결과 int 멤버 변수로 메모리를 참조했을 때 반환되는 값의 형태가 크게 바뀌었다.
    (양 또는 음 수를 오르내릴 정도의 큰 변화가 발생)

    또한 0이상 양의 정수를 저장하고 사용하려고 정의한 Unsigned int 멤버 변수에 참조했을 때 예상과 달리 음의 정수가 반환되었다.
    이러한 접근 및 사용은 프로그램의 에러를 부를 것이라 예상되며 앞으로 주의가 필요해보인다.
    */

    return;
}

/*Unions of practice_3*/
void _practice3_(void)
{
    // practice_2 val;

    // val.intval = 1000000;

    int theInt = 1000000;

    // %i == %d
    printf("print from int: %i, The bytes are [%i, %i, %i, %i]\n", 
    theInt, *((char*)&theInt+0), *((char*)&theInt+1), *((char*)&theInt+2), *((char*)&theInt+3));
    
    printf("print from int: %i, The bytes are [%i, %i, %i, %i]\n", 
    theInt, ((char*)&theInt)[0], ((char*)&theInt)[1], ((char*)&theInt)[2], ((char*)&theInt)[3]);
    /*
    Union 변수의 메모리 참조 방식에서 착안한 아이디어.
    포인터 연산자를 활용해 int형 변수를 char형 변수 크기(1byte) 만큼 접근하는 방식이다.
    변수 선언 또는 함수 호출로 할당한 메모리를 원하는 byte 사이즈 만큼 이동하며 참조할 수 있다.

    포인터 연산자가 적용된다는 것은 배열 문법(연산) 또한 사용가능하다는 것이니 더 편한 방법을 사용하면 될 것 같다.
    (포인터 연산자는 코드가 직관적으로 이해하기 어려워 보인다.-개인적 의견)
    */

    return;
}

/*Unions of practice_4*/
struct operator_1
{
    int type;           // 4byte
    int intNum;         // 4byte
    float floatNum;     // 4byte
    double doubleNum;   // 8byte
};

struct operator_2
{
    int type;
    union Unions
    {
        int intNum;
        float floatNum;
        double doubleNum;
    } types; // 변수 이름이 없으면 union 멤버 변수 이름을 사용해 바로 메모리 접근이 가능해 진다.
};

void _practice4_(void)
{
    struct operator_1 op_1;
    struct operator_2 op_2;

    op_2.type = 0;
    op_2.types.intNum = 352;
    
    // using %lu
    printf("op_1: [%lu], op_2: [%lu]\n", sizeof(op_1), sizeof(op_2));
    printf("op_1: [%lu], op_2: [%lu]\n", sizeof(struct operator_1), sizeof(struct operator_2));
    // op_1: [24], op_2: [16]

    printf("op_1.type: [%lu], op_1.intNum: [%lu], op_1.floatNum: [%lu], op_1.doubleNum: [%lu]\n", 
    sizeof(op_1.type), sizeof(op_1.intNum), sizeof(op_1.floatNum), sizeof(op_1.doubleNum));
    // op_1.type: [4], op_1.intNum: [4], op_1.floatNum: [4], op_1.doubleNum: [8]
    printf("op_2.type: [%lu], op_2.types.doubleNum: [%lu], op_2.types.floatNum: [%lu], op_2.types.intNum: [%lu]\n", sizeof(op_2.type), sizeof(op_2.types.doubleNum), sizeof(op_2.types.floatNum), sizeof(op_2.types.intNum));
    /*
    // 20byte 야 되는데 왜 사이즈 출력하면 24byte 로 나올까?
    
    struct에 정의된 변수의 총 크기가 20바이트로 예상되지만 실제로 24바이트로 출력되는 이유는 메모리 정렬과 패딩(padding) 기법 때문입니다. 
    컴파일러는 메모리를 효율적으로 접근하고 사용하기 위해 특정 바이트 단위(예: 4바이트)로 데이터를 정렬합니다. 
    이 과정에서 구조체의 멤버 변수 사이에 사용되지 않는 데이터 바이트를 삽입할 수 있으며, 이를 '패딩'이라고 합니다.

    예를 들어, int와 float는 4바이트를 차지하고, double은 8바이트를 차지합니다. 
    컴파일러가 4바이트 단위로 메모리를 정렬하려고 할 때, int, int, float 멤버는 연속적으로 배치되어도 문제가 없지만, double 멤버를 위해 추가적인 메모리 정렬이 필요할 수 있습니다. 
    따라서, 구조체의 실제 크기가 멤버 변수들의 크기의 합보다 클 수 있으며, 이는 메모리 접근 최적화를 위한 컴파일러의 동작 때문입니다​​.

    이러한 메모리 정렬과 패딩은 플랫폼(운영 체제 및 하드웨어 아키텍처), 컴파일러, 그리고 컴파일러의 설정에 따라 달라질 수 있습니다. 
    따라서, 동일한 구조체라도 다른 환경에서는 다른 메모리 크기를 가질 수 있습니다.
    */
   /*
    구조체 변수의 메모리 절약방법으로 Unions를 사용할 수 있다.
    위 예제를 통해 설명하자면,
    구조체 operator_1은 메모리 할당 시 멤버 변수들의 모든 사이즈의 합 만큼 메모리를 할당해 사용한다.
    (메모리 패딩에 의해 20byte가 아닌 24byte가 할당된다.)
    구조체 operator_2는 정의 단계에서 멤버 변수 중 일부를 Union으로 정의하여 메모리 할 당시 일부 메모리를 여러 변수 이름이 공유하게 된다.
    union을 사용하지 않은 operator_1에 비해 operator_2의 메모리 사용량은 -8byte로 줄어든다.
    (메모리 패딩을 감안하더라도 매우 유의미한 최적화가 가능해진다.)
    */
    
    return;
}

/*Unions of practice_5*/
union Coins
{
    struct
    {
        int quarter;        // 메모리 첫번째 공간 할당
        int dime;           // 메모리 두번째 공간 할당
        int nickel;         // 메모리 세번째 공간 할당
        int penny;          // 메모리 네번째 공간 할당
    };
    int coins[4];;
};

void _practice5_(void)
{
    union Coins change;

    change.quarter = 10;
    change.dime = 20;
    change.nickel = 30;
    change.penny = 40;

    for (int i = 0; i < sizeof(change) / sizeof(int); i++)
    {
        // printf("%d ", change.coins[i]);
        printf("%i ", *(change.coins + i));
    }
    printf("\n");
    // print: 10 20 30 40

    // scanf("%i", change.coins + i); 인자로 전달한 메모리 주소에 키보드로 입력받은 데이터를 저장하는 함수(변수의 메모리 값을 전달해야 함)
}

int main(void)
{
    // _practice1_();
    // _practice2_();
    // _practice3_();
    // _practice4_();
    _practice5_();

    return 0;
}

// 새롭게 안 사실
// 1. 메모리 참조는 아래에서 위로 진행된다. (낮은 값부터 참조)
// 2. unsigned ~ 로 정의(선언)하지 않은 변수는 메모리 할당 시 가장 높은 1byte 를 +(-) 표현에 사용한다.
//     따라서, union 사용 시 저장하는 데이터의 데이터 타입에 따라 1byte 값에 의해 값이 변질 될 수 있다.
// 3. 멥버 변수로 메모리를 배열 형식 또는 포인터 형식으로 자유롭게 이동할 수 있다.
//     멤버 변수로 struct 까지 추가할 수 있다.
// 4. struct 변수 선언 시 메모리 절약을 위해 union을 사용할 수 있다.
// 5. struct 변수 선언 시 패딩이라는 기능이 컴파일러에 단에서 진행되어 예상보다 큰 크기의 메모리가 할당된다.
//     (struct의 멤버 변수간 크기 차이가 있을 때 발생)
// 6. struct 멤버 변수는 메모리 할당 시 위에서 아래로 순서대로 메모리에 할당된다.
//     그래서 union 멤버 변수로 struct를 정의할 경우 다른 멤버 변수로 struct의 멤버 변수의 메모리에 자유롭게 접근이 가능해 진다. (3번의 추가 설명)
//     (메모리 할당은 아래에서 위로 쌓는 방식으로 진행된다.)