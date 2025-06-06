#include "graphtraversal.h"

LinkedStack* createLinkedStack(){
    LinkedStack* pReturn = (LinkedStack*)malloc(sizeof(LinkedStack));
    if(pReturn == NULL) return NULL;
    memset(pReturn, 0, sizeof(LinkedStack));
    return pReturn;
}

void deleteLinkedStack(LinkedStack* pStack){
    if(pStack == NULL) return;
    LinkedStackNode* pCurrentNode = pStack->pTopElement;
    LinkedStackNode* pDelNode;
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
    pNewNode->data = element.data;
    pNewNode->pLink = pStack->pTopElement;
    pStack->pTopElement = pNewNode;
    pStack->currentElementCount++;
    return true;
}

LinkedStackNode* popLS(LinkedStack* pStack){
    if(pStack == NULL) return NULL;
    if(pStack->currentElementCount == 0) return NULL;
    LinkedStackNode* pTargetNode = pStack->pTopElement;
    pStack->pTopElement = pTargetNode->pLink;
    pTargetNode->pLink = NULL;
    pStack->currentElementCount--;
    return pTargetNode;
}

LinkedStackNode* peekLS(LinkedStack* pStack){
    if(pStack == NULL) return NULL;
    if(pStack->currentElementCount == 0) return NULL;
    return pStack->pTopElement;
}

bool isLinkedStackFull(LinkedStack* pStack){
    return false;
}

bool isLinkedStackEmpty(LinkedStack* pStack){
    if(pStack == NULL) return false;
    return pStack->currentElementCount == 0;
}

LinkedQueue* createLinkedQueue(){
    LinkedQueue* pReturn = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    if(pReturn == NULL) return NULL;
    memset(pReturn, 0, sizeof(LinkedQueue));
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
    if(isLinkedQueueFull(pQueue)) return false;
    LinkedQueueNode* pNewNode = (LinkedQueueNode*)malloc(sizeof(LinkedQueueNode));
    if(pNewNode == NULL) return false;
    *pNewNode = element;
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
    if(isLinkedQueueEmpty(pQueue)) return NULL;
    LinkedQueueNode* pReturn = pQueue->pFront;
    if(pQueue->currentElementCount <= 1) {
       pQueue->pFront = NULL;
       pQueue->pRear = NULL;
    }
    else{
        pQueue->pFront = pReturn->pLink;
        pReturn->pLink = NULL;
    }
    pQueue->currentElementCount--;
    return pReturn;
}

LinkedQueueNode* peekLQ(LinkedQueue* pQueue){
    if(pQueue == NULL) return NULL;
    if(isLinkedQueueEmpty(pQueue)) return NULL;
    return pQueue->pFront;
}

bool isLinkedQueueFull(LinkedQueue* pQueue){
    return false;
}

bool isLinkedQueueEmpty(LinkedQueue* pQueue){
    if(pQueue == NULL) return false;
    return pQueue->currentElementCount == 0;
}
            
LinkedList* createLinkedList(){
    LinkedList* pReturn = (LinkedList*)malloc(sizeof(LinkedList));
    if(pReturn == NULL) return NULL;
    memset(pReturn, 0, sizeof(LinkedList));
    return pReturn;
}

void deleteLinkedList(LinkedList* pList){
    if(pList == NULL) return;

    LinkedListNode* pCurrentNode = pList->headerNode.pLink;
    LinkedListNode* pDelNode = NULL;
    
    while(pCurrentNode != NULL){
        pDelNode = pCurrentNode;
        pCurrentNode = pCurrentNode->pLink;
        free(pDelNode);
    }
    free(pList);
}

bool addLLElement(LinkedList* pList, int position, LinkedListNode element){
    if(pList == NULL) return false;
    if(position < 0 || position > pList->currentElementCount) return false;

    LinkedListNode* pNewNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    if(pNewNode == NULL) return false;
    pNewNode->data = element.data;
    pNewNode->pLink = NULL;

    LinkedListNode* pPreNode = &(pList->headerNode);
    for(int i = 0; i < position; i++){
        pPreNode = pPreNode->pLink;
    }
    LinkedListNode* pNextNode = pPreNode->pLink;

    pNewNode->pLink = pNextNode;
    pPreNode->pLink = pNewNode;
    pList->currentElementCount++;
    return true;
}

bool removeLLElement(LinkedList* pList, int position){
    if(pList == NULL) return false;
    if(position < 0 || position > pList->currentElementCount - 1) return false;

    LinkedListNode* pPreNode = &(pList->headerNode);
    for(int i = 0; i < position; i++){
        pPreNode = pPreNode->pLink;
    }
    LinkedListNode* pDelNode = pPreNode->pLink;
    LinkedListNode* pNextNode = pDelNode->pLink;

    pPreNode->pLink = pNextNode;
    free(pDelNode);
    pList->currentElementCount--;
    return true;
}

