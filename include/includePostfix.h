#ifndef __POSTFIX__
#define __POSTFIX__

bool Calc(const TOKEN * _pTOKEN_, const int _nSize_);

TOKEN *infix2postfix(const TOKEN *_pTOKEN_, const int _nSize_);

bool checkOperatorPriority(STACK *_pStack_, TOKEN *_pNewToken_, TOKEN _tData_, int *_pInputCount_);

int returnPriorityOutStack(const TYPE _type_);

int returnPriorityInStack(const TYPE _type_);

bool displayNotation(const TOKEN *_pToken_, const int _nSize_);

bool handlingBracket(TOKEN *_pToken_, STACK *_pStack_, int *_pInputCount_);
#endif