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
    if(count <= 1) return;
    for(int i = 1; i <= count - 1; i++){
        int j = i;
        int item = value[i];
        while(!(j <= 0 || value[j - 1] <= item)){
            value[j] = value[j - 1];
            j--;
        }
        if(j != i) value[j] = item;
    }
}