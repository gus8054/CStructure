#include "linkedstack.c"

// 스택의 현재 상태를 출력하는 함수
void displayLinkedStack(LinkedStack* pStack) {
    printf("\n===== 연결 스택 상태 =====\n");
    printf("현재 원소 개수: %d\n", pStack->currentElementCount);
    
    if (isLinkedStackEmpty(pStack)) {
        printf("스택이 비어있습니다.\n");
    } else {
        printf("스택 내용 (Top -> Bottom): ");
        LinkedStackNode* pNode = pStack->pTopElement;
        while (pNode != NULL) {
            printf("%c ", pNode->data);
            pNode = pNode->pLink;
        }
        printf("\n");
    }
    printf("=========================\n\n");
}

int linkedStackMain() {
    // 연결 스택 생성
    LinkedStack* pStack = createLinkedStack();
    if (pStack == NULL) {
        printf("스택 생성 실패\n");
        return -1;
    }
    
    // 1. 빈 스택 확인
    printf("1. 빈 스택 확인\n");
    displayLinkedStack(pStack);
    
    // 2. 데이터 삽입 테스트
    printf("2. 데이터 삽입 (A, B, C, D, E)\n");
    LinkedStackNode node;
    node.pLink = NULL;  // 일단 초기화 (실제로는 pushLS 함수에서 이 값을 덮어씁니다)
    
    node.data = 'A';
    pushLS(pStack, node);
    
    node.data = 'B';
    pushLS(pStack, node);
    
    node.data = 'C';
    pushLS(pStack, node);
    
    node.data = 'D';
    pushLS(pStack, node);
    
    node.data = 'E';
    pushLS(pStack, node);
    
    displayLinkedStack(pStack);
    
    // 3. peek 테스트
    printf("3. 스택의 맨 위 원소 확인 (peek)\n");
    LinkedStackNode* pNode = peekLS(pStack);
    if (pNode != NULL) {
        printf("맨 위 원소: %c\n", pNode->data);
    } else {
        printf("스택이 비어있습니다.\n");
    }
    
    // 4. pop 테스트
    printf("4. 스택에서 데이터 꺼내기 (pop)\n");
    pNode = popLS(pStack);
    if (pNode != NULL) {
        printf("꺼낸 원소: %c\n", pNode->data);
        free(pNode);  // 메모리 해제 필수
    }
    
    displayLinkedStack(pStack);
    
    // 5. 스택이 가득 찼는지 확인 (연결 리스트 스택은 가득 찰 수 없음)
    printf("5. 스택이 가득 찼는지 확인: %s\n", 
           isLinkedStackFull(pStack) ? "가득 참" : "가득 찰 수 없음");
    
    // 6. 남은 모든 원소 꺼내기
    printf("6. 남은 모든 원소 꺼내기\n");
    while (!isLinkedStackEmpty(pStack)) {
        pNode = popLS(pStack);
        if (pNode != NULL) {
            printf("꺼낸 원소: %c\n", pNode->data);
            free(pNode);  // 메모리 해제 필수
        }
    }
    
    displayLinkedStack(pStack);
    
    // 7. 빈 스택에서 pop 시도
    printf("7. 빈 스택에서 pop 시도\n");
    pNode = popLS(pStack);
    if (pNode == NULL) {
        printf("스택이 비어 있어서 원소를 꺼낼 수 없습니다.\n");
    }
    
    // 8. 메모리 해제
    printf("8. 스택 메모리 해제\n");
    node.pLink = NULL;  // 일단 초기화 (실제로는 pushLS 함수에서 이 값을 덮어씁니다)
    
    node.data = 'A';
    pushLS(pStack, node);
    
    node.data = 'B';
    pushLS(pStack, node);
    
    node.data = 'C';
    pushLS(pStack, node);
    
    node.data = 'D';
    pushLS(pStack, node);
    
    node.data = 'E';
    pushLS(pStack, node);
    printf("스택에 다시 값 추가\n");
    displayLinkedStack(pStack);
    deleteLinkedStack(pStack);
    printf("스택이 성공적으로 삭제되었습니다.\n");
    
    return 0;
}