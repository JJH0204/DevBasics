#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG() printf("func: %s, line: %d\n", __func__, __LINE__)
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
node *searchTargetNodeWithParentNode(binSearchTree *_pTree_, int _nKey_, node **_ppParentNode_);

// 삭제하는 노드에 자식 노드가 없을 때 해당 노드 삭제
bool deleteNoChildNode(binSearchTree *_pTree_, node *_pParentNode_, node *_pDelNode_);

// 삭제하는 노드에 자식 노드가 1개일 때 해당 노드 삭제
bool delete1ChildNode(binSearchTree *_pTree_, node *_pParentNode_, node *_pDelNode_);

// 삭제하는 노드에 자식 노드가 2개일 때 해당 노드 삭제
bool delete2ChildNode(binSearchTree *_pTree_, node *_pParentNode_, node *_pDelNode_);

// 이진 탐색 트리 출력 함수
bool displayBinSearchTree(node *_pNode_, int _nLevel_, char _cType_);

// 이진 탐색 트리 할당 해제
bool deleteBinSearchTree(binSearchTree *pTree);

// 이진 탐색 트리 내부 노드 할당 해제(재귀함수)
bool deleteBinSearchTreeNode(node *pNode);

// 메인함수
int main(int argc, char *argv[])
{
    binSearchTree *pTree = NULL;
    node *pSearchNode = NULL;

    int nKey = 0;
    pTree = createBinSearchTree(); // 메모리를 할당한 후에는 꼭 저장하는 값을 초기화 해주자... 이거 때문에 insertData()가 제대로 작동하지 않음...
    if (pTree == NULL)
        return -1;
    
    insertData(pTree, 70, 'A');
    insertData(pTree, 40, 'B');
    insertData(pTree, 90, 'C');
    insertData(pTree, 20, 'D');
    insertData(pTree, 60, 'E');
    insertData(pTree, 80, 'F');
    insertData(pTree, 100, 'G');
    insertData(pTree, 10, 'H');
    insertData(pTree, 30, 'I');
    insertData(pTree, 50, 'J');
    displayBinSearchTree(pTree->pROOT, 0, '-');

    nKey = 30;
    pSearchNode = search(pTree, nKey);
    if (pSearchNode != NULL)
        printf("Search: Key-[%d], Data-[%c]\n", nKey, pSearchNode->cVal);
    else
        printf("Search: Key-[%d], Fail\n", nKey);

    nKey = 70;
    printf("Data delete: Key-[%d]\n", nKey);
    deleteData(pTree, nKey);
    displayBinSearchTree(pTree->pROOT, 0, '-');

    nKey = 35;
    pSearchNode = search(pTree, nKey);
    if (pSearchNode != NULL)
        printf("Search: Key-[%d], Data-[%c]\n", nKey, pSearchNode->cVal);
    else
        printf("Search: Key-[%d], Fail\n", nKey);

    deleteBinSearchTree(pTree);

    return 0;
}

