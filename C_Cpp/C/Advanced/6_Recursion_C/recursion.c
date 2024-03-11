// recursion.c

/*Exercise*/
/*Define a new function called factorial() that will compute the factorial by recursive multiplication (5! = 5 x 4 x 3 x 2 x 1).
Note that by convention, the factorial of 0 is equal to 1 (0! = 1).*/
#include <stdio.h>

unsigned int factorial (unsigned int x);

int main() {
    /* testing code */
    printf("0! = %i\n", factorial(0));
    printf("1! = %i\n", factorial(1));
    printf("3! = %i\n", factorial(3));
    printf("5! = %i\n", factorial(5));
}

/* define your function here (don't forget to declare it) */
unsigned int factorial (unsigned int x)
{
    if (x == 1)
    {
        return x;
    }
    else if (x > 1)
    {
        return x * factorial(x - 1);
    }
    else
    {
        return 1;
    }
}