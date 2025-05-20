#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

enum GraphType {UNDIRECTED = 1, DIRECTED = 2};
typedef struct ArrayGraphType{
    int maxVertexCount;
    int currentVertexCount;
    enum GraphType graphType; // 그래프 타입(1: undirected(무방향), 2: directed(방향))
    bool * pVertex;            // 인덱스 : 노드번호, 값 : NOT_USED / USED
    int **ppAdjacentEdge;
} ArrayGraph;

ArrayGraph* createArrayGraph(int maxVertexCount);
ArrayGraph* createArrayDirectedGraph(int maxVertexCount);
void deleteArrayGraph(ArrayGraph* pGraph);
bool isArrayGraphEmpty(ArrayGraph* pGraph);

bool addVertexAG(ArrayGraph* pGraph, int vertexID);
bool addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);
bool addWeightEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight);
bool checkVertexValid(ArrayGraph* pGraph, int vertexID);

bool removeVertexAG(ArrayGraph* pGraph, int vertexID);
bool removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);


#define NOT_USED    0
#define USED        1

// #define FAIL        0
// #define SUCCESS     1