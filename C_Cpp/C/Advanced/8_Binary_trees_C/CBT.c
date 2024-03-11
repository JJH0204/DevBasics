// Complete Binary Tree (CBT).c
#include <stdio.h>
#include <stdlib.h>

/*Node Structure Type Definitions*/
typedef struct Tree
{
    int _val;
    struct Tree *P_left;
    struct Tree *P_right;
} BTree;

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
void insert(BTree **_tree, int _val);
BTree **BFS(BTree *_root);
void print_tree(BTree *_tree);

int main (void)
{
    /*Tree Dynamic Assignment*/
    BTree *root = NULL;

    /*Insert data in to tree*/
    insert(&root, 10);       
    insert(&root, 20);       
    insert(&root, 30);       
    insert(&root, 40);       
    insert(&root, 50);
    insert(&root, 60);
    insert(&root, 70);
    insert(&root, 80);

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
/*Add Data Function*/
void insert(BTree **_tree, int _val)
{
    BTree * newNode = NULL;
    BTree ** currentNode = NULL;

    if (_tree == NULL)
    {
        return;
    }

    newNode = (BTree *)malloc(sizeof(BTree));
    newNode->_val = _val;
    newNode->P_left = NULL;
    newNode->P_right = NULL;

    if ((*_tree) == NULL)
    {
        (*_tree) = newNode;
    }
    else
    {
        currentNode = BFS((*_tree));
        (*currentNode) = newNode;
    }
    return;
}

/*Idea: Breadth-First Search (using Queue data structures)*/
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

void print_tree(BTree *_tree)
{
    /*TODO: 트리 출력 BST*/
    return;
}