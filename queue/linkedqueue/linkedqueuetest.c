#include "linkedqueue.c"

// 큐의 현재 상태를 출력하는 유틸리티 함수
void displayQueue(LinkedQueue* pQueue) {
    if (pQueue == NULL) {
        printf("Queue does not exist\n");
        return;
    }
    
    if (isLinkedQueueEmpty(pQueue)) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Queue elements: ");
    LinkedQueueNode* pNode = pQueue->pFront;
    while (pNode != NULL) {
        printf("%c ", pNode->data);
        pNode = pNode->pLink;
    }
    printf("\n");
    printf("Queue size: %d\n", pQueue->currentElementCount);
}

int linkedQueueMain() {
    // 테스트 1: 큐 생성
    printf("===== 테스트 1: 큐 생성 =====\n");
    LinkedQueue* myQueue = createLinkedQueue();
    if (myQueue != NULL) {
        printf("큐가 성공적으로 생성되었습니다.\n");
    } else {
        printf("큐 생성에 실패했습니다.\n");
        return -1;
    }
    
    // 테스트 2: 빈 큐 확인
    printf("\n===== 테스트 2: 빈 큐 확인 =====\n");
    if (isLinkedQueueEmpty(myQueue)) {
        printf("큐가 비어 있습니다.\n");
    } else {
        printf("큐가 비어 있지 않습니다.\n");
    }
    
    // 테스트 3: 큐에 요소 추가 (enqueue)
    printf("\n===== 테스트 3: 요소 추가 (enqueue) =====\n");
    LinkedQueueNode node1 = {'A', NULL};
    LinkedQueueNode node2 = {'B', NULL};
    LinkedQueueNode node3 = {'C', NULL};
    LinkedQueueNode node4 = {'D', NULL};
    LinkedQueueNode node5 = {'E', NULL};
    
    printf("요소 'A' 추가: %s\n", enqueueLQ(myQueue, node1) ? "성공" : "실패");
    displayQueue(myQueue);
    
    printf("요소 'B' 추가: %s\n", enqueueLQ(myQueue, node2) ? "성공" : "실패");
    displayQueue(myQueue);
    
    printf("요소 'C' 추가: %s\n", enqueueLQ(myQueue, node3) ? "성공" : "실패");
    displayQueue(myQueue);
    
    // 테스트 4: 큐 맨 앞 요소 확인 (peek)
    printf("\n===== 테스트 4: 맨 앞 요소 확인 (peek) =====\n");
    LinkedQueueNode* frontNode = peekLQ(myQueue);
    if (frontNode != NULL) {
        printf("큐의 맨 앞 요소: %c\n", frontNode->data);
    } else {
        printf("큐가 비어 있거나 오류가 발생했습니다.\n");
    }
    
    // 테스트 5: 큐에서 요소 제거 (dequeue)
    printf("\n===== 테스트 5: 요소 제거 (dequeue) =====\n");
    LinkedQueueNode* removedNode = dequeueLQ(myQueue);
    if (removedNode != NULL) {
        printf("제거된 요소: %c\n", removedNode->data);
        free(removedNode);  // 메모리 해제
    } else {
        printf("큐가 비어 있거나 오류가 발생했습니다.\n");
    }
    displayQueue(myQueue);
    
    // 테스트 6: 더 많은 요소 추가 후 제거
    printf("\n===== 테스트 6: 더 많은 요소 추가 후 제거 =====\n");
    printf("요소 'D' 추가: %s\n", enqueueLQ(myQueue, node4) ? "성공" : "실패");
    printf("요소 'E' 추가: %s\n", enqueueLQ(myQueue, node5) ? "성공" : "실패");
    displayQueue(myQueue);
    
    // 모든 요소 제거
    printf("\n===== 테스트 7: 모든 요소 제거 =====\n");
    while (!isLinkedQueueEmpty(myQueue)) {
        removedNode = dequeueLQ(myQueue);
        if (removedNode != NULL) {
            printf("제거된 요소: %c\n", removedNode->data);
            free(removedNode);  // 메모리 해제
        }
    }
    displayQueue(myQueue);
    
    // 테스트 8: 빈 큐에서 dequeue 시도
    printf("\n===== 테스트 8: 빈 큐에서 dequeue 시도 =====\n");
    removedNode = dequeueLQ(myQueue);
    if (removedNode == NULL) {
        printf("빈 큐에서 dequeue 실패 (예상된 결과)\n");
    } else {
        printf("빈 큐에서 dequeue 성공 (오류!)\n");
        free(removedNode);
    }
    
    // 테스트 9: 큐 삭제
    printf("\n===== 테스트 9: 큐 삭제 =====\n");
    deleteLinkedQueue(myQueue);
    printf("큐가 성공적으로 삭제되었습니다.\n");
    
    return 0;
}