#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct GraphVertexType{
    int vertexID;
    int weight;
} GraphVertex;

typedef struct LinkedListNodeType{
    GraphVertex data;
    struct LinkedListNodeType* pLink;
} LinkedListNode;

typedef struct LinkedListType{
  int currentElementCount;
  LinkedListNode headerNode;
} LinkedList;

enum GraphType { UNDIRECTED = 1, DIRECTED = 2};

typedef struct LinkedGraphType{
    int maxVertexCount;
    int currentVertexCount;
    enum GraphType graphType;
    int* pVertex;
    LinkedList** ppAdjacentEdge;
} LinkedGraph;

LinkedList* createLinkedList();
void deleteLinkedList(LinkedList* pList);
bool addLLElement(LinkedList* pList, int position, LinkedListNode element);
bool removeLLElement(LinkedList* pList, int position);
void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
LinkedListNode* getLinkedListNode(LinkedList* pList, int position);

LinkedGraph* createLinkedGraph(int maxVertexCount);
LinkedGraph* createLinkedDirectedGraph(int maxVertexCount);
void _deleteLinkedGraph(LinkedGraph* pGraph);
bool _isEmptyLG(LinkedGraph* pGraph);
bool addVertexLG(LinkedGraph* pGraph, int vertexID);
bool addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
bool addWeightEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight);
bool checkVertexValid(LinkedGraph* pGraph, int vertexID);
bool hasEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
bool removeVertexLG(LinkedGraph* pGraph, int vertexID);
bool removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
void deleteGraphNode(LinkedList* pList, int delVertexID);
int findGraphNodePosition(LinkedList* pList, int vertexID);

#define NOT_USED    0
#define USED        1

#define FAIL        0
#define SUCCESS     1