#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct ArrayListNodeType{
  int data;
} ArrayListNode;

typedef struct ArrayListType{
  int maxElementCount;
  int currentElementCount;
  ArrayListNode* pElement;
} ArrayList;

ArrayList* createArrayList(int maxElementCount);
void deleteArrayList(ArrayList* pList);
bool addALElement(ArrayList* pList, int position, ArrayListNode element);
bool removeALElement(ArrayList* pList, int position);
bool isArrayListFull(ArrayList* pList);
void clearArrayList(ArrayList* pList);
int getArrayListLength(ArrayList* pList);
ArrayListNode* getArrayListNode(ArrayList* pList, int position);

