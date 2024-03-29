# 트리란?
```
        g                  s                  9
       / \                / \                / \
      b   m              f   u              5   13
     / \                    / \                /  \
    c   d                  t   y              11  15
```
- 나무 구조 혹은 나무 자료구조라고 한다.(보통은 그냥 트리라고 함)
- 데이터를 **계층 구조**(Hierarchical structure)로 저장한다.
- **다음 노드는 여러 개 연결될 수 있지만, 이전 노드는 단 한 개**
- 계층 구조를 **부모-자식(parent-child)구조**라고도 한다.
- 조직도 같은 현실에서 계층 구조를 갖는 시스템을 표현하는데 유용하다.
- 비선형구조(non-linear)이다.

## 1. 용어
> 트리(tree)는 계층 구조를 가지는 노드(node)와 간선(edge)의 집합이다.   
- 노드(node): 데이터를 저장하기 위한 단위
- 간선(edge): 노드 사이를 연결하는 선
### 1.1. 노드 종류
<details open> 
<summary>트리에서의 위치 기준</summary>
<div markdown="1">

| 용어                         | 내용                  |
| :--------------------------- | :-------------------- |
| 루트(root)노드               | 트리의 첫 번째 노드   |
| 단말(leaf 혹은 terminal)노드 | 자식 노드가 없는 노드 |
| 내부(internal)노드           | 자식 노드가 있는 노드 |

</div>
</details>

<details open>
<summary>노드 사이의 관계 기준</summary>
<div markdown="1">

| 용어                 | 내용                                                  |
| :------------------- | :---------------------------------------------------- |
| 부모(parent)노드     | 부모 노드와 자식 노드는 간선(edge)으로 연결되어 있음  |
| 자식(child)노드      | 부모 노드와 자식 노드는 간선(edge)으로 연결되어 있음  |
| 선조(ancestor)노드   | 루트 노드부터 부모 노드까지의 경로상에 있는 모든 노드 |
| 후손(descendent)노드 | 특정 노드의 아럐에 있는 모든 노드                     |
| 형제(sibling)노드    | 같은 부모 노드의 자식 노드                            |

</div>
</details>

### 1.2. 노드 속성
| 용어         | 내용                                                             |
| :----------- | :--------------------------------------------------------------- |
| 레벨(Level)  | 루트 노드부터의 거리                                             |
| 높이(height) | 루트 노드부터 가장 먼 거리에 있는 자식 노드의 높이에 1을 더한 값 |
| 차수(degree) | 한 노드가 가지는 자식 노드의 개수                                |

### 1.3. 기타 용어
- 서브트리(subtree):
  - 노드들의 부분 집합을 일컷는 말
- 포리스트(forest): 
  - 숲 구조 또는 숲 자료구조라고 함, 트리의 집합을 의미한다.
  - 루트 노드의 개수를 기준으로 트리와 포리스트를 분류
  - 트리는 단 1개의 루트 노드를 갖지만, 포리스트는 n개의 루트 노드를 갖는다.

## 2. 이진 트리
- 모든 트리 노드 차수가 2이하로 제한된 트리(일반적인 트리는 제한이 없다.)
- 따라서 **자식 노드를 최대 2개까지만 가질 수 있는 트리**
- 일반적인 트리에 비해 구조가 간단
- 검색, 계산 알고리즘에서 많이 활용

> [tip.] 트리의 노드와 간선 개수의 관계 => 트리에서 노드 개수가 n개일 때, 간선의 개수 = n - 1   

### 2.1. 이진 트리의 종류
- 어떤 모양을 가지는지에 따라 알고리즘 성능이 달라진다.
- 트리의 형태는 레벨과 노드 수에 따라 결정된다.
- 이진 트리의 형태는 크게 4 종류로 분류한다.
- [포화 이진 트리](FullBinaryTree.md), [완전 이진 트리](CompleteBinaryTree.md), [편향 이진 트리](SkewedBinaryTree.md), [이진 검색 트리](BinarySearchTree.md)
- 트리의 형태에 따라 이진 트리의 노드 개수를 계산할 수 있다.
> 1) 높이가 h인 이진 트리가 가질 수 있는 최소 노드의 개수는 [편향 이진 트리](SkewedBinaryTree.md)로 구할 수있다.
> 2) 최대 노드의 개수는 [포화 이진 트리](FullBinaryTree.md)에서 구할 수있다.
- 위 두 사항을 종합하여 노드 개수 $n$의 범위를 구하면 $h <= n <= (n^h-1)$
  - $n$: 높이가 $h$인 이진 트리의 노드 개수
