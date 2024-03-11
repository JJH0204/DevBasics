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
int getData(polyList *_pList_, int _nPos_);
int deleteList(polyList *_pList_);
int getListLength(polyList *_pList_);
int initList(polyList *_pList_);
int initNode(node *_pNode_);

// Function for polynomial calculation

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
    
    // memset(pNewList, 0, sizeof(polyList));
    initList(pNewList);
    return pNewList;
}

/* TODO: Function implementation */
int addData(polyList *_pList_, term _tData_, int _nPos_)
{
    // variable declaration
    int nCount = 0;
    node *newNode = NULL;

    // check validity
    if (_pList_ == NULL)
    {
        printf("Unallocated memory access error: addData(), _pList_\n");
        return -1;
    }
    if ((_nPos_ < 0) || (_nPos_>_pList_->nCurrentCount))
    {
        printf("Index access error: addData()\n");
        return -2;
    }
    
    // data addition process
    newNode = (node*)malloc(sizeof(node));
    initNode(newNode);
    newNode->tData = _tData_;
    /* code */

    // end function
    return 0;
}
int removeData(polyList *_pList_, int _nPos_);
int getData(polyList *_pList_, int _nPos_);
int deleteList(polyList *_pList_);
int getListLength(polyList *_pList_);

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