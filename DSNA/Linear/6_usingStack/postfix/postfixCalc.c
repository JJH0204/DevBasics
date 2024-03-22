#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "notationStack.h"
#include "postfixCalc.h"

bool Calc(const TOKEN *_pTOKEN_, const int _nSize_)
{
    int nCount = 0;
    STACK *pStack = NULL;
    TOKEN token_A, token_B;
    TYPE type;
    if (ISNULL(_pTOKEN_) || _nSize_ <= 2) return true;

    pStack = createStack();
    if (ISNULL(pStack)) return true;
    
    for (nCount = 0; nCount < _nSize_; nCount++)
    {
        type = _pTOKEN_[nCount].operType;
        if (type == OPERAND)
        {
            push(pStack, _pTOKEN_[nCount]);
        }
        else if (type == MULTIPLY)           // 곱하기
        {
            token_B = pop(pStack)->tData;
            token_A = pop(pStack)->tData;
            push(pStack, setToken(OPERAND, token_A.dValue * token_B.dValue));
        }
        else if (type == DIVIDE)        // 나누기
        {
            token_B = pop(pStack)->tData;
            token_A = pop(pStack)->tData;
            push(pStack, setToken(OPERAND, token_A.dValue / token_B.dValue));
        }
        else if (type == PLUS)          // 더하기
        {
            token_B = pop(pStack)->tData;
            token_A = pop(pStack)->tData;
            push(pStack, setToken(OPERAND, token_A.dValue + token_B.dValue));
        }
        else if (type == MINUS)         // 빼기
        {
            token_B = pop(pStack)->tData;
            token_A = pop(pStack)->tData;
            push(pStack, setToken(OPERAND, token_A.dValue - token_B.dValue));
        }
    }
    if (ISEMPTY(pStack))    return true;
    printf("> Result: %lf\n", pStack->pTOP->tData.dValue);
    deleteStack(pStack);
    return false;
}
