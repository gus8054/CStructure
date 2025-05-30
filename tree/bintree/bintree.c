#include "bintree.h"

BinTree* createBinTree(BinTreeNode rootNode){
    BinTree* pReturn = (BinTree*)malloc(sizeof(BinTree));
    if(pReturn == NULL) return NULL;

    pReturn->pRootNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    if(pReturn->pRootNode == NULL){
        free(pReturn);
        return NULL;
    }

    pReturn->pRootNode->data = rootNode.data;
    pReturn->pRootNode->pLeftChild = NULL;
    pReturn->pRootNode->pRightChild = NULL;
    return pReturn;
}

void deleteBinTree(BinTree* pBinTree){
    if(pBinTree == NULL) return;
    removeBinTreeNode(pBinTree->pRootNode);
    free(pBinTree);
}

void removeBinTreeNode(BinTreeNode* pBinTreeNode){
    if(pBinTreeNode == NULL) return;
    removeBinTreeNode(pBinTreeNode->pLeftChild);
    removeBinTreeNode(pBinTreeNode->pRightChild);
    free(pBinTreeNode);
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

BinTreeNode* getRootNodeBT(BinTree* pTree){
    if(pTree == NULL) return NULL;
    return pTree->pRootNode;
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pTreeNode){
    if(pTreeNode == NULL) return NULL;
    return pTreeNode->pLeftChild;
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pTreeNode){
    if(pTreeNode == NULL) return NULL;
    return pTreeNode->pRightChild;
}

void preorderTraversalRecursiveBinTree(BinTree* pTree){
    if(pTree == NULL) return;
    preorderTraversalRecursiveBinTreeNode(pTree->pRootNode);
}

void preorderTraversalRecursiveBinTreeNode(BinTreeNode* pTreeNode){
    if(pTreeNode == NULL) return;
    printf("%c ", pTreeNode->data);
    preorderTraversalRecursiveBinTreeNode(pTreeNode->pLeftChild);
    preorderTraversalRecursiveBinTreeNode(pTreeNode->pRightChild);
}

void inorderTraversalRecursiveBinTree(BinTree* pTree){
    if(pTree == NULL) return;
    inorderTraversalRecursiveBinTreeNode(pTree->pRootNode);
}

void inorderTraversalRecursiveBinTreeNode(BinTreeNode* pTreeNode){
    if(pTreeNode == NULL) return;
    inorderTraversalRecursiveBinTreeNode(pTreeNode->pLeftChild);
    printf("%c ", pTreeNode->data);
    inorderTraversalRecursiveBinTreeNode(pTreeNode->pRightChild);
}

void postorderTraversalRecursiveBinTree(BinTree* pTree){
    if(pTree == NULL) return;
    postorderTraversalRecursiveBinTreeNode(pTree->pRootNode);
}

void postorderTraversalRecursiveBinTreeNode(BinTreeNode* pTreeNode){
    if(pTreeNode == NULL) return;
    postorderTraversalRecursiveBinTreeNode(pTreeNode->pLeftChild);
    postorderTraversalRecursiveBinTreeNode(pTreeNode->pRightChild);
    printf("%c ", pTreeNode->data);
}

BinTree* copyBinTree(BinTree* pSource){
    if(pSource == NULL) return NULL;
    BinTree* pReturn = (BinTree*)malloc(sizeof(BinTree));
    if(pReturn == NULL) return NULL;
    pReturn->pRootNode = copyBinTreeNode(pSource->pRootNode);
    return pReturn;
}

BinTreeNode* copyBinTreeNode(BinTreeNode* pTreeNode){
    if(pTreeNode == NULL) return NULL;
    
    BinTreeNode* pReturn = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    if(pReturn == NULL) return NULL;

    pReturn->data = pTreeNode->data;
    pReturn->pLeftChild = copyBinTreeNode(pTreeNode->pLeftChild);
    pReturn->pRightChild = copyBinTreeNode(pTreeNode->pRightChild);
    return pReturn;
}

bool equalBinTree(BinTree* pTree1, BinTree* pTree2){
    if(pTree1 == NULL && pTree2 == NULL) return true;
    if(pTree1 != NULL && pTree2 != NULL && equalBinTreeNode(pTree1->pRootNode, pTree2->pRootNode)){
        return true;
    }else{
        return false;
    }
}

bool equalBinTreeNode(BinTreeNode* pTreeNode1, BinTreeNode* pTreeNode2){
    if(pTreeNode1 == NULL && pTreeNode2 == NULL) return true;
    if(pTreeNode1 != NULL && pTreeNode2 != NULL
        && pTreeNode1->data == pTreeNode2->data 
        && equalBinTreeNode(pTreeNode1->pLeftChild, pTreeNode2->pLeftChild)
        && equalBinTreeNode(pTreeNode1->pRightChild, pTreeNode2->pRightChild)){
            return true;
    }else{
        return false;
    }
}

int getNodeCountBT(BinTree* pTree){
    if(pTree == NULL) return -1;
    return getNodeCountBTNode(pTree->pRootNode);
}

int getNodeCountBTNode(BinTreeNode* pTreeNode){
    if(pTreeNode == NULL) return 0;
    return getNodeCountBTNode(pTreeNode->pLeftChild) + getNodeCountBTNode(pTreeNode->pRightChild) + 1;
}

int getLeafNodeCountBT(BinTree* pTree){
    if(pTree == NULL) return -1;
    return getLeafNodeCountBTNode(pTree->pRootNode);
}

int getLeafNodeCountBTNode(BinTreeNode* pTreeNode){
    if(pTreeNode == NULL) return 0;
    if(pTreeNode->pLeftChild == NULL && pTreeNode->pRightChild == NULL) return 1;
    return getLeafNodeCountBTNode(pTreeNode->pLeftChild) + getLeafNodeCountBTNode(pTreeNode->pRightChild);
}

int getHeightBT(BinTree* pTree){
    if(pTree == NULL) return -1;
    return getHeightBTNode(pTree->pRootNode);
}

int getHeightBTNode(BinTreeNode* pTreeNode){
    if(pTreeNode == NULL) return 0;
    int leftHeight = getHeightBTNode(pTreeNode->pLeftChild);
    int rightHeight = getHeightBTNode(pTreeNode->pRightChild);
    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}