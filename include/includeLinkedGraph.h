#ifndef _LINKEDGRAPH_
#define _LINKEDGRAPH_
#include "includeGenericStructure.h"

typedef struct DirectLinkedGraph
{
    int nNodeCount;   // 노드 개수 정보
    list **ppAdjEdge; // 간선 정보를 저장할 연결 리스트의 배열 이중 포인터 변수
} DirectLinkedGraph;

DirectLinkedGraph *createDirectLinkedGraph(const int _nNodeCount_);
bool addEdge(DirectLinkedGraph *_pGraph_, int _nFrom_, int _nTo_);
bool checkVertexValid_ERROR(DirectLinkedGraph *_pGraph_, int nNode);
bool removeEdge(DirectLinkedGraph *_pGraph_, int _nFrom_, int _nTo_);
int getEdge(DirectLinkedGraph *_pGraph_, int _nFrom_, int _nTo_);
bool deleteGraph(DirectLinkedGraph *_pGraph_);
void displayGraph(DirectLinkedGraph *_pGraph_);
#endif