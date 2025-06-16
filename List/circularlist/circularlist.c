#include "circularlist.h"

CircularList* createCircularList(){
    CircularList* pReturn = (CircularList*)malloc(sizeof(CircularList));
    if(pReturn == NULL) return NULL;
    memset(pReturn, 0, sizeof(CircularList));
    return pReturn;
}

void deleteCircularList(CircularList* pList){
    if(pList == NULL) return;

    CircularListNode* pCurrentNode = pList->pHeadPointer;
    CircularListNode* pDelNode = NULL;

    for(int i = 0; i < pList->currentElementCount; i++){
        pDelNode = pCurrentNode;
        pCurrentNode = pCurrentNode->pLink;
        free(pDelNode);
    }
    free(pList);
}

bool addCLElement(CircularList* pList, int position, CircularListNode element){
    if(pList == NULL) return false;
    if(position < 0 || position > pList->currentElementCount) return false;
    CircularListNode* pNewNode = (CircularListNode*)malloc(sizeof(CircularListNode));
    if(pNewNode == NULL) return false;
    pNewNode->data = element.data;
    pNewNode->pLink = NULL;
    if(pList->currentElementCount == 0){
        pNewNode->pLink = pNewNode;
        pList->pHeadPointer = pNewNode;
    }else if(position == 0){
        CircularListNode* pLastNode = pList->pHeadPointer;
        while(pLastNode->pLink != pList->pHeadPointer){
            pLastNode = pLastNode->pLink;
        }
        pNewNode->pLink = pLastNode->pLink;
        pLastNode->pLink = pNewNode;
        pList->pHeadPointer = pNewNode;
    }else{
        CircularListNode* pPreNode = pList->pHeadPointer;
        for(int i = 0; i < position - 1; i++){
            pPreNode = pPreNode->pLink;
        }
        pNewNode->pLink = pPreNode->pLink;
        pPreNode->pLink = pNewNode;
    }
    pList->currentElementCount++;
    return true;
}

bool removeCLElement(CircularList* pList, int position){
    if(pList == NULL) return false;
    if(position < 0 || position > pList->currentElementCount - 1) return false;
    if(pList->currentElementCount == 1){
        free(pList->pHeadPointer);
        pList->pHeadPointer = NULL;
    }else if(position == 0){
        CircularListNode* pLastNode = pList->pHeadPointer;
        while(pLastNode->pLink != pList->pHeadPointer){
            pLastNode = pLastNode->pLink;
        }
        pLastNode->pLink = pLastNode->pLink->pLink;
        free(pList->pHeadPointer);
        pList->pHeadPointer = pLastNode->pLink;
    }else{
        CircularListNode* pPreNode = pList->pHeadPointer;
        for(int i = 0; i < position - 1; i++){
            pPreNode = pPreNode->pLink;
        }
        CircularListNode* pDelNode = pPreNode->pLink;
        pPreNode->pLink = pDelNode->pLink;
        free(pDelNode);
    }
    pList->currentElementCount--;
    return true;
}

void clearCircularList(CircularList* pList){
    if(pList == NULL) return;

    CircularListNode* pCurrentNode = pList->pHeadPointer;
    CircularListNode* pDelNode = NULL;

    for(int i = 0; i < pList->currentElementCount; i++){
        pDelNode = pCurrentNode;
        pCurrentNode = pCurrentNode->pLink;
        free(pDelNode);
    }
    pList->pHeadPointer = NULL;
    pList->currentElementCount = 0;
}

int getCircularListLength(CircularList* pList){
    if(pList == NULL) return -1;
    return pList->currentElementCount;
}

CircularListNode* getCLElement(CircularList* pList, int position){
    if(pList == NULL) return NULL;
    if(position < 0 || position > pList->currentElementCount - 1) return NULL;
    CircularListNode* pTargetNode = pList->pHeadPointer;
    for(int i = 0; i < position; i++){
        pTargetNode = pTargetNode->pLink;
    }
    return pTargetNode;
}