#include "bintreetraversal.h"

BinTree* createBinTree(BinTreeNode element){
    BinTree* pReturn = (BinTree*)malloc(sizeof(BinTree));
    if(pReturn == NULL) return NULL;

    BinTreeNode* pRootNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    if(pRootNode == NULL){
        free(pReturn);
        return NULL;
    }
    memset(pRootNode, 0, sizeof(BinTreeNode));
    pRootNode->data = element.data;
    pReturn->pRootNode = pRootNode;
    return pReturn;
}

void deleteBinTree(BinTree* pBinTree){
    if(pBinTree == NULL) return;
    removeBinTreeNode(pBinTree->pRootNode);
    free(pBinTree);
}

void removeBinTreeNode(BinTreeNode* pNode){
    if(pNode == NULL) return;
    removeBinTreeNode(pNode->pLeftChild);
    removeBinTreeNode(pNode->pRightChild);
    free(pNode);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pNode, BinTreeNode element){
    if(pNode == NULL) return NULL;
    if(pNode->pLeftChild != NULL) return NULL;
    BinTreeNode* pNewNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    memset(pNewNode, 0, sizeof(BinTreeNode));
    pNewNode->data = element.data;
    pNode->pLeftChild = pNewNode;
    return pNewNode;
}

BinTreeNode* insertRightCHildNodeBT(BinTreeNode* pNode, BinTreeNode element){
    if(pNode == NULL) return NULL;
    if(pNode->pRightChild != NULL) return NULL;
    BinTreeNode* pNewNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    if(pNewNode == NULL) return NULL;
    memset(pNewNode, 0, sizeof(BinTreeNode));
    pNewNode->data = element.data;
    pNode->pRightChild = pNewNode;
    return pNewNode;
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree){
    if(pBinTree == NULL) return NULL;
    return pBinTree->pRootNode;
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode){
    if(pNode == NULL) return NULL;
    return pNode->pLeftChild;
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode){
    if(pNode == NULL) return NULL;
    return pNode->pRightChild;
}

Stack* createStack(){
    Stack* pReturn = (Stack*)malloc(sizeof(Stack));
    if(pReturn == NULL) return NULL;
    memset(pReturn, 0, sizeof(Stack));
    return pReturn;
}

void deleteStack(Stack* pStack){
    if(pStack == NULL) return;

    StackNode* pCurrentNode = pStack->pTopElement;
    StackNode* pDelNode = NULL;

    while(pCurrentNode != NULL){
        pDelNode = pCurrentNode;
        pCurrentNode = pCurrentNode->pLink;
        free(pDelNode);
    }

    free(pStack);
}

bool pushStack(Stack* pStack, StackNode element){
    if(pStack == NULL) return false;
    if(isStackFull(pStack)) return false;
    
    StackNode* pNewNode = (StackNode*)malloc(sizeof(StackNode));
    if(pNewNode == NULL) return false;
    pNewNode->data = element.data;
    pNewNode->pLink = pStack->pTopElement;

    pStack->pTopElement = pNewNode;
    pStack->currentElementCount++;
    return true;
}

StackNode* popStack(Stack* pStack){
    if(pStack == NULL) return NULL;
    if(isStackEmpty(pStack)) return NULL;

    StackNode* pReturn = pStack->pTopElement;
    pStack->pTopElement = pReturn->pLink;
    pReturn->pLink = NULL;

    pStack->currentElementCount--;
    return pReturn;
}

bool isStackFull(Stack* pStack){
    return false;
}

bool isStackEmpty(Stack* pStack){
    if(pStack == NULL) return false;
    return pStack->currentElementCount == 0;
}

int getStackLength(Stack* pStack){
    if(pStack == NULL) return 0;
    return pStack->currentElementCount;
}

StackNode* peekStack(Stack* pStack){
    if(pStack == NULL) return NULL;
    return pStack->pTopElement;
}

Queue* createQueue(){
    Queue* pReturn = (Queue*)malloc(sizeof(Queue));
    if(pReturn == NULL) return NULL;
    memset(pReturn, 0, sizeof(Queue));
    return pReturn;
}

void deleteQueue(Queue* pQueue){
    if(pQueue == NULL) return;

    QueueNode* pCurrentNode = pQueue->pFront;
    QueueNode* pDelNode = NULL;

    while(pCurrentNode != NULL){
        pDelNode = pCurrentNode;
        pCurrentNode = pCurrentNode->pLink;
        free(pDelNode);
    }

    free(pQueue);
}

bool enqueueQueue(Queue* pQueue, QueueNode element){
    if(pQueue == NULL) return false;
    if(isQueueFull(pQueue)) return false;

    QueueNode* pNewNode = (QueueNode*)malloc(sizeof(QueueNode));
    if(pNewNode == NULL) return false;
    pNewNode->data = element.data;
    pNewNode->pLink = NULL;

    if(pQueue->currentElementCount == 0){
        pQueue->pFront = pNewNode;
        pQueue->pRear = pNewNode;
    }else{
        pQueue->pRear->pLink = pNewNode;
        pQueue->pRear = pNewNode;
    }
    pQueue->currentElementCount++;
    return true;
}

