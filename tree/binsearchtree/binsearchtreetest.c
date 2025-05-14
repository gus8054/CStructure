#include "binsearchtree.c"

// 중위 순회 함수 추가 (테스트용)
void inorderTraversal(BinSearchTreeNode* pNode) {
    if (pNode != NULL) {
        inorderTraversal(pNode->pLeftChild);
        printf("키: %d, 값: %c\n", pNode->key, pNode->value);
        inorderTraversal(pNode->pRightChild);
    }
}

// 트리 상태 출력 함수
void displayTree(BinSearchTree* pTree) {
    printf("\n=== 이진 탐색 트리 상태 ===\n");
    if (pTree == NULL || pTree->pRootNode == NULL) {
        printf("트리가 비어 있습니다.\n");
        return;
    }
    
    inorderTraversal(pTree->pRootNode);
    printf("=======================\n");
}

// 테스트 케이스 함수들
void testInsert(BinSearchTree* pTree) {
    printf("\n[삽입 테스트 시작]\n");
    
    BinSearchTreeNode nodes[] = {
        {'A', 30, NULL, NULL},
        {'B', 20, NULL, NULL},
        {'C', 40, NULL, NULL},
        {'D', 10, NULL, NULL},
        {'E', 25, NULL, NULL},
        {'F', 35, NULL, NULL},
        {'G', 50, NULL, NULL}
    };
    
    for (int i = 0; i < 7; i++) {
        if (insertElementBST(pTree, nodes[i])) {
            printf("삽입 성공 - 키: %d, 값: %c\n", nodes[i].key, nodes[i].value);
        } else {
            printf("삽입 실패 - 키: %d, 값: %c\n", nodes[i].key, nodes[i].value);
        }
    }
    
    // 중복 키 삽입 테스트
    BinSearchTreeNode duplicateNode = {'X', 30, NULL, NULL};
    if (!insertElementBST(pTree, duplicateNode)) {
        printf("중복 키 삽입 거부 테스트 성공 - 키: %d\n", duplicateNode.key);
    } else {
        printf("중복 키 삽입 거부 테스트 실패 - 키: %d\n", duplicateNode.key);
    }
    
    displayTree(pTree);
    printf("[삽입 테스트 종료]\n");
}

void testSearch(BinSearchTree* pTree) {
    printf("\n[검색 테스트 시작]\n");
    
    int keysToSearch[] = {30, 20, 40, 10, 25, 35, 50, 15, 60};
    
    for (int i = 0; i < 9; i++) {
        BinSearchTreeNode* foundNode = searchBST(pTree, keysToSearch[i]);
        if (foundNode != NULL) {
            printf("키 %d 검색 성공 - 값: %c\n", keysToSearch[i], foundNode->value);
        } else {
            printf("키 %d 검색 실패 - 존재하지 않음\n", keysToSearch[i]);
        }
    }
    
    printf("[검색 테스트 종료]\n");
}

void testDelete(BinSearchTree* pTree) {
    printf("\n[삭제 테스트 시작]\n");
    
    // 1. 리프 노드 삭제
    printf("1. 리프 노드 삭제 (키: 10)\n");
    if (deleteElementBST(pTree, 10)) {
        printf("키 10 삭제 성공\n");
    } else {
        printf("키 10 삭제 실패\n");
    }
    displayTree(pTree);
    
    // 2. 자식이 하나인 노드 삭제
    printf("\n2. 자식이 하나인 노드 삭제 (키: 40)\n");
    if (deleteElementBST(pTree, 40)) {
        printf("키 40 삭제 성공\n");
    } else {
        printf("키 40 삭제 실패\n");
    }
    displayTree(pTree);
    
    // 3. 자식이 둘인 노드 삭제
    printf("\n3. 자식이 둘인 노드 삭제 (키: 20)\n");
    if (deleteElementBST(pTree, 20)) {
        printf("키 20 삭제 성공\n");
    } else {
        printf("키 20 삭제 실패\n");
    }
    displayTree(pTree);
    
    // 4. 루트 노드 삭제
    printf("\n4. 루트 노드 삭제 (키: 30)\n");
    if (deleteElementBST(pTree, 30)) {
        printf("키 30 삭제 성공\n");
    } else {
        printf("키 30 삭제 실패\n");
    }
    displayTree(pTree);
    
    // 5. 존재하지 않는 키 삭제 시도
    printf("\n5. 존재하지 않는 키 삭제 시도 (키: 100)\n");
    if (!deleteElementBST(pTree, 100)) {
        printf("존재하지 않는 키 삭제 거부 테스트 성공\n");
    } else {
        printf("존재하지 않는 키 삭제 거부 테스트 실패\n");
    }
    
    printf("[삭제 테스트 종료]\n");
}

