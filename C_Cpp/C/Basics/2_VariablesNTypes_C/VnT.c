//VnT.c
/*Topic*/
/*
Data types
C has several types of variables, but there are a few basic types:

Integers - whole numbers which can be either positive or negative. Defined using char, int, short, long or long long.
Unsigned integers - whole numbers which can only be positive. Defined using unsigned char, unsigned int, unsigned short, unsigned long or unsigned long long.
Floating point numbers - real numbers (numbers with fractions). Defined using float and double.
Structures - will be explained later, in the Structures section.
The different types of variables define their bounds. A char can range only from -128 to 127, whereas a long can range from -2,147,483,648 to 2,147,483,647 (long and other numeric data types may have another range on different computers, for example - from –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 on 64-bit computer).

Note that C does not have a boolean type. Usually, it is defined using the following notation:
#define BOOL char
#define FALSE 0
#define TRUE 1
*/

/*practice question*/
#include <stdio.h>

int main(void)
{
    int i = 3;
    float f = 4.5;
    double d = 5.25;
    float sum;

    sum = i + f + d;
    // float f2i = (float)i;
    // float f2d = (float)d;

    // sum = f + f2i + f2d;

    printf("The sum of a a, b, and c is %f.", sum);
    return 0;
}