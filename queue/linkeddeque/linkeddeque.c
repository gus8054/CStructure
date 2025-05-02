#include "linkeddeque.h"

LinkedDeque* createLinkedDeque(){
    LinkedDeque* pReturn = (LinkedDeque*)malloc(sizeof(LinkedDeque));
    if(pReturn == NULL) return NULL;
    memset(pReturn, 0, sizeof(LinkedDeque));
    return pReturn;
}

void deleteLinkedDeque(LinkedDeque* pDeque){
    if(pDeque == NULL) return;
    LinkedDequeNode* pCurrentNode = pDeque->pFront;
    LinkedDequeNode* pDelNode = NULL;
    while(pCurrentNode != NULL){
        pDelNode = pCurrentNode;
        pCurrentNode = pCurrentNode->pRightLink;
        free(pDelNode);
    }
    free(pDeque);
}

bool pushFrontLD(LinkedDeque* pDeque, LinkedDequeNode element){
    if(pDeque == NULL) return false;
    if(isLinkedDequeFull(pDeque)) return false;
    LinkedDequeNode* pNewNode = (LinkedDequeNode*)malloc(sizeof(LinkedDequeNode));
    if(pNewNode == NULL) return false;
    *pNewNode = element;
    pNewNode->pLeftLink = NULL;
    pNewNode->pRightLink = NULL;
    if(pDeque->currentElementCount == 0){
       pDeque->pFront = pNewNode;
       pDeque->pRear = pNewNode; 
    }else{
        pNewNode->pRightLink = pDeque->pFront;
        pDeque->pFront->pLeftLink = pNewNode;
        pDeque->pFront = pNewNode;
    }
    pDeque->currentElementCount++;
    return true;
}

LinkedDequeNode* popFrontLD(LinkedDeque* pDeque){
    if(pDeque == NULL) return NULL;
    if(isLinkedDequeEmpty(pDeque)) return NULL;
    LinkedDequeNode* pPopNode = pDeque->pFront;
    if(pDeque->currentElementCount == 1){
        pDeque->pFront = NULL;
        pDeque->pRear = NULL; 
    }else{
        pDeque->pFront = pPopNode->pRightLink;
        pPopNode->pRightLink = NULL;
        pDeque->pFront->pLeftLink = NULL;
    }
    pDeque->currentElementCount--;
    return pPopNode;
}


bool pushRearLD(LinkedDeque* pDeque, LinkedDequeNode element){
    if(pDeque == NULL) return false;
    if(isLinkedDequeFull(pDeque)) return false;
    LinkedDequeNode* pNewNode = (LinkedDequeNode*)malloc(sizeof(LinkedDequeNode));
    if(pNewNode == NULL) return false;
    *pNewNode = element;
    pNewNode->pLeftLink = NULL;
    pNewNode->pRightLink = NULL;
    if(pDeque->currentElementCount == 0){
       pDeque->pFront = pNewNode;
       pDeque->pRear = pNewNode; 
    }else{
        pNewNode->pLeftLink = pDeque->pRear;
        pDeque->pRear->pRightLink = pNewNode;
        pDeque->pRear = pNewNode;
    }
    pDeque->currentElementCount++;
    return true;
}

LinkedDequeNode* popRearLD(LinkedDeque* pDeque){
    if(pDeque == NULL) return NULL;
    if(isLinkedDequeEmpty(pDeque)) return NULL;
    LinkedDequeNode* pPopNode = pDeque->pRear;
    if(pDeque->currentElementCount == 1){
        pDeque->pFront = NULL;
        pDeque->pRear = NULL; 
    }else{
        pDeque->pRear = pPopNode->pLeftLink;
        pPopNode->pLeftLink = NULL;
        pDeque->pRear->pRightLink = NULL;
    }
    pDeque->currentElementCount--;
    return pPopNode;
}

LinkedDequeNode* peekFrontLD(LinkedDeque* pDeque){
    if(pDeque == NULL) return NULL;
    if(isLinkedDequeEmpty(pDeque)) return NULL;
    return pDeque->pFront;
}

LinkedDequeNode* peekRearLD(LinkedDeque* pDeque){
    if(pDeque == NULL) return NULL;
    if(isLinkedDequeEmpty(pDeque)) return NULL;
    return pDeque->pRear;
}

bool isLinkedDequeFull(LinkedDeque* pDeque){
    if(pDeque == NULL) return false;
    return false;
}

bool isLinkedDequeEmpty(LinkedDeque* pDeque){
    if(pDeque == NULL) return false;
    return pDeque->currentElementCount == 0;
}

