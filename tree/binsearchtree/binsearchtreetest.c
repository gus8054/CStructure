#include "binsearchtree.c"

// 추가 함수: 중위 순회로 트리 출력
void inorderTraversal(BinSearchTreeNode* pNode) {
    if (pNode != NULL) {
        inorderTraversal(pNode->pLeftChild);
        printf("키: %d, 값: %c\n", pNode->key, pNode->value);
        inorderTraversal(pNode->pRightChild);
    }
}

// 추가 함수: 트리 구조 시각적 출력
void printTree(BinSearchTreeNode* root, int level) {
    if (root == NULL) return;
    
    printTree(root->pRightChild, level + 1);
    
    for (int i = 0; i < level; i++) printf("    ");
    printf("%d(%c)\n", root->key, root->value);
    
    printTree(root->pLeftChild, level + 1);
}

// 메인 함수 - 테스트 코드
int binSearchTreeMain() {
    // 이진 탐색 트리 생성
    BinSearchTree* myTree = createBinSearchTree();
    if (myTree == NULL) {
        printf("트리 생성 실패\n");
        return -1;
    }
    printf("이진 탐색 트리 생성 성공\n\n");
    
    // 노드 삽입 테스트
    BinSearchTreeNode nodes[] = {
        {'G', 7, NULL, NULL},  // 루트 노드
        {'D', 4, NULL, NULL},
        {'B', 2, NULL, NULL},
        {'F', 6, NULL, NULL},
        {'A', 1, NULL, NULL},
        {'C', 3, NULL, NULL},
        {'E', 5, NULL, NULL},
        {'I', 9, NULL, NULL},
        {'H', 8, NULL, NULL},
        {'J', 10, NULL, NULL}
    };
    
    printf("=== 노드 삽입 테스트 ===\n");
    for (int i = 0; i < sizeof(nodes)/sizeof(nodes[0]); i++) {
        if (insertElementBST(myTree, nodes[i])) {
            printf("키:%d, 값:%c 삽입 성공\n", nodes[i].key, nodes[i].value);
        } else {
            printf("키:%d, 값:%c 삽입 실패\n", nodes[i].key, nodes[i].value);
        }
    }
    
    // 이미 존재하는 키로 삽입 테스트
    BinSearchTreeNode duplicateNode = {'X', 7, NULL, NULL};
    printf("\n=== 중복 키 삽입 테스트 ===\n");
    if (!insertElementBST(myTree, duplicateNode)) {
        printf("키:%d 중복으로 삽입 실패 (정상)\n", duplicateNode.key);
    }
    
    // 트리 출력 (중위 순회)
    printf("\n=== 트리 중위 순회 (오름차순 출력) ===\n");
    inorderTraversal(myTree->pRootNode);
    
    // 트리 구조 시각적 출력
    printf("\n=== 트리 구조 ===\n");
    printTree(myTree->pRootNode, 0);
    
    // 검색 테스트
    printf("\n=== 검색 테스트 ===\n");
    int keysToSearch[] = {5, 3, 11};
    for (int i = 0; i < sizeof(keysToSearch)/sizeof(keysToSearch[0]); i++) {
        BinSearchTreeNode* foundNode = searchBST(myTree, keysToSearch[i]);
        if (foundNode != NULL) {
            printf("키:%d 검색 성공 - 값:%c\n", keysToSearch[i], foundNode->value);
        } else {
            printf("키:%d 검색 실패 - 존재하지 않음\n", keysToSearch[i]);
        }
    }
    
    // 삭제 테스트 - 리프 노드 삭제
    printf("\n=== 리프 노드 삭제 테스트 ===\n");
    int leafKey = 1; // 'A' 노드 (리프 노드)
    if (removeElementBST(myTree, leafKey)) {
        printf("키:%d 삭제 성공\n", leafKey);
    } else {
        printf("키:%d 삭제 실패\n", leafKey);
    }
    
    printf("\n=== 리프 노드 삭제 후 트리 구조 ===\n");
    printTree(myTree->pRootNode, 0);
    
    // 삭제 테스트 - 자식이 하나인 노드 삭제
    printf("\n=== 자식이 하나인 노드 삭제 테스트 ===\n");
    int oneChildKey = 9; // 'I' 노드 (자식이 하나)
    if (removeElementBST(myTree, oneChildKey)) {
        printf("키:%d 삭제 성공\n", oneChildKey);
    } else {
        printf("키:%d 삭제 실패\n", oneChildKey);
    }
    
    printf("\n=== 자식이 하나인 노드 삭제 후 트리 구조 ===\n");
    printTree(myTree->pRootNode, 0);
    
    // 삭제 테스트 - 자식이 둘인 노드 삭제
    printf("\n=== 자식이 둘인 노드 삭제 테스트 ===\n");
    int twoChildrenKey = 4; // 'D' 노드 (자식이 둘)
    if (removeElementBST(myTree, twoChildrenKey)) {
        printf("키:%d 삭제 성공\n", twoChildrenKey);
    } else {
        printf("키:%d 삭제 실패\n", twoChildrenKey);
    }
    
    printf("\n=== 자식이 둘인 노드 삭제 후 트리 구조 ===\n");
    printTree(myTree->pRootNode, 0);
    
    // 루트 노드 삭제 테스트
    printf("\n=== 루트 노드 삭제 테스트 ===\n");
    int rootKey = 7; // 'G' 노드 (루트 노드)
    if (removeElementBST(myTree, rootKey)) {
        printf("키:%d (루트 노드) 삭제 성공\n", rootKey);
    } else {
        printf("키:%d 삭제 실패\n", rootKey);
    }
    
    printf("\n=== 루트 노드 삭제 후 트리 구조 ===\n");
    printTree(myTree->pRootNode, 0);
    
    // 트리가 비어있는지 확인
    printf("\n=== 최종 중위 순회 ===\n");
    inorderTraversal(myTree->pRootNode);
    
    // 트리 메모리 해제
    deleteBinSearchTree(myTree);
    printf("\n이진 탐색 트리 메모리 해제 완료\n");
    
    return 0;
}