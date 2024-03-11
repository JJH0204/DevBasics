//Exercise_Unions.c
/*Create a union that stores an array of 21 characters and 6 ints (6 since 21 / 4 == 5, but 5 * 4 == 20 so you need 1 more for the purpose of this exercise), 
you will set the integers to 6 given values and then print out the character array both as a series of chars and as a string.*/
#include <stdio.h>
#define Answer

#ifdef Question
/* define the union here */

int main() {

    // initializer lists like this are assigned to the first member of the union/struct!
    // There are 6 ints here so...
    <union declaration> intCharacters = {{1853169737, 1936876900, 1684955508, 1768838432, 561213039, 0}};
    
    /* testing code */
    printf("[");
    // only go to 18 because 1 byte is for the terminating 0 and we don't print the last in the loop
    for(int i = 0; i < 19; ++i)
        printf("%c, ", intCharacters.chars[i]);
    printf("%c]\n", intCharacters.chars[19]);

    printf("%s\n", intCharacters.chars);
}
#endif

#ifndef Question
/* 수정된 공용체 정의 */
union Data
{
    char chars[21]; // 21개의 문자를 저장하기 위한 배열
    int ints[6];    // 6개의 정수를 저장하기 위한 배열
};

int main()
{
    // 공용체 초기화
    union Data intCharacters = {.ints = {1853169737, 1936876900, 1684955508, 1768838432, 561213039, 0}};

    /* 테스트 코드 */
    printf("[");
    // 마지막 바이트는 문자열 종료를 위한 '\0'이므로 19까지만 출력
    for (int i = 0; i < 19; ++i)
        printf("%c, ", intCharacters.chars[i]);
    printf("%c]\n", intCharacters.chars[19]);

    printf("%s\n", intCharacters.chars); // chars 배열을 문자열로 출력

    return 0;
}

/*풀이 과정*/
// 1. 공용체 정의 수정하기 
// - 21개의 문자와 6개의 정수를 저장할 수 있는 공용체를 만들어야 한다.
// - 21개의 문자열을 저장하기 위한 'char'배열과 6개의 정수를 저장하기 위한 'int'배열은 같은 메모리 공간을 공유한다.

// 2. 초기화 수정하기
// - c언어 표준에서는 공용체에 대한 초기화 리스트를 사요하는 것이 제한적이다.
// - 공용체의 첫 번째 멤버만 초기화 할 수 있기 때문에 직접적으로 'int' 배열을 초기화하는 것은 표준 방식에서 어긋난다.
// - 그러나 목적 달성을 위해 간접적인 방법을 사용한다.
// - 주어진 정수 값들로 'char'배열을 초기화 하는 대신 'int'배열을 사용하는 방식으로 코드를 구성한다.
#endif