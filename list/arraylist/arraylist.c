#include "arraylist.h"

ArrayList* createArrayList(int maxElementCount){
  if(maxElementCount <= 0) return NULL;
  ArrayList* pReturn = (ArrayList*)malloc(sizeof(ArrayList));
  if(pReturn == NULL) return NULL;
  pReturn->maxElementCount = maxElementCount;
  pReturn->currentElementCount = 0;
  pReturn->pElement = (ArrayListNode*)malloc(sizeof(ArrayListNode)*maxElementCount);
  if(pReturn->pElement == NULL){
    free(pReturn);
    return NULL;
  }
  memset(pReturn->pElement, 0, sizeof(ArrayListNode) * maxElementCount);
  return pReturn;
}

void deleteArrayList(ArrayList* pList){
  if(pList == NULL) return;
  if(pList->pElement != NULL)
    free(pList->pElement);
  free(pList);
}

bool addALElement(ArrayList* pList, int position, ArrayListNode element){
  if(pList == NULL) return false;
  if(position < 0 || position > pList->currentElementCount) return false;
  if(isArrayListFull(pList)) return false;
  for(int i = pList->currentElementCount - 1; i >= position; i--){
    pList->pElement[i+1] = pList->pElement[i];
  }
  pList->pElement[position] = element;
  pList->currentElementCount++;
  return true;
}

bool removeALElement(ArrayList* pList, int position){
  if(pList == NULL) return false;
  if(position < 0 || position >= pList->currentElementCount) return false;
  for(int i = position + 1; i <= pList->currentElementCount - 1; i++){
    pList->pElement[i-1] = pList->pElement[i];
  }
  pList->currentElementCount--;
  return true;
}

bool isArrayListFull(ArrayList* pList){
  if(pList == NULL) return false;
  return pList->currentElementCount == pList->maxElementCount;
}

void clearArrayList(ArrayList* pList){
  if(pList == NULL) return;
  memset(pList->pElement, 0, sizeof(ArrayListNode) * pList->currentElementCount);
  pList->currentElementCount = 0;
}

int getArrayListLength(ArrayList* pList){
  if(pList == NULL) return -1;
  return pList->currentElementCount;
}

ArrayListNode* getArrayListNode(ArrayList* pList, int position){
  if(pList == NULL) return NULL;
  if(position < 0 || position >= pList->currentElementCount) return NULL;
  return &(pList->pElement[position]);
}
