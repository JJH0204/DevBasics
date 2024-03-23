#include <stdio.h>
#include <stdlib.h>

/*EX_1*/
void Ex_Fun_1(void);
void Ex_Fun_2(void);
void Ex_Fun_3(void);

void Ex_Fun_1(void)
{
    char vowels[] = {'A', 'E', 'I', 'O', 'U'};
    char *pvowels = vowels;
    int i;
    
    // Print the addresses
    for (i = 0; i < 5; i++) {
    printf("&vowels[%d]: %p, pvowels + %d: %p, vowels + %d: %p\n", i, &vowels[i], i, pvowels + i, i, vowels + i);
    }

    // Print the values
    for (i = 0; i < 5; i++) {
    printf("vowels[%d]: %c, *(pvowels + %d): %c, *(vowels + %d): %c\n", i, vowels[i], i, *(pvowels + i), i, *(vowels + i));
    }
}

void Ex_Fun_2(void)
{
    // Allocate memory to store five characters
    int n = 5;
    char *pvowels = (char *) malloc(n * sizeof(char));
    int i;

    pvowels[0] = 'A';
    pvowels[1] = 'E';
    *(pvowels + 2) = 'I';
    pvowels[3] = 'O';
    *(pvowels + 4) = 'U';

    for (i = 0; i < n; i++) {
        printf("%c ", pvowels[i]);
    }

    printf("\n");

    free(pvowels);
}

void Ex_Fun_3(void)
{
    int nrows = 2;
    int ncols = 5;
    int i, j;

    // Allocate memory for nrows pointers
    char **pvowels = (char **) malloc(nrows * sizeof(char *));

    // For each row, allocate memory for ncols elements
    pvowels[0] = (char *) malloc(ncols * sizeof(char));
    pvowels[1] = (char *) malloc(ncols * sizeof(char));

    pvowels[0][0] = 'A';
    pvowels[0][1] = 'E';
    pvowels[0][2] = 'I';
    pvowels[0][3] = 'O';
    pvowels[0][4] = 'U';

    pvowels[1][0] = 'a';
    pvowels[1][1] = 'e';
    pvowels[1][2] = 'i';
    pvowels[1][3] = 'o';
    pvowels[1][4] = 'u';

    for (i = 0; i < nrows; i++) {
        for(j = 0; j < ncols; j++) {
            printf("%c ", pvowels[i][j]);
        }

        printf("\n");
    }

    // Free individual rows
    free(pvowels[0]);
    free(pvowels[1]);

    // Free the top-level pointer
    free(pvowels);
}

/*Exercise*/
/*The first seven rows of Pascal's triangle are shown below. Note that row i contains i elements. 
Therefore, to store the numbers from the first three rows, one would require 1 + 2 + 3 = 6 memory slots.*/

int main() {
    int i, j;
    /* TODO: define the 2D pointer variable here */
    int **pnumbers;

    /* TODO: complete the following line to allocate memory for holding three rows */
    pnumbers = (int **) malloc(3 * sizeof(int *));

    /* TODO: allocate memory for storing the individual elements in a row */
    pnumbers[0] = (int *) malloc(1 * sizeof(int));
    pnumbers[1] = (int *) malloc(2 * sizeof(int));
    pnumbers[2] = (int *) malloc(3 * sizeof(int));

    pnumbers[0][0] = 1;
    pnumbers[1][0] = 1;
    pnumbers[1][1] = 1;
    pnumbers[2][0] = 1;
    pnumbers[2][1] = 2;
    pnumbers[2][2] = 1;

    for (i = 0; i < 3; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d", pnumbers[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++) {
        /* TODO: free memory allocated for each row */
        free(pnumbers[i]);
    }

    /* TODO: free the top-level pointer */
    free(pnumbers);

  return 0;
}