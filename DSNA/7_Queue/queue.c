// queue.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ISNULL(ptr) isnull((ptr), __func__)
// 매크로 함수 테스트
void isNull(const void *ptr, const char *funcName)
{
    if (ptr == NULL)
    {
        printf("%s: Null Memory Access\n", funcName);
        return true;
    }
    return false;
}

typedef struct QueueNode
{

} node;

typedef struct Queue
{

} queue;

// TODO: Implement and verify functions so that the code below operates properly
int main(int argc, char * argv[])
{
    queue *pQueue = NULL;
    node *pNode = NULL;

    pQueue = createQueue();
    if (pQueue == NULL)
    {
        printf("Memory allocation error\n");
        return -1;
    }
    enqueue(pQueue, 'A');
    enqueue(pQueue, 'B');
    enqueue(pQueue, 'C');
    enqueue(pQueue, 'D');
    displayQueue(pQueue);

    pNode = dequeue(pQueue);
    if (pNode != NULL)
    {
        printf("dequeue value - [%c]\n", pNode->cData);
        free(pNode);
    }
    displayQueue(pQueue);

    enqueue(pQueue, 'E');
    displayQueue(pQueue);
    
    deleteQueue(pQueue);
    return 0;
}
/* Target output result
Current node count: 4
    [0]-[A]
    [1]-[B]
    [2]-[C]
    [3]-[D]
> Dequeue value - [A]
Current node count: 3
    [0]-[B]
    [1]-[C]
    [2]-[D]
> Peek value - [B]
Current node count: 3
    [0]-[B]
    [1]-[C]
    [2]-[D]
Current node count: 4
    [0]-[B]
    [1]-[C]
    [2]-[D]
    [3]-[E]
*/