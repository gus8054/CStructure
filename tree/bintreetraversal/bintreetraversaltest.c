#include "bintreetraversal.c"

int binTreeTraversalMain() {
    BinTreeNode root = {'A', false, NULL, NULL};
    BinTree* tree = createBinTree(root);

    BinTreeNode nodeB = {'B', false, NULL, NULL};
    BinTreeNode nodeC = {'C', false, NULL, NULL};
    BinTreeNode nodeD = {'D', false, NULL, NULL};
    BinTreeNode nodeE = {'E', false, NULL, NULL};
    BinTreeNode nodeF = {'F', false, NULL, NULL};
    BinTreeNode nodeG = {'G', false, NULL, NULL};

    BinTreeNode* nB = insertLeftChildNodeBT(tree->pRootNode, nodeB);
    BinTreeNode* nC = insertRightChildNodeBT(tree->pRootNode, nodeC);
    BinTreeNode* nD = insertLeftChildNodeBT(nB, nodeD);
    BinTreeNode* nE = insertRightChildNodeBT(nB, nodeE);
    BinTreeNode* nF = insertLeftChildNodeBT(nC, nodeF);
    BinTreeNode* nG = insertRightChildNodeBT(nC, nodeG);

    printf("Preorder: ");
    preorderTraversalBinTree(tree);
    printf("\n");

    // Reset visited flags before postorder
    tree->pRootNode->visited = false;
    nB->visited = false; nC->visited = false;
    nD->visited = false; nE->visited = false;
    nF->visited = false; nG->visited = false;

    printf("Inorder: ");
    inorderTraversalBinTree(tree);
    printf("\n");

    printf("Postorder(visited 플래그 이용): ");
    postorderTraversalBinTree(tree);
    printf("\n");

    printf("Postorder(stack 2개 이용): ");
    postorderTraversalBinTreeWithTwoStacks(tree);
    printf("\n");
    // Reset visited again before another postorder call if needed
    tree->pRootNode->visited = false;
    nB->visited = false; nC->visited = false;
    nD->visited = false; nE->visited = false;
    nF->visited = false; nG->visited = false;

    printf("Level Order: ");
    levelOrderTraversalBinTree(tree);
    printf("\n");

    deleteBinTree(tree);
    return 0;
}
// 전위 순회:
// A B D E C F G

// 중위 순회:
// D B E A F C G

// 후위 순회:
// D E B F G C A

// 레벨 순회:
// A B C D E F G