#include "includeBitSet.h"
enum {ADD, RMV, SCH};

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

int main(int argc, char *argv[])
{
    int m, x, idx;

    BitSet s1 = BitSetNull;
    BitSet s2 = BitSetNull;

    while (1)
    {
        printf("s1: ");
        BitSet_PrintLn(s1);

        printf("s2: ");
        BitSet_PrintLn(s2);

        printf("(1)Add s1 (2) Remove s1 (3) Search s1 (4) Marge s1 <- s2 (5) More Oper\n"
               "(6)Add s2 (7) Remove s2 (8) Search s2 (9) Marge s2 <- s1 (0) Exit\n : ");
        scanf("%d", &m);

        if (m == 0)
            break;

        switch (m)
        {
        case 1:
            x = scan_data(ADD);
            BitSet_Add(&s1, x);
            break;
        case 2:
            x = scan_data(RMV);
            BitSet_Remove(&s1, x);
            break;
        case 3:
            x = scan_data(SCH);
            idx = BitSet_IsMember(s1, x);
            printf("%s s1.\n", idx >= 0 ? "In" : "Not in");
            break;
        case 4:
            s1 = s2;
            break;
        case 5:
            printf("s1 == s2 = %s\n", s1 == s2 ? "true" : "false");
            printf("s1 & s2 = ");
            BitSet_PrintLn(s1 & s2);
            printf("s1 | s2 = ");
            BitSet_PrintLn(s1 | s2);
            printf("s1 - s2 = ");
            BitSet_PrintLn(s1 & ~s2);
            printf("Symmetric difference between s1 and s2: ");
            BitSet_PrintLn(BitSet_SyDifference(s1, s2));
            break;
        case 6:
            x = scan_data(ADD);
            BitSet_Add(&s2, x);
            break;
        case 7:
            x = scan_data(RMV);
            BitSet_Remove(&s2, x);
            break;
        case 8:
            x = scan_data(SCH);
            idx = BitSet_IsMember(s2, x);
            printf("%s s2.\n", idx != 0 ? "In" : "Not in");
            break;
        case 9:
            s2 = s1;
            break;
        }
    }
    
    return 0;
}