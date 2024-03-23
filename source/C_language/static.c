//static.c
#include <stdio.h>

/*What is a static variable*/
int ExNoneStatic()
{
    int count = 0;
    count++;
    return count;
}

int ExStatic()
{
    static int count = 0;
    count++;
    return count;
}

void ExCode()
{
    /*None Static*/
    printf("%d ", ExNoneStatic());
    printf("%d\n", ExNoneStatic());

    /*Static*/
    printf("%d ", ExStatic());
    printf("%d\n", ExStatic());
}

static void ExStaticFun(void)
{
    printf("I am a static function.");
}
/*By default, functions are global in C. If we declare a function with static, the scope of that function is reduced to the file containing it.*/
// Static vs Global?
// While static variables have scope over the file containing them making them accessible only inside a given file, global variables can be accessed outside the file too.

/*Exercise*/
int sum (int num)
{
    static int i = 0;
    i += num;
    return i;
}

int main(void)
{
    ExCode();
    printf("%d ", sum(55));
    printf("%d ", sum(45));
    printf("%d ", sum(50));
    return 0;
}