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


int partitionQuickSort(int value[], int startPos, int endPos){
    if(startPos < 0 || endPos < 0) return -1;
    int pivot = endPos;
    int left = startPos;
    int right = endPos;
    
    while(left < right){
        while(true){
            if(left >= right) break;
            if(value[left] > value[pivot]) break;
            left++;
        }
        while(true){
            if(left >= right) break;
            if(value[right] < value[pivot]) break;
            right--;
        }
        mySwap(&value[left], &value[right]);
        printf("start-[%d], end-[%d], pivot-[%d], in-loop, ", startPos, endPos, value[pivot]);
        printArray(value, endPos - startPos + 1);
    }
    mySwap(&value[right], &value[pivot]);
    printf("start-[%d], end-[%d], pivot-[%d], out-loop, ", startPos, endPos, value[right]);
    printArray(value, endPos - startPos + 1);
    
    return right;
}
void quickSort(int value[], int startPos, int endPos){
    if(startPos < 0 || endPos < 0) return;

    int pivot = 0;
    if(startPos < endPos){
        pivot = partitionQuickSort(value, startPos, endPos);
        quickSort(value, startPos, pivot - 1);
        quickSort(value, pivot + 1, endPos);
    }
}