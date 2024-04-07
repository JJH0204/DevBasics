#ifndef _LINKEDGRAPH_
#define _LINKEDGRAPH_
#include "includeGenericStructure.h"

#define DIRECT_TYPE 0
#define UNDIRECT_TYPE 1

typedef struct LinkedGraph
{
    int nGraphType;
    int nNodeCount;   // 노드 개수 정보
    list **ppAdjEdge; // 간선 정보를 저장할 연결 리스트의 배열 이중 포인터 변수
} LinkedGraph;

LinkedGraph *createLinkedGraph(int _nGraphType_, const int _nNodeCount_);
bool addEdge(LinkedGraph *_pGraph_, int _nFrom_, int _nTo_);
bool checkVertexValid_ERROR(LinkedGraph *_pGraph_, int nNode);
bool removeEdge(LinkedGraph *_pGraph_, int _nFrom_, int _nTo_);
int getEdge(LinkedGraph *_pGraph_, int _nFrom_, int _nTo_);
bool deleteGraph(LinkedGraph *_pGraph_);
void displayGraph(LinkedGraph *_pGraph_);

// TODO: 간선의 가중치 정보를 반환하는 함수 구현
int *getEdge_Weight(LinkedGraph *_pGraph_, int _nFrom_, int _nTo_);
// TODO: 간선에 가중치 추가
bool addEdge_Weight(LinkedGraph *_pGraph_, int _nFrom_, int _nTo_, int _nWeight_);
#endif