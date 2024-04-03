#ifndef __GENERIC_STRUCTURE__

#define __GENERIC_STRUCTURE__
#define ISNULL_ERROR(ptr) isNull((ptr), __func__)
#define ISEMPTY_STACK(ptr) isEmptyStack((ptr), __func__)
#define ISEMPTY_QUEUE(ptr) isEmptyQueue((ptr), __func__)
#define ISEMPTY_List(ptr) isEmptyList((ptr), __func__)
#define PRINT_DEBUG() printf("Function: %s, Line: %d\n", __func__, __LINE__)

typedef struct NODE
{
    void *nodeData;
    struct NODE *pNextNode;
} node;

typedef struct STACK
{
    node *pTopNode;
    int nCurrentCount;
} stack;

typedef struct QUEUE
{
    node *pFront;
    node *pRear;
    int nCurrentCount;
} queue;

typedef struct INTEGERNODE
{
    int nData;
    struct INTEGERNODE *pNextNode;
} int_node;

typedef struct LinkedList
{
    int_node *pHead;
    int nCurrentCount;
} list;

bool isNull(const void *ptr, const char *funcName);
bool isEmptyStack(const stack *ptr, const char *funcName);
bool isEmptyQueue(const queue *ptr, const char *funcName);

// Func of Stack
stack *stack_Create(void);
bool stack_Push(stack *_pStack_, void *_data_);
void *stack_Pop(stack *_pStack_);
void *stack_Peek(const stack *_pStack_);
bool stack_Delete(stack *_pStack_);

// Func of Queue
queue *queue_Create(void);
bool queue_enqueue(queue *_pQueue_, void *_data_);
void *queue_dequeue(queue *_pQueue_);
bool queue_Delete(queue *_pQueue_);

// Func of Linked List
list *list_Create(void);
bool list_Add(list *_pList_, int _data_);
int list_Get(list *_pList_, const int _nIndex_);
bool list_Remove(list *_pList_, const int _nIndex_);
bool list_Delete(list *_pList_);
#endif