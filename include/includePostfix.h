#ifndef __POSTFIX__
#define __POSTFIX__

bool Calc(const TOKEN * _pTOKEN_, const int _nSize_);

TOKEN *infix2postfix(const TOKEN *_pTOKEN_, const int _nSize_);

#endif