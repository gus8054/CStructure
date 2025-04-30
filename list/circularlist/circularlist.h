#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct CircularListNodeType{
  int data;
  struct CircularListNodeType* pLink;
} CircularListNode;

typedef struct CircularListType{
  int currentElementCount;
  CircularListNode* pHeadPointer;
} CircularList;

CircularList* createCircularList();
void deleteCircularList(CircularList* pList);
bool addCLElement(CircularList* pList, int position, CircularListNode element);
bool removeCLElement(CircularList* pList, int position);
void clearCircularList(CircularList* pList);
int getCircularListLength(CircularList* pList);
CircularListNode* getCLElement(CircularList* pList, int position);
