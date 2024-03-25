#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "includeNotationStack.h"
#include "includePostfix.h"

/*
.\postfixNotation.exe
Infix Expression:
    > 2.0 - ( 3.0 + 4.0 ) * 5.0
*/

double Calc(const TOKEN *_pTOKEN_, const int _nSize_)
{
    int nCount = 0;
    double fResult = 0.0f;
    STACK *pStack = NULL;
    NODE *token_A = NULL;
    NODE *token_B = NULL;
    NODE *pNode = NULL;
    TYPE type = NOTYPE;
    if (ISNULL(_pTOKEN_) || _nSize_ <= 2) return -1.0;

    pStack = createStack();
    if (ISNULL(pStack)) return -1.0;
    
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
    if (ISEMPTY(pStack) || pStack->nCurrentCount > 1)    return -1.0;
    
    pNode = pop(pStack);
    fResult = pNode->tData.dValue;
    deleteStack(pStack);
    free(pNode);
    return fResult;
}

TOKEN *infix2postfix(const TOKEN *_pTOKEN_, const int _nSize_)
{
    int nCount = 0;
    int nInputCount = 0;
    TOKEN *newTOKEN = NULL;
    STACK *pStack = NULL;
    NODE *pNode = NULL;

    if (ISNULL(_pTOKEN_))
        return NULL;
    
    newTOKEN = (TOKEN*)malloc(sizeof(TOKEN)*_nSize_);
    pStack = createStack();
    if (ISNULL(newTOKEN) || ISNULL(pStack))
        return NULL;
    
    while (nCount < _nSize_)
    {
        if (_pTOKEN_[nCount].operType == OPERAND)
        {
            newTOKEN[nInputCount] = setToken(_pTOKEN_[nCount].operType, _pTOKEN_[nCount].dValue);
            nInputCount++;
        }
        else if (_pTOKEN_[nCount].operType != NOTYPE)
        {
            if (ISEMPTY(pStack))
            {
                push(pStack, setToken(_pTOKEN_[nCount].operType, _pTOKEN_[nCount].dValue));
            }
            else
            {
                operatorPriority(_pTOKEN_[nCount], pStack, newTOKEN, &nInputCount);
                handlingBracket(pStack, newTOKEN, &nInputCount);
            }
        }
        nCount++;
    }
    if (!ISEMPTY(pStack))
    {
        pNode = pop(pStack);
        newTOKEN[nInputCount] = setToken(pNode->tData.operType, pNode->tData.dValue);
        nInputCount++;
        free(pNode);
    }
    deleteStack(pStack);
    return newTOKEN;
}

bool operatorPriority(const TOKEN _Token_, STACK *_pStack_, TOKEN *_pTokenArray_, int *pInputCount)
{
    NODE *pNode = peek(_pStack_);
    // if (priorityOutStack(_Token_.operType) >= priorityInStack(pNode->tData.operType))
    // {
    //     push(_pStack_, setToken(_Token_.operType, _Token_.dValue));
    //     free(pNode);
    //     return false;
    // }

    while (priorityOutStack(_Token_.operType) < priorityInStack(pNode->tData.operType))
    {
        free(pNode);            // 피크 값 삭제
        pNode = pop(_pStack_);  // 스텍의 탑 팝
        _pTokenArray_[*pInputCount] = setToken(pNode->tData.operType, pNode->tData.dValue);     // 팝한 데이터 배열에 추가
        free(pNode);            // 팝한 데이터 삭제
        *pInputCount += 1;      // 배열 인덱스 번호 갱신
        pNode = peek(_pStack_);
    }
    push(_pStack_, setToken(_Token_.operType, _Token_.dValue));
    free(pNode);
    return false;
}

int priorityOutStack(const TYPE _type_)
{
    if ((_type_ == RPAREN) || (_type_ == LPAREN))
        return 4;
    else if ((_type_ == MULTIPLY) || (_type_ == DIVIDE))
        return 3;
    else if ((_type_ == PLUS) || (_type_ == MINUS))
        return 2;
    else
        return 1;
}

int priorityInStack(const TYPE _type_)
{
    if (_type_ == RPAREN)
        return 4;
    else if ((_type_ == MULTIPLY) || (_type_ == DIVIDE))
        return 3;
    else if ((_type_ == PLUS) || (_type_ == MINUS))
        return 2;
    else if (_type_ == LPAREN)
        return 1;
    else 
        return 0;
}

bool displayNotation(const TOKEN *_pToken_, const int _nSize_)
{
    int nCount = 0;
    TYPE type = 0;
    if (ISNULL(_pToken_)) return true;
    while (nCount < _nSize_)
    {
        type = _pToken_[nCount].operType;
        if (type == OPERAND)
            printf("%.01f ", _pToken_[nCount].dValue);
        else if (type == MULTIPLY)
            printf("* ");
        else if (type == DIVIDE)
            printf("/ ");
        else if (type == PLUS)
            printf("+ ");
        else if (type == MINUS)
            printf("- ");
        else if (type == RPAREN)
            printf(") ");
        else if (type == LPAREN)
            printf("( ");
        else
            break;
        nCount++;
    }
    printf("\n");
    return false;
}

bool handlingBracket(STACK *_pStack_, TOKEN *_pTokenArray_, int *pInputCount)
{
    NODE *pNode = NULL;

    if (ISNULL(_pStack_) || ISNULL(_pTokenArray_))
        return true;

    pNode = peek(_pStack_);
    if (pNode->tData.operType == RPAREN)
    {
        free(pNode);
        pNode = pop(_pStack_);
        while (pNode->tData.operType != LPAREN)
        {
            if (pNode->tData.operType != RPAREN)
            {
                _pTokenArray_[*pInputCount] = setToken(pNode->tData.operType, pNode->tData.dValue);
                *pInputCount += 1;
            }
            free(pNode);
            pNode = pop(_pStack_);
        }
        free(pNode);
    }
    
    // pNode = pop(_pStack_);
    // free(pNode);
    // pNode = peek(_pStack_);
    // while (pNode->tData.operType != LPAREN)
    // {
    //     _pNewToken_[*_pInputCount_] = setToken(pNode->tData.operType, pNode->tData.dValue); 
    //     *_pInputCount_++;
    //     free(pNode);
    // }
    // pNode = pop(_pStack_);
    // free(pNode);
    // while (_pStack_->pTOP->tData.operType != LPAREN)
    // {
    //     pNode = pop(_pStack_);
    //     _pToken_[*_pInputCount_] = pNode->tData;
    //     (*_pInputCount_)++;
    //     free(pNode);
    // }
    // pNode = pop(_pStack_);
    // free(pNode);
    return false;
}