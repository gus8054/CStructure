#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int ElementType;

typedef struct ArrayListNodeType{
    ElementType data;
} ArrayListNode;

typedef struct ArrayListType{
    int currentElementCount;
    int maxElementCount;
    ArrayListNode* pElement;
} ArrayList;

ArrayList* AL_Create(int maxElementCount);
void AL_Destroy(ArrayList* pList);
bool AL_Insert(ArrayList* pList, int position, ElementType element);
bool AL_Remove(ArrayList* pList, int position);
bool AL_Clear(ArrayList* pList);
ArrayListNode* AL_GetAt(ArrayList* pList, int position);