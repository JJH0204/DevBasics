#include <stdio.h>
#define RECURSIVE

#ifdef RECURSIVE
int binarySearch(int * _pVal_, int _nStart_, int _nEnd_, int _nKey_)
{
    int nMiddleIndex = 0;

    if (_nStart_ > _nEnd_)
        return -1;
    
    nMiddleIndex = (_nStart_ + _nEnd_) / 2;

    if (_nKey_ == _pVal_[nMiddleIndex])
        return nMiddleIndex;
    else if (_nKey_ < _pVal_[nMiddleIndex])
        return binarySearch(_pVal_, _nStart_, nMiddleIndex - 1, _nKey_);
    else
        return binarySearch(_pVal_, nMiddleIndex + 1, _nEnd_, _nKey_);
}
#endif

#ifndef RECURSIVE
int binarySearch(int *_pVal_, int _nStart_, int _nEnd_, int _nKey_)
{
    // TODO: 반복문으로 이진 탐색 구현
    
}
#endif
int main(int argc, char * argv[])
{
    int nKey = 0;
    int nIndex = 0;
    int ascSortedArray[] = {10, 20, 50, 60, 70, 80};

    nKey = 60;
    nIndex = binarySearch(ascSortedArray, 0, 5, nKey);

    if (nIndex >= 0)
        printf("Key-%d, Index-%d\n", nKey, nIndex);
    else
        printf("Key-%d (Search Fail)\n", nKey);

    nKey = 65;
    nIndex = binarySearch(ascSortedArray, 0, 5, nKey);

    if (nIndex >= 0)
        printf("Key-%d, Index-%d\n", nKey, nIndex);
    else
        printf("Key-%d (Search Fail)\n", nKey);
    
    return 0;
}