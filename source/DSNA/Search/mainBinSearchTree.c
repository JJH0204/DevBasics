#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 이진 트리 노드
typedef struct NODE
{
    int nKey;
    char cVal;

    struct NODE *pLeftChild;
    struct NODE *pRightChild;
} node;

// 이진 트리
typedef struct BINSEARCTREE
{
    node *pROOT;
} binSearchTree;

// 이진 검색 트리 생성
binSearchTree *createBinSearchTree();

// 이진 검색 트리 검색
node *search(binSearchTree *_pTree_, int _nKey_);

// 이진 검색 트리 노드 추가
bool insertData(binSearchTree *_pTree_, int _nKey_, char _cVal_);

// 메인함수
int main(int argc, char *argv[])
{

    return 0;
}

binSearchTree *createBinSearchTree()
{
    binSearchTree *pResult = (binSearchTree *)malloc(sizeof(binSearchTree));
    if (pResult == NULL)
        return NULL;
    return pResult;
}

node *search(binSearchTree *_pTree_, int _nKey_)
{
    node *pResult = NULL;
    if (_pTree_ == NULL) // 유효성 점검
        return NULL;

    pResult = _pTree_->pROOT;
    while (pResult != NULL) // 트리의 끝까지 이동하며 찾기
    {
        if (pResult->nKey == _nKey_) // 찾는 키 값이면 반복 종료
            break;
        else if (pResult->nKey > _nKey_) // 찾는 키 값 보다 크면 좌측 서브 트리로
            pResult = pResult->pLeftChild;
        else // 찾는 키 값 보다 작면 우측 서브 트리로
            pResult = pResult->pRightChild;
    }
    return pResult;
}

bool insertData(binSearchTree *_pTree_, int _nKey_, char _cVal_)
{

}