- 최솟값은 편향 이진 트리의 노드 개수이며 최댓값은 포화 이진 트리의 노드 개수
### 2.2. 이진 트리의 추상자료형
| name                | input            | output             | desc                                       |
| :------------------ | :--------------- | :----------------- | :----------------------------------------- |
| makeBinTree()       | data             | binTree            | data를 갖는 rootNode로 구성된 binTree 생성 |
| getRootNode()       | binTree          | rootNode           | binTree의 rootNode 반환                    |
| addLeftChildNode()  | parentNode, data | add_leftChildNode  | parentNode의 leftChildNode 추가            |
| addRightChildNode() | parentNode, data | add_rightChildNode | parentNode의 rightChildNode 추가           |
| getLeftChildNode()  | parentNode       | leftChildNode      | parentNode의 leftChildNode 반환            |
| getRightChildNode() | parentNode       | rightChildNode     | parentNode의 rightChildNode 반환           |
| getData()           | binTree          | data               | binTree의 rootNode의 data 반환             |
| deleteBinTree()     | binTree          | N/A                | free(binTree)                              |



### 2.3. [배열 이진 트리](ArrayBinaryTree.md)

### 2.4. 포인터 이진 트리
- 노드 사이의 간선(edge, 연결정보)를 포인터로 구현한 이진 트리
- 연결 이진 트리(Linked binary tree)라고도 한다.
- [배열 이진 트리](ArrayBinaryTree.md)와 달리 노드 개수 만큼 메모리를 할당하기 때문에 메모리 효율성이 상대적으로 우수하다.
- 단, 노드의 탐색과 메모리 관리 측면에서 구현이 어려워진다.

#### 2.4.1. 구조
```c
typedef struct BinaryTreeNode
{
    char cData;
    
    struct TreeNode *pLeftChild;
    struct TreeNode *pRightChild;
} node;

typedef struct BinaryTree
{
    node *pRootNode;
} tree;
```

#### 2.4.2. 생성
```c
tree * createBinTree(const char _cRootNodeData_)
{
    tree *pResult = NULL;
    pResult = (tree *)malloc(sizeof(tree));
    if (ISNULL(pResult))
        return NULL;
    
    pResult->pRootNode = createNodeBinTree(_cRootNodeData_);
    if (ISNULL(pResult))
    {
        free(pResult);
        return NULL;
    }
    return pResult;
}

node * createNodeBinTree(const char _cRootNodeData_)
{
    node * pResult = NULL;
    pResult = (node *)malloc(sizeof(node));
    if (ISNULL(pResult))
        return NULL;
    pResult->cData = _cRootNodeData_;
    pResult->pLeftChild = NULL;
    pResult->pRightChild = NULL;
    return pResult;
}
```

#### 2.4.3. 자식 노드 추가
```c
node * addLeftChildNode(node * _pParent_, const char _cData_)
{
    node *pResult = NULL;
    if (ISNULL(_pParent_))
        return pResult;
    if (ISNULL(_pParent_->pLeftChild))
    {
        pResult = createNodeBinTree(_cData_);
        _pParent_->pLeftChild = pResult;
    }
    else
        printf("error, The node already exists. addLeftChildNode()\n");
    return pResult;
}

node * addRightChildNode(node * _pParent_, const char _cData_)
{
    node *pResult = NULL;
    if (ISNULL(_pParent_))
        return pResult;
    if (ISNULL(_pParent_->pRightChild))
    {
        pResult = createNodeBinTree(_cData_);
        _pParent_->pRightChild = pResult;
    }
    else
        printf("error, The node already exists. addLeftChildNode()\n");
    return pResult;
}
```
> 추가된 자식 노드를 pResult로 반환, 반환된 노드를 이용해 반환된 노드의 자식 노드를 추가할 수 있게 된다.  
> 새로운 노드를 찾기 위한 추가 작업을 최소화 하기 위한 조치   

