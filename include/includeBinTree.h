#ifndef __BINARYTREE__

#define __BINARYTREE__
#define ISNULL_ERROR(ptr) isNull((ptr), __func__)

typedef struct BinaryTreeNode
{
    char cData;

    struct BinaryTreeNode *pLeftChild;
    struct BinaryTreeNode *pRightChild;
} node;

typedef struct BinaryTree
{
    node *pRootNode;
} tree;

bool isNull(const void *ptr, const char *funcName);
tree *createBinTree(const char _cRootNodeData_);
node *createNodeBinTree(const char _cRootNodeData_);
node *addLeftChildNode(node *_pParent_, const char _cData_);
node *addRightChildNode(node *_pParent_, const char _cData_);
node *getRootNode(const tree *_pBinTree_);
bool deleteBinTree(tree *_pBinTree_);
bool deleteBinTreeNode(node *_pParent_);

#endif