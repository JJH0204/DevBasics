#ifndef _GRAPH_
#define _GRAPH_

#define ISNULL_ERROR(ptr) isNull((ptr), __func__)
#define PRINT_DEBUG() printf("Function: %s, Line: %d\n", __func__, __LINE__)

typedef struct DirectArrayGraph
{
    int nNodeCount; // 노드 개수 정보
    int **ppEdge;   // 노드 개수 만큼 2차원 배열 할당할 포인터 변수
} DirectArrayGraph;
bool isNull(const void *ptr, const char *funcName);
DirectArrayGraph *createDirectArrayGraph(const int _nNodeCount_);
bool addEdge(DirectArrayGraph *_pGraph_, int _nFrom_, int _nTo_);
bool checkVertexValid_ERROR(DirectArrayGraph *_pGraph_, int nNode);
bool removeEdge(DirectArrayGraph *_pGraph_, int _nFrom_, int _nTo_);
int getEdge(DirectArrayGraph *_pGraph_, int _nFrom_, int _nTo_);
bool deleteGraph(DirectArrayGraph *_pGraph_);
void displayGraph(DirectArrayGraph *_pGraph_);
#endif