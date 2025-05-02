#include "bintree.c"

int binTreeMain(void) {
    printf("C 이진 트리 구현 테스트 코드 시작\n");

    // 1. 트리 생성 및 노드 삽입 테스트
    printf("\n--- 트리 생성 및 노드 삽입 테스트 ---\n");
    BinTreeNode rootElement = {'A', NULL, NULL};
    BinTree* pTree = createBinTree(rootElement);
    if (pTree == NULL) {
        fprintf(stderr, "트리 생성 실패\n");
        return 1;
    }
    printf("루트 노드 생성: %c\n", getRootNodeBT(pTree)->data);

    BinTreeNode b = {'B', NULL, NULL};
    BinTreeNode c = {'C', NULL, NULL};
    BinTreeNode d = {'D', NULL, NULL};
    BinTreeNode e = {'E', NULL, NULL};
    BinTreeNode f = {'F', NULL, NULL};
    BinTreeNode g = {'G', NULL, NULL};

    BinTreeNode* nodeB = insertLeftChildNodeBT(getRootNodeBT(pTree), b);
    BinTreeNode* nodeC = insertRightChildNodeBT(getRootNodeBT(pTree), c);
    if (nodeB && nodeC) {
        printf("루트 노드에 자식 노드 B(%c), C(%c) 삽입 완료\n", nodeB->data, nodeC->data);
    } else {
        fprintf(stderr, "자식 노드 삽입 실패\n");
    }

    BinTreeNode* nodeD = insertLeftChildNodeBT(nodeB, d);
    BinTreeNode* nodeE = insertRightChildNodeBT(nodeB, e);
    if (nodeD && nodeE) {
        printf("노드 B에 자식 노드 D(%c), E(%c) 삽입 완료\n", nodeD->data, nodeE->data);
    } else {
        fprintf(stderr, "노드 B 자식 노드 삽입 실패\n");
    }

    BinTreeNode* nodeF = insertLeftChildNodeBT(nodeC, f);
    BinTreeNode* nodeG = insertRightChildNodeBT(nodeC, g);
    if (nodeF && nodeG) {
        printf("노드 C에 자식 노드 F(%c), G(%c) 삽입 완료\n", nodeF->data, nodeG->data);
    } else {
        fprintf(stderr, "노드 C 자식 노드 삽입 실패\n");
    }

    // 2. 순회 테스트
    printf("\n--- 트리 순회 테스트 ---\n");
    printf("전위 순회 (Preorder): ");
    preorderTraversalRecursiveBinTree(pTree); // 예상 출력: A B D E C F G
    printf("\n");

    printf("중위 순회 (Inorder): ");
    inorderTraversalRecursiveBinTree(pTree); // 예상 출력: D B E A F C G
    printf("\n");

    printf("후위 순회 (Postorder): ");
    postorderTraversalRecursiveBinTree(pTree); // 예상 출력: D E B F G C A
    printf("\n");

    // 3. 노드 개수, 리프 노드 개수, 높이 테스트
    printf("\n--- 트리 정보 테스트 ---\n");
    printf("총 노드 개수: %d (예상: 7)\n", getNodeCountBT(pTree));
    printf("리프 노드 개수: %d (예상: 4)\n", getLeafNodeCountBT(pTree));
    printf("트리 높이: %d (예상: 3)\n", getHeightBT(pTree)); // 루트 높이 1부터 시작 시 3, 0부터 시작 시 2 (코드는 1부터 시작)

    // 4. 트리 복사 및 비교 테스트
    printf("\n--- 트리 복사 및 비교 테스트 ---\n");
    BinTree* pCopiedTree = copyBinTree(pTree);
    if (pCopiedTree) {
        printf("트리 복사 성공\n");
        printf("원본 트리와 복사본 트리 비교: %s\n", equalBinTree(pTree, pCopiedTree) ? "동일함" : "다름"); // 예상: 동일함

        // 복사본 트리 수정 후 비교
        BinTreeNode newElement = {'Z', NULL, NULL};
        insertLeftChildNodeBT(getLeftChildNodeBT(getRootNodeBT(pCopiedTree)), newElement); // 복사본의 D 노드 자리에 Z 삽입 시도 (원래 D는 자식 없음)
        printf("복사본 트리에 Z 삽입 후 원본과 비교: %s\n", equalBinTree(pTree, pCopiedTree) ? "동일함" : "다름"); // 예상: 다름

        // 복사본 트리 삭제
        deleteBinTree(pCopiedTree);
        printf("복사본 트리 삭제 완료\n");
    } else {
        fprintf(stderr, "트리 복사 실패\n");
    }

    // 5. 트리 삭제 테스트
    printf("\n--- 트리 삭제 테스트 ---\n");
    deleteBinTree(pTree);
    pTree = NULL; // 삭제 후 NULL로 설정하여 dangling pointer 방지
    printf("원본 트리 삭제 완료\n");

    // 삭제된 트리에 접근 시도 (segmentation fault 발생 가능, 테스트 목적으로 주석 처리)
    // printf("삭제 후 루트 노드: %p\n", getRootNodeBT(pTree)); // NULL 출력 예상

    printf("\nC 이진 트리 구현 테스트 코드 종료\n");

    return 0;
}