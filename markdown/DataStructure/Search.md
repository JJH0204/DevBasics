# 검색(Search)
- 저장된 데이터 중 원하는 데이터를 찾는 알고리즘
- 찾고자 하는 데이터와 다른 데이터를 구별하는 키(key)를 검색 키(search key)라고 한다.
- 검색 엔진에서 사용자가 입력한 키워드(keyword) = 검색 키(search key)
## 1. 순차 검색(sequential search)
- **일렬(sequential)로 저장된 데이터들을 차례로 비교하고 찾는 검색 방법**
- 선형 검색(linear search)라고도 한다.
- 검색 알고리즘 중에서 가장 단순, 직관적인 방법
- 데이터가 비교적 적은 경우에만 사용할 수 있다.(단점)
### 1.1. 데이터가 미리 정렬되지 않은 경우
```80 -> 20 -> 70 -> 50```
- 선처리(pre-processing)하지 않은 오름차순(내림차순)등 규칙이 없는 데이터에서 원하는 데이터를 찾기 위해 첫 데이터부터 끝 데이터까지 차례로 살펴야 한다.
#### 1.1.1. 검색에 성공한 경우
```80 -> 20 -> [70] -> 50   // key = 70```
- 위 예제는 3번째 순회에서 키 값과 같은 데이터를 찾는데 성공한 상황을 보여준다.
- 3번째 순회에서 원하는 데이터를 찾았기 때문에 4번째 순회를 진행하지 않는다.

#### 1.1.2. 검색에 실패한 경우
```80 -> 20 -> 70 -> 50   // key = 90```
- 리스트에 없는 데이터(90)을 key 값으로 검색하여 값을 찾지 못한 상황을 보여준다.
- 리스트의 모든 데이터를 순회하기 위해 4회 순회를 실행했지만 값을 찾지 못했다.
- 검색 성공 실패 여부를 떠나 찾으려는 값을 실제로 있는지 마지막까지 비교해야 알 수 있다.

#### 1.1.3. 검색 성능
- 순차 검색의 성능은 찾으려는 데이터의 위치에 따라 달라진다.
- n번째 데이터를 찾기 위해 n번의 연산이 필요 = $O(n)$
- 따라서 데이터의 수가 많은 경우 순차 검색은 효율이 떨어진다.
- 정렬 또한 안되어 있다면 더더욱(값을 찾기 위해 데이터 끝까지 가야하기 때문) 효율이 좋지 않다.

### 1.2. 데이터가 미리 정렬된 경우
```20 -> 50 -> 70 -> 80```
- 데이터가 오름차순(또는 내림차순)으로 정렬된 경우 (선처리(pre-processing) 과정을 거친 경우)

#### 1.2.1. 검색에 성공한 경우
```20 -> 50 -> [70] -> 80     // key = 70```
- 원하는 데이터를 key 값으로 데이터를 찾는 과정은 정렬 안된 리스트에서 데이터를 찾는 것과 같다.
- 다만, 데이터 값을 비교할 때 "같음(==)" 외 "크다(>)" 또한 사용한다.
- 데이터의 크기 비교는 검색을 실패한 경우에 필요성울 확인할 수 있다.

#### 1.2.2. 검색에 실패한 경우
```20 -> 50 -> 70 -> 80     // key = 25```
- 리스트에 없는 데이터(25)를 찾을 때 첫 번째 순회를 통해 두 조건을 비교한다.
- [20 == 25 = false, 20 < 25 = true] 두 조건 중 하나가 충족함으로 다음 데이터를 비교하는데 이때 검색 성공 때와 다른 결과가 나온다.
- [50 == 25 = false, 50 < 25 = false] 두 조건 중 하나라도 충족하지 못하게 되었을 때, 리스트에 데이터가 없음으로 판단하고 순회를 종료하게 된다. (더 이상 탐색할 필요가 없기 때문)

#### 1.2.3. 검색 성능
- 데이터의 정렬 여부와 상관 없이 순차 검색은 비교 연산의 횟수가 같다.
- 물론, 검색에 실패했을 경우에 대해서 정렬 여부에 따라 비교 연산 횟수가 절반으로 줄었다.
- 그럼에도 빅-오 표기법으로 표현되는 시간 복잡도는 $O(n)$이다.
- 따라서, 데이터의 개수가 증가하면 검색에 소요되는 시간도 비례해 증가하는 비교적 느린 알고리즘임을 알 수 있다.

