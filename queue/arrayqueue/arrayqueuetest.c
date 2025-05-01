#include "arrayQueue.c"

// 큐의 상태를 출력하는 함수
void displayArrayQueue(ArrayQueue* pQueue) {
    printf("\n===== 배열 큐 상태 =====\n");
    printf("최대 원소 개수: %d\n", pQueue->maxElementCount);
    printf("현재 원소 개수: %d\n", pQueue->currentElementCount);
    printf("Front 인덱스: %d\n", pQueue->front);
    printf("Rear 인덱스: %d\n", pQueue->rear);
    
    if (isArrayQueueEmpty(pQueue)) {
        printf("큐가 비어있습니다.\n");
    } else {
        printf("큐 내용 (Front -> Rear): ");
        int i, position;
        for (i = 0; i < pQueue->currentElementCount; i++) {
            position = (pQueue->front + 1 + i) % pQueue->maxElementCount;
            printf("%c ", pQueue->pElement[position].data);
        }
        printf("\n");
    }
    printf("=======================\n\n");
}

int arrayQueueMain() {
    // 큐 생성 (최대 5개의 원소를 저장할 수 있는 큐)
    int maxSize = 5;
    ArrayQueue* pQueue = createArrayQueue(maxSize);
    if (pQueue == NULL) {
        printf("큐 생성 실패\n");
        return -1;
    }
    
    // 1. 빈 큐 확인
    printf("1. 빈 큐 확인\n");
    displayArrayQueue(pQueue);
    
    // 2. 데이터 삽입 테스트 (A, B, C)
    printf("2. 데이터 삽입 (A, B, C)\n");
    ArrayQueueNode node;
    
    node.data = 'A';
    enqueueAQ(pQueue, node);
    
    node.data = 'B';
    enqueueAQ(pQueue, node);
    
    node.data = 'C';
    enqueueAQ(pQueue, node);
    
    displayArrayQueue(pQueue);
    
    // 3. peek 테스트
    printf("3. 큐의 맨 앞 원소 확인 (peek)\n");
    ArrayQueueNode* pNode = peekAQ(pQueue);
    if (pNode != NULL) {
        printf("맨 앞 원소: %c\n", pNode->data);
    } else {
        printf("큐가 비어있습니다.\n");
    }
    
    // 4. dequeue 테스트
    printf("4. 큐에서 데이터 꺼내기 (dequeue)\n");
    pNode = dequeueAQ(pQueue);
    if (pNode != NULL) {
        printf("꺼낸 원소: %c\n", pNode->data);
        free(pNode);  // 메모리 해제 필수
    }
    
    displayArrayQueue(pQueue);
    
    // 5. 추가 데이터 삽입 (D, E, F)
    printf("5. 추가 데이터 삽입 (D, E, F)\n");
    
    node.data = 'D';
    enqueueAQ(pQueue, node);
    
    node.data = 'E';
    enqueueAQ(pQueue, node);
    
    node.data = 'F';
    bool result = enqueueAQ(pQueue, node);
    if (!result) {
        printf("큐가 가득 차서 'F'를 삽입할 수 없습니다.\n");
    } else {
        printf("'F' 삽입 성공\n");
    }
    
    displayArrayQueue(pQueue);
    
    // 6. 큐가 가득 찼는지 확인
    printf("6. 큐가 가득 찼는지 확인: %s\n", 
           isArrayQueueFull(pQueue) ? "가득 참" : "여유 있음");
    
    // 7. 추가 데이터 삽입 시도 (G - 실패해야 함)
    printf("7. 큐가 가득 찬 상태에서 삽입 시도 (G)\n");
    node.data = 'G';
    result = enqueueAQ(pQueue, node);
    printf("삽입 결과: %s\n", result ? "성공" : "실패");
    
    // 8. 원형 큐의 동작 테스트 - 일부 데이터 제거 후 새 데이터 추가
    printf("8. 원형 큐 동작 테스트 - 일부 데이터 제거 후 새 데이터 추가\n");
    
    // 두 개의 항목 제거
    pNode = dequeueAQ(pQueue);
    if (pNode != NULL) {
        printf("꺼낸 원소: %c\n", pNode->data);
        free(pNode);
    }
    
    pNode = dequeueAQ(pQueue);
    if (pNode != NULL) {
        printf("꺼낸 원소: %c\n", pNode->data);
        free(pNode);
    }
    
    displayArrayQueue(pQueue);
    
    // 새 항목 두 개 추가
    printf("두 개의 항목 제거 후 새 항목 추가 (G, H)\n");
    
    node.data = 'G';
    enqueueAQ(pQueue, node);
    
    node.data = 'H';
    enqueueAQ(pQueue, node);
    
    displayArrayQueue(pQueue);
    
    // 9. 남은 모든 원소 꺼내기
    printf("9. 남은 모든 원소 꺼내기\n");
    while (!isArrayQueueEmpty(pQueue)) {
        pNode = dequeueAQ(pQueue);
        if (pNode != NULL) {
            printf("꺼낸 원소: %c\n", pNode->data);
            free(pNode);  // 메모리 해제 필수
        }
    }
    
    displayArrayQueue(pQueue);
    
    // 10. 빈 큐에서 dequeue 시도
    printf("10. 빈 큐에서 dequeue 시도\n");
    pNode = dequeueAQ(pQueue);
    if (pNode == NULL) {
        printf("큐가 비어 있어서 원소를 꺼낼 수 없습니다.\n");
    }
    
    // 11. 큐 메모리 해제
    printf("11. 큐 메모리 해제\n");
    deleteArrayQueue(pQueue);
    printf("큐가 성공적으로 삭제되었습니다.\n");
    
    return 0;
}