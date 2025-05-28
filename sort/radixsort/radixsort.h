#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct LinkedQueueNodeType{
    int data;
    struct LinkedQueueNodeType* pLink;
} LinkedQueueNode;

typedef struct LinkedQueueType{
    int currentElementCount;
    LinkedQueueNode* pFront;
    LinkedQueueNode* pRear;
}LinkedQueue;

LinkedQueue* createLinkedQueue();
void deleteLinkedQueue(LinkedQueue* pQueue);
bool enqueueLQ(LinkedQueue* pQueue, LinkedQueueNode element);
LinkedQueueNode* dequeueLQ(LinkedQueue* pQueue);
LinkedQueueNode* peekLQ(LinkedQueue* pQueue);
bool isLinkedQueueFull(LinkedQueue* pQueue);
bool isLinkedQueueEmpty(LinkedQueue* pQueue);
