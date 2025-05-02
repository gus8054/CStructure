#include "bintree.h"

BinTree* createBinTree(BinTreeNode rootNode){
    BinTree* pReturn = (BinTree*)malloc(sizeof(BinTree));
    if(pReturn == NULL) return NULL;
    pReturn->pRootNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    if(pReturn->pRootNode == NULL){
        free(pReturn);
        return NULL;
    }
    *(pReturn->pRootNode) = rootNode;
    pReturn->pRootNode->pLeftChild = NULL;
    pReturn->pRootNode->pRightChild = NULL;
    return pReturn;
}

void deleteBinTree(BinTree* pBinTree){
    if(pBinTree == NULL) return;
    removeBinTreeNode(pBinTree->pRootNode);
    free(pBinTree);
}

void removeBinTreeNode(BinTreeNode* pNode){
    if(pNode != NULL){
       removeBinTreeNode(pNode->pLeftChild);
       removeBinTreeNode(pNode->pRightChild);
       free(pNode);
    }
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element){
    if(pParentNode == NULL) return NULL;
    BinTreeNode* pNewNode = NULL;
    if(pParentNode->pLeftChild == NULL){
        pNewNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
        if(pNewNode == NULL) return NULL;
        *pNewNode = element;
        pNewNode->pLeftChild = NULL;
        pNewNode->pRightChild = NULL;
        pParentNode->pLeftChild = pNewNode;
    }else{
        printf("ERROR: 이미 왼쪽 자식 노드가 존재함.\n");
    }
    return pNewNode;
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element){
    if(pParentNode == NULL) return NULL;
    BinTreeNode* pNewNode = NULL;
    if(pParentNode->pRightChild == NULL){
        pNewNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
        if(pNewNode == NULL) return NULL;
        *pNewNode = element;
        pNewNode->pLeftChild = NULL;
        pNewNode->pRightChild = NULL;
        pParentNode->pRightChild = pNewNode;
    }else{
        printf("ERROR: 이미 오른쪽 자식 노드가 존재함.\n");
    }
    return pNewNode;
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree){
    if(pBinTree == NULL) return NULL;
    return pBinTree->pRootNode;
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode){
    if(pNode == NULL) return NULL;
    return pNode->pLeftChild;
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode){
    if(pNode == NULL) return NULL;
    return pNode->pRightChild;
}

void preorderTraversalRecursiveBinTree(BinTree* pBinTree){
    if(pBinTree == NULL) return;
    preorderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
}

void preorderTraversalRecursiveBinTreeNode(BinTreeNode* pParentNode){
    if(pParentNode == NULL) return;
    printf("%c ", pParentNode->data);
    preorderTraversalRecursiveBinTreeNode(pParentNode->pLeftChild);
    preorderTraversalRecursiveBinTreeNode(pParentNode->pRightChild);
}

void inorderTraversalRecursiveBinTree(BinTree* pBinTree){
    if(pBinTree == NULL) return;
    inorderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
}

void inorderTraversalRecursiveBinTreeNode(BinTreeNode* pParentNode){
    if(pParentNode == NULL) return;
    inorderTraversalRecursiveBinTreeNode(pParentNode->pLeftChild);
    printf("%c ", pParentNode->data);
    inorderTraversalRecursiveBinTreeNode(pParentNode->pRightChild);
}

void postorderTraversalRecursiveBinTree(BinTree* pBinTree){
    if(pBinTree == NULL) return;
    postorderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
}

void postorderTraversalRecursiveBinTreeNode(BinTreeNode* pParentNode){
    if(pParentNode == NULL) return;
    postorderTraversalRecursiveBinTreeNode(pParentNode->pLeftChild);
    postorderTraversalRecursiveBinTreeNode(pParentNode->pRightChild);
    printf("%c ", pParentNode->data);
}

BinTree* copyBinTree(BinTree* pSource){
    if(pSource == NULL) return NULL;
    BinTree* pReturn = (BinTree*)malloc(sizeof(BinTree));
    if(pReturn == NULL) return NULL;
    pReturn->pRootNode = copyBinTreeNode(pSource->pRootNode);
    return pReturn;
}

BinTreeNode* copyBinTreeNode(BinTreeNode* pSourceNode){
    if(pSourceNode == NULL) return NULL;
    BinTreeNode* pReturn = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    if(pReturn == NULL) return NULL;
    *pReturn = *pSourceNode;
    pReturn->pLeftChild = copyBinTreeNode(pSourceNode->pLeftChild);
    pReturn->pRightChild = copyBinTreeNode(pSourceNode->pRightChild);
    return pReturn;
}

bool equalBinTree(BinTree* pFirst, BinTree* pSecond){
    if(pFirst == NULL && pSecond == NULL) return true;
    else if((pFirst != NULL && pSecond != NULL)
        && equalBinTreeNode(pFirst->pRootNode, pSecond->pRootNode)){
        return true;
    }
    return false;
}

bool equalBinTreeNode(BinTreeNode* pFirst, BinTreeNode* pSecond){
    if(pFirst == NULL && pSecond == NULL) return true;
    else if((pFirst != NULL && pSecond != NULL)
        && (pFirst->data == pSecond->data)
        && equalBinTreeNode(pFirst->pLeftChild, pSecond->pLeftChild)
        && equalBinTreeNode(pFirst->pRightChild, pSecond->pRightChild))
        return true;
    return false;
}

int getNodeCountBT(BinTree* pSource){
    if(pSource == NULL) return 0;
    return getNodeCountBTNode(pSource->pRootNode);
}

int getNodeCountBTNode(BinTreeNode* pSource){
    if(pSource == NULL) return 0;
    return getNodeCountBTNode(pSource->pLeftChild) + getNodeCountBTNode(pSource->pRightChild) + 1;
}

int getLeafNodeCountBT(BinTree* pSource){
    if(pSource == NULL) return 0;
    return getLeafNodeCountBTNode(pSource->pRootNode);
}

int getLeafNodeCountBTNode(BinTreeNode* pSource){
    if(pSource == NULL) return 0;
    if(pSource->pLeftChild == NULL & pSource->pRightChild == NULL) return 1;
    else return getLeafNodeCountBTNode(pSource->pLeftChild) + getLeafNodeCountBTNode(pSource->pRightChild);
}

int getHeightBT(BinTree* pSource){
    if(pSource == NULL) return 0;
    return getHeightBTNode(pSource->pRootNode);
}

int getHeightBTNode(BinTreeNode* pSource){
    if(pSource == NULL) return 0;
    if(pSource->pLeftChild == NULL && pSource->pRightChild == NULL) return 1;
    int leftHeight = getHeightBTNode(pSource->pLeftChild);
    int rightHeight = getHeightBTNode(pSource->pRightChild);
    return (leftHeight >= rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

