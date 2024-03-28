// mainBinaryTree.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "includeBinTree.h"
#define _UseRecursion_

tree *EX_createBinTree(void);

// Pre-Order Traversal Func
bool traversalPreorder(tree *_pTree_);
bool traversalPreorderBinTreeNode(node *_pRootNode_);
// In-Order Traversal Func
bool traversalInorder(tree *_pTree_);
bool traversalInorderBinTreeNode(node *_pRootNode_);
// Post-Order Traversal Func
bool traversalPostorder(tree *_pTree_);
bool traversalPostorderBinTreeNode(node *_pRootNode_);

int main (int argc, char * argv[])
{
    tree *pTree = EX_createBinTree();
    if (ISNULL_ERROR(pTree))
        return -1;
    printf("Pre-Order:\t");
    traversalPreorder(pTree);
    printf("In-Order:\t");
    traversalInorder(pTree);
    printf("Post-Order:\t");
    traversalPostorder(pTree);
    deleteBinTree(pTree);
    return 0;
}
/*.\binaryTree.exe
Pre-Order:      A B D C E F
In-Order:       D B A E C F
Post-Order:     D B E F C A
*/

tree *EX_createBinTree(void)
{
    tree *pTree = NULL;
    node *pNodeA = NULL;
    node *pNodeB = NULL;
    node *pNodeC = NULL;
    node *pNodeD = NULL;
    node *pNodeE = NULL;
    node *pNodeF = NULL;

    pTree = createBinTree('A');
    if (!ISNULL_ERROR(pTree))
    {
        pNodeA = getRootNode(pTree);
        pNodeB = addLeftChildNode(pNodeA, 'B');
        pNodeC = addRightChildNode(pNodeA, 'C');
        if (!ISNULL_ERROR(pNodeB))
        {
            pNodeD = addLeftChildNode(pNodeB, 'D');
        }
        if (!ISNULL_ERROR(pNodeC))
        {
            pNodeE = addLeftChildNode(pNodeC, 'E');
            pNodeF = addRightChildNode(pNodeC, 'F');
        }
    }
    return pTree;
}

#ifdef _UseRecursion_
// Pre-Order Traversal Func
bool traversalPreorder(tree *_pTree_)
{
    if (ISNULL_ERROR(_pTree_))
        return true;
    traversalPreorderBinTreeNode(_pTree_->pRootNode);
    printf("\n");
    return false;
}

bool traversalPreorderBinTreeNode(node *_pRootNode_)
{
    if (_pRootNode_ == NULL)
        return true;
    printf("%c ", _pRootNode_->cData);
    traversalPreorderBinTreeNode(_pRootNode_->pLeftChild);
    traversalPreorderBinTreeNode(_pRootNode_->pRightChild);
    return false;
}

// In-Order Traversal Func
bool traversalInorder(tree *_pTree_)
{
    if (ISNULL_ERROR(_pTree_))
        return true;
    traversalInorderBinTreeNode(_pTree_->pRootNode);
    printf("\n");
    return false;
}

bool traversalInorderBinTreeNode(node *_pRootNode_)
{
    if (_pRootNode_ == NULL)
        return true;
    traversalInorderBinTreeNode(_pRootNode_->pLeftChild);
    printf("%c ", _pRootNode_->cData);
    traversalInorderBinTreeNode(_pRootNode_->pRightChild);
    return false;
}

// Post-Order Traversal Func
bool traversalPostorder(tree *_pTree_)
{
    if (ISNULL_ERROR(_pTree_))
        return true;
    traversalPostorderBinTreeNode(_pTree_->pRootNode);
    printf("\n");
    return false;
}

bool traversalPostorderBinTreeNode(node *_pRootNode_)
{
    if (_pRootNode_ == NULL)
        return true;
    traversalPostorderBinTreeNode(_pRootNode_->pLeftChild);
    traversalPostorderBinTreeNode(_pRootNode_->pRightChild);
    printf("%c ", _pRootNode_->cData);
    return false;
}
#endif

// TODO: Implementing breadth-first search (level traversal)
// TODO: Implementing depth-first search using stack