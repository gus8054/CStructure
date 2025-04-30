#include "linkedlist.c"

// 리스트의 모든 요소를 출력하는 유틸리티 함수
void displayLinkedList(LinkedList* pList) {
  if (pList == NULL) {
    printf("리스트가 존재하지 않습니다.\n");
    return;
  }

  if (pList->currentElementCount == 0) {
    printf("리스트가 비어있습니다.\n");
    return;
  }

  printf("연결 리스트 요소 [총 %d개]: ", pList->currentElementCount);
  LinkedListNode* pNode = pList->headerNode.pLink;
  while (pNode != NULL) {
    printf("%d", pNode->data);
    if (pNode->pLink != NULL) {
      printf(" -> ");
    }
    pNode = pNode->pLink;
  }
  printf("\n");
}

int linkedListMain() {
  // 테스트 시작 메시지
  printf("연결 리스트 구현 테스트 시작\n");
  printf("------------------------\n\n");

  // 1. 리스트 생성 테스트
  printf("1. 리스트 생성 테스트\n");
  LinkedList* myList = createLinkedList();
  if (myList != NULL) {
    printf("연결 리스트 생성 성공!\n");
  } else {
    printf("연결 리스트 생성 실패!\n");
    return -1;
  }
  printf("\n");

  // 2. 요소 추가 테스트
  printf("2. 요소 추가 테스트\n");

  // 처음 위치에 요소 추가
  LinkedListNode node1 = {10, NULL};
  if (addLLElement(myList, 0, node1)) {
    printf("첫 번째 요소(10) 추가 성공!\n");
  } else {
    printf("첫 번째 요소 추가 실패!\n");
  }
  displayLinkedList(myList);

  // 끝 위치에 요소 추가
  LinkedListNode node2 = {20, NULL};
  if (addLLElement(myList, 1, node2)) {
    printf("두 번째 요소(20) 추가 성공!\n");
  } else {
    printf("두 번째 요소 추가 실패!\n");
  }
  displayLinkedList(myList);

  // 중간 위치에 요소 추가
  LinkedListNode node3 = {15, NULL};
  if (addLLElement(myList, 1, node3)) {
    printf("중간 위치에 요소(15) 추가 성공!\n");
  } else {
    printf("중간 위치에 요소 추가 실패!\n");
  }
  displayLinkedList(myList);

  // 몇 개 더 추가
  addLLElement(myList, 3, (LinkedListNode){25, NULL});
  addLLElement(myList, 4, (LinkedListNode){30, NULL});
  printf("추가 요소 삽입 후:\n");
  displayLinkedList(myList);
  printf("\n");

  // 3. 요소 가져오기 테스트
  printf("3. getLinkedListNode 함수 테스트\n");

  // 모든 위치에 대해 테스트
  for (int i = 0; i < myList->currentElementCount; i++) {
    LinkedListNode* retrievedNode = getLinkedListNode(myList, i);
    if (retrievedNode != NULL) {
      printf("위치 %d의 요소 값: %d\n", i, retrievedNode->data);
    } else {
      printf("위치 %d의 요소를 가져오지 못했습니다.\n", i);
    }
  }

  // 특정 위치의 노드 수정 테스트
  int modifyPosition = 2;
  LinkedListNode* nodeToModify = getLinkedListNode(myList, modifyPosition);
  if (nodeToModify != NULL) {
    printf("\n위치 %d의 노드 값을 %d에서 100으로 변경\n", 
           modifyPosition, nodeToModify->data);
    nodeToModify->data = 100;
    printf("데이터 변경 후 리스트:\n");
    displayLinkedList(myList);
  }
  printf("\n");

  // 4. 요소 제거 테스트
  printf("4. 요소 제거 테스트\n");
  int removePosition = 1;
  if (removeLLElement(myList, removePosition)) {
    printf("위치 %d의 요소 제거 성공!\n", removePosition);
  } else {
    printf("위치 %d의 요소 제거 실패!\n", removePosition);
  }
  displayLinkedList(myList);
  printf("\n");

  // 5. 리스트 길이 테스트
  printf("5. 리스트 길이 테스트\n");
  printf("현재 리스트 길이: %d\n", getLinkedListLength(myList));
  printf("\n");

  // 6. 경계 값 테스트
  printf("6. 경계 값 테스트\n");

  // 맨 앞에 요소 추가
  if (addLLElement(myList, 0, (LinkedListNode){5, NULL})) {
    printf("맨 앞에 요소(5) 추가 성공!\n");
  }

  // 맨 뒤에 요소 추가
  int lastPos = myList->currentElementCount;
  if (addLLElement(myList, lastPos, (LinkedListNode){35, NULL})) {
    printf("맨 뒤에 요소(35) 추가 성공!\n");
  }

  // 맨 앞 요소 제거
  if (removeLLElement(myList, 0)) {
    printf("맨 앞 요소 제거 성공!\n");
  }

  // 맨 뒤 요소 제거
  if (removeLLElement(myList, myList->currentElementCount - 1)) {
    printf("맨 뒤 요소 제거 성공!\n");
  }

  printf("경계 값 테스트 후 리스트:\n");
  displayLinkedList(myList);
  printf("\n");

  // 7. 리스트 초기화 테스트
  printf("7. 리스트 초기화 테스트\n");
  clearLinkedList(myList);
  printf("리스트 초기화 후:\n");
  displayLinkedList(myList);
  printf("현재 리스트 길이: %d\n", getLinkedListLength(myList));
  printf("\n");

  // 8. 리스트에 다시 요소 추가
  printf("8. 리스트에 다시 요소 추가\n");
  addLLElement(myList, 0, (LinkedListNode){100, NULL});
  addLLElement(myList, 1, (LinkedListNode){200, NULL});
  addLLElement(myList, 2, (LinkedListNode){300, NULL});
  displayLinkedList(myList);
  printf("\n");

  // 9. 리스트 메모리 해제 테스트
  printf("9. 리스트 메모리 해제\n");
  deleteLinkedList(myList);
  printf("리스트 메모리 해제 완료\n");
  printf("\n");

  printf("테스트 완료!\n");

  return 0;
}