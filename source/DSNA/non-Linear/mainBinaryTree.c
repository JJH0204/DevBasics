// mainBinaryTree.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ISNULL(ptr) isNull((ptr), __func__)

typedef struct BinaryTreeNode
{
    char cData;

    struct TreeNode *pLeftChild;
    struct TreeNode *pRightChild;
} node;

typedef struct BinaryTree
{
    node *pRootNode;
} tree;

bool isNull(const void *ptr, const char *funcName);
tree * createBinTree(const char _cRootNodeData_);
node * createNodeBinTree(const char _cRootNodeData_);
node * addLeftChildNode(node * _pParent_, const char _cData_);
node * addRightChildNode(node * _pParent_, const char _cData_);
node * getRootNode(const tree * _pBinTree_);
bool deleteBinTree(tree * _pBinTree_);
bool deleteBinTreeNode(node * _pParent_);

int main (int argc, char * argv[])
{
    tree *pTree = NULL;
    node *pNodeA = NULL;
    node *pNodeB = NULL;
    node *pNodeC = NULL;
    node *pNodeD = NULL;
    node *pNodeE = NULL;
    node *pNodeF = NULL;

    pTree = createBinTree('A');
    if (!ISNULL(pTree))
    {
        pNodeA = getRootNode(pTree);
        pNodeB = addLeftChildNode(pNodeA, 'B');
        pNodeC = addRightChildNode(pNodeA, 'B');
    }

    if (!ISNULL(pNodeB))
    {
        pNodeD = addLeftChildNode(pNodeB, 'D');
    }

    if (!ISNULL(pNodeC))
    {
        pNodeE = addLeftChildNode(pNodeC, 'E');
        pNodeF = addRightChildNode(pNodeC, 'F');
    }
    
    deleteBinTree(pTree);
    
    return 0;
}

bool isNull(const void *ptr, const char *funcName)
{
    if (ptr == NULL)
    {
        printf("%s: Null Memory Access Error\n", funcName);
        return true;
    }
    return false;
}

tree * createBinTree(const char _cRootNodeData_)
{
    tree *pResult = NULL;
    pResult = (tree *)malloc(sizeof(tree));
    if (ISNULL(pResult))
        return NULL;
    
    pResult->pRootNode = createNodeBinTree(_cRootNodeData_);
    if (ISNULL(pResult))
    {
        free(pResult);
        return NULL;
    }
    return pResult;
}

node * createNodeBinTree(const char _cRootNodeData_)
{
    node * pResult = NULL;
    pResult = (node *)malloc(sizeof(node));
    if (ISNULL(pResult))
        return NULL;
    pResult->cData = _cRootNodeData_;
    pResult->pLeftChild = NULL;
    pResult->pRightChild = NULL;
    return pResult;
}

node * addLeftChildNode(node * _pParent_, const char _cData_)
{
    node *pResult = NULL;
    if (ISNULL(_pParent_))
        return pResult;
    if (ISNULL(_pParent_->pLeftChild))
    {
        pResult = createNodeBinTree(_cData_);
        _pParent_->pLeftChild = pResult;
    }
    else
        printf("error, The node already exists. addLeftChildNode()\n");
    return pResult;
}

node * addRightChildNode(node * _pParent_, const char _cData_)
{
    node *pResult = NULL;
    if (ISNULL(_pParent_))
        return pResult;
    if (ISNULL(_pParent_->pRightChild))
    {
        pResult = createNodeBinTree(_cData_);
        _pParent_->pRightChild = pResult;
    }
    else
        printf("error, The node already exists. addLeftChildNode()\n");
    return pResult;
}

node * getRootNode(const tree * _pBinTree_)
{
    node *pResult = NULL;
    if (ISNULL(_pBinTree_))
        return NULL;
    pResult = _pBinTree_->pRootNode;
    return pResult;
}

bool deleteBinTree(tree * _pBinTree_)
{
    if (ISNULL(_pBinTree_))
        return true;
    deleteBinTreeNode(_pBinTree_->pRootNode);
    free(_pBinTree_);
    return false;
}

bool deleteBinTreeNode(node * _pParent_)
{
    if (ISNULL(_pParent_))
        return true;
    deleteBinTreeNode(_pParent_->pLeftChild);
    deleteBinTreeNode(_pParent_->pRightChild);
    free(_pParent_);
    return false;
}

/*
/Users/admin/Documents/GitHub/DevBasics/source/DSNA/non-Linear/mainBinaryTree.c:110:31: warning: incompatible pointer types assigning to 'struct TreeNode *' from 'node *' (aka 'struct BinaryTreeNode *') [-Wincompatible-pointer-types]
        _pParent_->pLeftChild = pResult;
                              ^ ~~~~~~~
/Users/admin/Documents/GitHub/DevBasics/source/DSNA/non-Linear/mainBinaryTree.c:125:32: warning: incompatible pointer types assigning to 'struct TreeNode *' from 'node *' (aka 'struct BinaryTreeNode *') [-Wincompatible-pointer-types]
        _pParent_->pRightChild = pResult;
                               ^ ~~~~~~~
/Users/admin/Documents/GitHub/DevBasics/source/DSNA/non-Linear/mainBinaryTree.c:154:23: warning: incompatible pointer types passing 'struct TreeNode *' to parameter of type 'node *' (aka 'struct BinaryTreeNode *') [-Wincompatible-pointer-types]
    deleteBinTreeNode(_pParent_->pLeftChild);
                      ^~~~~~~~~~~~~~~~~~~~~
/Users/admin/Documents/GitHub/DevBasics/source/DSNA/non-Linear/mainBinaryTree.c:150:31: note: passing argument to parameter '_pParent_' here
bool deleteBinTreeNode(node * _pParent_)
                              ^
/Users/admin/Documents/GitHub/DevBasics/source/DSNA/non-Linear/mainBinaryTree.c:155:23: warning: incompatible pointer types passing 'struct TreeNode *' to parameter of type 'node *' (aka 'struct BinaryTreeNode *') [-Wincompatible-pointer-types]
    deleteBinTreeNode(_pParent_->pRightChild);
                      ^~~~~~~~~~~~~~~~~~~~~~
/Users/admin/Documents/GitHub/DevBasics/source/DSNA/non-Linear/mainBinaryTree.c:150:31: note: passing argument to parameter '_pParent_' here
bool deleteBinTreeNode(node * _pParent_)
                              ^
4 warnings generated.
*/