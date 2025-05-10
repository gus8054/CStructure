#include "arrayheap.c"

// 힙의 내용을 출력하는 함수 추가
void displayArrayHeap(ArrayMaxHeap* pHeap) {
    if(pHeap == NULL) return;
    
    printf("현재 힙 요소 수: %d\n", pHeap->currentElementCount);
    printf("힙 내용: ");
    for(int i = 1; i <= pHeap->currentElementCount; i++) {
        printf("(%c:%d) ", pHeap->pElement[i].data, pHeap->pElement[i].key);
    }
    printf("\n");
}

int arrayHeapTestMain() {
    // 최대 힙 생성 (크기 10)
    ArrayMaxHeap* maxHeap = createArrayMaxHeap(10);
    if(maxHeap == NULL) {
        printf("힙 생성 실패\n");
        return -1;
    }
    
    printf("==== 최대 힙 테스트 시작 ====\n");
    
    // 여러 원소 삽입
    ArrayMaxHeapNode nodes[] = {
        {'A', 9},
        {'B', 15},
        {'C', 4},
        {'D', 20},
        {'E', 13},
        {'F', 7},
        {'G', 10}
    };
    
    int nodeCount = sizeof(nodes) / sizeof(ArrayMaxHeapNode);
    
    printf("\n*** 요소 삽입 테스트 ***\n");
    for(int i = 0; i < nodeCount; i++) {
        printf("삽입: (%c:%d)\n", nodes[i].data, nodes[i].key);
        insertArrayMaxHeapElement(maxHeap, nodes[i]);
        displayArrayHeap(maxHeap);
    }
    
    printf("\n*** 요소 제거 테스트 ***\n");
    // 최대 힙에서 원소 제거 테스트
    while(maxHeap->currentElementCount > 0) {
        ArrayMaxHeapNode* removedNode = removeArrayMaxHeapElement(maxHeap);
        if(removedNode != NULL) {
            printf("제거된 최대값: (%c:%d)\n", removedNode->data, removedNode->key);
            free(removedNode);
            
            if(maxHeap->currentElementCount > 0) {
                printf("제거 후 힙 상태:\n");
                displayArrayHeap(maxHeap);
            }
        }
    }
    
    printf("\n힙이 비었습니다.\n");
    
    // 메모리 해제
    deleteArrayMaxHeap(maxHeap);
    printf("==== 최대 힙 테스트 종료 ====\n");
    
    return 0;
}