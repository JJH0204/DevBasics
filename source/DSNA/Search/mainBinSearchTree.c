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

// 부모 노드 찾기
node *getParentNode(node *_pCurrentNode_, int _nKey_);

// 이진 검색 트리 노드 제거
bool deleteData(binSearchTree *_pTree_, int _nKey_);

// 삭제할 노드를 찾으며 그 노드의 부모를 찾음
node *searchWithParentNode(binSearchTree *_pTree_, int _nKey_, node **_ppParentNode_);

// 삭제하는 노드에 자식 노드가 없을 때 해당 노드 삭제
bool deleteNoChildNode(binSearchTree *_pTree_, node *_pParentNode_, node *_pDelNode_);

// 삭제하는 노드에 자식 노드가 1개일 때 해당 노드 삭제
bool delete1ChildNode(binSearchTree *_pTree_, node *_pParentNode_, node *_pDelNode_);

// 삭제하는 노드에 자식 노드가 2개일 때 해당 노드 삭제
bool delete2ChildNode(binSearchTree *_pTree_, node *_pParentNode_, node *_pDelNode_);

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
    node *pParentNode = NULL;
    node *pNewNode = NULL;

    if (_pTree_ == NULL) // 유효성 점검
        return true;

    // 새 노드 생성
    pNewNode = (node *)malloc(sizeof(node));
    if (pNewNode == NULL)
        return true;
    pNewNode->cVal = _cVal_;
    pNewNode->nKey = _nKey_;
    pNewNode->pLeftChild = pNewNode->pRightChild = NULL;

    // 새 노드를 추가할 부모 노드를 찾고 노드 추가
    pParentNode = getParentNode(_pTree_->pROOT, _nKey_);
    if (pParentNode == NULL)
        _pTree_->pROOT = pNewNode;
    else if (pNewNode->nKey < pParentNode->nKey)
        pParentNode->pLeftChild = pNewNode;
    else
        pParentNode->pRightChild = pNewNode;

    // 노드 추가하고 함수 종료
    return false;
}

node *getParentNode(node *_pCurrentNode_, int _nKey_)
{
    node *pParentNode = NULL;

    while (_pCurrentNode_ != NULL)
    {
        if (_nKey_ == _pCurrentNode_->nKey)
        {
            printf("Error, duplicate key-%d, getParentNode()\n", _nKey_);
            return NULL;
        }
        else if (_nKey_ < _pCurrentNode_->nKey)
        {
            pParentNode = _pCurrentNode_;
            _pCurrentNode_ = _pCurrentNode_->pLeftChild;
        }
        else
        {
            pParentNode = _pCurrentNode_;
            _pCurrentNode_ = _pCurrentNode_->pRightChild;
        }
    }
    return pParentNode;
}

bool deleteData(binSearchTree *_pTree_, int _nKey_)
{
    node *pDelNode = NULL, *pParentNode = NULL;

    if (_pTree_ == NULL)
        return true;
    
    pDelNode = searchWithParentNode(_pTree_, _nKey_, &pParentNode);
    if (pDelNode == NULL)
    {
        printf("Error, non-existent key-%d, deleteData()\n", _nKey_);
        return true;
    }
    
    if (pDelNode->pLeftChild == NULL && pDelNode->pRightChild == NULL)      // 자식 노드가 없는 경우
    {
        deleteNoChildNode(_pTree_, pParentNode, pDelNode);
    }
    else if (pDelNode->pLeftChild != NULL && pDelNode->pRightChild != NULL) // 자식 노드가 모두 있는 경우
    {
        delete2ChildNode(_pTree_, pParentNode, pDelNode);
    }
    else                                                                    // 자식 노드가 1개 있는 경우
    {
        delete1ChildNode(_pTree_, pParentNode, pDelNode);
    }

    free(pDelNode);
    return false;
}

node *searchWithParentNode(binSearchTree *_pTree_, int _nKey_, node **_ppParentNode_)
{
    node *pResult = NULL;
    node *pParentNode = NULL;

    if (_pTree_ == NULL)
        return NULL;
    
    pResult = _pTree_->pROOT;

    while (pResult != NULL)
    {
        if (pResult->nKey == _nKey_)
            break;
        pParentNode = pResult;
        if (pResult->nKey > _nKey_)
            pResult = pResult->pLeftChild;
        else
            pResult = pResult->pRightChild;
    }
    if (_ppParentNode_ != NULL)
        *_ppParentNode_ = pParentNode;
    return pResult;
}

bool deleteNoChildNode(binSearchTree *_pTree_, node *_pParentNode_, node *_pDelNode_)
{
    if (_pParentNode_ != NULL)
    {
        if (_pParentNode_->pLeftChild == _pDelNode_)
        {
            _pParentNode_->pLeftChild = NULL;
        }
        else
        {
            _pParentNode_->pRightChild = NULL;
        }
    }
    else
    {
        _pTree_->pROOT = NULL;
    }
    return false;
}

bool delete1ChildNode(binSearchTree *_pTree_, node *_pParentNode_, node *_pDelNode_)
{
    node *pChildNode = NULL;

    if (_pDelNode_->pLeftChild != NULL)
        pChildNode = _pDelNode_->pLeftChild;
    else
        pChildNode = _pDelNode_->pRightChild;
    
    if (_pParentNode_ != NULL)
    {
        if (_pParentNode_->pLeftChild == _pDelNode_)
            _pParentNode_->pLeftChild = pChildNode;
        else
            _pParentNode_->pRightChild = pChildNode;
    }
    else
    {
        _pTree_->pROOT = pChildNode;
    }
    return false;
}

bool delete2ChildNode(binSearchTree *_pTree_, node *_pParentNode_, node *_pDelNode_)
{
    node *pPredecessor = _pDelNode_;
    node *pSuccessor = _pDelNode_->pLeftChild;

    while (pSuccessor->pRightChild != NULL)
    {
        pPredecessor = pSuccessor;
        pSuccessor = pSuccessor->pRightChild;
    }
    
    pPredecessor->pRightChild = pSuccessor->pLeftChild;
    pSuccessor->pLeftChild = _pDelNode_->pLeftChild;
    pSuccessor->pRightChild = _pDelNode_->pRightChild;

    if (_pParentNode_ != NULL)
    {
        if (_pParentNode_->pLeftChild == _pDelNode_)
        {
            _pParentNode_->pLeftChild = pSuccessor;
        }
        else
        {
            _pParentNode_->pRightChild = pSuccessor;
        }
    }
    else
    {
        _pTree_->pROOT = pSuccessor;
    }
    return false;
}