### 1.3. 순차 검색 구현
#### 1.3.1. [순차 검색 소스코드](../../source/DSNA/Search/mainSequentialSearch.c)
#### 1.3.2. 실행 결과
```shell
.\SequentialSearch.exe
1. 정렬되지 않은 경우
Index   |Key
-------------------------
0       ,80
1       ,20
2       ,70
3       ,50
1-1. 검색에 성공한 경우: key = 70
key-70, index-2
1-2. 검색에 실패한 경우: key = 25
key-25, Search Fail
2. 정렬된 경우
Index   |Key
-------------------------
0       ,20
1       ,50
2       ,70
3       ,80
2-1. 검색에 성공한 경우: key = 70
key-70, index-2
2-2. 검색에 실패한 경우: key = 25
key-25, Search Fail
```

## 2. 색인 순차 검색(index sequential search)
- 데이터가 미리 정렬된 경우 인덱스 테이블(index table)를 사용해 검색 효율을 올릴 수 있다.
- 인덱스를 사용해 데이터의 개수가 늘어나도 속도가 느려지지 않는 장점이 있다.

### 2.1. 인덱스와 인덱스 테이블
- 인덱스(index) 또는 색인이라는 것은 어떤 주제가 어느 위치(position)에 있는지 알려주는 용도로 사용된다.
- 자료구조의 인덱스는 찾으려는 검색 키 값의 위치를 저장한 것을 의미
- 자료구조 인덱스에서 데이터 위치란 배열에서 원소의 위치 혹은 변수의 주솟값을 의미한다.
- 인덱스 테이블이란 인덱스들을 모은 테이블을 의미
```
// 예제 배열
Array = {10, 20, 30, 40, 50, 60, 70, 80}

// 인덱스 테이블의 예시
10|0
50|4
70|6

※ 배열(원-데이터, source data)이 오름차순으로 정렬되어 있어 테이블 또한 오름차순으로 정렬되어야 한다.
```
- 테이블에 저장되는 데이터가 '키-값'처럼 쌍(pair)을 이루기 때문에 리스트라 하지 않는다.

### 2.2. 인덱스 테이블 사용
```
// 예제 배열
Array = {10, 20, 30, 40, 50, 60, 70, 80}

// 인덱스 테이블의 예시
10|0
50|4
70|6

// Key = 40
```
#### 2.2.1. 인덱스 테이블 검색
- 정확한 키 값을 찾는 것이 아닌 검색 키 값 보다 큰 인덱스를 찾는 것이 목적 
- 원-데이터가 오름차순이라 큰 인덱스를 찾는다. (만약 내림차순이라면 검색 키 값보다 작은 인덱스를 찾아야 함)
```
10|0 <- 10 < 40
50|4 <- 50 > 40 (FIND)
70|6
```
- 인덱스 테이블을 이용해 인덱스 4 아래에 원하는 값이 있음을 예상할 수 있게 되었다.
#### 2.2.2. 데이터 검색
- 인덱스 테이블 검색 결과로 얻은 검색 범위(0~4)에서 실제 데이터를 찾는다.
- 인덱스 테이블을 이용해 검색 범위를 줄일 수 있었다.
- 인덱스 3위치의 값(50)이 찾는 키 값(40) 보다 큰 것을 알고 있기에 0~3(4-1) 범위를 탐색한다.
```
Array = {10, 20, 30, 40,...} // 탐색 범위(0 ~ 3)의 데이터
```
- 인덱스 검색 결과로 얻어진 검색 범위를 대상으로 순차 검색을 하기 때문에 전체 비교 연산의 횟수가 줄게된다.
- 전체 데이터의 개수가 n, 인덱스 테이블의 인덱스 개수가 m이라 할때 시간 복잡도
  > 1) 인덱스 테이블에서 m번 키 값을 비교   
  > 2) 정해진 검색 범위에서 실제 데이터에서 n / m 번 값 비교   
  > 3) 색인 순차 검색의 성능은 1번과 2번의 합 = $O(m+n/m)$

