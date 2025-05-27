#include "graphmst.h"

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

ArrayMinHeap* createArrayMinHeap(int maxElementCount){
    if(maxElementCount <= 0) return NULL;

    ArrayMinHeap* pReturn = (ArrayMinHeap*)malloc(sizeof(ArrayMinHeap));
    if(pReturn == NULL) return NULL;

    ArrayHeapNode* pElement = (ArrayHeapNode*)malloc(sizeof(ArrayHeapNode) * (maxElementCount + 1));
    if(pElement == NULL){
        free(pReturn);
        return NULL;
    }
    memset(pElement, 0, sizeof(ArrayHeapNode) * (maxElementCount + 1));

    pReturn->currentElementCount = 0;
    pReturn->maxElementCount = maxElementCount;
    pReturn->pElement = pElement;
    return pReturn;
}

void deleteArrayMinHeap(ArrayMinHeap* pHeap){
    if(pHeap == NULL) return;
    if(pHeap->pElement != NULL) free(pHeap->pElement);
    free(pHeap);
}

void insertArrayHeapElement(ArrayMinHeap* pHeap, ArrayHeapNode element){
    if(pHeap == NULL) return;
    if(pHeap->currentElementCount == pHeap->maxElementCount) return;

    pHeap->currentElementCount++;

    int childIdx = pHeap->currentElementCount;
    int parentIdx = childIdx / 2;

    while(!(childIdx == 1 || pHeap->pElement[childIdx].key >= pHeap->pElement[parentIdx].key)){
        pHeap->pElement[childIdx] = pHeap->pElement[parentIdx];
        childIdx /= 2;
        parentIdx /= 2;
    }
    pHeap->pElement[childIdx] = element;
}

