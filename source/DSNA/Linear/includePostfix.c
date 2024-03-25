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
    NODE *pNode = NULL;

    if (ISNULL(_pTOKEN_)) return NULL;
    
    newTOKEN = (TOKEN*)malloc(sizeof(TOKEN)*_nSize_);
    if (ISNULL(newTOKEN)) return NULL;

    pStack = createStack();
    if (ISNULL(pStack)) return NULL;
    

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
                checkOperatorPriority(pStack, newTOKEN, _pTOKEN_[nCount], &nInputCount);
            }
        }
    }

    while (!ISEMPTY(pStack))
    {
        pNode = pop(pStack);
        newTOKEN[nInputCount] = pNode->tData;
        free(pNode);
        nInputCount++;
    }

    if (ISEMPTY(pStack))
        deleteStack(pStack);
    
    return newTOKEN;
}

bool checkOperatorPriority(STACK *_pStack_, TOKEN *_pNewToken_, TOKEN _tData_, int *_pInputCount_)
{
    int nRank_StackTop = 0;
    int nRank_Token = 0;
    NODE *pNode = NULL;

    if (ISNULL(_pStack_)) return true;
    
    nRank_StackTop = returnPriorityInStack(_pStack_->pTOP->tData.operType);
    nRank_Token = returnPriorityOutStack(_tData_.operType);
    
    if (nRank_StackTop <= nRank_Token)
    {
        push(_pStack_, _tData_);
    }
    else
    {
        while (nRank_StackTop > nRank_Token)
        {
            pNode = pop(_pStack_);
            _pNewToken_[*_pInputCount_] = pNode->tData;
            *_pInputCount_++;
            free(pNode);

            nRank_StackTop = returnPriorityInStack(_pStack_->pTOP->tData.operType);
        }
        push(_pStack_, _tData_);
    }
    pNode = peek(_pStack_);
    if (pNode->tData.operType == RPAREN)
        handlingBracket(_pNewToken_, _pStack_, _pInputCount_);
    
    free(pNode);
    return false;
}

int returnPriorityOutStack(const TYPE _type_)
{
    int nResult = 0;
    if (_type_ == OPERAND)
    {
        printf("Invalid function used.\n");
        return -1;
    }
    
    if ((_type_ == RPAREN) || (_type_ == LPAREN))
        nResult = 4;
    else if ((_type_ == MULTIPLY) || (_type_ == DIVIDE))
        nResult = 3;
    else if ((_type_ == PLUS) || (_type_ == MINUS))
        nResult = 2;
    else
        nResult = 1;
    
    return nResult;
}

int returnPriorityInStack(const TYPE _type_)
{
    int nResult = 0;
    if (_type_ == OPERAND)
    {
        printf("Invalid function used.\n");
        return -1;
    }
    
    if (_type_ == RPAREN)
        nResult = 4;
    else if ((_type_ == MULTIPLY) || (_type_ == DIVIDE))
        nResult = 3;
    else if ((_type_ == PLUS) || (_type_ == MINUS))
        nResult = 2;
    else
        nResult = 1;
    
    return nResult;
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

bool handlingBracket(TOKEN *_pToken_, STACK *_pStack_, int *_pInputCount_)
{
    NODE *pNode = NULL;

    if (ISNULL(_pStack_) || ISNULL(_pToken_)) return true;

    
    // pNode = pop(_pStack_);
    // free(pNode);
    // pNode = peek(_pStack_);
    // while (pNode->tData.operType != LPAREN)
    // {
    //     _pNewToken_[*_pInputCount_] = setToken(pNode->tData.operType, pNode->tData.dValue); 
    //     *_pInputCount_++;
    //     free(pNode);
    // }
    pNode = pop(_pStack_);
    free(pNode);
    while (_pStack_->pTOP->tData.operType != LPAREN)
    {
        pNode = pop(_pStack_);
        _pToken_[*_pInputCount_] = pNode->tData;
        (*_pInputCount_)++;
        free(pNode);
    }
    pNode = pop(_pStack_);
    free(pNode);
}