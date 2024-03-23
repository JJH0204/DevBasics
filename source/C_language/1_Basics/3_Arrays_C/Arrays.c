//Arrays.c
#include <stdio.h>

int main(void)
{
    int a_numbers[10];
    int max_Array = 10;

    for (int i=0; i < max_Array; i++)
    {
        a_numbers[i] = 10 * i;
    }

    printf("The 7th number in ther array is %d.", a_numbers[6]);

    /* TODO: define the grades variable here */
    int grades[3];
    int average;

    grades[0] = 80;
    /* TODO: define the missing grade
       so that the average will sum to 85. */
    grades[1] = 85;
    grades[2] = 90;

    average = (grades[0] + grades[1] + grades[2]) / 3;
    printf("The average of the 3 grades is: %d", average);

    return 0;
}