ArrayHeapNode* removeArrayHeapElement(ArrayMinHeap* pHeap){
    if(pHeap == NULL) return NULL;
    if(pHeap->currentElementCount == 0) return NULL;

    ArrayHeapNode* pReturn = (ArrayHeapNode*)malloc(sizeof(ArrayHeapNode));
    if(pReturn == NULL) return NULL;
    *pReturn = pHeap->pElement[1];
   
    ArrayHeapNode lastNode = pHeap->pElement[pHeap->currentElementCount];
    pHeap->currentElementCount--;

    int parentIdx = 1;
    int childIdx = 2;

    // 마지막 노드의 인덱스가 왼쪽 자식의 인덱스보다 같거나 크다면 ( 즉, 왼쪽 자식 또는 왼쪽 오른쪽 자식 둘 다 트리에 포함된다면 ) 진입
    while(pHeap->currentElementCount >= childIdx){
        // 왼쪽 오른쪽 자식 둘 다 존재할 때만 진입
        if(pHeap->currentElementCount >= childIdx + 1 && pHeap->pElement[childIdx].key > pHeap->pElement[childIdx + 1].key){
            childIdx++;
        }

        if(lastNode.key <= pHeap->pElement[childIdx].key) break;

        pHeap->pElement[parentIdx] = pHeap->pElement[childIdx];
        parentIdx = childIdx;
        childIdx = parentIdx * 2;
    }
    pHeap->pElement[parentIdx] = lastNode;
    return pReturn;
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
// graph mst
UnionFind* createUnionFind(int maxElementCount){
    if(maxElementCount <= 0) return NULL;
    UnionFind* pReturn = (UnionFind*)malloc(sizeof(UnionFind));
    if(pReturn == NULL) return NULL;
    pReturn->maxElementCount = maxElementCount;
    int* pParent = (int*)malloc(sizeof(int) * maxElementCount);
    if(pParent == NULL){
        free(pReturn);
        return NULL;
    }
    memset(pParent, -1, sizeof(int) * maxElementCount);
    pReturn->pParent = pParent;
    return pReturn;
}

void deleteUnionFind(UnionFind* pUF){
    if(pUF == NULL) return;
    if(pUF->pParent != NULL) free(pUF->pParent);
    free(pUF);
}

int findUF(UnionFind* pUF, int vertexID){
    if(pUF == NULL) return -1;
    if(vertexID < 0 || vertexID > pUF->maxElementCount - 1) return -1;
    if(pUF->pParent[vertexID] < 0) return vertexID;
    pUF->pParent[vertexID] = findUF(pUF, pUF->pParent[vertexID]);
    return pUF->pParent[vertexID];
}

bool unionUF(UnionFind* pUF, int vertexID1, int vertexID2){
    if(pUF == NULL) return false;
    if(vertexID1 < 0 || vertexID2 < 0 || vertexID1 > pUF->maxElementCount - 1 || vertexID2 > pUF->maxElementCount - 1) return false;
    int rootVertexID1 = findUF(pUF, vertexID1);
    int rootVertexID2 = findUF(pUF, vertexID2);
    if(rootVertexID1 == rootVertexID2) return false;

    int height1 = -pUF->pParent[rootVertexID1];
    int height2 = -pUF->pParent[rootVertexID2];

    if(height1 > height2){
        pUF->pParent[rootVertexID2] = rootVertexID1;
    }else if(height1 < height2){
        pUF->pParent[rootVertexID1] = rootVertexID2;
    }else{
        pUF->pParent[rootVertexID2] = rootVertexID1;
        pUF->pParent[rootVertexID1]--;
    }
    return true;
}

LinkedGraph* mstKruskal(LinkedGraph* pGraph){
    if(pGraph == NULL) return NULL;

    ArrayMinHeap* pHeap = orderEdges(pGraph);
    if(pHeap == NULL) return NULL;

    LinkedGraph* pReturn = createLinkedGraph(pGraph->maxVertexCount);
    if(pReturn == NULL){
        deleteArrayMinHeap(pHeap);
        return NULL;
    }

    UnionFind* pUF = createUnionFind(pGraph->maxVertexCount);
    if(pUF == NULL){
        deleteLinkedGraph(pReturn);
        deleteArrayMinHeap(pHeap);
        return NULL;
    }

    int edgeCount = 0;
    int targetEdges = pGraph->currentVertexCount - 1;

    while(!(edgeCount >= targetEdges || pHeap->currentElementCount <= 0)){
        ArrayHeapNode* pHeapNode = removeArrayHeapElement(pHeap);
        if(pHeapNode == NULL){
            deleteUnionFind(pUF);
            deleteLinkedGraph(pReturn);
            deleteArrayMinHeap(pHeap);
            return NULL;
        }
    
        int fromVertexID = pHeapNode->data.fromVertexID;
        int toVertexID = pHeapNode->data.toVertexID;
        int weight = pHeapNode->key;
        free(pHeapNode);

        if(!pReturn->pVertex[fromVertexID]) addVertexLG(pReturn, fromVertexID);
        if(!pReturn->pVertex[toVertexID]) addVertexLG(pReturn, toVertexID);
        if(!checkCycle(pUF, fromVertexID, toVertexID)){
            addWeightEdgeLG(pReturn, fromVertexID, toVertexID, weight);
            unionUF(pUF, fromVertexID, toVertexID);
            edgeCount++;
        }
    }
    deleteUnionFind(pUF);
    deleteArrayMinHeap(pHeap);
    // 애초에 MST 만들 수 없는 무방향 그래프였을 경우 종료
    if(edgeCount < targetEdges){
        deleteLinkedGraph(pReturn);
        return NULL;
    }
    return pReturn;
}

ArrayMinHeap* orderEdges(LinkedGraph* pGraph){
    if(pGraph == NULL) return NULL;

    int edgeCount = 0;
    for(int i = 0; i < pGraph->maxVertexCount; i++){
        int fromVertexID = i;
        LinkedListNode* pListNode = pGraph->ppAdjacentEdge[i]->headerNode.pLink;
        while(pListNode != NULL){
            int toVertexID = pListNode->data.vertexID;
            if(fromVertexID < toVertexID) edgeCount++;
            pListNode = pListNode->pLink;
        }
    }

    ArrayMinHeap* pReturn = createArrayMinHeap(edgeCount);
    if(pReturn == NULL) return NULL;

    for(int i = 0; i < pGraph->maxVertexCount; i++){
        int fromVertexID = i;
        LinkedListNode* pListNode = pGraph->ppAdjacentEdge[i]->headerNode.pLink;
        while(pListNode != NULL){
            int toVertexID = pListNode->data.vertexID;
            if(fromVertexID < toVertexID){
                int weight = pListNode->data.weight;
                Element data = {fromVertexID, toVertexID};
                ArrayHeapNode heapNode = {data, weight};
                insertArrayHeapElement(pReturn, heapNode);
            }
            pListNode = pListNode->pLink;
        }
    }
    return pReturn;
}

bool checkCycle(UnionFind* pUF, int fromVertexID, int toVertexID){
    if(pUF == NULL) return false;
    if(fromVertexID < 0 || toVertexID < 0 || fromVertexID > pUF->maxElementCount -1 || toVertexID > pUF->maxElementCount - 1) return false;
    return findUF(pUF, fromVertexID) == findUF(pUF, toVertexID);
}