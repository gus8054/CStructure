#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int value[], int count){
    for(int i = 0; i < count; i++){
        printf("%d ", value[i]);
    }
    printf("\n");
}

void insertionSort(int value[], int count){
    if(count <= 0) return;
    for(int i = 1; i <= count - 1; i++){
        int temp = value[i];
        int j = i - 1;
        while(j >= 0){
            if(temp < value[j]){
                value[j+1] = value[j];
                j--;
            }else break; 
        }
        value[j + 1] = temp;
        printf("Step-%d, ", i);
        printArray(value, count);
    }
}