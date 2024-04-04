// mainGraph.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// #define _ArrayGraph_

#ifdef _ArrayGraph_

#include "includeArrayGraph.h"

int main(int argc, char *argv[])
{
    int nNodeCount = 6;

    ArrayGraph *pArrayGraph = createArrayGraph(UNDIRECT_TYPE, nNodeCount);

    if (ISNULL_ERROR(pArrayGraph))
        return -1;

    addEdge(pArrayGraph, 0, 1);
    addEdge(pArrayGraph, 1, 2);
    addEdge(pArrayGraph, 2, 0);
    addEdge(pArrayGraph, 2, 3);
    addEdge(pArrayGraph, 3, 2);
    addEdge(pArrayGraph, 3, 4);
    addEdge(pArrayGraph, 4, 5);
    addEdge(pArrayGraph, 5, 3);

    printf("> ArrayGraph: UNDIRECT\n");
    displayGraph(pArrayGraph);
    deleteGraph(pArrayGraph);
    return 0;
}
/*..\arrayGraph.exe
> ArrayGraph: Digraph
0 1 0 0 0 0
0 0 1 0 0 0
1 0 0 1 0 0
0 0 1 0 1 0
0 0 0 0 0 1
0 0 0 1 0 0
*/
/*.\ArrayGraph.exe
> ArrayGraph: non-Digraph
0 1 1 0 0 0
1 0 1 0 0 0
1 1 0 1 0 0
0 0 1 0 1 1
0 0 0 1 0 1
0 0 0 1 1 0
*/
#endif

#ifndef _ArrayGraph_

#include "includeLinkedGraph.h"

int main(int argc, char *argv[])
{
    int nNodeCount = 6;

    LinkedGraph *pLinkedGraph = createLinkedGraph(UNDIRECT_TYPE, nNodeCount);

    if (ISNULL_ERROR(pLinkedGraph))
        return -1;

    addEdge(pLinkedGraph, 0, 1);
    addEdge(pLinkedGraph, 1, 2);
    addEdge(pLinkedGraph, 2, 0);
    addEdge(pLinkedGraph, 2, 3);
    addEdge(pLinkedGraph, 3, 2);
    addEdge(pLinkedGraph, 3, 4);
    addEdge(pLinkedGraph, 4, 5);
    addEdge(pLinkedGraph, 5, 3);

    printf("> LinkedGraph: UNDIRECT\n");
    displayGraph(pLinkedGraph);
    deleteGraph(pLinkedGraph);
    return 0;
}
/*.\linkedGraph.exe
> LinkedGraph: Digraph
0 1 0 0 0 0
0 0 1 0 0 0
1 0 0 1 0 0
0 0 1 0 1 0
0 0 0 0 0 1
0 0 0 1 0 0
*/
/*.\LinkedGraph.exe
> LinkedGraph: UNDIRECT
0 1 1 0 0 0
1 0 1 0 0 0
1 1 0 1 0 0
0 0 1 0 1 1
0 0 0 1 0 1
0 0 0 1 1 0
*/

#endif