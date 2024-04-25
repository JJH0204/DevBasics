# [Bubble Sorting] 버블 정렬 알고리즘
- 배열(또는 리스트)의 이웃한 두 요소의 대소 관계를 비교하여 교환을 반복하는 알고리즘
- 마치 비눗방울과 비슷한 모양이라고 해서 지어진 이름
- (오름차순 정렬 기준) 배열의 끝 부터 차례로 이웃한 요소와 값을 비교하여 큰 값은 뒤로, 작은 값은 앞으로 이동시킨다.
- 배열 요소의 개수가 n개일 때 n - 1 회 비교, 교환 작업을 진행한다.
- 위 (비교 및 교환 작업)과정을 패스(pass)라고 하며 첫번째 패스에서는 가장 작은 값이 배열의 가장 처음으로 이동하게 된다.
- (패스 시작 지점이 배열의 끝이 아니라 시작 지점이라면 배열의 가장 큰 값이 배열의 끝으로 이동하게 된다.)
- 배열의 가장 작은 값(또는 가장 큰 값)을 정렬한 후 다음 정렬을 위헤 n - 2회 패스를 진행한다.
- 모든 정렬이 끝나려면 n - 1 회 패스가 진행되어야 한다. (n - 1개 요소의 정렬이 끝나면 마지막 요소는 이미 끝에 놓이기 때문)

# 소스 코드
```c
/* 버블 내부 교환 매크로 함수*/
#define swapBubble(type, x, y) \
    do                   \
    {                    \
        type t = x;      \
        x = y;           \
        y = t;           \
    } while (0)

/* 버블 정렬 */
void bubble(int *a, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = n - 1; j > i; j--) /* 배열 끝 부터 패스 */
            if (a[j - 1] > a[j])
                swapBubble(int, a[j - 1], a[j]);
}
```
> TIP. 여러 줄에 걸쳐 매크로를 작성하고자 할 때는 \ (역슬래시)를 사용    

- 배열의 끝(오른쪽)부터 스캔하기 때문에 j의 시작값은 n - 1
- a[j - 1]과 a[j]를 비교해 앞쪽이 크면 교환
- j 값은 1씩 감소
- 한번의 패스에서 j의 값이 i + 1이 될 때까지 비교, 교환 수행
- 서로 이웃한 요소에 대한 비교, 교환이 이뤄짐으로 안정적이라 할 수 있다.
- 이동 횟수의 평균: $3n(n - 1) / 4$회

# 알고리즘 개선_1
- 패스(pase) 과정에서 교환이 이뤄지지 않는 경우: 이미 정렬이 완료되었다고 판단하고 루프에서 빠져 나온다.
```c
void bubble(int *a, int n)
{
    int i, j;
    int nExchange = 0;
    for (i = 0; i < n - 1; i++)
    {
        nExchange = 0;          /* 교환 횟수 체크를 위한 변수 초기화 */
        for (j = 0; j < n - i - 1; j++) /* 배열 시작부터 패스 */
            if (a[j] > a[j + 1])
            {
                swapBubble(int, a[j], a[j + 1]);
                nExchange++;    /* 교환 후 체크 */
            }
        if (nExchange == 0)     /* 교환이 이뤄지지 않으면 루프 탈출 */
            break;
        
    }
}
```
- 이 아이디어를 바탕으로 배열의 현재 정렬 상태를 확인하는 함수를 만들 수 있다.
```c
/* 배열 정렬 여부 확인*/
int is_sorted(const int *a, int n)
{
    int nLoopCount = 0;
    if (a == NULL || n < 2)
        return 0;
    
    for ( ; nLoopCount < n - 1; nLoopCount++)
        if (a[nLoopCount] > a[nLoopCount + 1])
            return 0;
    return 1;
}
```

# 알고리즘 개선_2
- 각각의 패스에서 비교, 교환을 하다가 어떤 시점 이후 교환이 수행되지 않는다면, 이미 정렬된 상태라 간주할 수 있다.
- 가장 마지막에 비교, 교환한 인덱스를 기준으로 비교 시작(또는 종료) 지점으로 삼아 루프를 진행할 수 있다.
```c
void bubble(int *a, int n)
{
    int i, j, k, last;
    int nExchange = 0;
    
    k = n - 1;
    for (i = 0; i < n - 1; i++)
    {
        nExchange = 0;
        for (j = 0; j < k ; j++)
            if (a[j] > a[j + 1])
            {
                swapBubble(int, a[j], a[j + 1]);
                nExchange++;    /* 가장 최근에 교환이 이뤄진 인덱스 위치를 기억 */
                last = j;
            }
        k = last;               /* 기억하고 있던 위치를 루프의 종료 조건으로 설정 */
        if (nExchange == 0)
            break;
    }
}
```

# 알고리즘 개선_3
```2, 3, 4, 5, 6, 7, 8, 9, 1```
- 위 배열을 정렬한다고 했을 때 두번째 개선된 버블 정렬 알고리즘으로 정렬해도 오랜시간이 걸린다.
- 패스 1회 진행 시 "1"의 위치는 고작 한칸만 앞으로 오기 때문이다.
- 그래서 홀수 번째 패스는 가장 작은 요소를 맨 앞으로,   
짝수 번째 패스는 가장 큰 요소를 맨 뒤로 옮기는 방식을 사용하면 적은 횟수로 정렬을 수행할 수 있다.
- 패스의 스캔 방향을 교대로 바꾼다 가정했을 때 이를 "양뱡향 버블 정렬(Bidirection bubble sort)"이라 한다.
- 같은 의미의 다른 말로 칵테일 정렬(Cocktail sort), 셰이커 정렬(Shaker sort)이 있다.
```c
/* 양뱡향 버블 정렬*/
void cocktail(int *a, int n)
{
    int nPase = 0, nStart = 0, nEnd = n - 1, nLoopCount = 0, nLast = 0, nExchange = 0;

    for (nPase = 0; nPase < n - 1; nPase++)
    {
        nExchange = 0;

        if ((nPase % 2) == 0) /* pase가 "짝수"라면*/
        {
            /* 배열의 끝부터 가장 작은 값을 찾아 앞으로 이동 */
            for (nLoopCount = nEnd; nLoopCount > nStart; nLoopCount--)
            {
                if (a[nLoopCount - 1] > a[nLoopCount])
                {
                    swapBubble(int, a[nLoopCount - 1], a[nLoopCount]);
                    nLast = nLoopCount;
                    nExchange++;
                }
            }
            nStart = nLast;
        }
        else /* pase가 "홀수"라면*/
        {
            /* 배열의 시작부터 가장 큰은 값을 찾아 뒤으로 이동 */
            for (nLoopCount = nStart; nLoopCount < nEnd; nLoopCount++)
            {
                if (a[nLoopCount] > a[nLoopCount + 1])
                {
                    swapBubble(int, a[nLoopCount], a[nLoopCount + 1]);
                    nLast = nLoopCount;
                    nExchange++;
                }
            }
            nEnd = nLast;
        }
        if (nExchange == 0)
            break;
    }
    return;
}
```