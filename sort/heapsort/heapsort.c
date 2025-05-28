#include "heapsort.h"

ArrayMaxHeap* createArrayMaxHeap(int maxElementCount){
    if(maxElementCount <= 0) return NULL;

    ArrayMaxHeap* pReturn = (ArrayMaxHeap*)malloc(sizeof(ArrayMaxHeap));
    if(pReturn == NULL) return NULL;

    ArrayMaxHeapNode* pElement = (ArrayMaxHeapNode*)malloc(sizeof(ArrayMaxHeapNode) * (maxElementCount + 1));
    if(pElement == NULL){
        free(pReturn);
        return NULL;
    }
    memset(pElement, 0, sizeof(ArrayMaxHeapNode) * (maxElementCount + 1));

    pReturn->currentElementCount = 0;
    pReturn->maxElementCount = maxElementCount;
    pReturn->pElement = pElement;
    return pReturn;
}

void deleteArrayMaxHeap(ArrayMaxHeap* pHeap){
    if(pHeap == NULL) return;
    if(pHeap->pElement != NULL) free(pHeap->pElement);
    free(pHeap);
}

void insertArrayMaxHeapElement(ArrayMaxHeap* pHeap, ArrayMaxHeapNode element){
    if(pHeap == NULL) return;
    if(pHeap->currentElementCount == pHeap->maxElementCount) return;

    pHeap->currentElementCount++;

    int childIdx = pHeap->currentElementCount;
    int parentIdx = childIdx / 2;

    while(!(childIdx == 1 || pHeap->pElement[childIdx].key <= pHeap->pElement[parentIdx].key)){
        pHeap->pElement[childIdx] = pHeap->pElement[parentIdx];
        childIdx /= 2;
        parentIdx /= 2;
    }
    pHeap->pElement[childIdx] = element;
}

ArrayMaxHeapNode* removeArrayMaxHeapElement(ArrayMaxHeap* pHeap){
    if(pHeap == NULL) return NULL;
    if(pHeap->currentElementCount == 0) return NULL;

    ArrayMaxHeapNode* pReturn = (ArrayMaxHeapNode*)malloc(sizeof(ArrayMaxHeapNode));
    if(pReturn == NULL) return NULL;
    *pReturn = pHeap->pElement[1];
   
    ArrayMaxHeapNode lastNode = pHeap->pElement[pHeap->currentElementCount];
    pHeap->currentElementCount--;

    int parentIdx = 1;
    int childIdx = 2;

    // 마지막 노드의 인덱스가 왼쪽 자식의 인덱스보다 같거나 크다면 ( 즉, 왼쪽 자식 또는 왼쪽 오른쪽 자식 둘 다 트리에 포함된다면 ) 진입
    while(pHeap->currentElementCount >= childIdx){
        // 왼쪽 오른쪽 자식 둘 다 존재할 때만 진입
        if(pHeap->currentElementCount >= childIdx + 1 && pHeap->pElement[childIdx].key < pHeap->pElement[childIdx + 1].key){
            childIdx++;
        }

        if(lastNode.key >= pHeap->pElement[childIdx].key) break;

        pHeap->pElement[parentIdx] = pHeap->pElement[childIdx];
        parentIdx = childIdx;
        childIdx = parentIdx * 2;
    }
    pHeap->pElement[parentIdx] = lastNode;
    return pReturn;
}

void heapSort(int value[], int count){
    if(count <= 1) return;

    ArrayMaxHeap* pHeap = createArrayMaxHeap(count);
    if(pHeap == NULL) return;

    for(int i = 0; i < count; i++){
        insertArrayMaxHeapElement(pHeap, (ArrayMaxHeapNode){0, value[i]});
    }
    for(int i = 0; i < count; i++){
        ArrayMaxHeapNode* pHeapNode = removeArrayMaxHeapElement(pHeap);
        if(pHeapNode != NULL){
            value[i] = pHeapNode->key;
            free(pHeapNode);
        }
    }
    deleteArrayMaxHeap(pHeap);
}

void printArray(int value[], int count){
    if(count <= 0) return;
    for(int i = 0; i < count; i++){
        printf("%d ", value[i]);
    }
    printf("\n");
}