QueueNode* dequeueQueue(Queue* pQueue){
    if(pQueue == NULL) return NULL;
    if(isQueueEmpty(pQueue)) return NULL;

    QueueNode* pTargetNode = pQueue->pFront;
    if(pQueue->currentElementCount == 1){
        pQueue->pFront = NULL;
        pQueue->pRear = NULL;
    }else{
        pQueue->pFront = pTargetNode->pLink;
        pTargetNode->pLink = NULL;
    }
    pQueue->currentElementCount--;
    return pTargetNode;
}

bool isQueueFull(Queue* pQueue){
    return false;
}

bool isQueueEmpty(Queue* pQueue){
    if(pQueue == NULL) return false;
    return pQueue->currentElementCount == 0;
}

int getQueueLength(Queue* pQueue){
    if(pQueue == NULL) return 0;
    return pQueue->currentElementCount;
}

QueueNode* peekQueue(Queue* pQueue){
    if(pQueue == NULL) return NULL;
    return pQueue->pFront;
}

bool pushBinTreeNode(Stack* pStack, BinTreeNode* pNode){
    if(pStack == NULL || pNode == NULL) return false;
    StackNode node;
    node.data = pNode;
    return pushStack(pStack, node);
}

bool enqueueBinTreeNode(Queue* pQueue, BinTreeNode* pNode){
    if(pQueue == NULL || pNode == NULL) return false;
    QueueNode node;
    node.data = pNode;
    return enqueueQueue(pQueue, node);
}

void preorderTraversalBinTree(BinTree* pBinTree){
    if(pBinTree == NULL) return;

    Stack* pStack = createStack();
    if(pStack == NULL) return;

    BinTreeNode* pRootNode = pBinTree->pRootNode;
    if(pRootNode == NULL) return;

    pushBinTreeNode(pStack, pBinTree->pRootNode);

    while(!isStackEmpty(pStack)){
        StackNode* pStackNode = popStack(pStack);
        if(pStackNode == NULL) return;
        pRootNode = pStackNode->data;
        
        printf("%c ", pRootNode->data);
    
        if(pRootNode->pRightChild != NULL){
            pushBinTreeNode(pStack, pRootNode->pRightChild);
        }
    
        if(pRootNode->pLeftChild != NULL){
            pushBinTreeNode(pStack, pRootNode->pLeftChild);
        }
        free(pStackNode);
    }
    deleteStack(pStack);
}

void inorderTraversalBinTree(BinTree* pBinTree){
    if(pBinTree == NULL) return;
    
    Stack* pStack = createStack();
    if(pStack == NULL) return;
    
    BinTreeNode* pNode = getRootNodeBT(pBinTree);
    if(pNode == NULL) return;

    while(true){
        while(pNode != NULL){
            pushBinTreeNode(pStack, pNode);
            pNode = pNode->pLeftChild;
    
        }
        if(isStackEmpty(pStack)) break;
        StackNode* pStackNode = popStack(pStack);
        if(pStackNode == NULL) return;
        BinTreeNode* pBinTreeNode = pStackNode->data;
    
        printf("%c ", pBinTreeNode->data);
        
        pNode = getRightChildNodeBT(pBinTreeNode);
        free(pStackNode);
    }
    deleteStack(pStack);
}

void postorderTraversalBinTree(BinTree* pBinTree){
    if(pBinTree == NULL) return;

    BinTreeNode* pRootNode = getRootNodeBT(pBinTree);
    if(pRootNode == NULL) return;

    Stack* pStack = createStack();
    if(pStack == NULL) return;

    pushBinTreeNode(pStack, pRootNode);

    while(!isStackEmpty(pStack)){
        StackNode* pStackNode = peekStack(pStack);
        BinTreeNode* pBTNode = pStackNode->data;

        if(pBTNode->pLeftChild != NULL && pBTNode->pLeftChild->visited == false)
            pushBinTreeNode(pStack, pBTNode->pLeftChild);
        else if(pBTNode->pRightChild != NULL && pBTNode->pRightChild->visited == false)
            pushBinTreeNode(pStack, pBTNode->pRightChild);
        else{
            pBTNode->visited = true;
            printf("%c ", pBTNode->data);
            free(popStack(pStack));
        }
    }
    deleteStack(pStack);
}

void levelOrderTraversalBinTree(BinTree* pBinTree){
    if(pBinTree == NULL) return;

    BinTreeNode* pRootNode = pBinTree->pRootNode;
    if(pRootNode == NULL) return;

    Queue* pQueue = createQueue();
    if(pQueue == NULL) return;

    enqueueBinTreeNode(pQueue, pRootNode);
    while(!isQueueEmpty(pQueue)){
        QueueNode* pQueueNode = dequeueQueue(pQueue);
        BinTreeNode* pBTNode = pQueueNode->data;
        printf("%c ", pBTNode->data);

        if(pBTNode->pLeftChild != NULL) enqueueBinTreeNode(pQueue, pBTNode->pLeftChild);
        if(pBTNode->pRightChild != NULL) enqueueBinTreeNode(pQueue, pBTNode->pRightChild);

        free(pQueueNode);
    }
    deleteQueue(pQueue);
}