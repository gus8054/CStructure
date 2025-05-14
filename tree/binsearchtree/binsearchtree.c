#include "binsearchtree.h"

BinSearchTree* createBinSearchTree(){
    BinSearchTree* pReturn = (BinSearchTree*)malloc(sizeof(BinSearchTree));
    if(pReturn == NULL) return NULL;
   
    pReturn->pRootNode = NULL;

    return pReturn;
}

void deleteBinSearchTree(BinSearchTree* pTree){
    if(pTree == NULL) return;
    if(pTree->pRootNode != NULL){
        deleteBinSearchTreeNode(pTree->pRootNode);
    }
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

    // 트리가 비어있다면 새 노드를 추가하고 종료.
    if(pTree->pRootNode == NULL){
        BinSearchTreeNode* pNewNode = (BinSearchTreeNode*)malloc(sizeof(BinSearchTreeNode));
        if(pNewNode == NULL) return false;
        *pNewNode = element;
        pNewNode->pLeftChild = NULL;
        pNewNode->pRightChild = NULL;
        pTree->pRootNode = pNewNode;
        return true;
    }
    BinSearchTreeNode* pParentNode = NULL;
    BinSearchTreeNode* pCurrentNode = pTree->pRootNode;
    // 키가 존재하는지 확인
    while(true){
        // 같은 노드가 존재하면 함수 종료
        if(element.key == pCurrentNode->key) return false;

        pParentNode = pCurrentNode;

        if(element.key < pCurrentNode->key){
            pCurrentNode = pCurrentNode->pLeftChild;
        }else{
            pCurrentNode = pCurrentNode->pRightChild;
        }
        // 삽입할 위치를 찾으면 반복종료.
        if(pCurrentNode == NULL) break;
    }

    // 새 노드 추가
    BinSearchTreeNode* pNewNode = (BinSearchTreeNode*)malloc(sizeof(BinSearchTreeNode));
    if(pNewNode == NULL) return false;
    *pNewNode = element;
    pNewNode->pLeftChild = NULL;
    pNewNode->pRightChild = NULL;

    if(element.key < pParentNode->key){
        pParentNode->pLeftChild = pNewNode;
    }else{
        pParentNode->pRightChild = pNewNode;
    }
    return true;
}

int getChildCount(BinSearchTreeNode* pNode) {
    if (pNode == NULL) return -1;
    
    int count = 0;
    if (pNode->pLeftChild != NULL) count++;
    if (pNode->pRightChild != NULL) count++;
    
    return count;
}

/**
 * 이진 탐색 트리에서 후계자 노드를 찾는 함수 (삭제할 노드의 오른쪽 서브트리에서 가장 작은 값)
 * @param pNode 후계자를 찾을 기준 노드
 * @return 후계자 노드와 그 부모 노드
 */
void findInOrderSuccessor(BinSearchTreeNode* pNode, BinSearchTreeNode** ppSuccessor, BinSearchTreeNode** ppParent) {
    *ppParent = pNode;
    *ppSuccessor = pNode->pRightChild;
    
    // 오른쪽 서브트리에서 가장 왼쪽(가장 작은) 노드를 찾음
    while ((*ppSuccessor)->pLeftChild != NULL) {
        *ppParent = *ppSuccessor;
        *ppSuccessor = (*ppSuccessor)->pLeftChild;
    }
}

/**
 * 이진 탐색 트리에서 요소 삭제
 * @param pTree 이진 탐색 트리
 * @param key 삭제할 요소의 키 값
 * @return 삭제 성공 여부
 */
