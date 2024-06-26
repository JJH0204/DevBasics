#ifndef __GENERIC_STRUCTURE__

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/* <정수와 포인터 크기 불일치 경고 우려>
- 32bit 운영체제에서 void * 와 int는 동일한 메모리 사이즈를 갖는다. (4byte)
- 64bit 운영체제에서 void * 는 8 byte, int는 동일한 4 byte를 갖는다.
- 이는 운영체제에 따라 참조하는 메모리 사이즈가 달라질 수 있다는 이야기 임으로 위험한 메모리 접근 방식이라 간주되어 컴파일러에서 막는다.
- 포인터타입을 사용해 이를 보완할 수 있다. (stdint.h를 포함한 이유)
- 사용 예시
intptr_t nodeIndex = (intptr_t)pQueueNode->nodeData;
queue_enqueue(pQueue, (void *)(intptr_t)nLoopCount);
*/

#define __GENERIC_STRUCTURE__
#define __LINEDLIST_
#define __STACK__
#define __QUEUE__

#define ISNULL_ERROR(ptr) isNull((ptr), __func__)
#define PRINT_DEBUG() printf("Function: %s, Line: %d\n", __func__, __LINE__)

typedef struct NODE
{
    void *nodeData;
    struct NODE *pNextNode;
} node;

bool isNull(const void *ptr, const char *funcName);

#ifdef __LINEDLIST_
#define ISEMPTY_List(ptr) isEmptyList((ptr), __func__)

typedef struct LinkedList
{
    node *pHead;
    int nCurrentCount;
} list;

// Func of Linked List
list *list_Create(void);
bool list_Add(list *_pList_, void *_data_);
void *list_Get(list *_pList_, const int _nIndex_);
bool list_Remove(list *_pList_, const int _nIndex_);
bool list_Delete(list *_pList_);

#endif

#ifdef __STACK__
#define ISEMPTY_STACK(ptr) isEmptyStack((ptr), __func__)

typedef struct STACK
{
    node *pTopNode;
    int nCurrentCount;
} stack;

// Func of Stack
stack *stack_Create(void);
bool stack_Push(stack *_pStack_, void *_data_);
void *stack_Pop(stack *_pStack_);
void *stack_Peek(const stack *_pStack_);
bool stack_Delete(stack *_pStack_);
bool isEmptyStack(const stack *ptr, const char *funcName);

#endif

#ifdef __QUEUE__
#define ISEMPTY_QUEUE(ptr) isEmptyQueue((ptr), __func__)

typedef struct QUEUE
{
    node *pFront;
    node *pRear;
    int nCurrentCount;
} queue;

// Func of Queue
queue *queue_Create(void);
bool queue_enqueue(queue *_pQueue_, void *_data_);
void *queue_dequeue(queue *_pQueue_);
bool queue_Delete(queue *_pQueue_);
bool isEmptyQueue(const queue *ptr, const char *funcName);

#endif

#endif