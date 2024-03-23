#ifndef __NOTATIONSTACK__
#define __NOTATIONSTACK__

typedef enum OperatorType
{
    LPAREN,     // 여는 괄호
    RPAREN,     // 닫는 괄호
    MULTIPLY,   // 곱하기
    DIVIDE,     // 나누기
    PLUS,       // 더하기
    MINUS,      // 빼기
    OPERAND     // 피연산자
} TYPE;

typedef struct TOKEN
{
    TYPE operType;
    double dValue;
} TOKEN;

typedef struct NODE
{
    TOKEN tData;
    struct NODE *pNext;
} NODE;

typedef struct STACK
{
    NODE *pTOP;
    int nCurrentCount;
} STACK;

#define ISNULL(ptr) isNull((ptr), __func__)
#define ISEMPTY(ptr) isEmpty((ptr), __func__)

bool isNull(const void *ptr, const char *funcName);

bool isEmpty(const STACK *ptr, const char *funcName);

STACK *createStack(void);

bool push(STACK *_pStack_, const TOKEN _tData_);

NODE *pop(STACK *_pStack_);

NODE *peek(const STACK *_pStack_);

// int displayStack(const stack *_pStack_);

bool deleteStack(STACK *_pStack_);

TOKEN setToken(const TYPE _type_, const double _val_);

#endif