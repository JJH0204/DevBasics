#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "includeBinTree.h"
#include "includeGenericStructure.h"

binTree *createBinTree(const char _cRootNodeData_)
{
    binTree *pResult = (binTree *)malloc(sizeof(binTree));
    if (ISNULL_ERROR(pResult))
        return NULL;

    pResult->pRootNode = createNodeBinTree(_cRootNodeData_);
    if (ISNULL_ERROR(pResult))
    {
        free(pResult);
        return NULL;
    }
    return pResult;
}

binTreeNode *createNodeBinTree(const char _cRootNodeData_)
{
    binTreeNode *pResult = NULL;
    pResult = (binTreeNode *)malloc(sizeof(binTreeNode));
    if (ISNULL_ERROR(pResult))
        return NULL;
    pResult->cData = _cRootNodeData_;
    pResult->pLeftChild = NULL;
    pResult->pRightChild = NULL;
    return pResult;
}

binTreeNode *addLeftChildNode(binTreeNode *_pParent_, const char _cData_)
{
    binTreeNode *pResult = NULL;
    if (ISNULL_ERROR(_pParent_))
        return pResult;
    if (_pParent_->pLeftChild == NULL)
    {
        pResult = createNodeBinTree(_cData_);
        _pParent_->pLeftChild = pResult;
    }
    else
        printf("error, The node already exists. addLeftChildNode()\n");
    return pResult;
}

binTreeNode *addRightChildNode(binTreeNode *_pParent_, const char _cData_)
{
    binTreeNode *pResult = NULL;
    if (ISNULL_ERROR(_pParent_))
        return pResult;
    if (_pParent_->pRightChild == NULL)
    {
        pResult = createNodeBinTree(_cData_);
        _pParent_->pRightChild = pResult;
    }
    else
        printf("error, The node already exists. addLeftChildNode()\n");
    return pResult;
}

binTreeNode *getRootNode(const binTree *_pBinTree_)
{
    binTreeNode *pResult = NULL;
    if (ISNULL_ERROR(_pBinTree_))
        return NULL;
    pResult = _pBinTree_->pRootNode;
    return pResult;
}

bool deleteBinTree(binTree *_pBinTree_)
{
    if (ISNULL_ERROR(_pBinTree_))
        return true;
    deleteBinTreeNode(_pBinTree_->pRootNode);
    free(_pBinTree_);
    return false;
}

bool deleteBinTreeNode(binTreeNode *_pParent_)
{
    if (!(_pParent_ == NULL))
    {
        deleteBinTreeNode(_pParent_->pLeftChild);
        deleteBinTreeNode(_pParent_->pRightChild);
        free(_pParent_);
    }
    return false;
}

#ifdef _UseRecursion_
// Pre-Order Traversal Func
bool traversalPreorder(binTree *_pTree_)
{
    if (ISNULL_ERROR(_pTree_))
        return true;
    traversalPreorderBinTreeNode(_pTree_->pRootNode);
    printf("\n");
    return false;
}

bool traversalPreorderBinTreeNode(binTreeNode *_pRootNode_)
{
    if (_pRootNode_ == NULL)
        return true;
    printf("%c ", _pRootNode_->cData);
    traversalPreorderBinTreeNode(_pRootNode_->pLeftChild);
    traversalPreorderBinTreeNode(_pRootNode_->pRightChild);
    return false;
}

// In-Order Traversal Func
bool traversalInorder(binTree *_pTree_)
{
    if (ISNULL_ERROR(_pTree_))
        return true;
    traversalInorderBinTreeNode(_pTree_->pRootNode);
    printf("\n");
    return false;
}

bool traversalInorderBinTreeNode(binTreeNode *_pRootNode_)
{
    if (_pRootNode_ == NULL)
        return true;
    traversalInorderBinTreeNode(_pRootNode_->pLeftChild);
    printf("%c ", _pRootNode_->cData);
    traversalInorderBinTreeNode(_pRootNode_->pRightChild);
    return false;
}

// Post-Order Traversal Func
bool traversalPostorder(binTree *_pTree_)
{
    if (ISNULL_ERROR(_pTree_))
        return true;
    traversalPostorderBinTreeNode(_pTree_->pRootNode);
    printf("\n");
    return false;
}

bool traversalPostorderBinTreeNode(binTreeNode *_pRootNode_)
{
    if (_pRootNode_ == NULL)
        return true;
    traversalPostorderBinTreeNode(_pRootNode_->pLeftChild);
    traversalPostorderBinTreeNode(_pRootNode_->pRightChild);
    printf("%c ", _pRootNode_->cData);
    return false;
}
#endif

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

// In-Order Traversal Func
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
    /* by my self */
    // while (true)
    // {
    //     if (pNode->pLeftChild != NULL)
    //     {
    //         push(pStack, (binTreeNode*)pNode);
    //         pNode = pNode->pLeftChild;
    //     }
    //     else
    //     {
    //         printf("%c ", pNode->cData);
    //         if (pNode->pRightChild != NULL)
    //         {
    //             pNode = pNode->pRightChild;
    //         }
    //         else
    //         {
    //             if (pStack->nCurrentCount<=0)
    //                 break;
    //             while(pNode->pRightChild == NULL)
    //             {
    //                 pNode = (binTreeNode *)pop(pStack);
    //                 printf("%C ", pNode->cData);
    //             }
    //             pNode = pNode->pRightChild;
    //         }
    //     }
    // }

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

// Post-Order Traversal Func
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