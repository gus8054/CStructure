#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct ArrayHeapNodeType{
    char data;
    int key;
} ArrayMaxHeapNode, ArrayMinHeapNode;

typedef struct ArrayHeapType{
    int maxElementCount;
    int currentElementCount;
    ArrayMaxHeapNode* pElement;
} ArrayMaxHeap, ArrayMinHeap;

ArrayMaxHeap* createArrayMaxHeap(int maxElementCount);
void deleteArrayMaxHeap(ArrayMaxHeap* pMaxHeap);
void insertArrayMaxHeapElement(ArrayMaxHeap* pMaxHeap, ArrayMaxHeapNode element);
ArrayMaxHeapNode* removeArrayMaxHeapElement(ArrayMaxHeap* pMaxHeap);