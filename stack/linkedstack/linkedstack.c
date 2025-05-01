#include "linkedstack.h"

LinkedStack* createLinkedStack(){
    LinkedStack* pReturn = (LinkedStack*)malloc(sizeof(LinkedStack));
    if(pReturn == NULL) return NULL;
    memset(pReturn, 0, sizeof(LinkedStack));
    return pReturn;
}

void deleteLinkedStack(LinkedStack* pStack){
    if(pStack == NULL) return;
    if(pStack->currentElementCount > 0){
        LinkedStackNode* pCurrentNode = pStack->pTopElement;
        LinkedStackNode* pDelNode = NULL;
        while(pCurrentNode != NULL){
            pDelNode = pCurrentNode;
            pCurrentNode = pCurrentNode->pLink;
            free(pDelNode);
        }
    }
    free(pStack);
}

bool pushLS(LinkedStack* pStack, LinkedStackNode element){
    if(pStack == NULL) return false;
    LinkedStackNode* pNewNode = (LinkedStackNode*)malloc(sizeof(LinkedStackNode));
    if(pNewNode == NULL) return false;
    pNewNode->data = element.data;
    pNewNode->pLink = pStack->pTopElement;
    pStack->pTopElement = pNewNode;
    pStack->currentElementCount++;
    return true;
}

LinkedStackNode* popLS(LinkedStack* pStack){
    if(pStack == NULL) return NULL;
    if(isLinkedStackEmpty(pStack)) return NULL;
    LinkedStackNode* pTargetNode = pStack->pTopElement;
    pStack->pTopElement = pTargetNode->pLink;
    pTargetNode->pLink = NULL;
    pStack->currentElementCount--;
    return pTargetNode;
}

LinkedStackNode* peekLS(LinkedStack* pStack){
    if(pStack == NULL) return NULL;
    if(isLinkedStackEmpty(pStack)) return NULL;
    return pStack->pTopElement;
}

bool isLinkedStackFull(LinkedStack* pStack){
    return false;
}

bool isLinkedStackEmpty(LinkedStack* pStack){
    if(pStack == NULL) return false;
    return pStack->currentElementCount == 0;
}


