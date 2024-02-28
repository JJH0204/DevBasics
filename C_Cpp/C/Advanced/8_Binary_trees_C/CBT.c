// Complete Binary Tree (CBT).c
/*배열을 응용한 완전 이진 트리 구현*/

#include <stdio.h>
#include <stdlib.h>

/*Node Structure Type Definitions*/
typedef struct Tree
{
    int _val;
    struct Tree *P_left;
    struct Tree *P_right;
} BTree;

/*Define a complete binary tree structure*/
// typedef struct Complete_Binary_Tree
// {
//     Node_t * P_root;
//     unsigned int _level;
// } Tree;

/*Define structures for Queue implementation*/
typedef struct Queue
{
    BTree *P_val;
    struct Queue *P_next;
} Queue;

/*Queue Function*/
void push(Queue ** head, BTree *_val);
BTree * pop(Queue ** head);

/*Tree Function*/
// Tree * new_tree(void);
void insert(BTree **_tree, int _val);
BTree **BFS(BTree *_root);
void print_tree(BTree *_tree);

int main (void)
{
    /*Tree Dynamic Assignment*/
    // Tree * Binary_Tree = new_tree();
    BTree *root = NULL;

    /*TODO: Insert data in to tree*/
    insert(&root, 10);       // root Node data
    // printf("%d", root->_val);
    insert(&root, 20);       // left Node from root Node
    // printf("%d", root->P_left->_val);
    insert(&root, 30);       // right Node from root Node
    // printf("%d", root->P_right->_val);
    insert(&root, 40);       // After Repetition
    printf("%d", root->P_left->P_left->_val);
    insert(&root, 50);
    printf("%d", root->P_left->P_right->_val);
    // insert(&root, 60);
    // insert(&root, 70);
    // insert(&root, 80);

    /*TODO: Print all data of tree*/
    // print_tree(root);

    return 0;
}

/*functions related to queues*/
void push(Queue ** _head, BTree * _val)
{
    if (_head == NULL)
    {
        return;
    }
    
    Queue * current = NULL;
    Queue * newQueue = (Queue *)malloc(sizeof(Queue));
    newQueue->P_val = _val;
    newQueue->P_next = NULL;

    if ((*_head) == NULL)
    {
        (*_head) = newQueue;
    }
    else
    {
        current = (*_head);

        while (current->P_next != NULL)
        {
            current = current->P_next;
        }
        current->P_next = newQueue;
    }
}

BTree* pop(Queue ** _head)
{
    if (_head == NULL || (*_head) == NULL)
    {
        printf("Queue is NULL\n");
        return NULL;
    }

    Queue * current = (*_head)->P_next;
    BTree * pop_val = (*_head)->P_val;
    free((*_head));
    (*_head) = current;

    return pop_val;
}

/*Function of allocate new tree*/
// Tree * new_tree(void)
// {
//     Tree * new_Tree = (Tree*)malloc(sizeof(Tree));
//     new_Tree->P_root=NULL;
//     new_Tree->_level=0;
//     return new_Tree;
// }

/*Add Data Function*/
/*Browse the tree and find the empty node.*/
/*Browse rule*/
// 1. 뿌리 레벨부터 순차적으로 탐색한다.
// 2. 왼쪽 > 오른쪽 순으로 탐색한다.
// 3. 아직 탐색을 완료하지 못한 레벨이 있을 경우 다음 레벨로 이동하지 않는다.
void insert(BTree **_tree, int _val)
{
    // Queue * P_queue = NULL;
    BTree * newNode = NULL;
    BTree ** currentNode = NULL;

    if (_tree == NULL)
    {
        return;
    }

    /*Create a Node*/
    newNode = (BTree *)malloc(sizeof(BTree));
    newNode->_val = _val;
    newNode->P_left = NULL;
    newNode->P_right = NULL;

    /*case1: If the structure member variable P_root in the _tree points to Null*/
    if ((*_tree) == NULL)
    {
        (*_tree) = newNode;
    }
    /*case2: If there is a node that P_root points to*/
    else
    {
        currentNode = BFS((*_tree));
        (*currentNode) = newNode;
    }
    return;
}

/*아이디어: 넓이 우선 탐색(Queue 자료구조 사용)*/
BTree **BFS(BTree *_root)
{
    Queue *P_head = NULL;
    BTree *P_currnt = NULL;

    if (_root == NULL)
    {
        return NULL;
    }

    push(&P_head, _root);
    while (1)
    {
        P_currnt = pop(&P_head);
        if (P_currnt->P_left == NULL)
        {
            return &(P_currnt->P_left);
        }
        else if (P_currnt->P_right == NULL)
        {
            return &(P_currnt->P_right);
        }
        else
        {
            push(&P_head, P_currnt->P_left);
            push(&P_head, P_currnt->P_right);
        }
    }
}

// void print_tree(Tree * _tree)
// {

//     return;
// }