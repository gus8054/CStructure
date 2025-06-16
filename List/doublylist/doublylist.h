#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct DoublyListNodeType{
  int data;
  struct DoublyListNodeType* pLeftLink;
  struct DoublyListNodeType* pRightLink;
} DoublyListNode;

typedef struct DoublyListType{
  int currentElementCount;
  DoublyListNode headerNode;
} DoublyList;

DoublyList* createDoublyList();
void deleteDoublyList(DoublyList* pList);
bool addDLElement(DoublyList* pList, int position, DoublyListNode element);
bool removeDLElement(DoublyList* pList, int position);
void clearDoublyList(DoublyList* pList);
int getDoublyListLength(DoublyList* pList);
DoublyListNode* getDLElement(DoublyList* pList, int position);
