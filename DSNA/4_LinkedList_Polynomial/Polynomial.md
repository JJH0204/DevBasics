# Polynomial (다항식)
> 계수(coefficient)와 차수(degree)로 정의되는 항(term)들의 집합  
> 일반적으로 계수가 큰 항부터 차례대로 내림차순으로 정렬해 작성

## 문제 1
- 두 개의 다항식을 입력 파라미터로 전달받아 더하는 함수 polyAdd()와 출력하는 함수 displayPoly()를 각각 구현해 보자.
- 그리고 구현된 함수로 두 다항식의 합을 구하고 결과를 출력해라
> 다항식 1: 7x^6 + 3x^5 + 5x^2  
> 다항식 2: x^5 + 2x^4 + 3x^2 + 4

### 자료구조 정의
- 다항식은 항(term)의 집합, 리스트로 표현 가능
- 리스트에 저장되는 데이터 = 항
- 항은 계수와 차수로 이뤄짐
- 계수는 실수 double 형, 차수는 정수 int  

        // definition data structure
        typedef struct Term         // '항' 구조체
        {
            double coefficient;     // 계수
            int degree;             // 차수
        } term;

        typedef struct Node         // 노드 구조체
        {
            term tData;             // 항 구조체 데이터
            struct Node *pNext;
        } node;

        typedef struct LinkedList   // 다항식 구조체
        {
            int nCurrentCount;
            node headerNode;
        } list, polyList;

### 연결 리스트 기본 함수 구현
- creatList(), addData()... 등등 리스트 동작에 필요한 기본적인 함수를 구현한다.  

        polyList *createList()
        {
            polyList *pNewList = (polyList*)malloc(sizeof(polyList));

            if (pNewList == NULL)
                return NULL;
            
            memset(pNewList, 0, sizeof(polyList));
            return pNewList;
        }

        // TODO: Function implementation
        int addData(polyList *_pList_, term _tData, int _nPos_)
        {
            // variable declaration
            int nCount = 0;

            // check validity
            if (_pList_ == NULL)
            {
                printf("Unallocated memory access error: addData(), _pList_\n");
                return -1;
            }
            if ((_nPos_ < 0) || (_nPos_>_pList_->nCurrentCount))
            {
                printf("Index access error: addData()\n");
                return -2;
            }
            
            // data addition process
            /* code */

            // end function
            return 0;
        }
        
        int removeData(polyList *_pList_, int _nPos_);
        int getData(polyList *_pList_, int _nPos_);
        int deleteList(polyList *_pList_);
        int getListLength(polyList *_pList_);