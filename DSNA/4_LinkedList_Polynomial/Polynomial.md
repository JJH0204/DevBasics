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
        
        int removeData(polyList *_pList_, int _nPos_)
        {
            // variable declaration
            int nCount = 0;
            node *pDeleteNode = NULL;
            node *pCurrentNode = NULL;

            // check validity
            if (_pList_ == NULL)
            {
                printf("Unallocated memory access error: removeData()\n");
                return -1;
            }
            if ((_nPos_ < 0) || (_nPos_ > _pList_->nCurrentCount))
            {
                printf("Index access error: removeData()\n");
                return -2;
            }

            // data addition process
            pCurrentNode = &(_pList_->headerNode);
            for ( ; nCount < _nPos_; nCount++)
                pCurrentNode = pCurrentNode->pNext;
            pDeleteNode = pCurrentNode->pNext;
            pCurrentNode->pNext = pDeleteNode->pNext;
            free(pDeleteNode);
            _pList_->nCurrentCount--;

            // end function
            return 0;
        }

        term getData(polyList *_pList_, int _nPos_)
        {
            // variable declaration
            term tResult = {0};
            int nCount = 0;
            node *pCurrentNode = NULL;

            // check validity
            if (_pList_ == NULL)
            {
                printf("Unallocated memory access error: getData()\n");
                return tResult;
            }
            if ((_nPos_ < 0) || (_nPos_ > _pList_->nCurrentCount))
            {
                printf("Index access error: getData()\n");
                return tResult;
            }

            // data addition process
            pCurrentNode = &(_pList_->headerNode);
            for ( ; nCount <= _nPos_; nCount++)
                pCurrentNode = pCurrentNode->pNext;
            tResult = pCurrentNode->tData;
            
            //return result
            return tResult;
        }

        int deleteList(polyList *_pList_)
        {
            if (_pList_ == NULL)
            {
                printf("Unallocated memory access error: deleteList()\n");
                return -1;
            }

            while (_pList_->headerNode.pNext != NULL)
                removeData(_pList_, 0);
            free(_pList_);

            return 0;
        }

        int getListLength(polyList *_pList_)
        {
            if (_pList_ == NULL)
            {
                printf("Unallocated memory access error: getListLength()\n");
                return -1;
            }

            return _pList_->nCurrentCount;
        }

        int initList(polyList *_pList_)
        {
            if (_pList_ == NULL)
            {
                printf("Error attempting to initialize unallocated memory: initList()\n");
                return -1;
            }
            _pList_->nCurrentCount = 0;
            initNode(&(_pList_->headerNode));
            return 0;
        }

        int initNode(node *_pNode_)
        {
            if (_pNode_ == NULL)
            {
                printf("Error attempting to initialize unallocated memory: initNode()\n");
                return -1;
            }
            _pNode_->pNext = NULL;
            _pNode_->tData.coefficient = 0;
            _pNode_->tData.degree = 0;
            return 0;
        }

### 다항식의 항 추가 연산과 출력 연산
#### addPolyNode_L()
> 다항식에 새로운 노드를 추가하는 함수  
> 단, 새로운 노드를 연결 리스트 마지막 위치에 추가  
> 입력 파리미터 coef와 degree를 전달하여 내부적으로 적절한 위치(연결 리스트의 마지막)에 알아서 새로운 노드를 추가  
> addListData()만 사용한다면, 사용자는 별도의 구조체 변수(term)를 선언하고 노드 위치를 계산해 직접 저장해야 함  

    int addPolyNode_L(polyList *_pList_, const double coef, const int degree)
    {
        int ret = 0, position = 0;
        term tData = {0,};
        
        if (_pList_ == NULL)
        {
            printf("Error attempting to initialize unallocated memory: addPolyNode_L()\n");
            return -1;
        }

        tData.coefficient = coef;
        tData.degree = degree;

        position = _pList_->nCurrentCount;
        ret = addData(_pList_, tData, position);

        return ret;
    }

#### 다항식 출력: displayPoly()
> 연결 리스트를 순회하며 데이터를 출력하는 함수와 동일한 구조  
> '7.0x^6 + 3.0x^5 + 5.0x^2' 형태로 출력  

    int displayPoly(const polyList *_pList_)
    {
        int nCount = 0;
        node *pNode = NULL;
        if (_pList_ == NULL)
        {
            printf("Error attempting to initialize unallocated memory: displayPoly()\n");
            return -1;
        }
        if (_pList_->nCurrentCount <= 0)
        {
            printf("There is no data.\n");
            return -2;
        }
        pNode = _pList_->headerNode.pNext;
        for ( ; nCount < _pList_->nCurrentCount; nCount++)
        {
            if ((nCount > 0) && (pNode->tData.coefficient >= 0))
                printf(" +");
            else
                printf(" ");
            
            printf("%.1f", pNode->tData.coefficient);

            if (pNode->tData.degree > 0)
                printf("x^%d", pNode->tData.degree);
            
                pNode = pNode->pNext;
        }
        printf("\n");
        
        return 0;
    }

