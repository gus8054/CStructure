#include "arrayqueue.h"

ArrayQueue* createArrayQueue(int maxElementCount){
    if(maxElementCount <= 0) return NULL;
    ArrayQueue* pReturn = (ArrayQueue*)malloc(sizeof(ArrayQueue));
    if(pReturn == NULL) return NULL;
    pReturn->maxElementCount = maxElementCount;
    pReturn->currentElementCount = 0;
    pReturn->front = -1;
    pReturn->rear = -1;
    pReturn->pElement = (ArrayQueueNode*)malloc(sizeof(ArrayQueueNode) * maxElementCount);
    if(pReturn->pElement == NULL){
        free(pReturn);
        return NULL;
    }
    memset(pReturn->pElement, 0, sizeof(ArrayQueueNode) * maxElementCount);
    return pReturn;
}

void deleteArrayQueue(ArrayQueue* pQueue){
    if(pQueue == NULL) return;
    if(pQueue->pElement != NULL) free(pQueue->pElement);
    free(pQueue);
}

bool enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element){
    if(pQueue == NULL) return false;
    if(isArrayQueueFull(pQueue)) return false;
    pQueue->rear = (pQueue->rear + 1) % pQueue->maxElementCount;
    pQueue->pElement[pQueue->rear] = element;
    pQueue->currentElementCount++;
    return true;
}

ArrayQueueNode* dequeueAQ(ArrayQueue* pQueue){
    if(pQueue == NULL) return NULL;
    if(isArrayQueueEmpty(pQueue)) return NULL;
    pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
    ArrayQueueNode* pReturn = (ArrayQueueNode*)malloc(sizeof(ArrayQueueNode));
    if(pReturn == NULL) return NULL;
    *pReturn = pQueue->pElement[pQueue->front];
    pQueue->currentElementCount--;
    return pReturn;
}

ArrayQueueNode* peekAQ(ArrayQueue* pQueue){
    if(pQueue == NULL) return NULL;
    if(isArrayQueueEmpty(pQueue)) return NULL;
    return &(pQueue->pElement[(pQueue->front + 1) % pQueue->maxElementCount]);
}

bool isArrayQueueFull(ArrayQueue* pQueue){
    if(pQueue == NULL) return false;
    return pQueue->currentElementCount == pQueue->maxElementCount;
}

bool isArrayQueueEmpty(ArrayQueue* pQueue){
    if(pQueue == NULL) return false;
    return pQueue->currentElementCount == 0;
}



