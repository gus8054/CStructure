#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct LinkedDequeNodeType{
    char data;
    struct LinkedDequeNodeType* pLeftLink;
    struct LinkedDequeNodeType* pRightLink;
}LinkedDequeNode;

typedef struct LinkedDequeType{
    int currentElementCount;
    LinkedDequeNode* pFront;
    LinkedDequeNode* pRear;
}LinkedDeque;

LinkedDeque* createLinkedDeque();
void deleteLinkedDeque(LinkedDeque* pDeque);
bool pushFrontLD(LinkedDeque* pDeque, LinkedDequeNode element);
LinkedDequeNode* popFrontLD(LinkedDeque* pDeque);
bool pushRearLD(LinkedDeque* pDeque, LinkedDequeNode element);
LinkedDequeNode* popRearLD(LinkedDeque* pDeque);
LinkedDequeNode* peekFrontLD(LinkedDeque* pDeque);
LinkedDequeNode* peekRearLD(LinkedDeque* pDeque);
bool isLinkedDequeFull(LinkedDeque* pDeque);
bool isLinkedDequeEmpty(LinkedDeque* pDeque);



