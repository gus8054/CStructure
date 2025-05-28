#include "radixsort.h"

LinkedQueue* createLinkedQueue(){
    LinkedQueue* pReturn = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    if(pReturn == NULL) return NULL;
    memset(pReturn, 0, sizeof(LinkedQueue));
    return pReturn;
}

void deleteLinkedQueue(LinkedQueue* pQueue){
    if(pQueue == NULL) return;
    LinkedQueueNode* pCurrentNode = pQueue->pFront;
    LinkedQueueNode* pDelNode = NULL;
    while(pCurrentNode != NULL){
        pDelNode = pCurrentNode;
        pCurrentNode = pCurrentNode->pLink;
        free(pDelNode);
    }
    free(pQueue);
}

bool enqueueLQ(LinkedQueue* pQueue, LinkedQueueNode element){
    if(pQueue == NULL) return false;
    if(isLinkedQueueFull(pQueue)) return false;
    LinkedQueueNode* pNewNode = (LinkedQueueNode*)malloc(sizeof(LinkedQueueNode));
    if(pNewNode == NULL) return false;
    *pNewNode = element;
    pNewNode->pLink = NULL;
    if(pQueue->currentElementCount == 0){
        pQueue->pFront = pNewNode;
        pQueue->pRear = pNewNode;
    }else{
        pQueue->pRear->pLink = pNewNode;
        pQueue->pRear = pNewNode;
    }
    pQueue->currentElementCount++;
    return true;
}

LinkedQueueNode* dequeueLQ(LinkedQueue* pQueue){
    if(pQueue == NULL) return NULL;
    if(isLinkedQueueEmpty(pQueue)) return NULL;
    LinkedQueueNode* pReturn = pQueue->pFront;
    if(pQueue->currentElementCount <= 1) {
       pQueue->pFront = NULL;
       pQueue->pRear = NULL;
    }
    else{
        pQueue->pFront = pReturn->pLink;
        pReturn->pLink = NULL;
    }
    pQueue->currentElementCount--;
    return pReturn;
}

LinkedQueueNode* peekLQ(LinkedQueue* pQueue){
    if(pQueue == NULL) return NULL;
    if(isLinkedQueueEmpty(pQueue)) return NULL;
    return pQueue->pFront;
}

bool isLinkedQueueFull(LinkedQueue* pQueue){
    return false;
}

bool isLinkedQueueEmpty(LinkedQueue* pQueue){
    if(pQueue == NULL) return false;
    return pQueue->currentElementCount == 0;
}

void printArray(int value[], int count){
    if(count <= 0) return;
    for(int i = 0; i < count; i++){
        printf("%d ", value[i]);
    }
    printf("\n");
}

void radixSort(int value[], int count, int radix, int digit){
    if(count <= 1 || radix <= 0 || digit <= 0) return;
    LinkedQueue** ppQueue = (LinkedQueue**)malloc(sizeof(LinkedQueue*) * radix);
    if(ppQueue == NULL) return;

    for(int i = 0; i < radix; i++){
        ppQueue[i] = createLinkedQueue();
        if(ppQueue[i] == NULL){
            for(int j = 0; j < i; j++){
                deleteLinkedQueue(ppQueue[j]);
            }
            free(ppQueue);
            return;
        }
    }

    for(int factor = 1, p = 1; p <= digit; factor *= radix, p++){
        for(int i = 0; i < count; i++){
            enqueueLQ(ppQueue[(value[i] / factor) % radix], (LinkedQueueNode){value[i], NULL});
        }
        int i = 0;
        for(int j = 0; j < radix; j++){
            while(!isLinkedQueueEmpty(ppQueue[j])){
                LinkedQueueNode* pNode = dequeueLQ(ppQueue[j]);
                if(pNode != NULL){
                    value[i] = pNode->data;
                    i++;
                    free(pNode);
                }
            }
        }
        printf("Factor-%d 처리 후 ", factor);
        printArray(value, count);
    }
    for(int i = 0; i < radix; i++){
        deleteLinkedQueue(ppQueue[i]);
    }
    free(ppQueue);
}