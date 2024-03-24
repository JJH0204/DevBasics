// Exercise_LinkedList.c
/*헤더에 대한 이중 포인터를 받고 값 값이 있는 목록의 첫 번째 항목을 제거하는 함수 remove_by_value를 구현해야 합니다.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

int pop(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

int remove_by_value(node_t ** head, int val) {
    /* TODO: fill in your code here */
    node_t * preNode = NULL;
    node_t * currentNode = NULL;

    if (*head == NULL)
    {
        return 0;
    }
    
    preNode = *head;
    currentNode = preNode->next;

    if (preNode->val == val)
    {
        *head = currentNode;
        free(preNode);
    }
    else
    {
        while (currentNode->val != val)
        {
            preNode = currentNode;
            currentNode = currentNode->next;
        }
        preNode->next = currentNode->next;
        free(currentNode);
    }
    return 0;
}

int main() {

    node_t * test_list = (node_t *) malloc(sizeof(node_t));
    test_list->val = 1;
    test_list->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->val = 2;
    test_list->next->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->next->val = 3;
    test_list->next->next->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->next->next->val = 4;
    test_list->next->next->next->next = NULL;

    remove_by_value(&test_list, 3);

    print_list(test_list);
}