#### 다항식 더하기 연산: polyAdd()  
> 두 다항식(pListA, pListB)를 전달 받아 높은 차수부터 낮은 차수 순으로 순서대로 덧셈을 진행  
> 이를 위해 다항식은 차수를 기준으로 무조건 내림차수로 작성되어야 한다.  
> 두 다항식의 덧셈 결과를 pResult라는 새로운 노드를 만들어 리스트에 저장한다.  
> 두 다항식의 어느 한 쪽에 차수가 없는 경우를 고려해 로직을 작성

    polyList *polyAdd(const polyList *_pListA_, const polyList *_pListB_)
    {
        polyList *pResult = NULL;
        node *pNodeA = NULL, *pNodeB = NULL;

        if ((_pListA_ == NULL) || (_pListB_ == NULL))
        {
            printf("Error attempting to initialize unallocated memory: polyAdd()\n");
            return NULL;
        }
        if ((_pListA_->headerNode.pNext == NULL) || (_pListB_->headerNode.pNext == NULL))
        {
            printf("The other formula for polynomial addition is empty.: polyAdd()\n");
            return NULL;
        }
        
        pResult = createList();
        if (pResult == NULL)
        {
            printf("memory allocation error: polyAdd()\n");
            return NULL;
        }
        initList(pResult);

        pNodeA = _pListA_->headerNode.pNext;
        pNodeB = _pListB_->headerNode.pNext;

        while ((pNodeA != NULL) && (pNodeB != NULL))
        // Tip: If either of them points to NULL, must terminate the while(). So we use AND(&&).
        {
            // case_1: The degree of term A is higher than the degree of term B
            if (pNodeA->tData.degree > pNodeB->tData.degree)
            {
                addPolyNode_L(pResult, pNodeA->tData.coefficient, pNodeA->tData.degree);
                pNodeA = pNodeA->pNext;
            }
            // case_2: The degree of term B is higher than the degree of term A
            else if (pNodeA->tData.degree < pNodeB->tData.degree)
            {
                addPolyNode_L(pResult, pNodeB->tData.coefficient, pNodeB->tData.degree);
                pNodeB = pNodeB->pNext;
            }
            // case_3: Two terms have the same degree
            else
            {
                addPolyNode_L(pResult, pNodeA->tData.coefficient + pNodeB->tData.coefficient, pNodeB->tData.degree);
                pNodeA = pNodeA->pNext;
                pNodeB = pNodeB->pNext;
            }
        }
        // case_4: There are terms remaining after addition, so post-processing is required.
        while (pNodeA != NULL)
        {
            addPolyNode_L(pResult, pNodeA->tData.coefficient, pNodeA->tData.degree);
            pNodeA = pNodeA->pNext;
        }
        
        while (pNodeB != NULL)
        {
            addPolyNode_L(pResult, pNodeB->tData.coefficient, pNodeB->tData.degree);
            pNodeB = pNodeB->pNext;
        }

        return pResult;
    }

#### 다항식 뺄셈 연산: polySub()  

    polyList *polySub(const polyList *_pListA_, const polyList *_pListB_)
    {
        // Implementation of subtraction of two polynomials
        polyList *pResult = NULL;
        node *pNodeA = NULL, *pNodeB = NULL;

        if ((_pListA_ == NULL) || (_pListB_ == NULL))
        {
            printf("Error attempting to initialize unallocated memory: polySub()\n");
            return NULL;
        }
        if ((_pListA_->headerNode.pNext == NULL) || (_pListB_->headerNode.pNext == NULL))
        {
            printf("The other formula for polynomial addition is empty.: polySub()\n");
            return NULL;
        }

        pResult = createList();
        if (pResult == NULL)
        {
            printf("memory allocation error: polySub()\n");
            return NULL;
        }
        initList(pResult);

        pNodeA = _pListA_->headerNode.pNext;
        pNodeB = _pListB_->headerNode.pNext;

        while ((pNodeA != NULL) && (pNodeB != NULL))
        // Tip: If either of them points to NULL, must terminate the while(). So we use AND(&&).
        {
            // case_1: The degree of term A is higher than the degree of term B
            if (pNodeA->tData.degree > pNodeB->tData.degree)
            {
                addPolyNode_L(pResult, pNodeA->tData.coefficient, pNodeA->tData.degree);
                pNodeA = pNodeA->pNext;
            }
            // case_2: The degree of term B is higher than the degree of term A
            else if (pNodeA->tData.degree < pNodeB->tData.degree)
            {
                addPolyNode_L(pResult, -1 * pNodeB->tData.coefficient, pNodeB->tData.degree);
                pNodeB = pNodeB->pNext;
            }
            // case_3: Two terms have the same degree
            else
            {
                addPolyNode_L(pResult, pNodeA->tData.coefficient - pNodeB->tData.coefficient, pNodeB->tData.degree);
                pNodeA = pNodeA->pNext;
                pNodeB = pNodeB->pNext;
            }
        }
        // case_4: There are terms remaining after addition, so post-processing is required.
        while (pNodeA != NULL)
        {
            addPolyNode_L(pResult, pNodeA->tData.coefficient, pNodeA->tData.degree);
            pNodeA = pNodeA->pNext;
        }

        while (pNodeB != NULL)
        {
            addPolyNode_L(pResult, -1 * pNodeB->tData.coefficient, pNodeB->tData.degree);
            pNodeB = pNodeB->pNext;
        }

        return pResult;
    }

#### 다항식 정렬: polySort()
    int polySort(polyList *_pList_)
    {
        // Supports sorting in descending order based on degree
        node *pPast = NULL;
        node *pCurrent = NULL;
        node *pFuture = NULL;

        if (_pList_ == NULL)
        {
            printf("Unallocated memory reference error: polySort()");
            return -1;
        }
        
        pPast = &(_pList_->headerNode);

        while (pPast->pNext->pNext != NULL)
        {
            pCurrent = pPast->pNext;
            pFuture = pCurrent->pNext;
            
            if (pCurrent->tData.degree < pFuture->tData.degree)
            {
                pPast->pNext = pFuture;
                pCurrent->pNext = pFuture->pNext;
                pFuture->pNext = pCurrent;
                
                pPast = &(_pList_->headerNode);
            }
            else
            {
                pPast = pPast->pNext;
            }
        }

        return 0;
    }