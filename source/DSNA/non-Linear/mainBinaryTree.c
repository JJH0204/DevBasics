// mainBinaryTree.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "includeBinTree.h"

binTree *EX_createBinTree(void);

int main (int argc, char * argv[])
{
    binTree *pTree = EX_createBinTree();
    if (ISNULL_ERROR(pTree))
        return -1;
    printf("Pre-Order:\t");
    traversalPreorder(pTree);
    printf("In-Order:\t");
    traversalInorder(pTree);
    // printf("Post-Order:\t");
    // traversalPostorder(pTree);
    deleteBinTree(pTree);
    return 0;
}
/*.\binaryTree.exe
Pre-Order:      A B D C E F
In-Order:       D B A E C F
Post-Order:     D B E F C A
*/

binTree *EX_createBinTree(void)
{
    binTree *pTree = NULL;
    binTreeNode *pNodeA = NULL;
    binTreeNode *pNodeB = NULL;
    binTreeNode *pNodeC = NULL;
    binTreeNode *pNodeD = NULL;
    binTreeNode *pNodeE = NULL;
    binTreeNode *pNodeF = NULL;

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
