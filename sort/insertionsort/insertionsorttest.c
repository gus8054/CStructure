#include "insertionsort.c"

int insertionSortMain(){
    int values[] = {80, 50, 70, 10, 60, 20, 40, 30};
    int len = sizeof(values)/sizeof(values[0]);
    printf("Before Sort\n");
    printArray(values, len);

    insertionSort(values, len);

    printf("After Sort\n");
    printArray(values, len);

    return 0;
}