#### 2.4.4. 그 외 연산들

```c
node * getRootNode(const tree * _pBinTree_)
{
    node *pResult = NULL;
    if (ISNULL(_pBinTree_))
        return NULL;
    pResult = _pBinTree_->pRootNode;
    return pResult;
}

bool deleteBinTree(tree * _pBinTree_)
{
    if (ISNULL(_pBinTree_))
        return true;
    deleteBinTreeNode(_pBinTree_->pRootNode);
    free(_pBinTree_);
    return false;
}

bool deleteBinTreeNode(node * _pParent_)
{
    if (ISNULL(_pParent_))
        return true;
    deleteBinTreeNode(_pParent_->pLeftChild);
    deleteBinTreeNode(_pParent_->pRightChild);
    free(_pParent_);
    return false;
}
```
> getRootNode(): 인자로 전달 받은 트리의 루트 노드를 반환하는 함수   

> deleteBinTree(): 
> - 인자로 전달 받은 트리를 메모리에서 삭제(할당 해제)하는 함수   
> - 트리 노드를 할당 해제하기 전 루트 노드를 기준으로 손자노드들을 모두 할당 해제한 후 트리를 할당 해제 하기 위해 deleteBinTreeNode()를 호출함   

> deleteBinTreeNode():
> - 재귀함수로 인자로 전달 받은 부모 노드에 자식이 있을 경우 자식을 인자로 deleteBinTreeNode()를 호출   
> - 인자로 받은 pParent가 NULL 인지 체크하는 것으로 재귀 탈출 조건을 설정   

#### 2.4.5. main()
```c
int main (int argc, char * argv[])
{
    tree *pTree = NULL;
    node *pNodeA = NULL;
    node *pNodeB = NULL;
    node *pNodeC = NULL;
    node *pNodeD = NULL;
    node *pNodeE = NULL;
    node *pNodeF = NULL;

    pTree = createBinTree('A');
    if (!ISNULL(pTree))
    {
        pNodeA = getRootNode(pTree);
        pNodeB = addLeftChildNode(pNodeA, 'B');
        pNodeC = addRightChildNode(pNodeA, 'B');
    }

    if (!ISNULL(pNodeB))
    {
        pNodeD = addLeftChildNode(pNodeB, 'D');
    }

    if (!ISNULL(pNodeC))
    {
        pNodeE = addLeftChildNode(pNodeC, 'E');
        pNodeF = addRightChildNode(pNodeC, 'F');
    }
    
    deleteBinTree(pTree);
    
    return 0;
}
```
> 위 main()는 지금까지 구현한 트리 함수를 활용해 문자를 트리에 저장하는 과정을 보여준다.   
> 저장에 문제는 없었지만 아쉽게도 트리의 형태를 직접 볼 수는 없다. (display함수가 없다.)   
> 트리의 내용을 출력하기 위해 이진 트리의 내용을 어떤 순서에 따라서 순회 할지 결정해야 한다.

## 3. 이진 트리의 순회(Traversal) 또는 탐색(Search)에 대하여
- 트리를 구현하는 것 보다 어떻게 활용할지가 더 중요하다.
- 트리를 활용하기 위해서는 트리 내부의 노드들에 접근하는 로직이 필요하다.
- 트리의 계층 구조의 특성으로 인해 모든 노드를 1회 이상 접근하기 위한 여러 알고리즘이 있다.
- 원하는 결과물을 얻기 위해 아래 알고리즘들 중 필요한 것을 차용하면 된다.
- 아래 소개하는 알고리즘들은 트리를 대상으로 한 많은 알고리즘의 기반(트리 내용 출력, 노드 개수 구하기 등등)이다.
- 또한, 이후 설명하는 히프(또는 그래프)에서 트리를 사용할 때 사용하게 되는 알고리즘들이다.