bool clearLinkedList(LinkedList* pList){
    if(pList == NULL) return false;

    LinkedListNode* pCurrentNode = pList->headerNode.pLink;
    LinkedListNode* pDelNode = NULL;

    while(pCurrentNode != NULL){
        pDelNode = pCurrentNode;
        pCurrentNode = pCurrentNode->pLink;
        free(pDelNode);
    }
    pList->currentElementCount = 0;
    pList->headerNode.pLink = NULL;
    return true;
}

LinkedGraph* createLinkedGraph(int maxVertexCount){
    if(maxVertexCount <= 0) return NULL;

    LinkedGraph* pReturn = (LinkedGraph*)malloc(sizeof(LinkedGraph));
    if(pReturn == NULL) return NULL;

    pReturn->currentVertexCount = 0;
    pReturn->maxVertexCount = maxVertexCount;
    pReturn->graphType = UNDIRECTED;
    pReturn->pVertex = (bool*)malloc(sizeof(bool) * maxVertexCount);
    if(pReturn->pVertex == NULL){
        free(pReturn);
        return NULL;
    }
    memset(pReturn->pVertex, 0, sizeof(bool) * maxVertexCount);
    pReturn->ppAdjacentEdge = (LinkedList**)malloc(sizeof(LinkedList*) * maxVertexCount);
    if(pReturn->ppAdjacentEdge == NULL){
        free(pReturn->pVertex);
        free(pReturn);
        return NULL;
    }
    for(int i = 0; i < maxVertexCount; i++){
        pReturn->ppAdjacentEdge[i] = createLinkedList();
        if(pReturn->ppAdjacentEdge[i] == NULL){
            for(int j = 0; j < i; j++) deleteLinkedList(pReturn->ppAdjacentEdge[j]);
            free(pReturn->ppAdjacentEdge);
            free(pReturn->pVertex);
            free(pReturn);
            return NULL;
        }
    }
    return pReturn;
}

LinkedGraph* createLinkedDirectedGraph(int maxVertexCount){
    if(maxVertexCount <= 0) return NULL;
    LinkedGraph* pReturn = createLinkedGraph(maxVertexCount);
    if(pReturn == NULL) return NULL;
    pReturn->graphType = DIRECTED;
    return pReturn;
}

void deleteLinkedGraph(LinkedGraph* pGraph){
    if(pGraph == NULL) return;
    
    for(int i = 0; i < pGraph->maxVertexCount; i++){
        if(pGraph->ppAdjacentEdge[i] != NULL) deleteLinkedList(pGraph->ppAdjacentEdge[i]);
    }
    if(pGraph->ppAdjacentEdge != NULL) free(pGraph->ppAdjacentEdge);
    if(pGraph->pVertex != NULL) free(pGraph->pVertex);
    free(pGraph);
}

bool addVertexLG(LinkedGraph* pGraph, int vertexID){
    if(pGraph == NULL) return false;
    if(vertexID < 0 || vertexID > pGraph->maxVertexCount - 1) return false;
    if(pGraph->pVertex[vertexID]) return false;
    pGraph->pVertex[vertexID] = true;
    pGraph->currentVertexCount++;
    return true;
}

bool checkVertexValid(LinkedGraph* pGraph, int vertexID){
    if(pGraph == NULL) return false;
    if(vertexID < 0 || vertexID > pGraph->maxVertexCount - 1) return false;
    return pGraph->pVertex[vertexID];
}

bool hasEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID){
    if(pGraph == NULL) return false;
    if(!checkVertexValid(pGraph, fromVertexID)) return false;
    if(!checkVertexValid(pGraph, toVertexID)) return false;

    LinkedListNode* pCurrentNode = pGraph->ppAdjacentEdge[fromVertexID]->headerNode.pLink;
    while(pCurrentNode != NULL){
       if(pCurrentNode->data.vertexID == toVertexID) return true;
       pCurrentNode = pCurrentNode->pLink;
    }
    return false;
}

bool addWeightEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight){
    if(pGraph == NULL) return false;
    if(!checkVertexValid(pGraph, fromVertexID)) return false;
    if(!checkVertexValid(pGraph, toVertexID)) return false;
    if(hasEdgeLG(pGraph, fromVertexID, toVertexID)) return false;
    addLLElement(pGraph->ppAdjacentEdge[fromVertexID], 0, (LinkedListNode){(GraphNode){toVertexID, weight}, NULL});
    if(pGraph->graphType == UNDIRECTED){
        addLLElement(pGraph->ppAdjacentEdge[toVertexID], 0, (LinkedListNode){(GraphNode){fromVertexID, weight}, NULL});
    }
    return true;
}

bool addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID){
    if(pGraph == NULL) return false;
    if(!checkVertexValid(pGraph, fromVertexID)) return false;
    if(!checkVertexValid(pGraph, toVertexID)) return false;
    return addWeightEdgeLG(pGraph, fromVertexID, toVertexID, 1);
}

