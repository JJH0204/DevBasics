//LinkedLists.c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node * next;
} Node;

typedef struct LinkedLists
{
    unsigned int N_Count;
    Node * header;
} LinkedLists;

LinkedLists * NewList(void);
void Push(LinkedLists * List, int val, int AddPos);
Node * SearchNode (Node * headNode, int SearchType, int NodeNum);
void PrintList (LinkedLists * List);
void Pop(LinkedLists * List, int PopPos);
void Clear(LinkedLists ** List);

void Ex_Code_1(void)
{
    /*링크드 리스트 생성*/
    LinkedLists * List = NewList();

    if (List == NULL)
    {
        return;
    }
    

    /* TODO: Push, Add Data to Linked List*/
    Push(List, 1, -1);  //Push to Last Node
    Push(List, 10, 0);  //Push to First Node
    Push(List, 5, 1);   //Push to data you want position

    /* TODO: 리스트 출력*/
    PrintList(List);    // Print all list item 

    /* TODO: Pop, Removed list item*/
    Pop(List, 0);
    PrintList(List);
    Pop(List, 1);
    PrintList(List);
    printf("%d\n", List->N_Count);

    /* TODO: List All Clear*/
    Clear(&List);
    PrintList(List);

    return;
}

int main(void)
{
    Ex_Code_1();

    return 0;
}

LinkedLists * NewList(void)
{
    LinkedLists * newList = (LinkedLists *)malloc(sizeof(LinkedLists));
    
    newList->header=NULL;
    newList->N_Count=0;
    return newList;
}

void Push(LinkedLists * List, int val, int AddPos)
{
    Node * AddNode = NULL;
    Node * preNode = NULL;
    Node * NextNode = NULL;

    // List == NULL, STOP!!
    if (List == NULL)
    {
        return;
    }

    /*데이터 생성*/
    AddNode = (Node *)malloc(sizeof(Node));
    AddNode->next = NULL;
    AddNode->val = val;

    /*리스트 데이터 확인*/
    /*헤더 Node가 없을 때 바로 데이터 추가*/
    if (List->header == NULL)
    {
        List->header = AddNode;
    }
    /*리스트 가장 마지막에 데이터 추가*/
    else if (AddPos == -1)
    {
        preNode = SearchNode(List->header, -1, 0);

        if(preNode == NULL)
        {
            return;
        }
        preNode->next = AddNode;
    }
    /*리스트 헤더를 신규 노드로 변경*/
    else if (AddPos == 0)
    {
        preNode = List->header;
        List->header = AddNode;
        List->header->next = preNode;
    }
    /*AddPos 값으로 선택한 위치에 데이터 추가*/
    else
    {
        preNode = SearchNode(List->header, 1, AddPos - 1);
        if (preNode->next == NULL)
        {
            preNode->next = AddNode;
        }
        else
        {
            NextNode = preNode->next;
            preNode->next = AddNode;
            AddNode->next = NextNode;
        }
    }
    List->N_Count++;
}
Node * SearchNode (Node * headNode, int SearchType, int NodeNum)
{
    int i;
    //Node * PreNode = NULL;

    if (headNode == NULL)
    {
        return NULL;
    }

    //PreNode = headNode;
    /*리스트 가장 마지막*/
    if (SearchType == -1)
    {
        while (headNode->next != NULL)
        {
            headNode = headNode->next;
        }
        
    }
    /*정해진 리스트 위치*/
    else if (SearchType == 1)
    {
        for (i = 0; i < NodeNum; i++)
        {
            if (headNode->next == NULL)
            {
                break;
            }
            headNode = headNode->next;
        }
    }
    return headNode;
}
void PrintList (LinkedLists * List)
{
    Node * PrintNode = NULL;

    if (List == NULL || List->header == NULL)
    {
        printf("No List.\n");
        return;
    }

    PrintNode = List->header;

    while (PrintNode != NULL)
    {
        printf("%d ", PrintNode->val);
        PrintNode = PrintNode->next;
    }
    printf("\n");
}
void Pop(LinkedLists * List, int PopPos)
{
    Node * PopNode = NULL;
    Node * PreNode = NULL;
    Node * NextNode = NULL;

    if (List == NULL || List->header == NULL)
    {
        printf("List is free~.\n");
        return;
    }
    
    /*삭제하는 노드가 헤더인 경우*/
    if (PopPos == 0)
    {
        PopNode = List->header;
        List->header = PopNode->next;
        free(PopNode);
    }
    /*헤더가 아닌 경우*/
    else
    {
        PreNode = SearchNode(List->header, 1, PopPos - 1);

        if (PreNode == NULL || PreNode->next == NULL)
        {
            printf("Can't remove data!");
        }
        else
        {
            PopNode = PreNode->next;
            NextNode = PopNode->next;
            PreNode->next = NextNode;
            free(PopNode);
        }
    }
    List->N_Count--;
}
void Clear(LinkedLists ** List)
{
    LinkedLists * current_List = *List;
    Node * current_Node = current_List->header;
    Node * temp_Node = current_Node->next;

    free(current_List);

    while (temp_Node != NULL)
    {
        free(current_Node);
        current_Node = temp_Node;
        temp_Node = temp_Node->next;
    }
    
    printf("List All Clear~\n");
    return;
}