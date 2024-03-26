#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "includeNotationStack.h"
#include "includePostfix.h"

/*
.\postfixNotation.exe
Infix Expression:
    > 2.0 - ( 3.0 + 4.0 ) * 5.0
// peek() 함수를 잘못 사용하고 있었다.
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
    if (ISNULL(_pTOKEN_) || _nSize_ <= 2)
        return -1.0;

    pStack = createStack();
    if (ISNULL(pStack))
        return -1.0;

    for (nCount = 0; nCount < _nSize_; nCount++)
    {
        type = _pTOKEN_[nCount].operType;
        if (type == OPERAND)
        {
            push(pStack, _pTOKEN_[nCount]);
        }
        else
        {
            token_B = pop(pStack);
            token_A = pop(pStack);
            if (type == MULTIPLY) // 곱하기
                push(pStack, setToken(OPERAND, token_A->tData.dValue * token_B->tData.dValue));
            else if (type == DIVIDE) // 나누기
                push(pStack, setToken(OPERAND, token_A->tData.dValue / token_B->tData.dValue));
            else if (type == PLUS) // 더하기
                push(pStack, setToken(OPERAND, token_A->tData.dValue + token_B->tData.dValue));
            else if (type == MINUS) // 빼기
                push(pStack, setToken(OPERAND, token_A->tData.dValue - token_B->tData.dValue));
            else // 에러
                break;
            free(token_A);
            free(token_B);
        }
    }
    if (ISEMPTY(pStack) || pStack->nCurrentCount > 1)
        return -1.0;

    pNode = pop(pStack);
    fResult = pNode->tData.dValue;
    deleteStack(pStack);
    free(pNode);
    return fResult;
}

TOKEN *infix2postfix(const TOKEN *_pInfix_, const int _nInfixSize_, int *_nPostfixSize_)
{
    int nCount = 0;
    int nInputCount = 0;
    TOKEN *newTOKEN = NULL;
    STACK *pStack = NULL;
    NODE *pNode = NULL;

    if (ISNULL(_pInfix_))
        return NULL;

    newTOKEN = (TOKEN *)malloc(sizeof(TOKEN) * _nInfixSize_);
    pStack = createStack();
    if (ISNULL(newTOKEN) || ISNULL(pStack))
        return NULL;

    while (nCount < _nInfixSize_)
    {
        if (_pInfix_[nCount].operType == OPERAND)
        {
            newTOKEN[nInputCount] = setToken(_pInfix_[nCount].operType, _pInfix_[nCount].dValue);
            nInputCount++;
        }
        else if (_pInfix_[nCount].operType != NOTYPE)
        {
            if (ISEMPTY(pStack))
            {
                push(pStack, setToken(_pInfix_[nCount].operType, _pInfix_[nCount].dValue));
            }
            else
            {
                operatorPriority(_pInfix_[nCount], pStack, newTOKEN, &nInputCount);
                handlingBracket(pStack, newTOKEN, &nInputCount);
            }
        }
        nCount++;
    }
    while (!ISEMPTY(pStack))
    {
        // printf(">%d<", pStack->pTOP->tData.operType);
        pNode = pop(pStack);
        newTOKEN[nInputCount] = setToken(pNode->tData.operType, pNode->tData.dValue);
        nInputCount++;
        free(pNode);
    }
    *_nPostfixSize_ = nInputCount;
    deleteStack(pStack);
    return newTOKEN;
}

bool operatorPriority(const TOKEN _Token_, STACK *_pStack_, TOKEN *_pTokenArray_, int *pInputCount)
{
    NODE *pNode = peek(_pStack_);

    while (priorityOutStack(_Token_.operType) < priorityInStack(pNode->tData.operType))
    {
        pNode = pop(_pStack_);                                                              // 스텍의 탑 팝
        _pTokenArray_[*pInputCount] = setToken(pNode->tData.operType, pNode->tData.dValue); // 팝한 데이터 배열에 추가
        *pInputCount += 1;                                                                  // 배열 인덱스 번호 갱신
        free(pNode);                                                                        // 팝한 데이터 삭제
        pNode = peek(_pStack_);
    }
    push(_pStack_, setToken(_Token_.operType, _Token_.dValue));

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
    if (ISNULL(_pToken_))
        return true;
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
    return false;
}