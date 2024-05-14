#include "includeIntSet.h"

void ExampleSet1 (void)
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

enum
{
    ADD,
    RMV,
    SCH
};

int scan_data(int sw)
{
    int data;
    switch (sw)
    {
    case ADD:
        printf("Add data: ");
        break;
    case RMV:
        printf("Remove data: ");
        break;
    case SCH:
        printf("Search data: ");
        break;
    }
    scanf("%d", &data);
    return data;
}

void ExampleSet2(void)
{
    IntSet s1, s2, temp;
    int m, x, idx;
    Initialize(&s1, 512);
    Initialize(&s2, 512);
    Initialize(&temp, 512);

    while (1)
    {
        printf("s1: ");
        PrintLn(&s1);
        printf("s2: ");
        PrintLn(&s2);

        printf("(1)Add s1 (2) Remove s1 (3) Search s1 (4) Marge s1 <- s2 (5) More Oper\n"
               "(6)Add s2 (7) Remove s2 (8) Search s2 (9) Marge s2 <- s1 (0) Exit\n : ");

        scanf("%d", &m);

        if (m == 0)
            break;

        switch (m)
        {
        case 1:
            x = scan_data(ADD);
            Add(&s1, x);
            break;
        case 2:
            x = scan_data(RMV);
            Remove(&s1, x);
            break;
        case 3:
            x = scan_data(SCH);
            idx = IsMember(&s1, x);
            printf("%s s1.\n", idx >= 0 ? "In" : "Not in");
            break;
        case 4:
            Assign(&s1, &s2);
            break;
        case 5:
            printf("s1 == s2 = %s\n", Equal(&s1, &s2) ? "true" : "false");
            printf("s1 & s2 = ");
            Intersection(&temp, &s1, &s2);
            PrintLn(&temp);
            printf("s1 | s2 = ");
            Union(&temp, &s1, &s2);
            PrintLn(&temp);
            printf("s1 - s2 = ");
            Difference(&temp, &s1, &s2);
            PrintLn(&temp);
            break;
        case 6:
            x = scan_data(ADD);
            Add(&s2, x);
            break;
        case 7:
            x = scan_data(RMV);
            Remove(&s2, x);
            break;
        case 8:
            x = scan_data(SCH);
            idx = IsMember(&s2, x);
            printf("%s s2.\n", idx >= 0 ? "In" : "Not in");
            break;
        case 9:
            Assign(&s2, &s1);
            break;
        }
    }
    Terminate(&s1);
    Terminate(&s2);
    Terminate(&temp);

    return;
}

int main(int argc, char *argv[])
{
    // ExampleSet1(); /* 집합 예제 1*/
    ExampleSet2(); /* 집합 예제 2*/
    return 0;
}