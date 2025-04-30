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
  clearDoublyList(pList);
  free(pList);
}

bool addDLElement(DoublyList* pList, int position, DoublyListNode element){
  if(pList == NULL) return false;
  if(position < 0 || position > pList->currentElementCount) return false;
  DoublyListNode* pNewNode = (DoublyListNode*)malloc(sizeof(DoublyListNode));
  if(pNewNode == NULL) return false;
  *pNewNode = element;

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
  if(position < 0 || position >= pList->currentElementCount) return false;

  DoublyListNode* pPreNode = &(pList->headerNode);
  for(int i = 0; i < position; i++){
    pPreNode = pPreNode->pRightLink;
  }
  DoublyListNode* pTargetNode = pPreNode->pRightLink;
  DoublyListNode* pNextNode = pTargetNode->pRightLink;

  pPreNode->pRightLink = pNextNode;
  pNextNode->pLeftLink = pPreNode;
  free(pTargetNode);
  
  pList->currentElementCount--;
  return true;
}

void clearDoublyList(DoublyList* pList){
  if(pList == NULL) return;
  if(pList->currentElementCount == 0) return;
  
  DoublyListNode* pCurrentNode = pList->headerNode.pRightLink;
  DoublyListNode* pDeleteNode = NULL;

  for(int i = 0; i < pList->currentElementCount; i++){
    pDeleteNode = pCurrentNode;
    pCurrentNode = pCurrentNode->pRightLink;
    free(pDeleteNode);
  }
  pList->currentElementCount = 0;
  pList->headerNode.pLeftLink = &(pList->headerNode);
  pList->headerNode.pRightLink = &(pList->headerNode);
}

int getDoublyListLength(DoublyList* pList){
  if(pList == NULL) return -1;
  return pList->currentElementCount;
}

DoublyListNode* getDLElement(DoublyList* pList, int position){
  if(pList == NULL) return NULL;
  if(position < 0 || position >= pList->currentElementCount) return NULL;

  DoublyListNode* pTargetNode = &(pList->headerNode);
  for(int i = 0; i < position + 1; i++){
    pTargetNode = pTargetNode->pRightLink;
  }
  return pTargetNode;
}