binSearchTree *createBinSearchTree()
{
    binSearchTree *pResult = (binSearchTree *)malloc(sizeof(binSearchTree));
    if (pResult == NULL)
        return NULL;
    pResult->pROOT = NULL;
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
    pNewNode->pLeftChild = NULL;
    pNewNode->pRightChild = NULL;

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

    pDelNode = searchTargetNodeWithParentNode(_pTree_, _nKey_, &pParentNode);   // nKey 값을 이용해 pTree에서 삭제할 노드와 삭제할 노드의 부모 노드를 찾는다.
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

node *searchTargetNodeWithParentNode(binSearchTree *_pTree_, int _nKey_, node **_ppParentNode_)
{
    node *pResult = NULL;
    node *pParentNode = NULL;

    if (_pTree_ == NULL)                    // 유효성 점검
        return NULL;
    
    pResult = _pTree_->pROOT;               // 탐색 시작 노드를 루트로 지정

    while (pResult != NULL)                 // 탐색 노드가 NULL일 때까지 반복
    {
        if (pResult->nKey == _nKey_)        // 탐색 노드의 key가 찾는 key 값이라면 -> 반복 종료
            break;
        pParentNode = pResult;              // 탐색 노드의 key가 찾는 key 값이아니라면 -> 탐색 노드를 부모 노드로 설정
        if (pResult->nKey > _nKey_)         // 크거나 작은지 비교 연산으로 구분
            pResult = pResult->pLeftChild;  // 찾는 키 값이 부모 노드의 키 값 보다 작으면 좌측 서브트리로
        else
            pResult = pResult->pRightChild; // 찾는 키 값이 부모 노드의 키 값 보다 크면 우측 서브트리로
    }
    if (_ppParentNode_ != NULL)             // 반복이 종료되고 삭제할 노드의 부모 노드를 이중 포인터로 저장해 반환(인자 값으로 부모 노드를 저장하지 않아도, NULL로 해도 코드는 정상 작동)
        *_ppParentNode_ = pParentNode;
    return pResult;                         // 삭제할 노드 반환
}

// 삭제할 노드와 그 노드의 부모 노드를 인자로 한다.
bool deleteNoChildNode(binSearchTree *_pTree_, node *_pParentNode_, node *_pDelNode_)
{
    // 자식이 없는 노드를 삭제할 때 
    if (_pParentNode_ != NULL)                          // 부모 노드가 비어있지 않다.
    {
        if (_pParentNode_->pLeftChild == _pDelNode_)    // 부모 노드의 왼쪽 노드가 삭제할 노드라면
            _pParentNode_->pLeftChild = NULL;           // 부모 노드가 가리키는 왼쪽 노드를 NULL로 변경한다.
        else
            _pParentNode_->pRightChild = NULL;          // 부모 노드가 가리키는 오른쪽 노드를 NULL로 변경한다.
    }
    else
    {
        _pTree_->pROOT = NULL;                          // 인자로 전달 받은 부모 노드가 없으면 루트 노드를 NULL로 바꾼다.
    }
    return false;
}

bool delete1ChildNode(binSearchTree *_pTree_, node *_pParentNode_, node *_pDelNode_)
{
    node *pChildNode = NULL;

    if (_pDelNode_->pLeftChild != NULL)         // 삭제할 노드의 왼쪽에 노드가 있다면
        pChildNode = _pDelNode_->pLeftChild;    // 자식 노드를 가리킬 포인터를 삭제할 노드의 왼쪽에 노드로 저장
    else
        pChildNode = _pDelNode_->pRightChild;   // 자식 노드를 가리킬 포인터를 삭제할 노드의 오른쪽에 노드로 저장

    if (_pParentNode_ != NULL)                          // 노드 삭제 후 삭제한 노드의 자식 노드를 빈 자리에 저장
    {
        if (_pParentNode_->pLeftChild == _pDelNode_)
            _pParentNode_->pLeftChild = pChildNode;
        else
            _pParentNode_->pRightChild = pChildNode;
    }
    else
    {
        _pTree_->pROOT = pChildNode;                    // 부모 노드를 인자로 받지 않았으면, 루트를 자식 노드로 변경
    }
    return false;
}

bool delete2ChildNode(binSearchTree *_pTree_, node *_pParentNode_, node *_pDelNode_)
{
    // 삭제할 노드에 자식 노드가 2다 있는 경우(가장 복잡)
    node *pPredecessor = _pDelNode_;            // 삭제할 노드를 전임자 노드로 지정
    node *pSuccessor = _pDelNode_->pLeftChild;  // 삭제할 노드의 좌측 자식 노드를 후임 노드로 지정

    while (pSuccessor->pRightChild != NULL)     // 후임 노드의 우측 노드가 있다면 (전임자 노드 보다 key 값이 큰 노드가 있으면) 반복
    {
        pPredecessor = pSuccessor;              // 전임자 노드를 후임 노드로 변경
        pSuccessor = pSuccessor->pRightChild;   // 후임 노드의 키 값 보다 큰 우측 자식 노드를 후임 노드로 지정
    }
    
    pPredecessor->pRightChild = pSuccessor->pLeftChild;     
    pSuccessor->pLeftChild = _pDelNode_->pLeftChild;
    pSuccessor->pRightChild = _pDelNode_->pRightChild;

    if (_pParentNode_ != NULL)
    {
        if (_pParentNode_->pLeftChild == _pDelNode_)
            _pParentNode_->pLeftChild = pSuccessor;
        else
            _pParentNode_->pRightChild = pSuccessor;
    }
    else
    {
        _pTree_->pROOT = pSuccessor;
    }
    return false;
}

// 이진 탐색 트리 출력 함수
bool displayBinSearchTree(node *_pNode_, int _nLevel_, char _cType_)
{
    int nLoopCount = 0;

    if (_pNode_ == NULL)
        return true;

    for (; nLoopCount < _nLevel_; nLoopCount++)
    {
        printf("   ");
    }
    printf("-(%c)-key: %i, value-%c\n", _cType_, _pNode_->nKey, _pNode_->cVal);

    displayBinSearchTree(_pNode_->pLeftChild, _nLevel_ + 1, 'L');
    displayBinSearchTree(_pNode_->pRightChild, _nLevel_ + 1, 'R');

    return false;
}

// 이진 탐색 트리 할당 해제
bool deleteBinSearchTree(binSearchTree *pTree)
{
    if (pTree != NULL)
    {
        deleteBinSearchTreeNode(pTree->pROOT);
        free(pTree);
        return false;
    }
    return true;
}

// 이진 탐색 트리 내부 노드 할당 해제(재귀함수)
bool deleteBinSearchTreeNode(node *pNode)
{
    if (pNode != NULL)
    {
        deleteBinSearchTreeNode(pNode->pLeftChild);
        deleteBinSearchTreeNode(pNode->pRightChild);
        free(pNode);
        return false;
    }
    return true;
}