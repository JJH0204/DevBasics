// mainGraph.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "includeArrayGraph.h"

int main(int argc, char *argv[])
{
    int nNodeCount = 6;
    
    DirectArrayGraph *pArrayGraph = createDirectArrayGraph(nNodeCount);
    
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

    printf("> ArrayGraph: Digraph\n");
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