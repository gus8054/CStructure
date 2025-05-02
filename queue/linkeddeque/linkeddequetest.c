#include "linkeddeque.c"

// 덱의 내용을 출력하는 함수
void displayDeque(LinkedDeque* pDeque) {
    if (pDeque == NULL) {
        printf("덱이 존재하지 않습니다.\n");
        return;
    }
    
    if (isLinkedDequeEmpty(pDeque)) {
        printf("덱이 비어있습니다.\n");
        return;
    }
    
    printf("덱 내용(앞에서 뒤로): ");
    LinkedDequeNode* current = pDeque->pFront;
    while (current != NULL) {
        printf("%c ", current->data);
        current = current->pRightLink;
    }
    printf("\n현재 원소 개수: %d\n", pDeque->currentElementCount);
}

int linkedDequeMain() {
    // 1. 덱 생성
    LinkedDeque* myDeque = createLinkedDeque();
    if (myDeque == NULL) {
        printf("덱 생성 실패\n");
        return -1;
    }
    printf("덱이 생성되었습니다.\n");
    
    // 2. 앞쪽에 원소 추가
    LinkedDequeNode node;
    node.data = 'A';
    if (pushFrontLD(myDeque, node)) {
        printf("앞쪽에 %c를 추가했습니다.\n", node.data);
    }
    displayDeque(myDeque);
    
    // 3. 뒤쪽에 원소 추가
    node.data = 'B';
    if (pushRearLD(myDeque, node)) {
        printf("뒤쪽에 %c를 추가했습니다.\n", node.data);
    }
    displayDeque(myDeque);
    
    // 4. 여러 원소 추가
    node.data = 'C';
    pushFrontLD(myDeque, node);
    node.data = 'D';
    pushRearLD(myDeque, node);
    printf("여러 원소를 추가했습니다.\n");
    displayDeque(myDeque);
    
    // 5. 앞쪽에서 원소 확인
    LinkedDequeNode* frontNode = peekFrontLD(myDeque);
    if (frontNode != NULL) {
        printf("앞쪽 원소: %c\n", frontNode->data);
    }
    
    // 6. 뒤쪽에서 원소 확인
    LinkedDequeNode* rearNode = peekRearLD(myDeque);
    if (rearNode != NULL) {
        printf("뒤쪽 원소: %c\n", rearNode->data);
    }
    
    // 7. 앞쪽에서 원소 제거
    LinkedDequeNode* poppedFront = popFrontLD(myDeque);
    if (poppedFront != NULL) {
        printf("앞쪽에서 %c를 제거했습니다.\n", poppedFront->data);
        free(poppedFront);  // 메모리 해제
    }
    displayDeque(myDeque);
    
    // 8. 뒤쪽에서 원소 제거
    LinkedDequeNode* poppedRear = popRearLD(myDeque);
    if (poppedRear != NULL) {
        printf("뒤쪽에서 %c를 제거했습니다.\n", poppedRear->data);
        free(poppedRear);  // 메모리 해제
    }
    displayDeque(myDeque);
    
    // 9. 모든 원소 제거
    while (!isLinkedDequeEmpty(myDeque)) {
        LinkedDequeNode* popped = popFrontLD(myDeque);
        if (popped != NULL) {
            printf("%c 제거\n", popped->data);
            free(popped);
        }
    }
    displayDeque(myDeque);
    
    // 10. 빈 덱에서 pop 시도
    if (popFrontLD(myDeque) == NULL) {
        printf("빈 덱에서 앞쪽 pop 시도: 실패(정상)\n");
    }
    
    if (popRearLD(myDeque) == NULL) {
        printf("빈 덱에서 뒤쪽 pop 시도: 실패(정상)\n");
    }
    
    // 11. 덱 메모리 해제
    deleteLinkedDeque(myDeque);
    printf("덱이 삭제되었습니다.\n");
    
    return 0;
}