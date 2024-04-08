#ifndef _GRAPH_
#define _GRAPH_
#include "includeGenericStructure.h"

// #define ISNULL_ERROR(ptr) isNull((ptr), __func__)
#define PRINT_DEBUG() printf("Function: %s, Line: %d\n", __func__, __LINE__)

#define DIRECT_TYPE     0
#define UNDIRECT_TYPE   1

typedef struct ArrayGraph
{
    int nGraphType; // 그래프 종류: 방향 / 무방향
    int nNodeCount; // 노드 개수 정보
    int **ppEdge;   // 노드 개수 만큼 2차원 배열 할당할 포인터 변수
} ArrayGraph;
// bool isNull(const void *ptr, const char *funcName);
ArrayGraph *createArrayGraph(const int _nGraphType_, const int _nNodeCount_);
bool addEdge(ArrayGraph *_pGraph_, int _nFrom_, int _nTo_);
bool addEdgeInternal(ArrayGraph *_pGraph_, int _nFrom_, int _nTo_);
bool checkVertexValid_ERROR(ArrayGraph *_pGraph_, int nNode);
bool removeEdge(ArrayGraph *_pGraph_, int _nFrom_, int _nTo_);
bool removeEdgeInternal(ArrayGraph *_pGraph_, int _nFrom_, int _nTo_);
int getEdge(ArrayGraph *_pGraph_, int _nFrom_, int _nTo_);
bool deleteGraph(ArrayGraph *_pGraph_);
void displayGraph(ArrayGraph *_pGraph_);

bool traversalDFS(ArrayGraph *_pGraph_, int _nStartNode_, int *_pVisitNodes_);
bool traversalBFS(ArrayGraph *_pGraph_, int _nStartNode_);
bool traversalDFS_Loop(ArrayGraph *_pGraph_, int _nStartNode_);

#endif