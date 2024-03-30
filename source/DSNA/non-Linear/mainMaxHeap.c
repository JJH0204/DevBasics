// mainMaxHeap.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "includeHeap.h"

int main(int argc, char *argv[])
{
    int nMaxHeapSize = 20;
    arrayMaxHeap *pMaxHeap = NULL;
    heapNode *pNode = NULL;

    pMaxHeap = createArrayMaxHeap(nMaxHeapSize);
    if (pMaxHeap == NULL)
        return -1;
    
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

    return 0;
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