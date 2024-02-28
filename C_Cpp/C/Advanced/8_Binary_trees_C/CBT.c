// Complete Binary Tree (CBT).c
/*배열을 응용한 완전 이진 트리 구현*/

#include <stdio.h>
#include <stdlib.h>

/*Node Structure Type Definitions*/
typedef struct Node
{
    int _val;
    struct Node * P_left;
    struct Node * P_right;
} Node_t;

/*Define a complete binary tree structure*/
typedef struct Complete_Binary_Tree
{
    Node_t * P_root;
    unsigned int _level;
} Tree;

Tree * new_tree(void);
void insert(Tree * _tree, int _val);
void print_tree(Tree * _tree);

int main (void)
{
    /*Tree Dynamic Assignment*/
    Tree * Binary_Tree = new_tree();
    
    /*TODO: Insert data in to tree*/
    insert(Binary_Tree, 10);    // root Node data
    insert(Binary_Tree, 20);    // left Node from root Node
    insert(Binary_Tree, 30);    // right Node from root Node
    insert(Binary_Tree, 40);    // After Repetition
    insert(Binary_Tree, 50);
    insert(Binary_Tree, 60);
    insert(Binary_Tree, 70);
    insert(Binary_Tree, 80);

    /*TODO: Print all data of tree*/
    print_tree(Binary_Tree);

    return 0;
}

/*Function of allocate new tree*/
Tree * new_tree(void)
{
    Tree * new_Tree = (Tree*)malloc(sizeof(Tree));
    new_Tree->P_root=NULL;
    new_Tree->_level=0;
    return new_Tree;
}

/*Add Data Function*/
void insert(Tree * _tree, int _val)
{
    if (_tree == NULL)
    {
        return;
    }
    /*Create a Node*/
    Node_t * newNode = (Node_t*)malloc(sizeof(Node_t));
    newNode->_val = _val;
    newNode->P_left = NULL;
    newNode->P_right = NULL;

    /*case1: If the structure member variable P_root in the _tree points to Null*/
    if (_tree->P_root == NULL)
    {
        _tree->P_root = newNode;
    }
    /*case2: If there is a node that P_root points to*/
    else
    {
        /*Browse the tree and find the empty node.*/
        /*Browse rule*/
        //1. 뿌리 레벨부터 순차적으로 탐색한다.
        //2. 왼쪽 > 오른쪽 순으로 탐색한다.
        //3. 아직 탐색을 완료하지 못한 레벨이 있을 경우 다음 레벨로 이동하지 않는다.

        /*아이디어 1*/
        //1. 순차적인 탐색 및 데이터 저장을 위해 Node 타입의 큐를 생성한다.
        //2. 큐에 root 노드를 저장한다.
        //3. 큐에 저장된 노드에서 왼쪽(또는 오른쪽) 노드의 Null 여부를 확인한다.
        //3.1. 왼쪽(또는 오른쪽) 노드가 NULL 인 경우 새로 생성한 노드를 연결하고 반복 종료
        //3.2. 왼쪽(또는 오른쪽) 노드 중 NULL 포인터가 없는 경우 자식 노드를 큐에 추가하고 반복
        //4. 반복 종료 시 큐 할당을 모두 해제
    }
    
    
    
    return;
}

void print_tree(Tree * _tree)
{

    return;
}