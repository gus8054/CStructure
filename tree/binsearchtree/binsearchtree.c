#include "binsearchtree.h"

BinSearchTree* createBinSearchTree(){
    BinSearchTree* pReturn = (BinSearchTree*)malloc(sizeof(BinSearchTree));
    if(pReturn == NULL) return NULL;

    pReturn->pRootNode = NULL;
    return pReturn;
}

void deleteBinSearchTree(BinSearchTree* pTree){
    if(pTree == NULL) return;
    deleteBinSearchTreeNode(pTree->pRootNode);
    free(pTree);
}

void deleteBinSearchTreeNode(BinSearchTreeNode* pTreeNode){
    if(pTreeNode == NULL) return;
    deleteBinSearchTreeNode(pTreeNode->pLeftChild);
    deleteBinSearchTreeNode(pTreeNode->pRightChild);
    free(pTreeNode);
}

bool insertElementBST(BinSearchTree* pTree, BinSearchTreeNode element){
    if(pTree == NULL) return false;
    
    BinSearchTreeNode* pNewNode = (BinSearchTreeNode*)malloc(sizeof(BinSearchTreeNode));
    if(pNewNode == NULL) return false;
    *pNewNode = element;
    pNewNode->pLeftChild = NULL;
    pNewNode->pRightChild = NULL;

    if(pTree->pRootNode == NULL){
       pTree->pRootNode = pNewNode;
       return true; 
    }

    BinSearchTreeNode* pParentNode = NULL;
    BinSearchTreeNode* pTreeNode = pTree->pRootNode;

    while(true){
        if(element.key < pTreeNode->key){
            pParentNode = pTreeNode;
            pTreeNode = pTreeNode->pLeftChild;
            if(pTreeNode == NULL){
                pParentNode->pLeftChild = pNewNode;
                break;
            } 
        }else if(element.key > pTreeNode->key){
            pParentNode = pTreeNode;
            pTreeNode = pTreeNode->pRightChild;
            if(pTreeNode == NULL){
                pParentNode->pRightChild = pNewNode;
                break;
            }
        }else{
            free(pNewNode);
            return false;
        }
    }
    return true;
}

BinSearchTreeNode* searchBST(BinSearchTree* pTree, int key){
    if(pTree == NULL) return NULL;
    if(pTree->pRootNode == NULL) return NULL;

    BinSearchTreeNode* pTreeNode = pTree->pRootNode;
    while(true){
        if(key < pTreeNode->key){
            pTreeNode = pTreeNode->pLeftChild;
        }else if(key > pTreeNode->key){
            pTreeNode = pTreeNode->pRightChild;
        }else{
            break;
        }
        if(pTreeNode == NULL) return NULL;
    }
    return pTreeNode;
}

bool findRemoveNode(BinSearchTree* pTree, int key, BinSearchTreeNode** ppParentNode, BinSearchTreeNode** ppChildNode){
    if(pTree == NULL) return false;
    if(pTree->pRootNode == NULL) return false;

    *ppParentNode = NULL;
    *ppChildNode = pTree->pRootNode;

    while(*ppChildNode != NULL){
        if(key < (*ppChildNode)->key){
            *ppParentNode = *ppChildNode;
            *ppChildNode = (*ppChildNode)->pLeftChild;
        }else if(key > (*ppChildNode)->key){
            *ppParentNode = *ppChildNode;
            *ppChildNode = (*ppChildNode)->pRightChild;
        }else break;
    }
    if(*ppChildNode == NULL) return false;
    return true;
}

bool removeElementBST(BinSearchTree* pTree, int key){
    if(pTree == NULL) return false;
    if(pTree->pRootNode == NULL) return false;

    BinSearchTreeNode* pParentNode = NULL; // 삭제할 노드의 부모 노드
    BinSearchTreeNode* pChildNode = pTree->pRootNode; // 삭제할 노드

    if(!findRemoveNode(pTree, key, &pParentNode, &pChildNode)) return false;

    // 삭제할 노드가 루트 노드일 때
    if(pParentNode == NULL){
        // 삭제할 노드가 리프노드 일 때
        if(pChildNode->pLeftChild == NULL && pChildNode->pRightChild == NULL){
            pTree->pRootNode = NULL;
        }else if(pChildNode->pLeftChild != NULL && pChildNode->pRightChild != NULL){
            // 삭제할 노드가 두 개의 자식을 가질 때
            BinSearchTreeNode* pPreNode = pChildNode;
            BinSearchTreeNode* pCurrentNode = pChildNode->pRightChild;
            while(true){
                if(pCurrentNode->pLeftChild == NULL) break;
                pPreNode = pCurrentNode;
                pCurrentNode = pCurrentNode->pLeftChild; 
            }
            if(pPreNode == pChildNode){
                pPreNode->pRightChild = pCurrentNode->pRightChild;
            }else{
                pPreNode->pLeftChild = pCurrentNode->pRightChild;
            }
            pCurrentNode->pLeftChild = pChildNode->pLeftChild;
            pCurrentNode->pRightChild = pChildNode->pRightChild;
            pTree->pRootNode = pCurrentNode;
        }else if(pChildNode->pLeftChild != NULL){
            // 삭제할 노드가 왼쪽 자식만 가질 때
            pTree->pRootNode = pChildNode->pLeftChild;
        }else{
            // 삭제할 노드가 오른쪽 자식만 가질 때
            pTree->pRootNode = pChildNode->pRightChild;
        }
        free(pChildNode);
    }else{
    // 삭제할 노드가 루트 노드가 아닐 때
        // 삭제할 노드가 리프노드 일 때
        if(pChildNode->pLeftChild == NULL && pChildNode->pRightChild == NULL){
            if(pParentNode->pLeftChild == pChildNode){
                pParentNode->pLeftChild = NULL;
            }else{
                pParentNode->pRightChild = NULL;
            }
        }else if(pChildNode->pLeftChild != NULL && pChildNode->pRightChild != NULL){
            // 삭제할 노드가 두 개의 자식을 가질 때
            BinSearchTreeNode* pPreNode = pChildNode;
            BinSearchTreeNode* pCurrentNode = pChildNode->pRightChild;
            while(true){
                if(pCurrentNode->pLeftChild == NULL) break;
                pPreNode = pCurrentNode;
                pCurrentNode = pCurrentNode->pLeftChild; 
            }
            if(pPreNode == pChildNode){
                pPreNode->pRightChild = pCurrentNode->pRightChild;
            }else{
                pPreNode->pLeftChild = pCurrentNode->pRightChild;
            }
            pCurrentNode->pLeftChild = pChildNode->pLeftChild;
            pCurrentNode->pRightChild = pChildNode->pRightChild;
            if(pParentNode->pLeftChild == pChildNode){
                pParentNode->pLeftChild = pCurrentNode;
            }else{
                pParentNode->pRightChild = pCurrentNode;
            }
        }else if(pChildNode->pLeftChild != NULL){
            // 삭제할 노드가 왼쪽 자식만 가질 때
            if(pParentNode->pLeftChild == pChildNode){
                pParentNode->pLeftChild = pChildNode->pLeftChild;
            }else{
                pParentNode->pRightChild = pChildNode->pLeftChild;
            }
        }else{
            // 삭제할 노드가 오른쪽 자식만 가질 때
            if(pParentNode->pLeftChild == pChildNode){
                pParentNode->pLeftChild = pChildNode->pRightChild;
            }else{
                pParentNode->pRightChild = pChildNode->pRightChild;
            }
        }
        free(pChildNode);
    }
    return true;
}