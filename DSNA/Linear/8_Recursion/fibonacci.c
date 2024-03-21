// fibonacci.c
#include <stdio.h>
// #define RECURSION
#ifdef RECURSION
int fib(int n)
{
    int ret = 0;

    if (n == 0)
    {
        ret = 0;
    }
    else if (n == 1)
    {
        ret = 1;
    }
    else
    {
        ret = fib(n - 1) + fib(n - 2);
    }
    return ret;
}
#endif
#ifndef RECURSION
int fib(int n)
{
    int nLast = 0;
    int nCurrent = 1;
    int nTemp = 0;
    int nCount = 0;

    if (n <= 1)
        return n;
    for (nCount = 2; nCount <= n; nCount++)
    {
        nTemp = nCurrent;
        nCurrent += nLast;
        nLast = nTemp;
    }
    return nCurrent;
}
#endif
int main(int argc, char * argv[])
{
    int n = 1000;
    printf("fib(%d) = %d\n", n, fib(n));
    return 0;
}