#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "includeNotationStack.h"
#include "includePostfix.h"

bool Calc(const TOKEN *_pTOKEN_, const int _nSize_)
{
    int nCount = 0;
    STACK *pStack = NULL;
    NODE *token_A = NULL;
    NODE *token_B = NULL;
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

// TODO: 중위표기 법을 후위 표기법으로 변환하는 코드 작성
TOKEN *infix2postfix(const TOKEN *_pTOKEN_, const int _nSize_)
{
    int nCount = 0;
    int nInputCount = 0;
    TYPE type;
    TOKEN *newTOKEN = NULL;
    STACK *pStack = NULL;

    if (ISNULL(_pTOKEN_)) return true;
    
    newTOKEN = (TOKEN*)malloc(sizeof(TOKEN)*_nSize_);
    if (ISNULL(newTOKEN)) return true;

    pStack = createStack();
    if (ISNULL(pStack)) return true;
    

    for (; nCount < _nSize_; nCount++)
    {
        type = _pTOKEN_[nCount].operType;
        if (type == OPERAND)
        {
            newTOKEN[nInputCount] = _pTOKEN_[nCount];
            nInputCount++;
        }
        else
        {
            if (ISEMPTY(pStack))
            {
                push(pStack, _pTOKEN_[nCount]);
            }
            else
            {
                // 연산자 우선순위 검사
                // 검사 결과에 따른 처리
            }
        }
    }
    
    return false;
}
