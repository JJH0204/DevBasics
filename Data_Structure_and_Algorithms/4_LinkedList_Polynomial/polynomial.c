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

polyList *createList();
int addData(polyList *_pList_, term _tData, int _nPos_);
int removeData(polyList *_pList_, int _nPos_);
int getData(polyList *_pList_, int _nPos_);
int deleteList(polyList *_pList_);
int getListLength(polyList *_pList_);


int main (int argc, char* argv[])
{

    return 0;
}

polyList *createList()
{
    polyList *pNewList = (polyList*)malloc(sizeof(polyList));

    if (pNewList == NULL)
        return NULL;
    
    memset(pNewList, 0, sizeof(polyList));
    return pNewList;
}

// TODO: Function implementation
int addData(polyList *_pList_, term _tData, int _nPos_)
{
    // variable declaration
    int nCount = 0;

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
    /* code */

    // end function
    return 0;
}
int removeData(polyList *_pList_, int _nPos_);
int getData(polyList *_pList_, int _nPos_);
int deleteList(polyList *_pList_);
int getListLength(polyList *_pList_);