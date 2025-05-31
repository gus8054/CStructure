#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct BinTreeNodeType{
    char data;
    bool visited;
    struct BinTreeNodeType* pLeftChild;
    struct BinTreeNodeType* pRightChild;
} BinTreeNode;

typedef struct BinTreeType{
    BinTreeNode* pRootNode;
} BinTree;

typedef struct LinkedStackNodeType{
    BinTreeNode* pTreeNode;
    struct LinkedStackNodeType* pLink;
} LinkedStackNode;

typedef struct LinkedStackType{
    int currentElementCount;
    LinkedStackNode* pTopElement;
} LinkedStack;

typedef struct LinkedQueueNodeType{
    BinTreeNode* pTreeNode;
    struct LinkedQueueNodeType* pLink;
} LinkedQueueNode;

typedef struct LinkedQueueType{
    int currentElementCount;
    LinkedQueueNode* pFront;
    LinkedQueueNode* pRear;
} LinkedQueue;

BinTree* createBinTree(BinTreeNode rootNode);
void deleteBinTree(BinTree* pTree);
void deleteBinTreeNode(BinTreeNode* pNode);
BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pNode, BinTreeNode element);
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pNode, BinTreeNode element);

LinkedStack* createLinkedStack();
void deleteLinkedStack(LinkedStack* pStack);
bool pushLS(LinkedStack* pStack, LinkedStackNode element);
LinkedStackNode* popLS(LinkedStack* pStack);
LinkedStackNode* peekLS(LinkedStack* pStack);

LinkedQueue* createLinkedQueue();
void deleteLinkedQueue(LinkedQueue* pQueue);
bool enqueueLQ(LinkedQueue* pQueue, LinkedQueueNode element);
LinkedQueueNode* dequeueLQ(LinkedQueue* pQueue);
LinkedQueueNode* peekLQ(LinkedQueue* pQueue);

void preorderTraversalBinTree(BinTree* pTree);
void inorderTraversalBinTree(BinTree* pTree);
void postorderTraversalBinTree(BinTree* pTree);
void postorderTraversalBinTreeWithTwoStacks(BinTree* pTree);
void levelOrderTraversalBinTree(BinTree* pTree);