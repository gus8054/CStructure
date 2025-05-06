#include "bintreetraversal.c"

// 트리의 모든 노드의 visited 플래그를 초기화
void resetTreeVisitedFlags(BinTreeNode* pNode) {
    if (pNode == NULL) return;
    
    pNode->visited = false;
    resetTreeVisitedFlags(pNode->pLeftChild);
    resetTreeVisitedFlags(pNode->pRightChild);
}

int binTreeTraversalMain() {
    // 테스트 트리 생성
    // 구조:
    //      A
    //     / \
    //    B   C
    //   / \   \
    //  D   E   F
    //     / \
    //    G   H
    
    BinTreeNode nodeA = {'A', false, NULL, NULL};
    BinTree* pBinTree = createBinTree(nodeA);
    
    if (pBinTree == NULL) {
        printf("트리 생성 실패\n");
        return -1;
    }
    
    BinTreeNode nodeB = {'B', false, NULL, NULL};
    BinTreeNode nodeC = {'C', false, NULL, NULL};
    BinTreeNode nodeD = {'D', false, NULL, NULL};
    BinTreeNode nodeE = {'E', false, NULL, NULL};
    BinTreeNode nodeF = {'F', false, NULL, NULL};
    BinTreeNode nodeG = {'G', false, NULL, NULL};
    BinTreeNode nodeH = {'H', false, NULL, NULL};
    
    // 노드 연결
    BinTreeNode* pNodeA = getRootNodeBT(pBinTree);
    BinTreeNode* pNodeB = insertLeftChildNodeBT(pNodeA, nodeB);
    BinTreeNode* pNodeC = insertRightCHildNodeBT(pNodeA, nodeC);
    BinTreeNode* pNodeD = insertLeftChildNodeBT(pNodeB, nodeD);
    BinTreeNode* pNodeE = insertRightCHildNodeBT(pNodeB, nodeE);
    BinTreeNode* pNodeF = insertRightCHildNodeBT(pNodeC, nodeF);
    BinTreeNode* pNodeG = insertLeftChildNodeBT(pNodeE, nodeG);
    BinTreeNode* pNodeH = insertRightCHildNodeBT(pNodeE, nodeH);
    
    // 순회 테스트
    printf("전위 순회(Preorder): ");
    preorderTraversalBinTree(pBinTree);
    printf("\n");
    
    printf("중위 순회(Inorder): ");
    inorderTraversalBinTree(pBinTree);
    printf("\n");
    
    // 후위 순회 전에 visited 플래그 초기화
    resetTreeVisitedFlags(pBinTree->pRootNode);
    printf("후위 순회(Postorder): ");
    postorderTraversalBinTree(pBinTree);
    printf("\n");
    
    // 레벨 순회
    printf("레벨 순회(LevelOrder): ");
    levelOrderTraversalBinTree(pBinTree);
    printf("\n");

    // 메모리 해제
    deleteBinTree(pBinTree);
    
    return 0;
}

// 전위 순회(Preorder): A B D E G H C F 
// 중위 순회(Inorder): D B G E H A C F 
// 후위 순회(Postorder): D G H E B F C A
// 레벨 순회(LevelOrder): A B C D E F G H