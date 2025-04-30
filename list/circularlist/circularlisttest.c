#include "circularlist.c"

void displayCircularList(CircularList* pList){
  if(pList == NULL) {
    printf("리스트가 존재하지 않습니다.\n");
    return;
  }

  if(pList->currentElementCount == 0) {
    printf("리스트가 비어 있습니다.\n");
    return;
  }

  printf("원형 연결 리스트 내용: ");
  CircularListNode* pNode = pList->pHeadPointer;
  for(int i = 0; i < pList->currentElementCount; i++){
    printf("%d", pNode->data);
    if(i < pList->currentElementCount - 1){
      printf(" -> ");
    }
    pNode = pNode->pLink;
  }
  printf(" -> [처음으로 돌아감]\n");
}

int circularListMain(){
  // 원형 연결 리스트 생성
  CircularList* pList = createCircularList();
  if(pList == NULL) {
    printf("원형 연결 리스트 생성 실패\n");
    return -1;
  }
  printf("원형 연결 리스트가 생성되었습니다.\n");

  // 노드 추가 테스트
  CircularListNode node;
  node.data = 10;
  addCLElement(pList, 0, node);
  printf("첫 번째 노드 추가 후 리스트 크기: %d\n", getCircularListLength(pList));
  displayCircularList(pList);

  // 여러 노드 추가
  node.data = 20;
  addCLElement(pList, 1, node);
  node.data = 30;
  addCLElement(pList, 2, node);
  node.data = 40;
  addCLElement(pList, 3, node);
  printf("4개 노드 추가 후 리스트 크기: %d\n", getCircularListLength(pList));
  displayCircularList(pList);

  // 맨 앞에 노드 추가
  node.data = 5;
  addCLElement(pList, 0, node);
  printf("맨 앞에 노드 추가 후 리스트 크기: %d\n", getCircularListLength(pList));
  displayCircularList(pList);

  // 중간에 노드 추가
  node.data = 25;
  addCLElement(pList, 3, node);
  printf("중간에 노드 추가 후 리스트 크기: %d\n", getCircularListLength(pList));
  displayCircularList(pList);

  // 노드 삭제 테스트
  removeCLElement(pList, 0);
  printf("첫 번째 노드 삭제 후 리스트 크기: %d\n", getCircularListLength(pList));
  displayCircularList(pList);

  removeCLElement(pList, 2);
  printf("중간 노드 삭제 후 리스트 크기: %d\n", getCircularListLength(pList));
  displayCircularList(pList);

  // 특정 위치의 노드 가져오기
  CircularListNode* pNode = getCLElement(pList, 1);
  if(pNode != NULL){
    printf("인덱스 1의 노드 데이터: %d\n", pNode->data);
  }

  // 원형 연결 리스트 초기화
  clearCircularList(pList);
  printf("리스트 초기화 후 크기: %d\n", getCircularListLength(pList));
  displayCircularList(pList);

  // 리스트 메모리 해제
  deleteCircularList(pList);
  printf("원형 연결 리스트가 삭제되었습니다.\n");

  return 0;
}