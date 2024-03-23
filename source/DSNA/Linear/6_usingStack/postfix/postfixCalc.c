#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "notationStack.h"
#include "postfixCalc.h"

bool Calc(const TOKEN *_pTOKEN_, const int _nSize_)
{
    int nCount = 0;
    STACK *pStack = NULL;
    NODE *token_A = *token_B = NULL;
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
        else {
            token_B = pop(pStack);
            token_A = pop(pStack);
            if (type == MULTIPLY)           // 곱하기
                push(pStack, setToken(OPERAND, token_A->tData.dValue * token_B->tData.dValue));
            else if (type == DIVIDE)        // 나누기
                push(pStack, setToken(OPERAND, token_A->tData.dValue / token_B->tData.dValue));
            else if (type == PLUS)          // 더하기
                push(pStack, setToken(OPERAND, token_A->tData.dValue + token_B->tData.dValue));
            else if (type == MINUS)         // 빼기
                push(pStack, setToken(OPERAND, token_A->tData.dValue - token_B->tData.dValue));
            else                            // 에러
                break;
            free(token_A);
            free(token_B);
        }
    }
    if (ISEMPTY(pStack) || pStack->nCurrentCount > 1)    return true;
    printf("> Result: %lf\n", pStack->pTOP->tData.dValue);
    deleteStack(pStack);
    return false;
}
