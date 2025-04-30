#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct LinkedListNodeType{
  int data;
  struct LinkedListNodeType* pLink;
} LinkedListNode;

typedef struct LinkedListType{
  int currentElementCount;
  LinkedListNode headerNode;
} LinkedList;

LinkedList* createLinkedList();
void deleteLinkedList(LinkedList* pList);
bool addLLElement(LinkedList* pList, int position, LinkedListNode element);
bool removeLLElement(LinkedList* pList, int position);
void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
LinkedListNode* getLinkedListNode(LinkedList* pList, int position);