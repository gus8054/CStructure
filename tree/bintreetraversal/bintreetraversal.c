#include "bintreetraversal.h"

BinTree* createBinTree(BinTreeNode rootNode){
    BinTree* pReturn = (BinTree*)malloc(sizeof(BinTree));
    if(pReturn == NULL) return NULL;

    pReturn->pRootNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    if(pReturn->pRootNode == NULL){
        free(pReturn);
        return NULL;
    }
    pReturn->pRootNode->data = rootNode.data;
    pReturn->pRootNode->pLeftChild = NULL;
    pReturn->pRootNode->pRightChild = NULL;
    
    return pReturn;
}

void deleteBinTree(BinTree* pTree){
    if(pTree == NULL) return;
    deleteBinTreeNode(pTree->pRootNode);
    free(pTree);
}

void deleteBinTreeNode(BinTreeNode* pNode){
    if(pNode == NULL) return;
    deleteBinTreeNode(pNode->pLeftChild);
    deleteBinTreeNode(pNode->pRightChild);
    free(pNode);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pNode, BinTreeNode element){
    if(pNode == NULL) return NULL;
    if(pNode->pLeftChild != NULL) return NULL;
    BinTreeNode* pReturn = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    if(pReturn == NULL) return NULL;
    pReturn->data = element.data;
    pReturn->pLeftChild = NULL;
    pReturn->pRightChild = NULL;
    
    pNode->pLeftChild = pReturn;

    return pReturn;
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pNode, BinTreeNode element){
    if(pNode == NULL) return NULL;
    if(pNode->pRightChild != NULL) return NULL;
    BinTreeNode* pReturn = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    if(pReturn == NULL) return NULL;
    pReturn->data = element.data;
    pReturn->pLeftChild = NULL;
    pReturn->pRightChild = NULL;
    
    pNode->pRightChild = pReturn;

    return pReturn;
}

LinkedStack* createLinkedStack(){
    LinkedStack* pReturn = (LinkedStack*)malloc(sizeof(LinkedStack));
    if(pReturn == NULL) return NULL;
    pReturn->currentElementCount = 0;
    pReturn->pTopElement = NULL;
    return pReturn;
}

void deleteLinkedStack(LinkedStack* pStack){
    if(pStack == NULL) return;

    LinkedStackNode* pCurrentNode = pStack->pTopElement;
    LinkedStackNode* pDelNode = NULL;

    while(pCurrentNode != NULL){
        pDelNode = pCurrentNode;
        pCurrentNode = pCurrentNode->pLink;
        free(pDelNode);
    }

    free(pStack);
}

bool pushLS(LinkedStack* pStack, LinkedStackNode element){
    if(pStack == NULL) return false;

    LinkedStackNode* pNewNode = (LinkedStackNode*)malloc(sizeof(LinkedStackNode));
    if(pNewNode == NULL) return false;

    pNewNode->pTreeNode = element.pTreeNode;
    pNewNode->pLink = pStack->pTopElement;
    pStack->pTopElement = pNewNode;
    pStack->currentElementCount++;
    return true;
}

LinkedStackNode* popLS(LinkedStack* pStack){
    if(pStack == NULL) return NULL;
    if(pStack->currentElementCount == 0) return NULL;

    LinkedStackNode* pReturn = pStack->pTopElement;
    pStack->pTopElement = pReturn->pLink;
    pReturn->pLink = NULL;
    pStack->currentElementCount--;
    return pReturn;
}

LinkedStackNode* peekLS(LinkedStack* pStack){
    if(pStack == NULL) return NULL;
    if(pStack->currentElementCount == 0) return NULL;
    return pStack->pTopElement;
}

LinkedQueue* createLinkedQueue(){
    LinkedQueue* pReturn = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    if(pReturn == NULL) return NULL;

    pReturn->currentElementCount = 0;
    pReturn->pFront = NULL;
    pReturn->pRear = NULL;
    return pReturn;
}

