#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int value[], int count){
    for(int i = 0; i < count; i++){
        printf("%d ", value[i]);
    }
    printf("\n");
}

void selectionSort(int value[], int count){
    if(count <= 0) return;
    for(int i = 0; i < count - 1; i++){
        int minPosition = i;
        for(int j = i + 1; j < count; j++){
            if(value[minPosition] > value[j]) minPosition = j;
        }
        int temp = value[i];
        value[i] = value[minPosition];
        value[minPosition] = temp;

        printf("Step-%d, ", i+1);
        printArray(value, count);
    }
}