// 추가: 트리 구조 출력 함수 (디버깅용)
void printTree(BinSearchTreeNode* node, int level) {
    if (node != NULL) {
        // 오른쪽 서브트리 먼저 출력 (그래야 시각적으로 왼쪽이 왼쪽에 표시됨)
        printTree(node->pRightChild, level + 1);
        
        // 현재 노드 출력
        for (int i = 0; i < level; i++) {
            printf("    ");
        }
        printf("[%d:%c]\n", node->key, node->value);
        
        // 왼쪽 서브트리 출력
        printTree(node->pLeftChild, level + 1);
    }
}

// 중위 순회로 트리 내용 출력 (오름차순)
void inOrder(BinSearchTreeNode* node) {
    if (node != NULL) {
        inOrder(node->pLeftChild);
        printf("%d:%c ", node->key, node->value);
        inOrder(node->pRightChild);
    }
}

int binSearchTreeMain() {
    printf("=== 이진 탐색 트리 테스트 시작 ===\n");
    
    // 트리 생성
    BinSearchTree* myTree = createBinSearchTree();
    if (myTree == NULL) {
        printf("트리 생성 실패\n");
        return -1;
    }
    printf("트리 생성 성공\n");
    
    // 삽입 테스트
    testInsert(myTree);
    
    // 검색 테스트
    testSearch(myTree);
    
    // 삭제 테스트
    testDelete(myTree);
    
    // 메모리 해제
    deleteBinSearchTree(myTree);
    printf("\n트리 메모리 해제 완료\n");
    
    printf("=== 이진 탐색 트리 테스트 종료 ===\n");
    
    printf("\n삭제 노드의 왼쪽자식이 오른쪽 자식을 갖지 않는 케이스 테이스 시작\n");

    BinSearchTree* pTree = createBinSearchTree();
    if (pTree == NULL) {
        printf("트리 생성 실패\n");
        return -1;
    }
    
    // 테스트 데이터 준비
    BinSearchTreeNode nodes[] = {
        {'A', 30, NULL, NULL},  // 루트 노드
        {'B', 20, NULL, NULL},  // 루트의 왼쪽 자식
        {'C', 40, NULL, NULL},  // 루트의 오른쪽 자식
        {'D', 10, NULL, NULL},  // B의 왼쪽 자식
    };
    
    // 트리에 노드 삽입
    for (int i = 0; i < sizeof(nodes)/sizeof(nodes[0]); i++) {
        if (!insertElementBST(pTree, nodes[i])) {
            printf("노드 삽입 실패: %d\n", nodes[i].key);
        }
    }
    
    // 초기 트리 상태 출력
    printf("===== 초기 트리 상태 =====\n");
    printTree(pTree->pRootNode, 0);
    printf("\n중위 순회 결과: ");
    inOrder(pTree->pRootNode);
    printf("\n\n");
    
    // 문제가 발생하는 케이스: 루트 노드(30) 삭제
    printf("===== 노드 30 삭제 =====\n");
    if (deleteElementBST(pTree, 30)) {
        printf("노드 30 삭제 성공\n");
    } else {
        printf("노드 30 삭제 실패\n");
    }
    
    // 삭제 후 트리 상태 출력 (오류 발생하면 잘못된 트리 구조나 무한 루프 발생)
    printf("\n===== 삭제 후 트리 상태 =====\n");
    printTree(pTree->pRootNode, 0);
    printf("\n중위 순회 결과: ");
    inOrder(pTree->pRootNode);  // 순환 참조 있으면 스택 오버플로우 발생
    printf("\n\n");
    
    // 추가 테스트: 노드 20 삭제
    // 이것도 문제 발생할 수 있음 (왼쪽 자식이 자기 자신 참조)
    printf("===== 노드 20 삭제 =====\n");
    if (deleteElementBST(pTree, 20)) {
        printf("노드 20 삭제 성공\n");
    } else {
        printf("노드 20 삭제 실패\n");
    }
    
    printf("\n===== 삭제 후 최종 트리 상태 =====\n");
    printTree(pTree->pRootNode, 0);
    printf("\n중위 순회 결과: ");
    inOrder(pTree->pRootNode);
    printf("\n\n");
    
    // 트리 메모리 해제
    deleteBinSearchTree(pTree);
    printf("트리 메모리 해제 완료\n");
    return 0;
}