# 연결 리스트 기초

## 연결 리스트 소개
링크드 리스트는 그 구현을 위해 포인터를 사용하는 동적 데이터 구조의 가장 우수하고 간단한 예이다. 그러나 포인터를 이해하는 것은 링크된 목록의 작동 방식을 이해하는 데 매우 중요하므로 포인터 튜토리얼을 건너뛰었다면 돌아가서 다시 실행해야 한다. 동적 메모리 할당 및 구조에 대해서도 잘 알고 있어야 합니다.

기본적으로, 링크된 리스트들은 배열의 임의의 지점으로부터 필요에 따라 성장하고 축소할 수 있는 배열로서 기능한다.

연결 리스트는 배열에 비해 몇 가지 장점이 있습니다:

1. Items can be added or removed from the middle of the list
2. here is no need to define an initial size

그러나 링크 리스트에는 몇 가지 단점이 있다:

1. There is no "random" access - it is impossible to reach the nth item in the array without first iterating over all items up until that item. This means we have to start from the beginning of the list and count how many times we advance in the list until we get to the desired item.
2. Dynamic memory allocation and pointers are required, which complicates the code and increases the risk of memory leaks and segment faults.
3. Linked lists have a much larger overhead over arrays, since linked list items are dynamically allocated (which is less efficient in memory usage) and each item in the list also must store an additional pointer.

## 연결 리스트란 무엇입니까?
연결 리스트는 동적으로 할당된 노드들의 세트로서, 각각의 노드가 하나의 값과 하나의 포인터를 포함하는 방식으로 배열된다. 포인터는 항상 목록의 다음 구성원을 가리킵니다. 포인터가 NULL이면 목록의 마지막 노드입니다.

연결 리스트는 목록의 첫 번째 항목을 가리키는 로컬 포인터 변수를 사용하여 유지된다.(헤더 포인터라고 한다.) 해당 포인터도 NULL이면 목록이 비어 있는 것으로 간주됩니다.

    ------------------------------              ------------------------------
    |              |             |            \ |              |             |
    |     DATA     |     NEXT    |--------------|     DATA     |     NEXT    |
    |              |             |            / |              |             |
    ------------------------------              ------------------------------
연결 리스트의 노드를 정의해 보겠습니다:

    typedef struct node {
        int val;
        struct node * next;
    } node_t;
Notice that we are defining the struct in a recursive manner, which is possible in C. Let's name our node type node_t.

이제 노드를 사용할 수 있습니다. 리스트의 첫 번째 항목(헤드라고 함)을 가리키는 로컬 변수를 만들어 보자.
    
    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    if (head == NULL) {
        return 1;
    }

    head->val = 1;
    head->next = NULL;
방금 리스트의 첫 번째 변수를 만들었습니다. 목록 채우기를 완료하려면 값을 설정하고 다음 항목을 비워 두어야 합니다. malloc함수가 NULL 값을 반환했는지 여부를 항상 확인해야 합니다.

목록 끝에 변수를 추가하려면 다음 포인터로 계속 이동하면 됩니다:

    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    head->val = 1;
    head->next = (node_t *) malloc(sizeof(node_t));
    head->next->val = 2;
    head->next->next = NULL;
계속할 수 있지만, 다음 항목이 Null을 가리키는 마지막 항목으로 이동해야 한다.

## 목록 순환
리스트의 모든 항목을 출력하는 기능을 구축해 봅시다. 이를 위해서는 현재 인쇄 중인 노드를 추적할 전류(current) 포인터를 사용해야 합니다. 노드의 값을 인쇄한 후 다음 노드로 현재 포인터를 설정하고 목록의 끝에 도달할 때까지 다시 인쇄합니다.

    void print_list(node_t * head) {
        node_t * current = head;

        while (current != NULL) {
            printf("%d\n", current->val);
            current = current->next;
        }
    }
