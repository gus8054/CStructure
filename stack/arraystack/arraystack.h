#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct ArrayStackNodeType{
    char data;
} ArrayStackNode;

typedef struct ArrayStackType{
    int maxElementCount;
    int currentElementCount;
    ArrayStackNode* pElement;
} ArrayStack;

ArrayStack* createArrayStack(int maxElementCount);
void deleteArrayStack(ArrayStack* pStack);
bool pushAS(ArrayStack* pStack, ArrayStackNode element);
ArrayStackNode* popAS(ArrayStack* pStack);
ArrayStackNode* peekAS(ArrayStack* pStack);
bool isArrayStackFull(ArrayStack* pStack);
bool isArrayStackEmpty(ArrayStack* pStack);