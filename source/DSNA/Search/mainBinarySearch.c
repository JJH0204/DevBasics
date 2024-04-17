#include <stdio.h>
// #define RECURSIVE

#ifdef RECURSIVE
int binarySearch(int *_pVal_, int _nStart_, int _nEnd_, int _nKey_)
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
void printIndex(int _nArraySize_)
{
    int nLoopCount = 0;
    printf("\t|");
    for (nLoopCount = 0; nLoopCount < _nArraySize_; nLoopCount++)
        printf("%02d\t", nLoopCount);
    printf("\n-------------------------------------\n");
    return;
}

void printProcedure(int *_pArray_, int _nArraySize_, int _nStart_, int _nEnd_, int _nMiddle_)
{
    int nLoopCount = 0;

    printf("\t|");
    for (nLoopCount = 0; nLoopCount < _nArraySize_; nLoopCount++)
    {
        if (nLoopCount == _nStart_)
            printf("<");
        if (nLoopCount == _nMiddle_)
            printf("+");
        if (nLoopCount == _nEnd_)
        {
            printf(">\n");
            break;
        }
        printf("\t");
    }
    printf("%02d\t|", _nMiddle_);
    for (nLoopCount = 0; nLoopCount < _nArraySize_; nLoopCount++)
        printf("%02d\t", _pArray_[nLoopCount]);

    printf("\n\t|\n");
    return;
}

int binarySearch(int *_pArray_, int _nArraySize_, int _nStart_, int _nEnd_, int _nKey_)
{
    int nMiddleIndex = 0;
    printIndex(_nArraySize_);
    while (_nStart_ <= _nEnd_)
    {
        nMiddleIndex = (_nStart_ + _nEnd_) / 2;
        printProcedure(_pArray_, _nArraySize_, _nStart_, _nEnd_, nMiddleIndex);
        if (_nKey_ == _pArray_[nMiddleIndex])
            return nMiddleIndex;
        else if (_nKey_ < _pArray_[nMiddleIndex])
            _nEnd_ = nMiddleIndex - 1;
        else
            _nStart_ = nMiddleIndex + 1;
    }
    return -1;
}

int binarySearch_2(int *_pArray_, int _nArraySize_, int _nStart_, int _nEnd_, int _nKey_)
{
    int nMiddleIndex = 0;
    printIndex(_nArraySize_);
    while (_nStart_ <= _nEnd_)
    {
        nMiddleIndex = (_nStart_ + _nEnd_) / 2;
        printProcedure(_pArray_, _nArraySize_, _nStart_, _nEnd_, nMiddleIndex);
        while (_nKey_ == _pArray_[nMiddleIndex])
            {
                nMiddleIndex--;
                if (_nKey_ != _pArray_[nMiddleIndex])
                    return nMiddleIndex + 1;
                
                printProcedure(_pArray_, _nArraySize_, _nStart_, _nEnd_, nMiddleIndex);
            }
        if (_nKey_ < _pArray_[nMiddleIndex])
            _nEnd_ = nMiddleIndex - 1;
        else
            _nStart_ = nMiddleIndex + 1;
    }

    return -1;
}
#endif
int main(int argc, char *argv[])
{
    int nKey = 0;
    int nIndex = 0;
    int ascSortedArray[] = {1, 2, 3, 3, 3, 3, 4, 4, 4, 5};
    int nArraySize = 10;

    nKey = 3;
    nIndex = binarySearch_2(ascSortedArray, nArraySize, 0, nArraySize - 1, nKey);

    if (nIndex >= 0)
        printf("Key-%d, Index-%d\n", nKey, nIndex);
    else
        printf("Key-%d (Search Fail)\n", nKey);

    nKey = 4;
    nIndex = binarySearch_2(ascSortedArray, nArraySize, 0, nArraySize - 1, nKey);

    if (nIndex >= 0)
        printf("Key-%d, Index-%d\n", nKey, nIndex);
    else
        printf("Key-%d (Search Fail)\n", nKey);

    return 0;
}