### 3.1. 깊이 우선 탐색(Depth-first search, DFS)
- 서브트리 방문 순서가 핵심인 알고리즘
- 리프 노드(leaf node)까지 내려가면서 검색하는 것을 의미한다.
- 리프에 도달할 때까지 탐색을 진행하고, 더 이상 검색할 곳이 없을 때 이전(부모)노드로 되돌아간다.
- 그리고, 가능한 다른 자식 노드로 다시 내려가 탐색을 계속합니다.
- 이러한 과정은 모든 노드를 방문할 때 까지 반복된다.
- 대표로 전위 순회(preorder), 중위 순회(inorder), 후위 순회(postorder) 가 있다.
- 주요 특징
  - **스택(Stack) 또는 재귀 호출(Recursive Calls)응용**: 스택을 사용하는 경우, 방문한 노드를 스택에 푸시(push)하고, 더 이상 탐색할 자식 노드가 없으면 스택에서 팝(pop)하여 되돌아 간다. 재귀 호출을 사용하는 경우, 함수가 자기 자신을 호출하여 노드를 방문하는 방식으로 탐색을 진행
  - **모든 노드를 방문할 수 있다는 점에서 완전 탐색 방법**: 특히, 미로 찾기와 같은 문제 해결에 유용하게 사용된다.
  - **경로의 특성을 파악하거나, 특정 노드로부터 가능한 모든 경로를 찾아내는 데 적합**: 예를 들어, 그래프 내의 사이클(cycle)을 탐지하거나, 두 노드 사이의 경로를 찾는 데 사용될 수 있습니다.
- 탐색의 순서나 선택하는 경로에 따라 탐색의 효율성이 달라 질 수 있으며, 탐색 과정에서 방문한 노드의 경로를 기록하는 방법으로 다양한 문제 해결 전략을 구현할 수 있다. 
<details open>
<summary>전위 순회(Pre-Order Traversal)</summary>
<div markdown="1">  

- 현재 노드를 가장 먼저 방문(pre-order)하여 데이터를 처리하고 이동하는 방법
- 노드 방문 순서: 1)현재 노드, 2)왼쪽 서브트리, 3)오른쪽 서브트리
- 순회 목적에 따라 연산이 달라질 수 있다.(트리 내용 출력이 목적이라면 현재 노드 방문 시 내용 출력)
- 노드에 방문 하여 데이터를 처리한 후 왼쪽 자식 노드로 이동하여 데이터 처리를 진행한다.
- 만약 자식이 없는 단말 노드의 경우 같은 레벨의 형제 노드(오른쪽 노드) 로 이동하여 데이터를 처리한다.
- 현재 노드에서 더 이상 후손 노드에 처리할 데이터가 남지 않았을 때도 같은 레벨의 형제 노드로 이동하여 위 과정을 반복한다.

```c
// Pre-Order Traversal Func
bool traversalPreorder(tree *_pTree_)
{
    if (ISNULL_ERROR(_pTree_))
        return true;
    traversalPreorderBinTreeNode(_pTree_->pRootNode);
    printf("\n");
    return false;
}

bool traversalPreorderBinTreeNode(node *_pRootNode_)
{
    if (_pRootNode_ == NULL)
        return true;
    printf("%c ", _pRootNode_->cData);
    traversalPreorderBinTreeNode(_pRootNode_->pLeftChild);
    traversalPreorderBinTreeNode(_pRootNode_->pRightChild);
    return false;
}
```
```c
// Use Stack
bool traversalPreorder(binTree *_pTree_)
{
    binTreeNode *pNode = NULL;
    stack *pStack = NULL;
    if (ISNULL_ERROR(_pTree_))
        return true;

    pNode = _pTree_->pRootNode;
    if (ISNULL_ERROR(pNode))
        return true;

    pStack = stack_Create();
    if (ISNULL_ERROR(pStack))
        return true;

    stack_Push(pStack, (binTreeNode *)pNode);
    while (pStack->nCurrentCount > 0)
    {
        pNode = (binTreeNode *)stack_Pop(pStack);
        printf("%c ", pNode->cData);
        if (pNode->pRightChild != NULL)
            stack_Push(pStack, (binTreeNode *)pNode->pRightChild);
        if (pNode->pLeftChild != NULL)
            stack_Push(pStack, (binTreeNode *)pNode->pLeftChild);
    }
    printf("\n");
    stack_Delete(pStack);
    return false;
}
```
</div>
</details>

