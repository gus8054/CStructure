#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct BinSearchTreeNodeType{
    char value;
    int key;
    struct BinSearchTreeNodeType* pLeftChild;
    struct BinSearchTreeNodeType* pRightChild;
} BinSearchTreeNode;

typedef struct BinSearchTreeType{
    BinSearchTreeNode* pRootNode;
} BinSearchTree;

BinSearchTree* createBinSearchTree();
void deleteBinSearchTree(BinSearchTree* pTree);
void deleteBinSearchTreeNode(BinSearchTreeNode* pTreeNode);
bool insertElementBST(BinSearchTree* pTree, BinSearchTreeNode element);
bool removeElementBST(BinSearchTree* pTree, int key);
BinSearchTreeNode* searchBST(BinSearchTree* pTree, int key);
