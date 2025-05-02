#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct BinTreeNodeType{
    char data;
    struct BinTreeNodeType* pLeftChild;
    struct BinTreeNodeType* pRightChild;
} BinTreeNode;

typedef struct BinTreeType{
    BinTreeNode* pRootNode;
} BinTree;

BinTree* createBinTree(BinTreeNode rootNode);
void deleteBinTree(BinTree* pBinTree);
BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);
void removeBinTreeNode(BinTreeNode* pNode);
BinTreeNode* getRootNodeBT(BinTree* pBinTree);
BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode);
BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode);

void preorderTraversalRecursiveBinTree(BinTree* pBinTree);
void preorderTraversalRecursiveBinTreeNode(BinTreeNode* pParentNode);
void inorderTraversalRecursiveBinTree(BinTree* pBinTree);
void inorderTraversalRecursiveBinTreeNode(BinTreeNode* pParentNode);
void postorderTraversalRecursiveBinTree(BinTree* pBinTree);
void postorderTraversalRecursiveBinTreeNode(BinTreeNode* pParentNode);

BinTree* copyBinTree(BinTree* pSource);
BinTreeNode* copyBinTreeNode(BinTreeNode* pSourceNode);
bool equalBinTree(BinTree* pFirst, BinTree* pSecond);
bool equalBinTreeNode(BinTreeNode* pFirst, BinTreeNode* pSecond);
int getNodeCountBT(BinTree* pSource);
int getNodeCountBTNode(BinTreeNode* pSource);
int getLeafNodeCountBT(BinTree* pSource);
int getLeafNodeCountBTNode(BinTreeNode* pSource);
int getHeightBT(BinTree* pSource);
int getHeightBTNode(BinTreeNode* pSource);