<details open>
<summary>중위 순회(In-Order Traversal)</summary>
<div markdown="1">  

- 현재 노드를 왼쪽 서브트리를 처리한 후에 처리하는 방법
- 노드 방문 순서: 1)왼쪽 서브트리, 2)현재 노드, 3)오른쪽 서브트리
- **현재 노드를 기준으로 왼쪽 서브트리가 모두 처리 되어야 하는 점이 핵심**
- 만약 현재 노드의 왼쪽 자식 노드가 있다면, 왼쪽 자식 노드가 더 이상 없을 때까지 왼쪽 서브트리로 계속 이동
- 왼쪽 자식 노드의 데이터가 단말 노드일 경우 데이터 처리 > 부모 노드로 이동하여 데이터 처리 > 오른쪽 자식 노드로 이동 순으로 순차적으로 진행한다.
```c
// In-Order Traversal Func
bool traversalInorder(tree *_pTree_)
{
    if (ISNULL_ERROR(_pTree_))
        return true;
    traversalInorderBinTreeNode(_pTree_->pRootNode);
    printf("\n");
    return false;
}

bool traversalInorderBinTreeNode(node *_pRootNode_)
{
    if (_pRootNode_ == NULL)
        return true;
    traversalInorderBinTreeNode(_pRootNode_->pLeftChild);
    printf("%c ", _pRootNode_->cData);
    traversalInorderBinTreeNode(_pRootNode_->pRightChild);
    return false;
}
```
```c
// use stack
bool traversalInorder(binTree *_pTree_)
{
    binTreeNode *pNode = NULL;
    stack *pStack = NULL;
    if (ISNULL_ERROR(_pTree_))
        return true;

    pNode = _pTree_->pRootNode;
    if (ISNULL_ERROR(pNode))
        return true;

    pStack = stack_Create();
    if (ISNULL_ERROR(pStack))
        return true;

    while (pNode != NULL || pStack->nCurrentCount > 0)
    {
        // 왼쪽 리프 노드를 향해 이동
        while (pNode != NULL)
        {
            stack_Push(pStack, (binTreeNode *)pNode);
            pNode = pNode->pLeftChild;
        }

        // pNode가 NULL이면 stack에서 pop
        pNode = (binTreeNode *)stack_Pop(pStack);
        printf("%c ", pNode->cData);

        // 오른쪽 서브 트리로 이동
        pNode = pNode->pRightChild;
    }
    stack_Delete(pStack);
    printf("\n");
    return false;
}
```

</div>
</details>

<details open>
<summary>후위 순회(Post-Order Traversal)</summary>
<div markdown="1">  

