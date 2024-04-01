// mainMaxHeap.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "includeHeap.h"

void exMaxHeap(void);
void exMinHeap(void);

int main(int argc, char *argv[])
{
    printf("[EX Max Heap]\n");
    exMaxHeap();
    printf("\n\n");
    printf("[EX Min Heap]\n");
    exMinHeap();
    return 0;
}

void exMaxHeap(void)
{
    int nMaxHeapSize = 20;
    arrayMaxHeap *pMaxHeap = NULL;
    heapNode *pNode = NULL;

    pMaxHeap = createArrayHeap(nMaxHeapSize);
    if (pMaxHeap == NULL)
        return;

    insertArrayMaxHeap(pMaxHeap, 90);
    insertArrayMaxHeap(pMaxHeap, 85);
    insertArrayMaxHeap(pMaxHeap, 80);
    insertArrayMaxHeap(pMaxHeap, 75);
    insertArrayMaxHeap(pMaxHeap, 70);
    insertArrayMaxHeap(pMaxHeap, 65);
    insertArrayMaxHeap(pMaxHeap, 60);
    insertArrayMaxHeap(pMaxHeap, 55);
    insertArrayMaxHeap(pMaxHeap, 50);
    insertArrayMaxHeap(pMaxHeap, 45);
    insertArrayMaxHeap(pMaxHeap, 40);
    insertArrayMaxHeap(pMaxHeap, 35);
    insertArrayMaxHeap(pMaxHeap, 30);

    printf("> Max Heap:\n");
    displayArrayHeap(pMaxHeap);

    insertArrayMaxHeap(pMaxHeap, 100);
    printf("> After insertArrayMaxHeap(): %d\n> Max Heap:\n", 100);
    displayArrayHeap(pMaxHeap);

    pNode = removeArrayMaxHeap(pMaxHeap);
    if (pNode != NULL)
    {
        printf("> removeArrayMaxHeap(): %d\n", pNode->nData);
        free(pNode);
    }

    printf("> Max Heap:\n");
    displayArrayHeap(pMaxHeap);

    deleteArrayMaxHeap(pMaxHeap);
}
/*.\heap.exe
> Max Heap:
        [1], 90
        [2], 85
        [3], 80
        [4], 75
        [5], 70
        [6], 65
        [7], 60
        [8], 55
        [9], 50
        [10], 45
        [11], 40
        [12], 35
        [13], 30
> After insertArrayMaxHeap(): 100
> Max Heap:
        [1], 100
        [2], 85
        [3], 90
        [4], 75
        [5], 70
        [6], 65
        [7], 80
        [8], 55
        [9], 50
        [10], 45
        [11], 40
        [12], 35
        [13], 30
        [14], 60
> removeArrayMaxHeap(): 100
> Max Heap:
        [1], 90
        [2], 85
        [3], 80
        [4], 75
        [5], 70
        [6], 65
        [7], 60
        [8], 55
        [9], 50
        [10], 45
        [11], 40
        [12], 35
        [13], 30
*/

void exMinHeap(void)
{
    int nMinHeapSize = 20;
    arrayMinHeap *pMinHeap = NULL;
    heapNode *pNode = NULL;

    pMinHeap = createArrayHeap(nMinHeapSize);
    if (pMinHeap == NULL)
        return;

    insertArrayMinHeap(pMinHeap, 30);
    insertArrayMinHeap(pMinHeap, 35);
    insertArrayMinHeap(pMinHeap, 40);
    insertArrayMinHeap(pMinHeap, 45);
    insertArrayMinHeap(pMinHeap, 50);
    insertArrayMinHeap(pMinHeap, 55);
    insertArrayMinHeap(pMinHeap, 60);
    insertArrayMinHeap(pMinHeap, 65);
    insertArrayMinHeap(pMinHeap, 70);
    insertArrayMinHeap(pMinHeap, 75);
    insertArrayMinHeap(pMinHeap, 80);
    insertArrayMinHeap(pMinHeap, 85);
    insertArrayMinHeap(pMinHeap, 90);

    printf("> Min Heap:\n");
    displayArrayHeap(pMinHeap);

    insertArrayMinHeap(pMinHeap, 53);
    printf("> After insertArrayMinHeap(): %d\n> Min Heap:\n", 53);
    displayArrayHeap(pMinHeap);

    pNode = removeArrayMinHeap(pMinHeap);
    if (pNode != NULL)
    {
        printf("> removeArrayMinHeap(): %d\n", pNode->nData);
        free(pNode);
    }

    printf("> Min Heap:\n");
    displayArrayHeap(pMinHeap);

    deleteArrayMaxHeap(pMinHeap);
}