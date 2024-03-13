// polynomial.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definition data structure
typedef struct Term         // 'term' structure
{
    double coefficient;     // Coefficient
    int degree;             // degree
} term;

typedef struct Node         // node structure
{
    term tData;             // term structure data
    struct Node *pNext;
} node;

typedef struct LinkedList   // polynomial structure
{
    int nCurrentCount;
    node headerNode;
} list, polyList;

// Basic function of linked list
polyList *createList();
int addData(polyList *_pList_, const term _tData_, const int _nPos_);
int removeData(polyList *_pList_, const int _nPos_);
term getData(polyList *_pList_, const int _nPos_);
int deleteList(polyList *_pList_);
int getListLength(const polyList *_pList_);
int initList(polyList *_pList_);
int initNode(node *_pNode_);

// Function for polynomial calculation
int addPolyNode_L(polyList *_pList_, const double coef, const int degree);
polyList *polyAdd(const polyList *_pListA_, const polyList *_pListB_);
int displayPoly(const polyList *_pList_);
polyList *polySub(const polyList *_pListA_, const polyList *_pListB_);
int polySort(polyList *_pList_);

// main function
int main(int argc, char *argv[])
{
    polyList *pListA = createList();
    polyList *pListB = createList();
    polyList *pListC = createList();

    if ((pListA == NULL) && (pListB == NULL) && (pListC == NULL))
    {
        printf("Memory allocation error.: main()");
        return -1;
    }

    addPolyNode_L(pListA, 5, 2);
    addPolyNode_L(pListA, 7, 6);
    addPolyNode_L(pListA, 3, 5);
    

    addPolyNode_L(pListB, 1, 5);
    addPolyNode_L(pListB, 2, 4);
    addPolyNode_L(pListB, 3, 2);
    addPolyNode_L(pListB, 4, 0);

    printf("Polynomial-A: \n");
    displayPoly(pListA);
    polySort(pListA);
    printf("After sorting of Polynomial-A: \n");
    displayPoly(pListA);
    printf("Polynomial-B: \n");
    displayPoly(pListB);

    pListC = polyAdd(pListA, pListB);

    if (pListC == NULL)
    {
        printf("Function result return error: main()->call 'polyAdd()'");
        return -2;
    }

    printf("Polynomial addition result: \n");
    displayPoly(pListC);

    pListC = polySub(pListA, pListB);

    if (pListC == NULL)
    {
        printf("Function result return error: main()->call 'polyAdd()'");
        return -2;
    }

    printf("Polynomial subtraction result: \n");
    displayPoly(pListC);

    deleteList(pListA);
    deleteList(pListB);
    deleteList(pListC);

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

int addData(polyList *_pList_, const term _tData_, const int _nPos_)
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

int removeData(polyList *_pList_, const int _nPos_)
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

term getData(polyList *_pList_, const int _nPos_)
{
    // variable declaration
    term tResult = {0,};
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

int getListLength(const polyList *_pList_)
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

int displayPoly(const polyList *_pList_)
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
    pNode = _pList_->headerNode.pNext;      // code=3221225477 Error cause: Trying to reference memory with a null pointer
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

polyList *polyAdd(const polyList *_pListA_, const polyList *_pListB_)
{
    polyList *pResult = NULL;
    node *pNodeA = NULL, *pNodeB = NULL;

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
    if (pResult == NULL)
    {
        printf("memory allocation error: polyAdd()\n");
        return NULL;
    }
    initList(pResult);

    pNodeA = _pListA_->headerNode.pNext;
    pNodeB = _pListB_->headerNode.pNext;

    while ((pNodeA != NULL) && (pNodeB != NULL))
    // Tip: If either of them points to NULL, must terminate the while(). So we use AND(&&).
    {
        // case_1: The degree of term A is higher than the degree of term B
        if (pNodeA->tData.degree > pNodeB->tData.degree)
        {
            addPolyNode_L(pResult, pNodeA->tData.coefficient, pNodeA->tData.degree);
            pNodeA = pNodeA->pNext;
        }
        // case_2: The degree of term B is higher than the degree of term A
        else if (pNodeA->tData.degree < pNodeB->tData.degree)
        {
            addPolyNode_L(pResult, pNodeB->tData.coefficient, pNodeB->tData.degree);
            pNodeB = pNodeB->pNext;
        }
        // case_3: Two terms have the same degree
        else
        {
            addPolyNode_L(pResult, pNodeA->tData.coefficient + pNodeB->tData.coefficient, pNodeB->tData.degree);
            pNodeA = pNodeA->pNext;
            pNodeB = pNodeB->pNext;
        }
    }
    // case_4: There are terms remaining after addition, so post-processing is required.
    while (pNodeA != NULL)
    {
        addPolyNode_L(pResult, pNodeA->tData.coefficient, pNodeA->tData.degree);
        pNodeA = pNodeA->pNext;
    }
    
    while (pNodeB != NULL)
    {
        addPolyNode_L(pResult, pNodeB->tData.coefficient, pNodeB->tData.degree);
        pNodeB = pNodeB->pNext;
    }

    return pResult;
}

// TODO: Implementation of new function
polyList *polySub(const polyList *_pListA_, const polyList *_pListB_)
{
    // Implementation of subtraction of two polynomials
    return NULL;
}

int polySort(polyList *_pList_)
{
    // Supports sorting in descending order based on degree
    node *pPast = NULL;
    node *pCurrent = NULL;
    node *pFuture = NULL;

    if (_pList_ == NULL)
    {
        printf("Unallocated memory reference error: polySort()");
        return -1;
    }
    
    pPast = &(_pList_->headerNode);

    while (pPast->pNext->pNext != NULL)
    {
        pCurrent = pPast->pNext;
        pFuture = pCurrent->pNext;
        
        if (pCurrent->tData.degree < pFuture->tData.degree)
        {
            pPast->pNext = pFuture;
            pCurrent->pNext = pFuture->pNext;
            pFuture->pNext = pCurrent;
            
            pPast = &(_pList_->headerNode);
        }
        else
        {
            pPast = pPast->pNext;
        }
    }

    return 0;
}