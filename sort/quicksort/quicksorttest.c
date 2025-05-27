#include "quicksort.c"

int quickSortMain(){
    int values[] = {80, 50, 70, 10, 60, 20, 40, 30};
    int len = sizeof(values)/sizeof(values[0]);
    printf("Before Sort\n");
    printArray(values, len);

    quickSort(values, 0, len - 1);

    printf("After Sort\n");
    printArray(values, len);

    return 0;
}