## 리스트 끝에 항목 추가
연결 리스트의 모든 구성원들을 반복하기 위해, 우리는 전류(current)라고 불리는 포인터 변수를 사용한다. 헤드에서 시작하도록 설정한 다음 각 단계에서 마지막 리스트에 도달할 때까지 리스트의 다음 항목으로 포인터를 이동한다.

    void push(node_t * head, int val) {
        node_t * current = head;
        while (current->next != NULL) {
            current = current->next;
        }

        /* now we can add a new variable */
        current->next = (node_t *) malloc(sizeof(node_t));
        current->next->val = val;
        current->next->next = NULL;
    }
연결 리스트의 가장 적합한 사용 사례는 스택과 큐이며, 앞으로 구현할 것입니다:

## 리스트 맨 앞에 항목 추가 (pushing to the list)
목록의 처음에 추가하려면 다음을 수행해야 합니다:

1. 새 노드을 생성하고 값을 저장합니다
2. 새 노드을 연결하여 리스트의 헤드 노드를 가리킵니다
3. 리스트의 헤드노드를 새 노드으로 설정합니다

이렇게 하면 새 값으로 리스트에 대한 새 헤드가 생성되고 나머지 리스트는 연결된 상태를 유지합니다.

함수를 사용하여 헤더 변수를 수정할 수 있어야 하기 때문에 인수로 포인터 변수(이중 포인터)에 포인터를 전달해야 포인터 자체를 수정할 수 있다.

    void push(node_t ** head, int val) {
        node_t * new_node;
        new_node = (node_t *) malloc(sizeof(node_t));

        new_node->val = val;
        new_node->next = *head;
        *head = new_node;
    }

## 첫 번째 항목 제거 (popping from the list)
변수를 제거하려면 다음 작업(Push)을 반대로 수행해야 합니다:

1. 머리가 가리키는 다음 항목을 가져가서 저장합니다
2. 헤드 항목을 해제합니다
3. 머리를 옆에 보관한 다음 항목으로 설정합니다

코드는 다음과 같습니다:

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
## 목록의 마지막 항목 제거
목록에서 마지막 항목을 제거하는 것은 목록 끝에 항목을 추가하는 것과 매우 유사하지만 한 가지 큰 예외가 있습니다 - 마지막 항목 이전에 한 항목을 변경해야 하기 때문에 실제로 두 항목을 미리 살펴보고 다음 항목이 목록의 마지막 항목인지 확인해야 합니다:

    int remove_last(node_t * head) {
        int retval = 0;
        /* if there is only one item in the list, remove it */
        if (head->next == NULL) {
            retval = head->val;
            free(head);
            return retval;
        }

        /* get to the second to last node in the list */
        node_t * current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }

        /* now current points to the second to last item of the list, so let's remove current->next */
        retval = current->next->val;
        free(current->next);
        current->next = NULL;
        return retval;

    }
## 특정 항목 제거
목록에서 특정 항목을 제거하려면 목록의 처음부터 해당 항목의 인덱스 또는 해당 값으로 제거하려면 모든 항목을 검토하고 제거하려는 항목 이전에 노드에 도달했는지 여부를 계속해서 확인해야 합니다. 이전 노드가 가리키는 위치로 위치도 변경해야 하기 때문입니다.

알고리즘은 다음과 같습니다:

1. 삭제할 노드 이전의 노드를 반복합니다
2. 삭제할 노드를 임시 포인터에 저장합니다
3. 삭제할 노드 뒤에 있는 노드를 가리키도록 이전 노드의 다음 포인터 설정
4. 임시 포인터를 사용하여 노드 삭제

저희가 처리해야 할 엣지 케이스가 몇 개 있으니 코드를 이해했는지 확인하세요.

    int remove_by_index(node_t ** head, int n) {
        int i = 0;
        int retval = -1;
        node_t * current = *head;
        node_t * temp_node = NULL;

        if (n == 0) {
            return pop(head);
        }

        for (i = 0; i < n-1; i++) {
            if (current->next == NULL) {
                return -1;
            }
            current = current->next;
        }

        if (current->next == NULL) {
            return -1;
        }

        temp_node = current->next;
        retval = temp_node->val;
        current->next = temp_node->next;
        free(temp_node);

        return retval;

    }