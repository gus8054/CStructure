#include "linkedgraph.h"

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
  LinkedListNode* pPreNode = &(pList->headerNode);
  for(int i = 0; i < position; i++){
    pPreNode = pPreNode->pLink;
  }
  pNewNode->pLink = pPreNode->pLink;
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
  pPreNode->pLink = pDelNode->pLink;
  free(pDelNode);
  pList->currentElementCount--;
  return true;
}

void clearLinkedList(LinkedList* pList){
  if(pList == NULL) return;

  LinkedListNode* pCurrentNode = pList->headerNode.pLink;
  LinkedListNode* pDelNode = NULL;

  while(pCurrentNode != NULL){
    pDelNode = pCurrentNode;
    pCurrentNode = pCurrentNode->pLink;
    free(pDelNode);
  }
  pList->headerNode.pLink = NULL;
  pList->currentElementCount = 0;
}

int getLinkedListLength(LinkedList* pList){
  if(pList == NULL) return -1;
  return pList->currentElementCount;
}

LinkedListNode* getLinkedListNode(LinkedList* pList, int position){
  if(pList == NULL) return NULL;
  if(position < 0 || position > pList->currentElementCount - 1) return NULL;
  LinkedListNode* pPreNode = &(pList->headerNode);
  for(int i = 0; i < position; i++){
    pPreNode = pPreNode->pLink;
  }
  return pPreNode->pLink;
}
LinkedGraph* createLinkedGraph(int maxVertexCount){
    if(maxVertexCount <= 0) return NULL;

    LinkedGraph* pReturn = (LinkedGraph*)malloc(sizeof(LinkedGraph));
    if(pReturn == NULL) return NULL;

    pReturn->maxVertexCount = maxVertexCount;
    pReturn->currentVertexCount = 0;
    pReturn->graphType = UNDIRECTED;
    pReturn->pVertex = (int*)malloc(sizeof(int) * maxVertexCount);
    if(pReturn->pVertex == NULL){
        free(pReturn);
        return NULL;
    }
    memset(pReturn->pVertex, 0, sizeof(int) * maxVertexCount);
    pReturn->ppAdjacentEdge = (LinkedList**)malloc(sizeof(LinkedList*) * maxVertexCount);
    if(pReturn->ppAdjacentEdge == NULL){
        free(pReturn->pVertex);
        free(pReturn);
        return NULL;
    }
    memset(pReturn->ppAdjacentEdge, 0, sizeof(LinkedList*) * maxVertexCount);
    for(int i = 0; i < maxVertexCount; i++){
        pReturn->ppAdjacentEdge[i] = createLinkedList();
        if(pReturn->ppAdjacentEdge[i] == NULL){
            for(int j = 0; j < i; j++){
                deleteLinkedList(pReturn->ppAdjacentEdge[j]);
            }
            free(pReturn->ppAdjacentEdge);
            free(pReturn->pVertex);
            free(pReturn);
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

bool addVertexLG(LinkedGraph* pGraph, int vertexID){
    if(pGraph == NULL) return false;
    if(vertexID < 0 || vertexID > pGraph->maxVertexCount - 1) return false;
    if(pGraph->pVertex[vertexID] == USED) return false;

    pGraph->pVertex[vertexID] = USED;
    pGraph->currentVertexCount++;
    return true;
}

bool addWeightEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight){
    if(pGraph == NULL) return false;
    if(checkVertexValid(pGraph, fromVertexID) == FAIL) return false;
    if(checkVertexValid(pGraph, toVertexID) == FAIL) return false;
    // 이미 간선이 존재하는지 확인
    if(hasEdgeLG(pGraph, fromVertexID, toVertexID)) return false;

    GraphVertex toNode = {toVertexID, weight};
    addLLElement(pGraph->ppAdjacentEdge[fromVertexID], 0, (LinkedListNode){toNode, NULL});

    if(pGraph->graphType == UNDIRECTED){
        GraphVertex fromNode = {fromVertexID, weight};
        addLLElement(pGraph->ppAdjacentEdge[toVertexID], 0, (LinkedListNode){fromNode, NULL});
    }
    return true;
}

bool checkVertexValid(LinkedGraph* pGraph, int vertexID){
    if(pGraph == NULL) return false;
    if(vertexID < 0 || vertexID > pGraph->maxVertexCount - 1) return false;
    return pGraph->pVertex[vertexID] == USED;
}

// 중복 간선 체크 함수 추가
bool hasEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID){
    if(pGraph == NULL) return false;
    if(checkVertexValid(pGraph, fromVertexID) == FAIL) return false;
    if(checkVertexValid(pGraph, toVertexID) == FAIL) return false;
    
    LinkedList* pList = pGraph->ppAdjacentEdge[fromVertexID];
    if(pList == NULL) return false;
    
    int position = findGraphNodePosition(pList, toVertexID);
    return position >= 0;
}

bool addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID){
    return addWeightEdgeLG(pGraph, fromVertexID, toVertexID, 1);
}

bool removeVertexLG(LinkedGraph* pGraph, int vertexID){
    if(pGraph == NULL) return false;
    if(checkVertexValid(pGraph, vertexID) == FAIL) return false;
    for(int i = 0; i < pGraph->maxVertexCount; i++){
        removeEdgeLG(pGraph, vertexID, i);
        removeEdgeLG(pGraph, i, vertexID);
    }
    pGraph->pVertex[vertexID] = NOT_USED;
    pGraph->currentVertexCount--;
    return true;
}

bool removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID){
    if(pGraph == NULL) return false;
    if(checkVertexValid(pGraph, fromVertexID) == FAIL) return false;
    if(checkVertexValid(pGraph, toVertexID) == FAIL) return false;

    deleteGraphNode(pGraph->ppAdjacentEdge[fromVertexID], toVertexID);
    if(pGraph->graphType == UNDIRECTED){
        deleteGraphNode(pGraph->ppAdjacentEdge[toVertexID], fromVertexID);
    }
    return true;
}

void deleteGraphNode(LinkedList* pList, int delVertexID){
    if(pList == NULL) return;
    if(pList->currentElementCount == 0) return;
    int position = findGraphNodePosition(pList, delVertexID);
    if(position >= 0){
        removeLLElement(pList, position);
    }
}

int findGraphNodePosition(LinkedList* pList, int delVertexID){
    if(pList == NULL) return -1;
    if(pList->currentElementCount == 0) return -1;

    LinkedListNode* pCurrentNode = pList->headerNode.pLink;
    int position = 0;
    while(pCurrentNode != NULL){
        if(pCurrentNode->data.vertexID == delVertexID) return position;
        pCurrentNode = pCurrentNode->pLink;
        position++;
    }
    return -1;
}

bool isEmptyLG(LinkedGraph* pGraph){
    if(pGraph == NULL) return false;
    return pGraph->currentVertexCount == 0;
}

void deleteLinkedGraph(LinkedGraph* pGraph){
    if(pGraph == NULL) return;
    for(int i = 0; i < pGraph->maxVertexCount; i++){
        deleteLinkedList(pGraph->ppAdjacentEdge[i]);
    }
    if(pGraph->ppAdjacentEdge != NULL) free(pGraph->ppAdjacentEdge);
    if(pGraph->pVertex != NULL) free(pGraph->pVertex);
    free(pGraph);
}