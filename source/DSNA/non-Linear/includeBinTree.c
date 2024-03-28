#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "includeBinTree.h"

bool isNull(const void *ptr, const char *funcName)
{
    if (ptr == NULL)
    {
        printf("%s: Null Memory Access Error\n", funcName);
        return true;
    }
    return false;
}

tree *createBinTree(const char _cRootNodeData_)
{
    tree *pResult = NULL;
    pResult = (tree *)malloc(sizeof(tree));
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

node *createNodeBinTree(const char _cRootNodeData_)
{
    node *pResult = NULL;
    pResult = (node *)malloc(sizeof(node));
    if (ISNULL_ERROR(pResult))
        return NULL;
    pResult->cData = _cRootNodeData_;
    pResult->pLeftChild = NULL;
    pResult->pRightChild = NULL;
    return pResult;
}

node *addLeftChildNode(node *_pParent_, const char _cData_)
{
    node *pResult = NULL;
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

node *addRightChildNode(node *_pParent_, const char _cData_)
{
    node *pResult = NULL;
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

node *getRootNode(const tree *_pBinTree_)
{
    node *pResult = NULL;
    if (ISNULL_ERROR(_pBinTree_))
        return NULL;
    pResult = _pBinTree_->pRootNode;
    return pResult;
}

bool deleteBinTree(tree *_pBinTree_)
{
    if (ISNULL_ERROR(_pBinTree_))
        return true;
    deleteBinTreeNode(_pBinTree_->pRootNode);
    free(_pBinTree_);
    return false;
}

bool deleteBinTreeNode(node *_pParent_)
{
    if (!(_pParent_ == NULL))
    {
        deleteBinTreeNode(_pParent_->pLeftChild);
        deleteBinTreeNode(_pParent_->pRightChild);
        free(_pParent_);
    }
    return false;
}
