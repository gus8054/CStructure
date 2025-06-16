#include "doublylist.c"

// 리스트의 내용을 출력하는 함수 추가
void displayDoublyList(DoublyList* pList) {
  if (pList == NULL) {
    printf("리스트가 존재하지 않습니다.\n");
    return;
  }

  if (pList->currentElementCount == 0) {
    printf("리스트가 비어 있습니다.\n");
    return;
  }

  printf("더블 연결 리스트 내용(정방향): ");
  DoublyListNode* pNode = pList->headerNode.pRightLink;
  for (int i = 0; i < pList->currentElementCount; i++) {
    printf("%d", pNode->data);
    if (i < pList->currentElementCount - 1) {
      printf(" <-> ");
    }
    pNode = pNode->pRightLink;
  }
  printf("\n");

  printf("더블 연결 리스트 내용(역방향): ");
  pNode = pList->headerNode.pLeftLink;
  for (int i = 0; i < pList->currentElementCount; i++) {
    printf("%d", pNode->data);
    if (i < pList->currentElementCount - 1) {
      printf(" <-> ");
    }
    pNode = pNode->pLeftLink;
  }
  printf("\n");
}

int doublyListMain() {
  // 더블 연결 리스트 생성
  DoublyList* pList = createDoublyList();
  if (pList == NULL) {
    printf("더블 연결 리스트 생성 실패\n");
    return -1;
  }
  printf("더블 연결 리스트가 생성되었습니다.\n");

  // 노드 추가 테스트
  DoublyListNode node;
  node.data = 10;
  addDLElement(pList, 0, node);
  printf("첫 번째 노드 추가 후 리스트 크기: %d\n", getDoublyListLength(pList));
  displayDoublyList(pList);

  // 여러 노드 추가
  node.data = 20;
  addDLElement(pList, 1, node);
  node.data = 30;
  addDLElement(pList, 2, node);
  node.data = 40;
  addDLElement(pList, 3, node);
  printf("4개 노드 추가 후 리스트 크기: %d\n", getDoublyListLength(pList));
  displayDoublyList(pList);

  // 중간에 노드 추가
  node.data = 25;
  addDLElement(pList, 2, node);
  printf("중간에 노드 추가 후 리스트 크기: %d\n", getDoublyListLength(pList));
  displayDoublyList(pList);

  // 맨 앞에 노드 추가
  node.data = 5;
  addDLElement(pList, 0, node);
  printf("맨 앞에 노드 추가 후 리스트 크기: %d\n", getDoublyListLength(pList));
  displayDoublyList(pList);

  // 특정 위치의 노드 가져오기
  DoublyListNode* pNode = getDLElement(pList, 2);
  if (pNode != NULL) {
    printf("인덱스 2의 노드 데이터: %d\n", pNode->data);
  }

  // 노드 삭제 테스트
  removeDLElement(pList, 0);
  printf("첫 번째 노드 삭제 후 리스트 크기: %d\n", getDoublyListLength(pList));
  displayDoublyList(pList);

  removeDLElement(pList, 2);
  printf("중간 노드 삭제 후 리스트 크기: %d\n", getDoublyListLength(pList));
  displayDoublyList(pList);

  // 리스트 초기화
  clearDoublyList(pList);
  printf("리스트 초기화 후 크기: %d\n", getDoublyListLength(pList));

  // 다시 노드 추가
  node.data = 100;
  addDLElement(pList, 0, node);
  node.data = 200;
  addDLElement(pList, 1, node);
  printf("초기화 후 노드 추가: %d\n", getDoublyListLength(pList));
  displayDoublyList(pList);

  // 리스트 메모리 해제
  deleteDoublyList(pList);
  printf("더블 연결 리스트가 삭제되었습니다.\n");

  return 0;
}