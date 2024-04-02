# 우선순위 큐 (Priority Queue)
- 우선순위 큐를 구현하는 수단으로 히프를 사용할 수 있다.
- 노드 반환(dequeue)시에 큐에서 우선순위가 가장 높거나 혹은 가장 낮은 노드를 먼저 반환하는 큐를 말한다.
- 일반적으로 큐(queue)는 가장 먼저 추가된 데이터를 반환하는 FIFO(선입선출) 특징을 갖고 있으나, 우선순위 큐는 반환 순서는 삽입되는 순서와 상관없이 오직 저장된 데이터의 크기로 결정된다.
> - 최대 히프로 구현된 큐에서는 우선순위가 가장 높은 노드가 반환된다.
> - 최소 히프로 구현된 큐에서는 우선순위가 가장 낮은 노드가 반환된다.
- 최대(또는 최소)히프에서 단순히 데이터를 삭제하기만 하면 값이 가장 큰 데이터가 반환되기 때문이다.
- 또한, 자료를 삽입하거나 삭제할 때 시간 복잡도가 $O(log n)$이 되어 비교적 빠른 속도를 갖는다. (리스트로 구현하면 $O(n)$이 되어 히프보다 느린다.)

## 히프 정렬(sort)
> 정렬(Sort):
> - 순서 없이 배열된 자료들을 값에 따라 순서대로 재배열하는 것을 말한다.
> - 값이 증가하는 순서대로 배열하는 것을 "오름차순(ascending)정렬"이라 한다.
> - 반대로 값이 감소하는 순서대로 배열하는 것을 "내림차순(descending)정렬"이라 한다. 

### 히프 정렬 구현
- 최대 히프를 이용하면 내림차순 정렬을 구현할 수 있다.
- 최대 히프에 자료를 추가했다가 단순히 제거만하면 되기 때문
> 최대 히프가 빈 히프가 될 때까지 제거 연산을 호출하면 가장 큰 값 부터 차례대로 반환된다.   
```c
void heapSort(int _arrayVal_[], const int _nCount_)
{
    int nIndex = 0;
    arrayMaxHeap *pHeap = NULL;
    heapNode *pNode = NULL;

    pHeap = createArrayHeap(10);                            // 히프 할당하고 검증
    if (pHeap ==  NULL)
        return;
    for (; nIndex < _nCount_; nIndex++)                     // 전달 받은 데이터를 히프에 최대 히프 형태로 저장
        insertArrayMaxHeap(pHeap, _arrayVal_[nIndex]);
    for (nIndex = 0; nIndex < _nCount_; nIndex++)           // 전달 받은 데이터 수 만큼 최대 히프에서 제거 연산 실행
    {
        pNode = removeArrayMaxHeap(pHeap);
        if (pNode != NULL)
        {
            _arrayVal_[nIndex] = pNode->nData;
            free(pNode);
        }
        
    }
    deleteArrayHeap(pHeap);                                 // 최대 히프 메모리 할당 해제
    return;
}

bool printArray(const int _arrayVal_[], const int _nCount_)
{
    int nIndex = 0;
    for (; nIndex < _nCount_; nIndex++)
        printf("%d ", _arrayVal_[nIndex]);
    printf("\n");
}

int main(int argc, char *argv[])
{
    int arrayVal[] = {10, 50, 70, 80, 60, 20, 40, 30};
    printf("[Before Sort]\n\t> ");
    printArray(arrayVal, 8);

    heapSort(arrayVal, 8);

    printf("[After Sort]\n\t> ");
    printArray(arrayVal, 8);

    return 0;
}
```
### 히프 정렬의 특성
- 저장된 데이터의 개수를 n개라고 한다면 데이터 1개를 삭제(정렬)에 평균 시간 복잡도는 $O(log_2n)$
> - 루트 노드의 삭제 자체는 $O(1)$이지만, 루트 노드 삭제 후 완전 이진 트리 재구성에 평균 $O(log_2n)$의 시간 소요된다.   
> - 다른 알고리즘 속도에 비하면 우수한 편   
- 히프 이용하여 정렬을 수행하기 떄문에, 히프 생성에 필요한 메모리가 필요하며 정렬의 안정성은 유지되지 못한다는 단점이 있다.
> - 정령에 사용되는 데이터의 종류가 2개 이상인 경우 각 데이터의 정렬 결과가 유지되지 않는 점   