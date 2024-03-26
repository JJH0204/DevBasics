#ifndef __POSTFIX__
#define __POSTFIX__

double Calc(const TOKEN *_pTOKEN_, const int _nSize_);

TOKEN *infix2postfix(const TOKEN *_pInfix_, const int _nInfixSize_, int *_nPostfixSize_);

bool operatorPriority(const TOKEN _Token_, STACK *_pStack_, TOKEN *_pTokenArray_, int *pInputCount);

int priorityOutStack(const TYPE _type_);

int priorityInStack(const TYPE _type_);

bool displayNotation(const TOKEN *_pToken_, const int _nSize_);

bool handlingBracket(STACK *_pStack_, TOKEN *_pTokenArray_, int *pInputCount);
#endif