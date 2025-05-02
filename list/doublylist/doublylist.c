#include "doublylist.h"

DoublyList* createDoublyList(){
    DoublyList* pReturn = (DoublyList*)malloc(sizeof(DoublyList));
    if(pReturn == NULL) return NULL;
    memset(pReturn, 0, sizeof(DoublyList));
    pReturn->headerNode.pLeftLink = &(pReturn->headerNode);
    pReturn->headerNode.pRightLink = &(pReturn->headerNode);
    return pReturn;
}

void deleteDoublyList(DoublyList* pList){
    if(pList == NULL) return;
    DoublyListNode* pCurrentNode = pList->headerNode.pRightLink;
    DoublyListNode* pDelNode = NULL;

    for(int i = 0; i < pList->currentElementCount; i++){
        pDelNode = pCurrentNode;
        pCurrentNode = pCurrentNode->pRightLink;
        free(pDelNode);
    }
    free(pList);
}

bool addDLElement(DoublyList* pList, int position, DoublyListNode element){
    if(pList == NULL) return false;
    if(position < 0 || position > pList->currentElementCount) return false;
    DoublyListNode* pNewNode = (DoublyListNode*)malloc(sizeof(DoublyListNode));
    if(pNewNode == NULL) return false;
    pNewNode->data = element.data;
    pNewNode->pLeftLink = NULL;
    pNewNode->pRightLink = NULL;

    DoublyListNode* pPreNode = &(pList->headerNode);
    for(int i = 0; i < position; i++){
        pPreNode = pPreNode->pRightLink;
    }
    DoublyListNode* pNextNode = pPreNode->pRightLink;
    pNewNode->pLeftLink = pPreNode;
    pNewNode->pRightLink = pNextNode;
    pPreNode->pRightLink = pNewNode;
    pNextNode->pLeftLink = pNewNode;    

    pList->currentElementCount++;
    return true;
}

bool removeDLElement(DoublyList* pList, int position){
    if(pList == NULL) return false;
    if(position < 0 || position > pList->currentElementCount -1) return false;

    DoublyListNode* pPreNode = &(pList->headerNode);
    for(int i = 0; i < position; i++){
        pPreNode = pPreNode->pRightLink;
    }
    DoublyListNode* pDelNode = pPreNode->pRightLink;
    pPreNode->pRightLink = pDelNode->pRightLink;
    pDelNode->pRightLink->pLeftLink = pPreNode;
    free(pDelNode);
    pList->currentElementCount--;
    return true;
}

void clearDoublyList(DoublyList* pList){
    if(pList == NULL) return;

    DoublyListNode* pCurrentNode = pList->headerNode.pRightLink;
    DoublyListNode* pDelNode = NULL;

    for(int i = 0; i < pList->currentElementCount; i++){
        pDelNode = pCurrentNode;
        pCurrentNode = pCurrentNode->pRightLink;
        free(pDelNode);
    }
    pList->headerNode.pLeftLink = &(pList->headerNode);
    pList->headerNode.pRightLink = &(pList->headerNode);
    pList->currentElementCount = 0;
}

int getDoublyListLength(DoublyList* pList){
    if(pList == NULL) return -1;
    return pList->currentElementCount;
}

DoublyListNode* getDLElement(DoublyList* pList, int position){
    if(pList == NULL) return NULL;
    if(position < 0 || position > pList->currentElementCount - 1) return NULL;
    DoublyListNode* pTargetNode = &(pList->headerNode);
    for(int i = 0; i < position + 1; i++){
        pTargetNode = pTargetNode->pRightLink;
    }
    return pTargetNode;
}