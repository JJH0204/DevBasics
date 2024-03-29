#ifndef __GENERIC_STACK__

#define __GENERIC_STACK__
#define ISNULL_ERROR(ptr) isNull((ptr), __func__)
#define ISEMPTY_ERROR(ptr) isEmpty((ptr), __func__)

typedef struct STACKNODE
{
    void *nodeData;
    struct STACKNODE *pNextNode;
} stackNode;

typedef struct STACK
{
    stackNode *pTopNode;
    int nCurrentCount;
} stack;

bool isNull(const void *ptr, const char *funcName);
bool isEmpty(const stack *ptr, const char *funcName);

stack *createStack(void);

bool push(stack *_pStack_, void *_data_);

void *pop(stack *_pStack_);

void *peek(const stack *_pStack_);

bool deleteStack(stack *_pStack_);

#endif