bool removeVertexLG(LinkedGraph* pGraph, int vertexID){
    if(pGraph == NULL) return false;
    if(!checkVertexValid(pGraph, vertexID)) return false;

    clearLinkedList(pGraph->ppAdjacentEdge[vertexID]);
    for(int i = 0; i < pGraph->maxVertexCount; i++){
        removeEdgeLG(pGraph, i, vertexID);
    }
    pGraph->pVertex[vertexID] = false;
    pGraph->currentVertexCount--;
    return true;
}

bool removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID){
    if(pGraph == NULL) return false;
    if(!checkVertexValid(pGraph, fromVertexID)) return false;
    if(!checkVertexValid(pGraph, toVertexID)) return false;
    if(!hasEdgeLG(pGraph, fromVertexID, toVertexID)) return false;

    int position = findGraphNodePosition(pGraph->ppAdjacentEdge[fromVertexID], toVertexID);
    if(position >= 0) removeLLElement(pGraph->ppAdjacentEdge[fromVertexID], position);
    if(pGraph->graphType == UNDIRECTED){
        position = findGraphNodePosition(pGraph->ppAdjacentEdge[toVertexID], fromVertexID);
        if(position >= 0) removeLLElement(pGraph->ppAdjacentEdge[toVertexID], position);
    }
    return true;
}

int findGraphNodePosition(LinkedList* pList, int vertexID){
    if(pList == NULL) return -1;
    
    int position = 0;
    LinkedListNode* pCurrentNode = pList->headerNode.pLink;
    while(pCurrentNode != NULL){
        if(pCurrentNode->data.vertexID == vertexID) return position;
        pCurrentNode = pCurrentNode->pLink;
        position++;
    }
    return -1;
}

bool isLinkedGraphEmpty(LinkedGraph* pGraph){
    if(pGraph == NULL) return false;
    return pGraph->currentVertexCount == 0;
}

// graph traversal

void traversalDFS(LinkedGraph* pGraph, int startVertexID){
    if(pGraph == NULL) return;
    if(!checkVertexValid(pGraph, startVertexID)) return;

    
    bool* pVisit = (bool*)malloc(sizeof(bool) * pGraph->maxVertexCount);
    if(pVisit == NULL) return;
    memset(pVisit, 0, sizeof(bool) * pGraph->maxVertexCount);
    pVisit[startVertexID] = true;
    
    LinkedStack* pStack = createLinkedStack();
    if(pStack == NULL){
        free(pVisit);
        return;
    } 

    LinkedStackNode stackNode = {startVertexID, NULL};
    pushLS(pStack, stackNode);

    while(true){
        LinkedStackNode* pPopNode = popLS(pStack);    
        printf("방문 : [%d]\n", pPopNode->data);
        
        LinkedListNode* pListNode = pGraph->ppAdjacentEdge[pPopNode->data]->headerNode.pLink;
        while(pListNode != NULL){
            if(!pVisit[pListNode->data.vertexID]){
                pVisit[pListNode->data.vertexID] = true;
                pushLS(pStack, (LinkedStackNode){pListNode->data.vertexID, NULL});
            }
            pListNode = pListNode->pLink;
        }
        free(pPopNode);
        if(isLinkedStackEmpty(pStack)) break;
    }
    free(pVisit);
    deleteLinkedStack(pStack);
}

void traversalBFS(LinkedGraph* pGraph, int startVertexID){
    if(pGraph == NULL) return;
    if(!checkVertexValid(pGraph, startVertexID)) return;

    bool* pVisit = (bool*)malloc(sizeof(bool) * pGraph->maxVertexCount);
    if(pVisit == NULL) return;
    memset(pVisit, 0, sizeof(bool) * pGraph->maxVertexCount);
    pVisit[startVertexID] = true;

    LinkedQueue* pQueue = createLinkedQueue();
    if(pQueue == NULL){
        free(pVisit);
        return;
    }
    LinkedQueueNode queueNode = {startVertexID, NULL};
    enqueueLQ(pQueue, queueNode);

    while(true){
        LinkedQueueNode* pDequeueNode = dequeueLQ(pQueue);
        printf("방문 : [%d]\n", pDequeueNode->data);

        LinkedListNode* pListNode = pGraph->ppAdjacentEdge[pDequeueNode->data]->headerNode.pLink;
        while(pListNode != NULL){
            if(!pVisit[pListNode->data.vertexID]){
                pVisit[pListNode->data.vertexID] = true;
                enqueueLQ(pQueue, (LinkedQueueNode){pListNode->data.vertexID, NULL});
            }
            pListNode = pListNode->pLink;
        }
        free(pDequeueNode);
        if(isLinkedQueueEmpty(pQueue)) break;
    }
    free(pVisit);
    deleteLinkedQueue(pQueue);
}