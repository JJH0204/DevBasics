#ifndef _STACK_
#define _STACK_

typedef struct StackNode
{
    char cData;
    struct StackNode *pNext;
} node;

typedef struct LinkedStack
{
    node *pTop;
    int nCurrentCount;
} stack;

// memory initialization
int initStack(stack *_pStack_);
int initNode(node *_pNode_, const char _cData_);
// Stack data structure function
stack *createStack();
int push(stack *_pStack_, const char _cData_);
node *pop(stack *_pStack_);
node *peek(const stack *_pStack_);
int displayStack(const stack *_pStack_);
int deleteStack(stack *_pStack_);

#endif