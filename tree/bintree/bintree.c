#include "bintree.h"

BinTree* createBinTree(BinTreeNode element){
    BinTree* pReturn = (BinTree*)malloc(sizeof(BinTree));
    if(pReturn == NULL) return NULL;

    BinTreeNode* pRootNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    if(pRootNode == NULL){
        free(pReturn);
        return NULL;
    }

    pRootNode->data = element.data;
    pRootNode->pLeftChild = NULL;
    pRootNode->pRightChild = NULL;
    
    pReturn->pRootNode = pRootNode;
    return pReturn;
}

void deleteBinTree(BinTree* pBinTree){
    if(pBinTree == NULL) return;
    removeBinTreeNode(pBinTree->pRootNode);
    free(pBinTree);
}

void removeBinTreeNode(BinTreeNode* pNode){
    if(pNode == NULL) return;
    removeBinTreeNode(pNode->pLeftChild);
    removeBinTreeNode(pNode->pRightChild);
    free(pNode);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element){
    if(pParentNode == NULL) return NULL;
    if(pParentNode->pLeftChild != NULL) return NULL;

    BinTreeNode* pNewNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    if(pNewNode == NULL) return NULL;

    pNewNode->data = element.data;
    pNewNode->pLeftChild = NULL;
    pNewNode->pRightChild = NULL;

    pParentNode->pLeftChild = pNewNode;
    return pNewNode;
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element){
    if(pParentNode == NULL) return NULL;
    if(pParentNode->pRightChild != NULL) return NULL;

    BinTreeNode* pNewNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    if(pNewNode == NULL) return NULL;

    pNewNode->data = element.data;
    pNewNode->pLeftChild = NULL;
    pNewNode->pRightChild = NULL;

    pParentNode->pRightChild = pNewNode;
    return pNewNode;
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree){
    if(pBinTree == NULL) return NULL;
    return pBinTree->pRootNode;
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pParentNode){
    if(pParentNode == NULL) return NULL;
    return pParentNode->pLeftChild;
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pParentNode){
    if(pParentNode == NULL) return NULL;
    return pParentNode->pRightChild;
}

void preorderTraversalRecursiveBinTree(BinTree* pBinTree){
    if(pBinTree == NULL) return;
    preorderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
}

void preorderTraversalRecursiveBinTreeNode(BinTreeNode* pNode){
    if(pNode == NULL) return;
    printf("%c ", pNode->data);
    preorderTraversalRecursiveBinTreeNode(pNode->pLeftChild);
    preorderTraversalRecursiveBinTreeNode(pNode->pLeftChild);
}

void inorderTraversalRecursiveBinTree(BinTree* pBinTree){
    if(pBinTree == NULL) return;
    inorderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
}

void inorderTraversalRecursiveBinTreeNode(BinTreeNode* pNode){
    if(pNode == NULL) return;
    inorderTraversalRecursiveBinTreeNode(pNode->pLeftChild);
    printf("%c ", pNode->data);
    inorderTraversalRecursiveBinTreeNode(pNode->pLeftChild);
}

void postorderTraversalRecursiveBinTree(BinTree* pBinTree){
    if(pBinTree == NULL) return;
    postorderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
}

void postorderTraversalRecursiveBinTreeNode(BinTreeNode* pNode){
    if(pNode == NULL) return;
    postorderTraversalRecursiveBinTreeNode(pNode->pLeftChild);
    postorderTraversalRecursiveBinTreeNode(pNode->pLeftChild);
    printf("%c ", pNode->data);
}

BinTree* copyBinTree(BinTree* pSourceBinTree){
    if(pSourceBinTree == NULL) return NULL;
    BinTree* pReturn = (BinTree*)malloc(sizeof(BinTree));
    if(pReturn == NULL) return NULL;
    
    BinTreeNode* pRootNode = copyBinTreeNode(pSourceBinTree->pRootNode);
    pReturn->pRootNode = pRootNode;
    return pReturn;
}

BinTreeNode* copyBinTreeNode(BinTreeNode* pNode){
    if(pNode == NULL) return NULL;
    BinTreeNode* pNewNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    if(pNewNode == NULL) return NULL;
    pNewNode->data = pNode->data;
    pNewNode->pLeftChild = copyBinTreeNode(pNode->pLeftChild);
    pNewNode->pRightChild = copyBinTreeNode(pNode->pRightChild);
    return pNewNode;
}

bool equalBinTree(BinTree* pFirstBinTree, BinTree* pSecondBinTree){
    if(pFirstBinTree == NULL && pSecondBinTree == NULL) return true;
    if(pFirstBinTree != NULL && pSecondBinTree != NULL && equalBinTreeNode(pFirstBinTree->pRootNode, pSecondBinTree->pRootNode)) return true;
    return false;
}

bool equalBinTreeNode(BinTreeNode* pFirstNode, BinTreeNode* pSecondNode){
    if(pFirstNode == NULL && pSecondNode == NULL) return true;
    if(pFirstNode != NULL && pSecondNode != NULL && pFirstNode->data == pSecondNode->data
        && equalBinTreeNode(pFirstNode->pLeftChild, pSecondNode->pLeftChild) && equalBinTreeNode(pFirstNode->pRightChild, pSecondNode->pRightChild))
        return true;
    return false;
}

int getNodeCountBT(BinTree* pBinTree){
    if(pBinTree == NULL) return 0;
    return getNodeCountBTNode(pBinTree->pRootNode);
}

int getNodeCountBTNode(BinTreeNode* pNode){
    if(pNode == NULL) return 0;
    return 1 + getNodeCountBTNode(pNode->pLeftChild) + getNodeCountBTNode(pNode->pRightChild);
}

int getLeafNodeCountBT(BinTree* pBinTree){
    if(pBinTree == NULL) return 0;
    return getLeafNodeCountBTNode(pBinTree->pRootNode);
}

int getLeafNodeCountBTNode(BinTreeNode* pNode){
    if(pNode == NULL) return 0;
    if(pNode->pLeftChild == NULL && pNode->pRightChild == NULL) return 1;
    return getLeafNodeCountBTNode(pNode->pLeftChild) + getLeafNodeCountBTNode(pNode->pRightChild);
}

int getHeightBT(BinTree* pBinTree){
    if(pBinTree == NULL) return 0;
    return getHeightBTNode(pBinTree->pRootNode);
}

int getHeightBTNode(BinTreeNode* pNode){
    if(pNode == NULL) return 0;
    int leftHeight = getHeightBTNode(pNode->pLeftChild);
    int rightHeight = getHeightBTNode(pNode->pRightChild);
    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}
