#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct LinkedStackNodeType{
    char data;
    struct LinkedStackNodeType* pLink;
} LinkedStackNode;

typedef struct LinkedStackType{
    int currentElementCount;
    LinkedStackNode* pTopElement;
}LinkedStack;

LinkedStack* createLinkedStack();
void deleteLinkedStack(LinkedStack* pStack);
bool pushLS(LinkedStack* pStack, LinkedStackNode element);
LinkedStackNode* popLS(LinkedStack* pStack);
LinkedStackNode* peekLS(LinkedStack* pStack);
bool isLinkedStackFull(LinkedStack* pStack);
bool isLinkedStackEmpty(LinkedStack* pStack);