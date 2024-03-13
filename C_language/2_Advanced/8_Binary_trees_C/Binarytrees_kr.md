# 이진 트리
## 소개
이진 트리(Binary Tree)는 각 노드가 최대 2개의 자식(왼쪽 자식과 오른쪽 자식)을 갖는 데이터 구조의 한 종류이다.
이진 트리는 이진 탐색 트리 및 이진 힙을 구현하기 위해 사용되며, 효율적인 탐색 및 정렬을 위해 사용된다.이진 트리는 K-ary 트리의 특수한 경우이며, 여기서 k는 2이다. 
이진 트리에 대한 일반적인 연산에는 삽입, 삭제, 순회가 포함된다. 이러한 연산을 수행하는 어려움은 트리가 균형 잡힌 경우와 노드가 리프 노드인지 분기 노드인지 여부에 따라 다양하다. 
균형 트리의 경우 모든 노드의 왼쪽 부분 트리와 오른쪽 부분 트리의 깊이는 1 이하 차이가 난다. 
이것은 높이라고도 알려진 예측 가능한 깊이를 허용한다. 
이것은 뿌리에서 잎까지의 노드의 척도이며, 여기서 뿌리는 0이고 세브후스 노드는 (1,2..n)이다. 
이는 log2(n)의 정수 부분으로 표현할 수 있으며, 여기서 n은 트리의 노드 수이다.

        g                  s                  9
       / \                / \                / \
      b   m              f   u              5   13
     / \                    / \                /  \
    c   d                  t   y              11  15
트리에서 수행되는 작업은 다음과 같은 두 가지 주요 방법 중 하나를 사용하여 검색해야 합니다: 
Depth First Search and Width-First Search. 
깊이 우선 검색(depth-first search, DFS)은 트리 또는 그래프 데이터 구조를 탐색하거나 탐색하기 위한 알고리즘이다. 
루트에서 시작하여 역추적하기 전에 각 분기를 따라 가능한 한 멀리 탐색한다. 
깊이 우선 탐색 경로에는 사전순차 방문, 좌, 우, 순서대로 좌, 방문, 우, 사후순차 좌, 우, 방문의 세 가지 유형이 있다. 
폭 우선 검색(BFS)은 트리 또는 그래프 구조를 탐색하거나 탐색하기 위한 알고리즘이다. 
레벨 순서대로, 우리가 더 낮은 레벨로 가기 전에 레벨의 모든 노드를 방문한다.

## 완전 이진 트리(Complete Binary Tree)
이진 트리의 한 종류로 모든 레벨이 노드로 가득 차 있고, 마지막 레벨을 제외한 모든 레벨이 완전히 채워져 있는 상태에서 마지막 레벨은 왼쪽부터 오른쪽으로 차례대로 채워지는 트리입니다.
마지막 레벨을 제외하고는 모든 노드가 자식 노드를 두 개씩 가집니다. 완전 이진 트리는 힙 정렬과 같은 알고리즘에서 사용됩니다.

## 이진 검색 트리(Binary Search Tree, BST)
이진 검색 트리는 특정 조건을 만족하는 이진 트리로, 어떤 노드 N을 기준으로 그 노드의 왼쪽 서브 트리에는 N의 키 값보다 작은 모든 키 값을 가진 노드들이, 오른쪽 서브 트리에는 N의 키 값보다 큰 모든 키 값을 가진 노드들이 위치하게 됩니다. 이진 검색 트리에서는 중위 순회를 수행하면 키 값을 오름차순으로 노드를 방문할 수 있습니다.

## 너비 우선 탐색(Breadth-First Search, BFS)
이진 트리의 탐색에 큐(Queue)사용하는 방법을 의미합니다. 각 레벨별로 노드를 방문하는 방식으로, 트리의 루트 노드부터 시작하여 왼쪽에서 오른쪽으로, 위에서 아래로 레벨별로 순차적으로 탐색합니다. 이 과정에서 큐를 사용하는 이유는 탐색 순서를 관리하기 위함입니다.


너비 우선 탐색의 기본적인 알고리즘은 다음과 같습니다.
1. 탐색을 시작할 루트 노드를 큐에 삽입합니다.
2. 큐가 비어있지 않는 한 다음의 단계를 반복합니다.
* 큐에서 노드를 하나 꺼냅니다.
* 해당 노드를 처리합니다. (기능 수행)
* 해당 노드의 왼쪽 자식 노드와 오른쪽 자식 노드가 있으면, 이 노드들을 큐에 삽입합니다.

이 방식은 모든 노드를 방문하며, 각 노드를 한 번씩 처리하기 때문에 완전 이진 트리뿐만 아니라 일반적인 이진 트리에서도 넓이(레벨)별로 탐색하는 데 매우 유용합니다.