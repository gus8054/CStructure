#include "ArrayList.c"

int test(){

    ArrayList* list = AL_Create(3);  // 초깃값 3으로 작게 설정
    if (!list) {
        printf("Failed to create ArrayList.\n");
        return 1;
    }
    printf("ArrayList created.\n");

    // 삽입 테스트
    AL_Insert(list, 0, 100);  // [100]
    AL_Insert(list, 1, 200);  // [100, 200]
    AL_Insert(list, 2, 300);  // [100, 200, 300]
    AL_Insert(list, 1, 150);  // [100, 150, 200, 300] → 용량 확장 테스트 포함

    printf("After insertion:\n");
    for (int i = 0; i < list->currentElementCount; ++i) {
        printf("[%d] %d\n", i, AL_GetAt(list, i)->data);
    }

    // 삭제 테스트
    AL_Remove(list, 2);  // 200 삭제 → [100, 150, 300]
    printf("\nAfter removal at index 2:\n");
    for (int i = 0; i < list->currentElementCount; ++i) {
        printf("[%d] %d\n", i, AL_GetAt(list, i)->data);
    }

    // 유효하지 않은 접근 테스트
    ArrayListNode* node = AL_GetAt(list, 10);
    if (node == NULL) {
        printf("\nAccess to invalid index correctly returned NULL.\n");
    }

    // 메모리 해제
    AL_Destroy(list);
    printf("\nArrayList destroyed.\n");

    return 0;
}