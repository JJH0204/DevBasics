# 1. 힙 정렬 (Heap Sort)
- 최대 또는 최소 힙의 특징을 활용한 정렬 알고리즘
- [힙 관련 문서](../../DataStructure/Heap.md)를 참고하면 힙의 특징을 이해할 수 있다.

# 2. 힙 정렬 구현
- 배열의 오름차순 정렬을 위해 최대 힙의 특징을 활용한다.

## 2.1. 소스코드
```c
#include "includeHeap.h"
/* -- 중략 -- */
void heapSort(int *a, int n)
{
    arrayMaxHeap *buff;
    int nArrayPtr;

    if (a == NULL || n < 1)
        return;
    
    buff = createArrayHeap(n);
    if (buff == NULL)
        return;
    for (nArrayPtr = 0; nArrayPtr < n; nArrayPtr++)
        insertArrayMaxHeap(buff, a[nArrayPtr]);
    
    for (nArrayPtr = n - 1; nArrayPtr >= 0; nArrayPtr--)
        a[nArrayPtr] = removeArrayMaxHeap(buff)->nData;
    
    deleteArrayHeap(buff);
}
```
# 3. 알고리즘 평가
- 힙 정렬 알고리즘은 선택 정렬 알고리즘을 응용한 알고리즘이다.
- 선택 정렬과 달리 힙 정렬은 첫 요소를 꺼내는 것 만으로 가장 큰 값을 구할 수 있음으로 힙 구현 후 힙 정렬 구현 자체의 난이도는 낮다.
- 첫 요소를 꺼낸 후 나머지 요소를 다시 힙으로 만들어야 그 다음 작업이 가능함으로 힙 구현의 난이도는 높은 편이다.
- 단순 선택 정렬에서 가장 큰 값을 선택할 때 시간 복잡도가 $O(n)$인 반면 힙 정렬은 $O(1)$로 줄어든다.
- 대신 힙 정렬을 위해 나머지 요소를 다시 힙으로 만드는 작업의 시간 복잡도는 $O(log n)$이다.
- 단순 선택 정렬의 전체 정렬에 걸리는 시간 복잡도는 $O(n^2)$이지만, 힙 정렬은 $O(n log n)$의 시간 복잡도를 가져 효율적이다.

# 4. array[left] ~ array[right]를 힙으로 만드는 함수
```c
/* array[left] ~ array[right] 를 최대 힙으로 만드는 함수 */
static void maxHeap(int *array, int left, int right)
{
    int temp, child, parent, leftC, rightC;

    if (array == NULL)
        return;
    
    temp = array[left];

    for (parent = left; parent < (right + 1) / 2; parent = child)
    {
        leftC = parent * 2 + 1; /* 왼쪽 자식 */
        rightC = leftC + 1; /* 오른쪽 자식 */

        child = (rightC <= right && array[rightC] > array[leftC]) ? rightC : leftC ; /* 두 자식 중 큰 값을 선택 */

        if (temp >= array[child])
            break;
        array[parent] = array[child];
    }
    array[parent] = temp;
}
```
# 5. 4번 알고리즘을 활용한 힙 구현
```c
void _heapSort(int * a, int n)
{
    int i;
    /* 배열을 힙으로 만든다. */
    for (i = (n - 1) / 2; i >= 0; i--)
        maxHeap(a, i, n - 1);
    /* 정렬 로직 수행 */
    for (i = n - 1; i > 0; i--)
    {
        swap(int, a[0], a[i]); /* 루트 값과 배열의 정렬되지 않은 끝 요소와 교환 */
        maxHeap(a, 0, i - 1); /* 배열의 시작부터 정렬되지 않은 끝 요소까지 다시 힙으로 만든다. */
    }
}
```