// polynomial.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definition data structure
typedef struct Term         // '항' 구조체
{
    double coefficient;     // 계수
    int degree;             // 차수
} term;

typedef struct Node         // 노드 구조체
{
    term tData;             // 항 구조체 데이터
    struct Node *pNext;
} node;

typedef struct LinkedList   // 다항식 구조체
{
    int nCurrentCount;
    node headerNode;
} list, polyList;

// Basic function of linked list
polyList *createList();
int addData(polyList *_pList_, term _tData_, int _nPos_);
int removeData(polyList *_pList_, int _nPos_);
term getData(polyList *_pList_, int _nPos_);
int deleteList(polyList *_pList_);
int getListLength(polyList *_pList_);
int initList(polyList *_pList_);
int initNode(node *_pNode_);

// Function for polynomial calculation
int addPolyNode_L(polyList *_pList_, const double coef, const int degree);
polyList *polyAdd(polyList *_pListA_, polyList *_pListB_);
int displayPoly(polyList *_pList_);

// main function
int main(int argc, char *argv[])
{

    return 0;
}

// function definition
polyList *createList()
{
    polyList *pNewList = (polyList*)malloc(sizeof(polyList));

    if (pNewList == NULL)
        return NULL;
    initList(pNewList);
    return pNewList;
}

int addData(polyList *_pList_, term _tData_, int _nPos_)
{
    // variable declaration
    int nCount = 0;
    node *pNewNode = NULL;
    node *pCurrentNode = NULL;

    // check validity
    if (_pList_ == NULL)
    {
        printf("Unallocated memory access error: addData()\n");
        return -1;
    }
    if ((_nPos_ < 0) || (_nPos_>_pList_->nCurrentCount))
    {
        printf("Index access error: addData()\n");
        return -2;
    }
    
    // data addition process
    pNewNode = (node *)malloc(sizeof(node));
    if (pNewNode == NULL)
    {
        printf("Memory allocation error: addData()\n");
        return -3;
    }
    initNode(pNewNode);
    pNewNode->tData = _tData_;

    pCurrentNode = &(_pList_->headerNode);
    for ( ; nCount < _nPos_; nCount++)
        pCurrentNode = pCurrentNode->pNext;
    pNewNode->pNext = pCurrentNode->pNext;
    pCurrentNode->pNext = pNewNode;

    _pList_->nCurrentCount++;

    // end function
    return 0;
}

int removeData(polyList *_pList_, int _nPos_)
{
    // variable declaration
    int nCount = 0;
    node *pDeleteNode = NULL;
    node *pCurrentNode = NULL;

    // check validity
    if (_pList_ == NULL)
    {
        printf("Unallocated memory access error: removeData()\n");
        return -1;
    }
    if ((_nPos_ < 0) || (_nPos_ > _pList_->nCurrentCount))
    {
        printf("Index access error: removeData()\n");
        return -2;
    }

    // data addition process
    pCurrentNode = &(_pList_->headerNode);
    for ( ; nCount < _nPos_; nCount++)
        pCurrentNode = pCurrentNode->pNext;
    pDeleteNode = pCurrentNode->pNext;
    pCurrentNode->pNext = pDeleteNode->pNext;
    free(pDeleteNode);
    _pList_->nCurrentCount--;

    // end function
    return 0;
}

term getData(polyList *_pList_, int _nPos_)
{
    // variable declaration
    term tResult = {0};
    int nCount = 0;
    node *pCurrentNode = NULL;

    // check validity
    if (_pList_ == NULL)
    {
        printf("Unallocated memory access error: getData()\n");
        return tResult;
    }
    if ((_nPos_ < 0) || (_nPos_ > _pList_->nCurrentCount))
    {
        printf("Index access error: getData()\n");
        return tResult;
    }

    // data addition process
    pCurrentNode = &(_pList_->headerNode);
    for ( ; nCount <= _nPos_; nCount++)
        pCurrentNode = pCurrentNode->pNext;
    tResult = pCurrentNode->tData;
    
    //return result
    return tResult;
}

int deleteList(polyList *_pList_)
{
    if (_pList_ == NULL)
    {
        printf("Unallocated memory access error: deleteList()\n");
        return -1;
    }

    while (_pList_->headerNode.pNext != NULL)
        removeData(_pList_, 0);
    free(_pList_);

    return 0;
}

int getListLength(polyList *_pList_)
{
    if (_pList_ == NULL)
    {
        printf("Unallocated memory access error: getListLength()\n");
        return -1;
    }

    return _pList_->nCurrentCount;
}

