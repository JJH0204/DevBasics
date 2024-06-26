# 배열로 구현한 이진 트리
- 이진 트리의 각 노드를 배열에 저장했다는 의미
- 이진 트리의 루트 노드부터 그 후손 노드들을 왼쪽에서 오른쪽 순서대로 저장하는 방법을 많이 사용
- 배열의 첫 번째 인덱스는 비운다. 
  - 인덱스 1 부터 루트노드를 시작으로 순서대로 배열에 저장
- 배열로 구현한 이진 트리의 경우 노드 번호가 배열의 인덱스 역할을 한다.
  - 루트 노드의 1부터 시작하여 왼쪽에서 오른쪽으로 그리고 작은 레벨에서 큰 레벨로 이동하며 노드 번호가 차례로 1씩 증가한다.
- 이진 트리의 중간 노드가 없는 경우, 노드에 해당하는 배열의 칸은 그대로 비워둔다.
  - 노드 번호에 해당하는 배열의 인덱스 값은 고정되어 있기 때문
  - 해당 위치의 배열 원소뿐 아니라, 후손들의 위치에도 자료가 저장되지 않아야 한다.
- 배열 인덱스를 사용하여 노드 접근이 편리한 장점에 반해 빈 노드가 많을 경우 메모리 낭비가 심하다는 단점이 있다.
  - [편향 이진 트리](SkewedBinaryTree.md)의 경우 이 문제가 더 부각된다.
  - [완전 이진 트리](CompleteBinaryTree.md)와 같이 빈 노드가 적은 경우에 사용하는 것이 적합
- 배열로 높이가 $h$인 이진 트리를 저장할 경우, 최대 저장 노드 개수 보다 1 더 많게 $(2^h = 2^h - 1 + 1)$ 메모리를 할당해야 한다.
  - 배열의 첫번째 원소를 비워두기 때문
- 