bool deleteElementBST(BinSearchTree* pTree, int key) {
    // 유효성 검사
    if (pTree == NULL || pTree->pRootNode == NULL) {
        return false;
    }

    // 삭제할 노드와 그 부모 노드 찾기
    BinSearchTreeNode* pParentNode = NULL;
    BinSearchTreeNode* pDelNode = pTree->pRootNode;
    
    // 삭제할 노드 탐색
    while (pDelNode != NULL && pDelNode->key != key) {
        pParentNode = pDelNode;
        
        if (key < pDelNode->key) {
            pDelNode = pDelNode->pLeftChild;
        } else {
            pDelNode = pDelNode->pRightChild;
        }
    }
    
    // 삭제할 노드가 없으면 실패
    if (pDelNode == NULL) {
        return false;
    }
    
    // 자식 노드 수에 따라 다른 처리
    int childCount = getChildCount(pDelNode);
    
    // 경우 1: 리프 노드 (자식 없음)
    if (childCount == 0) {
        // 루트 노드인 경우
        if (pParentNode == NULL) {
            pTree->pRootNode = NULL;
        } 
        // 부모 노드와 연결 끊기
        else {
            if (pParentNode->pLeftChild == pDelNode) {
                pParentNode->pLeftChild = NULL;
            } else {
                pParentNode->pRightChild = NULL;
            }
        }
    }
    // 경우 2: 자식이 하나인 경우
    else if (childCount == 1) {
        // 자식 노드 결정
        BinSearchTreeNode* pChildNode = (pDelNode->pLeftChild != NULL) ? 
                                        pDelNode->pLeftChild : pDelNode->pRightChild;
        
        // 루트 노드인 경우
        if (pParentNode == NULL) {
            pTree->pRootNode = pChildNode;
        }
        // 부모 노드와 자식 노드 연결
        else {
            if (pParentNode->pLeftChild == pDelNode) {
                pParentNode->pLeftChild = pChildNode;
            } else {
                pParentNode->pRightChild = pChildNode;
            }
        }
    }
    // 경우 3: 자식이 둘인 경우
    else {
        // 후계자 노드 찾기 (중위 순회 기준 다음 노드)
        BinSearchTreeNode* pSuccessor = NULL;
        BinSearchTreeNode* pSuccessorParent = NULL;
        
        findInOrderSuccessor(pDelNode, &pSuccessor, &pSuccessorParent);
        
        // 후계자가 삭제 노드의 직접적인 자식이 아닌 경우
        if (pSuccessorParent != pDelNode) {
            // 후계자의 오른쪽 자식을 후계자 부모의 왼쪽에 연결
            pSuccessorParent->pLeftChild = pSuccessor->pRightChild;
            
            // 후계자가 삭제 노드의 오른쪽 자식을 물려받음
            pSuccessor->pRightChild = pDelNode->pRightChild;
        }
        
        // 후계자가 삭제 노드의 왼쪽 자식을 물려받음
        pSuccessor->pLeftChild = pDelNode->pLeftChild;
        
        // 삭제 노드가 루트인 경우
        if (pParentNode == NULL) {
            pTree->pRootNode = pSuccessor;
        }
        // 부모 노드와 후계자 연결
        else {
            if (pParentNode->pLeftChild == pDelNode) {
                pParentNode->pLeftChild = pSuccessor;
            } else {
                pParentNode->pRightChild = pSuccessor;
            }
        }
    }
    
    // 삭제 노드 메모리 해제
    free(pDelNode);
    return true;
}

int getChildCountBST(BinSearchTreeNode* pNode) {
    if (pNode == NULL) return -1;
    
    int count = 0;
    if (pNode->pLeftChild != NULL) count++;
    if (pNode->pRightChild != NULL) count++;
    
    return count;
}

void findSuccessor(BinSearchTreeNode* pNode, BinSearchTreeNode** ppSuccessor, BinSearchTreeNode** ppParent) {
    *ppParent = pNode;
    *ppSuccessor = pNode->pLeftChild;
    // *ppSuccessor = pNode->pRightChild;
    
    // 오른쪽 서브트리에서 가장 왼쪽(가장 작은) 노드를 찾음
    // while ((*ppSuccessor)->pLeftChild != NULL) {
    //     *ppParent = *ppSuccessor;
    //     *ppSuccessor = (*ppSuccessor)->pLeftChild;
    // }
    while((*ppSuccessor)->pRightChild != NULL){
        *ppParent = *ppSuccessor;
        *ppSuccessor = (*ppSuccessor)->pRightChild;
    }
}

