#include "includeIntSet.h"

void ExampleSet1(void)
{
    IntSet s1, s2, s3;
    Initialize(&s1, 24);
    Initialize(&s2, 24);
    Initialize(&s3, 24);

    Add(&s1, 10);
    Add(&s1, 15);
    Add(&s1, 20);
    Add(&s1, 25);

    Assign(&s2, &s1);
    Add(&s2, 12);
    Remove(&s2, 20);

    Assign(&s3, &s2);

    printf("s1: ");
    PrintLn(&s1);
    printf("s2: ");
    PrintLn(&s2);
    printf("s3: ");
    PrintLn(&s3);

    printf("The number 15 is %s set s1.\n", IsMember(&s1, 15) > 0 ? "in" : "not in");
    printf("The number 25 is %s set s2.\n", IsMember(&s2, 25) > 0 ? "in" : "not in");

    printf("Set s1 is %s Set s2.\n", Equal(&s1, &s2) ? "same as" : "not same as");
    printf("Set s2 is %s Set s3.\n", Equal(&s2, &s3) ? "same as" : "not same as");

    Terminate(&s1);
    Terminate(&s2);
    Terminate(&s3);
}

void ExampleSet1(void)
{

}

int main(int argc, char *argv[])
{
    ExampleSet1(); /* 집합 예제 1*/
    ExampleSet2(); /* 집합 예제 2*/
    return 0;
}