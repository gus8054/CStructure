#include "arraystack.h"

ArrayStack* createArrayStack(int maxElementCount){
    if(maxElementCount <= 0 ) return NULL;
    ArrayStack* pReturn = (ArrayStack*)malloc(sizeof(ArrayStack));
    if(pReturn == NULL) return NULL;
    pReturn->maxElementCount = maxElementCount;
    pReturn->currentElementCount = 0;
    pReturn->pElement = (ArrayStackNode*)malloc(sizeof(ArrayStackNode) * maxElementCount);
    if(pReturn->pElement == NULL){
        free(pReturn);
        return NULL;
    }
    memset(pReturn->pElement, 0, sizeof(ArrayStackNode) * maxElementCount);
    return pReturn;
}

void deleteArrayStack(ArrayStack* pStack){
    if(pStack == NULL) return;
    if(pStack->pElement != NULL)
        free(pStack->pElement);
    free(pStack);
}

bool pushAS(ArrayStack* pStack, ArrayStackNode element){
    if(pStack == NULL) return false;
    if(isArrayStackFull(pStack)) return false;

    pStack->pElement[pStack->currentElementCount] = element;
    pStack->currentElementCount++;
    return true;
}

ArrayStackNode* popAS(ArrayStack* pStack){
    if(pStack == NULL) return NULL;
    if(isArrayStackEmpty(pStack)) return NULL;
    ArrayStackNode* pReturn = (ArrayStackNode*)malloc(sizeof(ArrayStackNode));
    if(pReturn == NULL) return NULL;
    pStack->currentElementCount--;
    *pReturn = pStack->pElement[pStack->currentElementCount];
    return pReturn;
}

ArrayStackNode* peekAS(ArrayStack* pStack){
    if(pStack == NULL) return NULL;
    if(isArrayStackEmpty(pStack)) return NULL;
    return &(pStack->pElement[pStack->currentElementCount - 1]);
}

bool isArrayStackFull(ArrayStack* pStack){
    if(pStack == NULL) return false;
    return pStack->currentElementCount == pStack->maxElementCount;
}

bool isArrayStackEmpty(ArrayStack* pStack){
    if(pStack == NULL) return false;
    return pStack->currentElementCount == 0;
}