bool removeElementBST(BinSearchTree* pTree, int key) {
    // 유효성 검사
    if (pTree == NULL || pTree->pRootNode == NULL) {
        return false;
    }

    // 삭제할 노드와 그 부모 노드 찾기
    BinSearchTreeNode* pParentNode = NULL;
    BinSearchTreeNode* pDelNode = pTree->pRootNode;
    
    // 삭제할 노드 탐색
    while (pDelNode != NULL && pDelNode->key != key) {
        pParentNode = pDelNode;
        
        if (key < pDelNode->key) {
            pDelNode = pDelNode->pLeftChild;
        } else {
            pDelNode = pDelNode->pRightChild;
        }
    }
    
    // 삭제할 노드가 없으면 실패
    if (pDelNode == NULL) {
        return false;
    }
    
    // 자식 노드 수에 따라 다른 처리
    int childCount = getChildCountBST(pDelNode);
    
    // 경우 1: 리프 노드 (자식 없음)
    if (childCount == 0) {
        // 루트 노드인 경우
        if (pParentNode == NULL) {
            pTree->pRootNode = NULL;
        } 
        // 부모 노드와 연결 끊기
        else {
            if (pParentNode->pLeftChild == pDelNode) {
                pParentNode->pLeftChild = NULL;
            } else {
                pParentNode->pRightChild = NULL;
            }
        }
    }
    // 경우 2: 자식이 하나인 경우
    else if (childCount == 1) {
        // 자식 노드 결정
        BinSearchTreeNode* pChildNode = (pDelNode->pLeftChild != NULL) ? 
                                        pDelNode->pLeftChild : pDelNode->pRightChild;
        
        // 루트 노드인 경우
        if (pParentNode == NULL) {
            pTree->pRootNode = pChildNode;
        }
        // 부모 노드와 자식 노드 연결
        else {
            if (pParentNode->pLeftChild == pDelNode) {
                pParentNode->pLeftChild = pChildNode;
            } else {
                pParentNode->pRightChild = pChildNode;
            }
        }
    }
    // 경우 3: 자식이 둘인 경우
    else {
        // 후계자 노드 찾기 (중위 순회 기준 다음 노드)
        BinSearchTreeNode* pSuccessor = NULL;
        BinSearchTreeNode* pSuccessorParent = NULL;
        
        findSuccessor(pDelNode, &pSuccessor, &pSuccessorParent);
        
        // 후계자가 삭제 노드의 직접적인 자식이 아닌 경우
        if (pSuccessorParent != pDelNode) {
            // 후계자의 오른쪽 자식을 후계자 부모의 왼쪽에 연결
            pSuccessorParent->pLeftChild = pSuccessor->pRightChild;
            
            // 후계자가 삭제 노드의 오른쪽 자식을 물려받음
            pSuccessor->pRightChild = pDelNode->pRightChild;
        }
        
        // 후계자가 삭제 노드의 왼쪽 자식을 물려받음
        pSuccessor->pLeftChild = pDelNode->pLeftChild;
        
        // 삭제 노드가 루트인 경우
        if (pParentNode == NULL) {
            pTree->pRootNode = pSuccessor;
        }
        // 부모 노드와 후계자 연결
        else {
            if (pParentNode->pLeftChild == pDelNode) {
                pParentNode->pLeftChild = pSuccessor;
            } else {
                pParentNode->pRightChild = pSuccessor;
            }
        }
    }
    
    // 삭제 노드 메모리 해제
    free(pDelNode);
    return true;
}

BinSearchTreeNode* searchBST(BinSearchTree* pTree, int key){
    if(pTree == NULL) return NULL;
    if(pTree->pRootNode == NULL) return NULL;

    BinSearchTreeNode* pCurrentNode = pTree->pRootNode;
    while(true){
        if(pCurrentNode == NULL) return NULL;
        if(key == pCurrentNode->key) break;
        else if(key < pCurrentNode->key){
            pCurrentNode = pCurrentNode->pLeftChild;
        }else{
            pCurrentNode = pCurrentNode->pRightChild;
        }
    }

    return pCurrentNode;
}


