#ifndef __BINARYTREE__

#define __BINARYTREE__

typedef struct BinaryTreeNode
{
    char cData;

    struct BinaryTreeNode *pLeftChild;
    struct BinaryTreeNode *pRightChild;
} binTreeNode;

typedef struct BinaryTree
{
    binTreeNode *pRootNode;
} binTree;

binTree *createBinTree(const char _cRootNodeData_);
binTreeNode *createNodeBinTree(const char _cRootNodeData_);
binTreeNode *addLeftChildNode(binTreeNode *_pParent_, const char _cData_);
binTreeNode *addRightChildNode(binTreeNode *_pParent_, const char _cData_);
binTreeNode *getRootNode(const binTree *_pBinTree_);
bool deleteBinTree(binTree *_pBinTree_);
bool deleteBinTreeNode(binTreeNode *_pParent_);

// Pre-Order Traversal Func
bool traversalPreorder(binTree *_pTree_);
bool traversalPreorderBinTreeNode(binTreeNode *_pRootNode_);
// In-Order Traversal Func
bool traversalInorder(binTree *_pTree_);
bool traversalInorderBinTreeNode(binTreeNode *_pRootNode_);
// Post-Order Traversal Func
bool traversalPostorder(binTree *_pTree_);
bool traversalPostorderBinTreeNode(binTreeNode *_pRootNode_);
// breadth-first search (level traversal)
bool BreadthFirstSearch(binTree *_pTree_);

#endif