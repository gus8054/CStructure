#include "linkedlist.h"

LinkedList* createLinkedList(){
  LinkedList* pReturn = (LinkedList*)malloc(sizeof(LinkedList));
  if(pReturn == NULL) return NULL;
  memset(pReturn, 0, sizeof(LinkedList));
  return pReturn;
}

void deleteLinkedList(LinkedList* pList){
  if(pList != NULL){
    clearLinkedList(pList);
    free(pList);
  }
}

bool addLLElement(LinkedList* pList, int position, LinkedListNode element){
  if(pList == NULL) return false;
  if(position < 0 || position >= pList->currentElementCount + 1) return false;
  LinkedListNode* pNewNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
  if(pNewNode == NULL) return false;
  *pNewNode = element;
  pNewNode->pLink = NULL;
  LinkedListNode* pPreNode = &(pList->headerNode);
  for(int i = 0; i < position; i++){
    pPreNode = pPreNode->pLink;
  }
  pNewNode->pLink = pPreNode->pLink;
  pPreNode->pLink = pNewNode;
  pList->currentElementCount++;
  return true;
}

bool removeLLElement(LinkedList* pList, int position){
  if(pList == NULL) return false;
  if(position < 0 || position >= pList->currentElementCount) return false;

  LinkedListNode* pPreNode = &(pList->headerNode);
  for(int i = 0; i < position; i++){
    pPreNode = pPreNode->pLink;
  }
  LinkedListNode* pTargetNode = pPreNode->pLink;
  pPreNode->pLink = pTargetNode->pLink;
  free(pTargetNode);
  pList->currentElementCount--;
  return true;
}

void clearLinkedList(LinkedList* pList){
  if(pList == NULL) return;
  while(pList->currentElementCount != 0){
    removeLLElement(pList, 0);
  }
}

int getLinkedListLength(LinkedList* pList){
  if(pList == NULL) return -1;
  return pList->currentElementCount;
}

LinkedListNode* getLinkedListNode(LinkedList* pList, int position){
  if(pList == NULL) return NULL;
  if(position < 0 || position >= pList->currentElementCount) return NULL;
  LinkedListNode* pTargetNode = &(pList->headerNode);
  for(int i = 0; i < position + 1; i++){
    pTargetNode = pTargetNode->pLink;
  }
  return pTargetNode;
}