#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
enum GraphType {UNDIRECTED, DIRECTED};
typedef struct GraphNodeType{
    int vertexID;
    int weight;
} GraphNode;
typedef struct LinkedListNodeType{
    GraphNode data;
    struct LinkedListNodeType* pLink;
} LinkedListNode;
typedef struct LinkedListType{
    int currentElementCount;
    LinkedListNode headerNode;
} LinkedList;
typedef struct LinkedGraph{
    int currentVertexCount;
    int maxVertexCount;
    enum GraphType graphType;
    bool* pVertex;
    LinkedList** ppAdjacentEdge;
} LinkedGraph;

LinkedList* createLinkedList();
void deleteLinkedList(LinkedList* pList);
bool addLLElement(LinkedList* pList, int position, LinkedListNode element);
bool removeLLElement(LinkedList* pList, int position);
bool clearLinkedList(LinkedList* pList);
LinkedGraph* createLinkedGraph(int maxVertexCount);
LinkedGraph* createLinkedDirectedGraph(int maxVertexCount);
void deleteLinkedGraph(LinkedGraph* pGraph);
bool addVertexLG(LinkedGraph* pGraph, int vertexID);
bool checkVertexValid(LinkedGraph* pGraph, int vertexID);
bool hasEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
bool addWeightEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight);
bool addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
bool removeVertexLG(LinkedGraph* pGraph, int vertexID);
bool removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
int findGraphNodePosition(LinkedList* pList, int vertexID);
bool isLinkedGraphEmpty(LinkedGraph* pGraph);