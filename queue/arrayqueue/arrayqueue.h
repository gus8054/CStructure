#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct ArrayQueueNodeType{
    char data;
} ArrayQueueNode;

typedef struct ArrayQueueType{
    int maxElementCount;
    int currentElementCount;
    int front;
    int rear;
    ArrayQueueNode* pElement;
} ArrayQueue;

ArrayQueue* createArrayQueue(int maxElementCount);
void deleteArrayQueue(ArrayQueue* pQueue);
bool enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element);
ArrayQueueNode* dequeueAQ(ArrayQueue* pQueue);
ArrayQueueNode* peekAQ(ArrayQueue* pQueue);
bool isArrayQueueFull(ArrayQueue* pQueue);
bool isArrayQueueEmpty(ArrayQueue* pQueue);