void deleteLinkedQueue(LinkedQueue* pQueue){
    if(pQueue == NULL) return;

    LinkedQueueNode* pCurrentNode = pQueue->pFront;
    LinkedQueueNode* pDelNode = NULL;

    while(pCurrentNode != NULL){
        pDelNode = pCurrentNode;
        pCurrentNode = pCurrentNode->pLink;
        free(pDelNode);
    }
    free(pQueue);
}

bool enqueueLQ(LinkedQueue* pQueue, LinkedQueueNode element){
    if(pQueue == NULL) return false;
    LinkedQueueNode* pNewNode = (LinkedQueueNode*)malloc(sizeof(LinkedQueueNode));
    if(pNewNode == NULL) return false;

    pNewNode->pTreeNode = element.pTreeNode;
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

LinkedQueueNode* dequeueLQ(LinkedQueue* pQueue){
    if(pQueue == NULL) return NULL;
    if(pQueue->currentElementCount == 0) return NULL;

    LinkedQueueNode* pReturn = pQueue->pFront;

    if(pQueue->currentElementCount == 1){
        pQueue->pFront = NULL;
        pQueue->pRear = NULL;
    }else{
        pQueue->pFront = pReturn->pLink;
        pReturn->pLink = NULL;
    }
    pQueue->currentElementCount--;
    return pReturn;
}

LinkedQueueNode* peekLQ(LinkedQueue* pQueue){
    if(pQueue == NULL) return NULL;
    if(pQueue->currentElementCount == 0) return NULL;
    return pQueue->pFront;
}

void preorderTraversalBinTree(BinTree* pTree){
    if(pTree == NULL) return;
    if(pTree->pRootNode == NULL) return;

    LinkedStack* pStack = createLinkedStack();
    if(pStack == NULL) return;

    pushLS(pStack, (LinkedStackNode){pTree->pRootNode, NULL});
    while(true){
        LinkedStackNode* pStackNode = popLS(pStack);
        if(pStackNode == NULL){
            deleteLinkedStack(pStack);
            return;
        }
        BinTreeNode* pTreeNode = pStackNode->pTreeNode;
        free(pStackNode);
        printf("%c ", pTreeNode->data);
        if(pTreeNode->pRightChild != NULL) pushLS(pStack, (LinkedStackNode){pTreeNode->pRightChild, NULL});
        if(pTreeNode->pLeftChild != NULL) pushLS(pStack, (LinkedStackNode){pTreeNode->pLeftChild, NULL});
        if(pStack->currentElementCount == 0) break;
    }
    deleteLinkedStack(pStack);
}

void inorderTraversalBinTree(BinTree* pTree){
    if(pTree == NULL) return;
    if(pTree->pRootNode == NULL) return;

    LinkedStack* pStack = createLinkedStack();
    if(pStack == NULL) return;

    BinTreeNode* pCurrentNode = pTree->pRootNode;
    while(true){
        while(pCurrentNode != NULL){
            pushLS(pStack, (LinkedStackNode){pCurrentNode, NULL});
            pCurrentNode = pCurrentNode->pLeftChild;
        } 
    
        if(pStack->currentElementCount == 0) break;
        LinkedStackNode* pStackNode = popLS(pStack);
        if(pStackNode == NULL){
            deleteLinkedStack(pStack);
            return;
        } 
        pCurrentNode = pStackNode->pTreeNode;
        free(pStackNode);
        printf("%c ", pCurrentNode->data);
    
        pCurrentNode = pCurrentNode->pRightChild;
    }
    deleteLinkedStack(pStack);
}

void postorderTraversalBinTree(BinTree* pTree){
    if(pTree == NULL) return;
    if(pTree->pRootNode == NULL) return;

    LinkedStack* pStack = createLinkedStack();
    if(pStack == NULL) return;

    pushLS(pStack, (LinkedStackNode){pTree->pRootNode, NULL});
    while(true){
        LinkedStackNode* pStackNode = peekLS(pStack);
        if(pStackNode == NULL){
            deleteLinkedStack(pStack);
            return;
        } 
        BinTreeNode* pTreeNode = pStackNode->pTreeNode;

        if(pTreeNode->pLeftChild != NULL && pTreeNode->pLeftChild->visited == false){
            pushLS(pStack, (LinkedStackNode){pTreeNode->pLeftChild, NULL});
        }else if(pTreeNode->pRightChild != NULL && pTreeNode->pRightChild->visited == false){
            pushLS(pStack, (LinkedStackNode){pTreeNode->pRightChild, NULL});
        }else{
            printf("%c ", pTreeNode->data);
            pTreeNode->visited = true;
            LinkedStackNode* pDelNode = popLS(pStack);
            if(pDelNode == NULL){
                deleteLinkedStack(pStack);
                return;
            }
            free(pDelNode);
        }
        if(pStack->currentElementCount == 0) break;
    }
    deleteLinkedStack(pStack);
}

void postorderTraversalBinTreeWithTwoStacks(BinTree* pTree){
    if(pTree == NULL) return;
    if(pTree->pRootNode == NULL) return;

    LinkedStack* pStack1 = createLinkedStack();
    if(pStack1 == NULL) return;
    
    LinkedStack* pStack2 = createLinkedStack();
    if(pStack2 == NULL){
        deleteLinkedStack(pStack1);
        return;
    }

    pushLS(pStack1, (LinkedStackNode){pTree->pRootNode, NULL});
    while(true){
        LinkedStackNode* pStackNode = popLS(pStack1);
        if(pStackNode == NULL){
            deleteLinkedStack(pStack2);
            deleteLinkedStack(pStack1);
            return;
        }
        BinTreeNode* pTreeNode = pStackNode->pTreeNode;
        free(pStackNode);

        pushLS(pStack2, (LinkedStackNode){pTreeNode, NULL});

        if(pTreeNode->pLeftChild != NULL) pushLS(pStack1, (LinkedStackNode){pTreeNode->pLeftChild, NULL});
        if(pTreeNode->pRightChild != NULL) pushLS(pStack1, (LinkedStackNode){pTreeNode->pRightChild, NULL});
        if(pStack1->currentElementCount == 0) break;
    }

    while(true){
        LinkedStackNode* pStackNode = popLS(pStack2);
        if(pStackNode == NULL){
            deleteLinkedStack(pStack2);
            deleteLinkedStack(pStack1);
            return;
        }
        BinTreeNode* pTreeNode = pStackNode->pTreeNode;
        free(pStackNode);
        printf("%c ", pTreeNode->data);
        if(pStack2->currentElementCount == 0) break;
    }
    deleteLinkedStack(pStack2);
    deleteLinkedStack(pStack1);
}
void levelOrderTraversalBinTree(BinTree* pTree){
    if(pTree == NULL) return;
    if(pTree->pRootNode == NULL) return;

    LinkedQueue* pQueue = createLinkedQueue();
    if(pQueue == NULL) return;

    enqueueLQ(pQueue, (LinkedQueueNode){pTree->pRootNode, NULL});
    while(true){
        LinkedQueueNode* pQueueNode = dequeueLQ(pQueue);
        if(pQueueNode == NULL){
            deleteLinkedQueue(pQueue);
            return;
        }
        BinTreeNode* pTreeNode = pQueueNode->pTreeNode;
        free(pQueueNode);

        printf("%c ", pTreeNode->data);
        if(pTreeNode->pLeftChild != NULL) enqueueLQ(pQueue, (LinkedQueueNode){pTreeNode->pLeftChild, NULL});
        if(pTreeNode->pRightChild != NULL) enqueueLQ(pQueue, (LinkedQueueNode){pTreeNode->pRightChild, NULL});
        if(pQueue->currentElementCount == 0) break;
    }
    deleteLinkedQueue(pQueue);
}