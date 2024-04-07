// mainGraph.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define _ArrayGraph_

#ifdef _ArrayGraph_
#include "includeArrayGraph.h"

void ex_PrintGraph(void)
{
    int nNodeCount = 6;

    ArrayGraph *pArrayGraph = createArrayGraph(UNDIRECT_TYPE, nNodeCount);

    if (ISNULL_ERROR(pArrayGraph))
        return;

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
}

void ex_DFS(void)
{
    int nNodeCount = 4;
    ArrayGraph *pGraph = createArrayGraph(UNDIRECT_TYPE, nNodeCount);
    int *pVisitNodes = (int *)malloc(sizeof(int) * nNodeCount);     // 노드 방문여부 체크용 배열 변수

    if (ISNULL_ERROR(pGraph) || ISNULL_ERROR(pVisitNodes))
        return;
    
    addEdge(pGraph, 0, 1);
    addEdge(pGraph, 0, 2);
    addEdge(pGraph, 1, 3);
    
    memset(pVisitNodes, 0, sizeof(int) * nNodeCount);

    printf("pGraph's DFS\n");
    traversalDFS(pGraph, 0, pVisitNodes);       // 시작 노드를 0으로 깊이 우선 탐색(재귀함수) 호출(실행)

    deleteGraph(pGraph);
    free(pVisitNodes);
    return;
}

void ex_BFS(void)
{
    int nNodeCount = 4;
    ArrayGraph *pGraph = createArrayGraph(UNDIRECT_TYPE, nNodeCount);

    if (ISNULL_ERROR(pGraph))
        return;
    
    addEdge(pGraph, 0, 1);
    addEdge(pGraph, 0, 2);
    addEdge(pGraph, 1, 3);

    printf("pGraph: BFS\n");
    traversalBFS(pGraph, 0);

    deleteGraph(pGraph);

    return;
}

#endif

#ifndef _ArrayGraph_
#include "includeLinkedGraph.h"

void ex_PrintGraph(void)
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
}

void ex_DFS(void)
{
    int nNodeCount = 4;
    ArrayGraph *pGraph = createArrayGraph(UNDIRECT_TYPE, nNodeCount);
    int *pVisitNodes = (int *)malloc(sizeof(int) * nNodeCount);

    if (ISNULL_ERROR(pGraph) || ISNULL_ERROR(pVisitNodes))
        return;

    addEdge(pGraph, 0, 1);
    addEdge(pGraph, 0, 2);
    addEdge(pGraph, 1, 3);

    memset(pVisitNodes, 0, sizeof(int) * nNodeCount);

    printf("pGraph's DFS\n");
    traversalDFS(pGraph, 0, pVisitNodes);

    deleteGraph(pGraph);
    free(pVisitNodes);
    return;
}

#endif

int main(int argc, char *argv[])
{
    ex_PrintGraph();
    ex_DFS();
    ex_BFS();

    return 0;
}
/*
> ArrayGraph: UNDIRECT
0 1 1 0 0 0
1 0 1 0 0 0
1 1 0 1 0 0
0 0 1 0 1 1
0 0 0 1 0 1
0 0 0 1 1 0
pGraph's DFS
Node - [0] (visit)
Node - [1] (visit)
Node - [3] (visit)
Node - [2] (visit)
pGraph: BFS
Node - [0] (visit)
Node - [1] (visit)
Node - [2] (visit)
Node - [3] (visit)
*/