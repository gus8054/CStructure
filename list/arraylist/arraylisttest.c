#include "arraylist.c"

// 리스트의 모든 요소를 출력하는 유틸리티 함수
void displayArrayList(ArrayList* pList) {
  if (pList == NULL) {
    printf("리스트가 존재하지 않습니다.\n");
    return;
  }

  if (pList->currentElementCount == 0) {
    printf("리스트가 비어있습니다.\n");
    return;
  }

  printf("리스트 요소 [총 %d개]: ", pList->currentElementCount);
  for (int i = 0; i < pList->currentElementCount; i++) {
    printf("%d", pList->pElement[i].data);
    if (i < pList->currentElementCount - 1) {
      printf(", ");
    }
  }
  printf("\n");
}

int arrayListMain() {
  // 테스트 시작 메시지
  printf("ArrayList 구현 테스트 시작\n");
  printf("------------------------\n\n");

  // 1. 리스트 생성 테스트
  printf("1. 리스트 생성 테스트\n");
  ArrayList* myList = createArrayList(5);
  if (myList != NULL) {
    printf("리스트 생성 성공! 최대 요소 수: %d\n", myList->maxElementCount);
  } else {
    printf("리스트 생성 실패!\n");
    return -1;
  }
  printf("\n");

  // 2. 요소 추가 테스트
  printf("2. 요소 추가 테스트\n");

  // 처음 위치에 요소 추가
  ArrayListNode node1 = {10};
  if (addALElement(myList, 0, node1)) {
    printf("첫 번째 요소(10) 추가 성공!\n");
  } else {
    printf("첫 번째 요소 추가 실패!\n");
  }
  displayArrayList(myList);

  // 끝 위치에 요소 추가
  ArrayListNode node2 = {20};
  if (addALElement(myList, 1, node2)) {
    printf("두 번째 요소(20) 추가 성공!\n");
  } else {
    printf("두 번째 요소 추가 실패!\n");
  }
  displayArrayList(myList);

  // 중간 위치에 요소 추가
  ArrayListNode node3 = {15};
  if (addALElement(myList, 1, node3)) {
    printf("중간 위치에 요소(15) 추가 성공!\n");
  } else {
    printf("중간 위치에 요소 추가 실패!\n");
  }
  displayArrayList(myList);

  // 몇 개 더 추가
  addALElement(myList, 3, (ArrayListNode){25});
  addALElement(myList, 4, (ArrayListNode){30});
  printf("추가 요소 삽입 후:\n");
  displayArrayList(myList);
  printf("\n");

  // 3. 요소 가져오기 테스트
  printf("3. getArrayListNode 함수 테스트\n");
  int testPosition = 2;
  ArrayListNode* retrievedNode = getArrayListNode(myList, testPosition);
  if (retrievedNode != NULL) {
    printf("위치 %d의 요소 값: %d\n", testPosition, retrievedNode->data);

    // 원본 데이터 수정 테스트
    printf("노드 값을 %d에서 100으로 변경\n", retrievedNode->data);
    retrievedNode->data = 100;

    // 변경 후 리스트 출력
    printf("데이터 변경 후 리스트:\n");
    displayArrayList(myList);
  } else {
    printf("위치 %d의 요소를 가져오지 못했습니다.\n", testPosition);
  }
  printf("\n");

  // 4. 요소 제거 테스트
  printf("4. 요소 제거 테스트\n");
  int removePosition = 1;
  if (removeALElement(myList, removePosition)) {
    printf("위치 %d의 요소 제거 성공!\n", removePosition);
  } else {
    printf("위치 %d의 요소 제거 실패!\n", removePosition);
  }
  displayArrayList(myList);
  printf("\n");

  // 5. 리스트 길이 테스트
  printf("5. 리스트 길이 테스트\n");
  printf("현재 리스트 길이: %d\n", getArrayListLength(myList));
  printf("\n");

  // 6. 리스트가 가득 찼는지 테스트
  printf("6. 리스트 Full 여부 테스트\n");
  if (isArrayListFull(myList)) {
    printf("리스트가 가득 찼습니다.\n");
  } else {
    printf("리스트에 여유 공간이 있습니다. (현재: %d/%d)\n", 
           myList->currentElementCount, myList->maxElementCount);
  }

  // 리스트를 가득 채워보기
  printf("리스트를 가득 채워봅니다...\n");
  while (!isArrayListFull(myList)) {
    ArrayListNode newNode = {99};
    addALElement(myList, myList->currentElementCount, newNode);
  }
  displayArrayList(myList);

  if (isArrayListFull(myList)) {
    printf("리스트가 가득 찼습니다!\n");
  }
  printf("\n");

  // 7. 리스트 초기화 테스트
  printf("7. 리스트 초기화 테스트\n");
  clearArrayList(myList);
  printf("리스트 초기화 후:\n");
  displayArrayList(myList);
  printf("현재 리스트 길이: %d\n", getArrayListLength(myList));
  printf("\n");

  // 8. 리스트 메모리 해제 테스트
  printf("8. 리스트 메모리 해제\n");
  deleteArrayList(myList);
  printf("리스트 메모리 해제 완료\n");
  printf("\n");

  printf("테스트 완료!\n");

  return 0;
}