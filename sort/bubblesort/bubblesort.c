#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int value[], int count){
    for(int i = 0; i < count; i++){
        printf("%d ", value[i]);
    }
    printf("\n");
}

void mySwap(int* num1, int* num2){
    if(num1 == NULL || num2 == NULL) return;
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void bubbleSort(int value[], int count){
    if(count <= 0) return;

    for(int i = count - 2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            if(value[j] > value[j + 1]) mySwap(&value[j], &value[j + 1]);
        }
        printf("Step-%d, ", count-1-i);
        printArray(value, count);
    }
}