- 현재 노드의 데이터를 가장 마지막에 처리하는 방법
- 노드 방문 순서: 1)왼쪽 서브트리, 2)오른쪽 서브트리, 3)현재 노드
- 현재 노드의 데이터를 처리하기 전 좌우 자식 노드를 루트 노드로 삼는 두 서브트리를 모두 처리한 해야 한다.
- 현재 노드의 왼쪽 자식 노드가 있다면 왼쪽 자식 노드가 더 이상 없을 때까지 왼쪽 서브트리로 계속 이동한다. (중위 순회와 같은 점)
- 왼쪽 자식 노드를 방문한 다음 오른쪽 서브트리로 이동한다.(중위 순회와 다른 점)
- 자식이 없는 단말 노드의 데이터 처리가 끝나면 해당 서브트리의 방문이 끝난 것으로 판단, 부모 노드로 이동한다.
- 이전에 처리한 좌,우 자식 노드는 다시 처리할 필요가 없다.
```c
// Post-Order Traversal Func
bool traversalPostorder(tree *_pTree_)
{
    if (ISNULL_ERROR(_pTree_))
        return true;
    traversalPostorderBinTreeNode(_pTree_->pRootNode);
    printf("\n");
    return false;
}

bool traversalPostorderBinTreeNode(node *_pRootNode_)
{
    if (_pRootNode_ == NULL)
        return true;
    traversalPostorderBinTreeNode(_pRootNode_->pLeftChild);
    traversalPostorderBinTreeNode(_pRootNode_->pRightChild);
    printf("%c ", _pRootNode_->cData);
    return false;
}
```
```c
// use stack
bool traversalPostorder(binTree *_pTree_)
{
    binTreeNode *pNode = NULL;
    stack *pStack = NULL;
    if (ISNULL_ERROR(_pTree_))
        return true;

    pNode = _pTree_->pRootNode;
    if (ISNULL_ERROR(pNode))
        return true;

    pStack = stack_Create();
    if (ISNULL_ERROR(pStack))
        return true;

    while (pNode != NULL || pStack->nCurrentCount > 0)
    {
        if (pNode != NULL)
        {
            if (pNode->pRightChild != NULL)
                stack_Push(pStack, (binTreeNode *)pNode->pRightChild);
            stack_Push(pStack, (binTreeNode *)pNode);
            pNode = pNode->pLeftChild;
        }
        else
        {
            pNode = (binTreeNode *)stack_Pop(pStack);
            if (pStack->nCurrentCount > 0 && pNode->pRightChild == (binTreeNode *)stack_Peek(pStack))
            {
                stack_Pop(pStack);
                stack_Push(pStack, (binTreeNode *)pNode);
                pNode = pNode->pRightChild;
            }
            else
            {
                printf("%c ", pNode->cData);
                pNode = NULL;
            }
        }
    }

    printf("\n");
    stack_Delete(pStack);
    return false;
}
```

</div>
</details>

### 3.2. 너비 우선 탐색 (Breadth-first Search, BFS)
- 너비 우선 탐색(또는 레벨 순회, Level Traversal)은 레벨 크기에 따라 트리 내부를 순회하는 방법을 의미한다.
- 낮은 레벨 > 높은 레벨 순으로 노드의 데이터를 처리한다.
- 같은 레벨일 경우 왼쪽 > 오른쪽 순으로 데이터를 처리한다.
- 형제 노드의 데이터 처리가 핵심, 비교적 순회 순서를 정하기 쉽다.
- 탐색 순서를 관리하는 목적으로 큐를 사용한다.
- 너비 우선 탐색의 기본적인 알고리즘은 다음과 같습니다.
> 1. 탐색을 시작할 루트 노드를 큐에 삽입합니다.
> 2. 큐가 비어있지 않는 한 다음의 단계를 반복합니다.
>    * 큐에서 노드를 하나 꺼냅니다.
>    * 해당 노드를 처리합니다. (기능 수행)
>    * 해당 노드의 왼쪽 자식 노드와 오른쪽 자식 노드가 있으면, 이 노드들을 큐에 삽입합니다.
```c
// breadth-first search (level traversal)
bool BreadthFirstSearch(binTree *_pTree_)
{
    binTreeNode *pCurrentNode = NULL;
    queue *pQueue = NULL;
    if (ISNULL_ERROR(_pTree_))
        return true;

    pCurrentNode = _pTree_->pRootNode;
    if (ISNULL_ERROR(pCurrentNode))
        return true;

    pQueue = queue_Create();
    if (ISNULL_ERROR(pQueue))
        return true;
    
    while (pCurrentNode != NULL || pQueue->nCurrentCount > 0)
    {
        if (pQueue->nCurrentCount > 0)
        {
            pCurrentNode = (binTreeNode *)queue_dequeue(pQueue);
            printf("%c ", pCurrentNode->cData);
            if (pCurrentNode->pLeftChild != NULL)
                queue_enqueue(pQueue, (binTreeNode *)pCurrentNode->pLeftChild);
            if (pCurrentNode->pRightChild != NULL)
                queue_enqueue(pQueue, (binTreeNode *)pCurrentNode->pRightChild);
        }
        else
            queue_enqueue(pQueue, (binTreeNode *)pCurrentNode);
        pCurrentNode = NULL;
    }
    printf("\n");
    queue_Delete(pQueue);
    return false;
}
```
