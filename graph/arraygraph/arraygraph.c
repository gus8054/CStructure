#include "arraygraph.h"

ArrayGraph* createArrayGraph(int maxVertexCount){
    if(maxVertexCount <= 0) return NULL;
    
    ArrayGraph* pReturn = (ArrayGraph*)malloc(sizeof(ArrayGraph));
    if(pReturn == NULL) return NULL;

    pReturn->currentVertexCount = 0;
    pReturn->maxVertexCount = maxVertexCount;
    pReturn->graphType = UNDIRECTED;
    pReturn->pVertex = (int*)malloc(sizeof(int) * maxVertexCount);
    if(pReturn->pVertex == NULL){
        free(pReturn);
        return NULL;
    }
    memset(pReturn->pVertex, NOT_USED, sizeof(int) * maxVertexCount);

    pReturn->ppAdjacentEdge = (int**)malloc(sizeof(int*) * maxVertexCount);
    if(pReturn->ppAdjacentEdge == NULL){
        free(pReturn->pVertex);
        free(pReturn);
        return NULL;
    }

    for(int i = 0; i < maxVertexCount; i++){
        pReturn->ppAdjacentEdge[i] = (int*)malloc(sizeof(int) * maxVertexCount);
        if(pReturn->ppAdjacentEdge[i] == NULL){
            for(int j = 0; j < i; j++){
                free(pReturn->ppAdjacentEdge[j]);
            }
            free(pReturn->ppAdjacentEdge);
            free(pReturn->pVertex);
            free(pReturn);
            return NULL;
        }
        memset(pReturn->ppAdjacentEdge[i], 0, sizeof(int) * maxVertexCount);
    }

    return pReturn;
}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount){
    if(maxVertexCount <= 0) return NULL;

    ArrayGraph* pReturn = createArrayGraph(maxVertexCount);
    if(pReturn == NULL) return NULL;

    pReturn->graphType = DIRECTED;

    return pReturn;
}

void deleteArrayGraph(ArrayGraph* pGraph){
    if(pGraph == NULL) return;
    if(pGraph->pVertex != NULL) free(pGraph->pVertex);
    for(int i = 0; i < pGraph->maxVertexCount; i++){
        if(pGraph->ppAdjacentEdge[i] != NULL) free(pGraph->ppAdjacentEdge[i]);
    }
    if(pGraph->ppAdjacentEdge != NULL) free(pGraph->ppAdjacentEdge);
    free(pGraph);
}

bool isArrayGraphEmpty(ArrayGraph* pGraph){
    if(pGraph == NULL) return false;
    return pGraph->currentVertexCount == 0;
}

bool addVertexAG(ArrayGraph* pGraph, int vertexID){
    if(pGraph == NULL) return false;
    if(vertexID < 0 || vertexID > pGraph->maxVertexCount - 1) return false;
    if(pGraph->pVertex[vertexID] != NOT_USED) return false;
    pGraph->pVertex[vertexID] = USED;
    pGraph->currentVertexCount++;
    return true;
}

bool addWeightEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight){
    if(pGraph == NULL) return false;
    if(checkVertexValid(pGraph, fromVertexID) == FAIL) return false;
    if(checkVertexValid(pGraph, toVertexID) == FAIL) return false;
    pGraph->ppAdjacentEdge[fromVertexID][toVertexID] = weight;

    if(pGraph->graphType == UNDIRECTED){
        pGraph->ppAdjacentEdge[toVertexID][fromVertexID] = weight;
    }
    return true;
}

// true : SUCCESS, false : FAIL
bool checkVertexValid(ArrayGraph* pGraph, int vertexID){
    if(pGraph == NULL) return false;
    if(vertexID < 0 || vertexID > pGraph->maxVertexCount - 1) return false;
    return pGraph->pVertex[vertexID] == USED;
}

bool addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID){
    return addWeightEdgeAG(pGraph, fromVertexID, toVertexID, 1);
}

bool removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID){
    if(pGraph == NULL) return false;
    if(checkVertexValid(pGraph, fromVertexID) == FAIL) return false;
    if(checkVertexValid(pGraph, toVertexID) == FAIL) return false;
    pGraph->ppAdjacentEdge[fromVertexID][toVertexID] = 0;

    if(pGraph->graphType == UNDIRECTED){
        pGraph->ppAdjacentEdge[toVertexID][fromVertexID] = 0;
    }
    return true;
}

bool removeVertexAG(ArrayGraph* pGraph, int vertexID){
    if(pGraph == NULL) return false;
    if(checkVertexValid(pGraph, vertexID) == FAIL)  return false;
    for(int i = 0; i < pGraph->maxVertexCount; i++){
        removeEdgeAG(pGraph, vertexID, i);
        removeEdgeAG(pGraph, i, vertexID);
    }
    pGraph->pVertex[vertexID] = NOT_USED;
    pGraph->currentVertexCount--;
    return true;
}
