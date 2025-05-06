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
}BinTree;

typedef struct StackNodeType{
    BinTreeNode* data;
    struct StackNodeType* pLink;
} StackNode;

typedef struct StackType{
    int currentElementCount;
    StackNode* pTopElement;
} Stack;

typedef struct QueueNodeType{
    BinTreeNode* data;
    struct QueueNodeType* pLink;
} QueueNode;

typedef struct QueueType{
    int currentElementCount;
    QueueNode* pFront;
    QueueNode* pRear;
} Queue;

BinTree* createBinTree(BinTreeNode rootNode);
void deleteBinTree(BinTree* pBinTree);
void removeBinTreeNode(BinTreeNode* pNode);
BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParent, BinTreeNode element);
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParent, BinTreeNode element);
BinTreeNode* getRootNodeBT(BinTree* pBinTree);
BinTreeNode* getLeftChildNodeBT(BinTreeNode* pParentNode);
BinTreeNode* getRightChildNodeBT(BinTreeNode* pParentNode);

Stack* createStack();
void deleteStack(Stack* pStack);
bool pushStack(Stack* pStack, StackNode element);
StackNode* popStack(Stack* pStack);
bool isStackFull(Stack* pStack);
bool isStackEmpty(Stack* pStack);
int getStackLength(Stack* pStack);
StackNode* peekStack(Stack* pStack);

Queue* createQueue();
void deleteQueue(Queue* pQueue);
bool enqueueQueue(Queue* pQueue, QueueNode element);
QueueNode* dequeueQueue(Queue* pQueue);
bool isQueueFull(Queue* pQueue);
bool isQueueEmpty(Queue* pQueue);
int getQueueLength(Queue* pQueue);
QueueNode* peekQueue(Queue* pQueue);

void preorderTraversalBinTree(BinTree* pBinTree);
void inorderTraversalBinTree(BinTree* pBinTree);
void postorderTraversalBinTree(BinTree* pBinTree);
void levelOrderTraversalBinTree(BinTree* pBinTree);

bool pushBinTreeNode(Stack* pStack, BinTreeNode* pNode);
bool enqueueBinTreeNode(Queue* pQueue, BinTreeNode* pNode);