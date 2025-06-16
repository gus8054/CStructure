#include "ArrayList.h"

ArrayList* AL_Create(int maxElementCount){
    if(maxElementCount <= 0) return NULL;
    
    ArrayList* pReturn = (ArrayList*)malloc(sizeof(ArrayList));
    if(pReturn == NULL) return NULL;

    pReturn->currentElementCount = 0;
    pReturn->maxElementCount = maxElementCount;
    pReturn->pElement = (ArrayListNode*)malloc(sizeof(ArrayListNode) * maxElementCount);
    if(pReturn->pElement == NULL){
        free(pReturn);
        return NULL;
    }
    
    memset(pReturn->pElement, 0, sizeof(ArrayListNode) * maxElementCount);
    return pReturn;
}

void AL_Destroy(ArrayList* pList){
    if(pList == NULL) return;
    if(pList->pElement != NULL) free(pList->pElement);
    free(pList);
}

bool AL_Insert(ArrayList* pList, int position, ElementType element){
    if(pList == NULL) return false;
    if(position < 0 || position > pList->currentElementCount) return false;
    if(pList->currentElementCount == pList->maxElementCount){
        pList->maxElementCount *= 2;
        ArrayListNode* pTemp = (ArrayListNode*)realloc(pList->pElement, sizeof(ArrayListNode) * pList->maxElementCount);
        if(pTemp == NULL) return false;
        pList->pElement = pTemp; 
    }
    for(int i = pList->currentElementCount - 1; i >= position; i--){
        pList->pElement[i+1] = pList->pElement[i];
    }
    pList->pElement[position].data = element;
    pList->currentElementCount++;
    return true;
}

bool AL_Remove(ArrayList* pList, int position){
    if(pList == NULL) return false;
    if(position < 0 || position > pList->currentElementCount - 1) return false;

    for(int i = position + 1; i <= pList->currentElementCount - 1; i++){
        pList->pElement[i - 1] = pList->pElement[i];
    }

    pList->currentElementCount--;
    return true;
}

ArrayListNode* AL_GetAt(ArrayList* pList, int position){
    if(pList == NULL) return NULL;
    if(position < 0 || position > pList->currentElementCount - 1) return NULL;
    return &(pList->pElement[position]);
}