### 2.3. 색인 순차 검색 구현
#### 2.3.1. [색인 순차 검색 소스코드](../../source/DSNA/Search/mainIndexSequentialSearch.c)
#### 2.3.2. 색인 순차 검색 결과
```shell
.\SequentialIndexSearch.exe
Index   |Key
---------------
0       |10
1       |20
2       |50
3       |60
4       |70
5       |80
> Index Table
Index   |Key
---------------
0       |10
2       |50
4       |70
Key-60, Index-3
Key-65, Search Fail
```
#### 2.3.3. 색인 순차 검색의 주의점
- 시간 복잡도 $O(m+n/m)$에서 알 수 있듯 순차 검색의 성능 향상은 최적의 m과 n의 결정에 의해 반영된다.
- 너무 큰 m 또는 적절하지 않은 m과 n의 비율은 성능을 떨어뜨리게 된다.
- 인덱스 테이블의 크기가 커진다면 2, 3차 인덱스 테이블을 만들어 관리할 수 있으나 언제 새로운 인덱스 테이블을 만들고 크기를 얼마로 할 것인지 저장되는 데이터의 성격에 따라 결정하기 어려운 문제가 될 수 있다.
- 원-데이터에 변경이 발생하면 색인 테이블도 같이 변경해야 한다. 
- 그래서 색인 순차 검색은 가능하면 한번 데이터가 추가되면 이후에 데이터의 변경이 없는 경우에 주로 사용된다.

## 3. 이진 검색(binary search) 기법
- 미리 정렬된 자료를 대상으로 검색 범위를 반으로 감소시켜 가며 검색 키를 찾는 검색 방법
- 분할과 비교 연산을 반복하여 검색 대상이 되는 자료를 찾는다.
- 이분 검색으로 불리기도 하며, 보간 검색(interpolation search)의 한 종류로 분류된다.

### 3.1. 이진 검색 예시 (성공)
```Array = {10, 20, 50, 60, 70, 80}```
```Search_Key = 60```
#### 1) $중간 찾기 = (시작 위치 + 마지막 위치) / 2 = (0 + 5) / 2 = 2.5 = 2(나머지 버림)$
#### 2) $값 비교 = Array[2] 보다 Search_Key가 크냐? 작냐? 또는 같냐? = 크다$
#### 3) $중간 찾기 = (시작 위치 + 마지막 위치) / 2 = (3 + 5) / 2 = 4$
#### 4) $값 비교 = Array[4] 보다 Search_Key가 크냐? 작냐? 또는 같냐? = 작다$
#### 5) $중간 찾기 = (시작 위치 + 마지막 위치) / 2 = (3 + 3) / 2 = 3$
#### 6) $값 비교 = Array[3] 보다 Search_Key가 크냐? 작냐? 또는 같냐? = 같다!!!$

### 3.2. 이진 검색 예시 (실패)
```Array = {10, 20, 50, 60, 70, 80}```
```Search_Key = 65```
#### 1) $중간 찾기 = (시작 위치 + 마지막 위치) / 2 = (0 + 5) / 2 = 2.5 = 2(나머지 버림)$
#### 2) $값 비교 = Array[2] 보다 Search_Key가 크냐? 작냐? 또는 같냐? = 크다$
#### 3) $중간 찾기 = (시작 위치 + 마지막 위치) / 2 = (3 + 5) / 2 = 4$
#### 4) $값 비교 = Array[4] 보다 Search_Key가 크냐? 작냐? 또는 같냐? = 작다$
#### 5) $중간 찾기 = (시작 위치 + 마지막 위치) / 2 = (3 + 3) / 2 = 3$
#### 6) $값 비교 = Array[3] 보다 Search_Key가 크냐? 작냐? 또는 같냐? = 크다$
#### 7) $예외 처리 = 시작 위치가 마지막 위치 크거나 마지막 위치가 시작 위치보다 작은 경우 값을 찾지 못한 것으로 간주하고 루프를 탈출$

### 3.3. [이진 검색 소스코드](../../source/DSNA/Search/mainBinarySearch.c)

### 3.4. 실행 결과
```shell
>SequentialIndexSearch.exe
Key-60, Index-3
Key-65 (Search Fail)
```
## 4. 이진 검색 트리(binary search tree)
- 검색을 위해 구현한 이진 트리, 이진 검색 원리를 트리로 구현
※이진 검색과 이진 검색 트리 비교※
|        |  이진 검색  | 이진 검색 트리 |
| :----: | :---------: | :------------: |
|  구분  |  알고리즘   |    자료구조    |
|  대상  | 정렬된 배열 |   이진 트리    |
| 공통점 |    검색     |      검색      |
- 효율적인 데이터 검색을 위해 기존 이진 트리에 몇 가지 제약 사항을 추가했다.

### 4.1. [이진 검색 트리란?](/markdown/DataStructure/BinarySearchTree.md)