#include "arraystack.c"

// 스택의 상태를 출력하는 함수
void displayStack(ArrayStack* pStack) {
    printf("\n===== 스택 상태 =====\n");
    printf("최대 원소 개수: %d\n", pStack->maxElementCount);
    printf("현재 원소 개수: %d\n", pStack->currentElementCount);
    
    if (isArrayStackEmpty(pStack)) {
        printf("스택이 비어있습니다.\n");
    } else {
        printf("스택 내용: ");
        for (int i = 0; i < pStack->currentElementCount; i++) {
            printf("%c ", pStack->pElement[i].data);
        }
        printf("\n");
    }
    printf("======================\n\n");
}

int arrayStackMain() {
    // 스택 생성 (최대 5개의 원소를 저장할 수 있는 스택)
    ArrayStack* pStack = createArrayStack(5);
    if (pStack == NULL) {
        printf("스택 생성 실패\n");
        return -1;
    }
    
    printf("1. 빈 스택 확인\n");
    displayStack(pStack);
    
    // 데이터 삽입 테스트
    printf("2. 데이터 삽입 (A, B, C, D, E)\n");
    ArrayStackNode node;
    
    node.data = 'A';
    pushAS(pStack, node);
    
    node.data = 'B';
    pushAS(pStack, node);
    
    node.data = 'C';
    pushAS(pStack, node);
    
    node.data = 'D';
    pushAS(pStack, node);
    
    node.data = 'E';
    pushAS(pStack, node);
    
    displayStack(pStack);
    
    // 스택이 가득 찼는지 확인
    printf("3. 스택이 가득 찼는지 확인: %s\n", 
           isArrayStackFull(pStack) ? "가득 참" : "여유 있음");
    
    // 추가 데이터 삽입 시도 (실패해야 함)
    printf("4. 스택이 가득 찬 상태에서 삽입 시도\n");
    node.data = 'F';
    bool result = pushAS(pStack, node);
    printf("삽입 결과: %s\n", result ? "성공" : "실패");
    
    // peek 테스트
    printf("5. 스택의 맨 위 원소 확인 (peek)\n");
    ArrayStackNode* pNode = peekAS(pStack);
    if (pNode != NULL) {
        printf("맨 위 원소: %c\n", pNode->data);
    } else {
        printf("스택이 비어있습니다.\n");
    }
    
    // pop 테스트
    printf("6. 스택에서 데이터 꺼내기 (pop)\n");
    pNode = popAS(pStack);
    if (pNode != NULL) {
        printf("꺼낸 원소: %c\n", pNode->data);
        free(pNode);  // 메모리 해제 필수
    }
    
    displayStack(pStack);
    
    // 남은 모든 원소 꺼내기
    printf("7. 남은 모든 원소 꺼내기\n");
    while (!isArrayStackEmpty(pStack)) {
        pNode = popAS(pStack);
        if (pNode != NULL) {
            printf("꺼낸 원소: %c\n", pNode->data);
            free(pNode);  // 메모리 해제 필수
        }
    }
    
    displayStack(pStack);
    
    // 빈 스택에서 pop 시도
    printf("8. 빈 스택에서 pop 시도\n");
    pNode = popAS(pStack);
    if (pNode == NULL) {
        printf("스택이 비어 있어서 원소를 꺼낼 수 없습니다.\n");
    }
    
    // 스택 삭제
    printf("9. 스택 메모리 해제\n");
    deleteArrayStack(pStack);
    printf("스택이 성공적으로 삭제되었습니다.\n");
    
    return 0;
}