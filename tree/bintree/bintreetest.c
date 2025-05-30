#include "bintree.c"

    //     A
    //    / \
    //   B   C
    //  / \   \
    // D   E   F

int binTreeMain(void) {
    // 1. createBinTree()
    BinTreeNode rootNode = {'A', NULL, NULL};
    BinTree* tree = createBinTree(rootNode);
    if (tree == NULL) {
        printf("Failed to create tree.\n");
        return 1;
    }

    // 2. insertLeftChildNodeBT(), insertRightChildNodeBT()
    BinTreeNode nodeB = {'B', NULL, NULL};
    BinTreeNode nodeC = {'C', NULL, NULL};
    BinTreeNode nodeD = {'D', NULL, NULL};
    BinTreeNode nodeE = {'E', NULL, NULL};
    BinTreeNode nodeF = {'F', NULL, NULL};

    BinTreeNode* nodeBPtr = insertLeftChildNodeBT(tree->pRootNode, nodeB);
    BinTreeNode* nodeCPtr = insertRightChildNodeBT(tree->pRootNode, nodeC);
    insertLeftChildNodeBT(nodeBPtr, nodeD);
    insertRightChildNodeBT(nodeBPtr, nodeE);
    insertRightChildNodeBT(nodeCPtr, nodeF);

    printf("== Preorder Traversal ==\n");
    preorderTraversalRecursiveBinTree(tree);  // A B D E C F
    printf("\n");

    printf("== Inorder Traversal ==\n");
    inorderTraversalRecursiveBinTree(tree);   // D B E A C F
    printf("\n");

    printf("== Postorder Traversal ==\n");
    postorderTraversalRecursiveBinTree(tree); // D E B F C A
    printf("\n");

    // 3. getNodeCountBT()
    printf("Total Node Count: %d\n", getNodeCountBT(tree));  // 6

    // 4. getLeafNodeCountBT()
    printf("Leaf Node Count: %d\n", getLeafNodeCountBT(tree));  // 3 (D, E, F)

    // 5. getHeightBT()
    printf("Tree Height: %d\n", getHeightBT(tree));  // 3

    // 6. copyBinTree()
    BinTree* treeCopy = copyBinTree(tree);
    if (treeCopy == NULL) {
        printf("Failed to copy tree.\n");
        return 1;
    }

    printf("== Preorder of Copied Tree ==\n");
    preorderTraversalRecursiveBinTree(treeCopy);  // A B D E C F
    printf("\n");

    // 7. equalBinTree()
    bool isEqual = equalBinTree(tree, treeCopy);
    printf("Trees are equal: %s\n", isEqual ? "true" : "false");

    // 8. Access child node functions
    printf("Root Node: %c\n", getRootNodeBT(tree)->data);  // A
    printf("Left Child of Root: %c\n", getLeftChildNodeBT(tree->pRootNode)->data);  // B
    printf("Right Child of Root: %c\n", getRightChildNodeBT(tree->pRootNode)->data);  // C

    // 9. deleteBinTree()
    deleteBinTree(tree);
    deleteBinTree(treeCopy);

    printf("Trees deleted successfully.\n");

    return 0;
}