int initList(polyList *_pList_)
{
    if (_pList_ == NULL)
    {
        printf("Error attempting to initialize unallocated memory: initList()\n");
        return -1;
    }
    _pList_->nCurrentCount = 0;
    initNode(&(_pList_->headerNode));
    return 0;
}

int initNode(node *_pNode_)
{
    if (_pNode_ == NULL)
    {
        printf("Error attempting to initialize unallocated memory: initNode()\n");
        return -1;
    }
    _pNode_->pNext = NULL;
    _pNode_->tData.coefficient = 0;
    _pNode_->tData.degree = 0;
    return 0;
}

// polynomial function
int addPolyNode_L(polyList *_pList_, const double coef, const int degree)
{
    int ret = 0, position = 0;
    term tData = {0,};
    
    if (_pList_ == NULL)
    {
        printf("Error attempting to initialize unallocated memory: addPolyNode_L()\n");
        return -1;
    }

    tData.coefficient = coef;
    tData.degree = degree;

    position = _pList_->nCurrentCount;
    ret = addData(_pList_, tData, position);

    return ret;
}

int displayPoly(polyList *_pList_)
{
    int nCount = 0;
    node *pNode = NULL;
    if (_pList_ == NULL)
    {
        printf("Error attempting to initialize unallocated memory: displayPoly()\n");
        return -1;
    }
    if (_pList_->nCurrentCount <= 0)
    {
        printf("There is no data.\n");
        return -2;
    }
    for ( ; nCount < _pList_->nCurrentCount; nCount++)
    {
        if (nCount > 0)
            printf(" + ");
        
        printf("%.1fx^%d", pNode->tData.coefficient, pNode->tData.degree);
        pNode = pNode->pNext;
    }
    printf("\n");
    
    return 0;
}

polyList *polyAdd(polyList *_pListA_, polyList *_pListB_)
{
    polyList *pResult = NULL;
    // node *pNodeA = NULL;
    // node *pNodeB = NULL;
    // term tData = {0,};

    if ((_pListA_ == NULL) || (_pListB_ == NULL))
    {
        printf("Error attempting to initialize unallocated memory: polyAdd()\n");
        return NULL;
    }
    if ((_pListA_->headerNode.pNext == NULL) || (_pListB_->headerNode.pNext == NULL))
    {
        printf("The other formula for polynomial addition is empty.: polyAdd()\n");
        return NULL;
    }
    
    pResult = createList();
    // 두 리스트의 첫 노드를 검사헤 두 리스트 중 한 리스트라도 데이터가 남아 있는 경우 반복 실행
    while ((_pListA_->headerNode.pNext != NULL) || (_pListB_->headerNode.pNext != NULL))
    {
        // _pListA_ 만 리스트에 데이터가 있는 경우
        if ((_pListA_->headerNode.pNext != NULL) && (_pListB_->headerNode.pNext == NULL))
        {
            addPolyNode_L(pResult, _pListA_->headerNode.pNext->tData.coefficient, _pListA_->headerNode.pNext->tData.degree);
            removeData(_pListA_, 0);
        }
        // _pListB_ 만 리스트에 데이터가 있는 경우
        else if ((_pListA_->headerNode.pNext == NULL) && (_pListB_->headerNode.pNext != NULL))
        {
            addPolyNode_L(pResult, _pListB_->headerNode.pNext->tData.coefficient, _pListB_->headerNode.pNext->tData.degree);
            removeData(_pListB_, 0);
        }
        // 둘다 데이터가 있는 경우
        else
        {
            // 두 리스트가 가리키는 첫 노드의 차수가 같다면
            if (_pListA_->headerNode.pNext->tData.degree == _pListB_->headerNode.pNext->tData.degree)
            {
                addPolyNode_L(pResult, _pListA_->headerNode.pNext->tData.coefficient + _pListB_->headerNode.pNext->tData.coefficient, _pListA_->headerNode.pNext->tData.degree);
                removeData(_pListA_, 0);
                removeData(_pListB_, 0);
            }
            // _pListA_의 헤더 노드가 가리키는 첫번째 노드의 차수가 더 높은 경우
            else if (_pListA_->headerNode.pNext->tData.degree > _pListB_->headerNode.pNext->tData.degree)
            {
                addPolyNode_L(pResult, _pListA_->headerNode.pNext->tData.coefficient, _pListA_->headerNode.pNext->tData.degree);
                removeData(_pListA_, 0);
            }
            // _pListB_의 헤더 노드가 가리키는 첫번째 노드의 차수가 더 높은 경우
            else
            {
                addPolyNode_L(pResult, _pListB_->headerNode.pNext->tData.coefficient, _pListB_->headerNode.pNext->tData.degree);
                removeData(_pListB_, 0);
            }
        }
    }

    return pResult;
}