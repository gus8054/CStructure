#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void mergeSortInternal(int value[], int buffer[], int startPos, int endPos);

void printArray(int value[], int count){
    if(count <= 0) return;
    for(int i = 0; i < count; i++){
        printf("%d ", value[i]);
    }
    printf("\n");
}

void mergeSort(int value[], int count){
    if(count <= 1) return;
    int* buffer = (int*)malloc(sizeof(int) * count);
    if(buffer == NULL) return;
    mergeSortInternal(value, buffer, 0, count - 1);
    free(buffer);
}
void mergeSortInternal(int value[], int buffer[], int startPos, int endPos){
    if(endPos - startPos <= 0) return;
    int middlePos = (startPos + endPos) / 2;
    mergeSortInternal(value, buffer, startPos, middlePos);
    mergeSortInternal(value, buffer, middlePos + 1, endPos);

    int index1 = startPos;
    int index2 = middlePos + 1;
    int bufferIndex = startPos;
    while(index1 <= middlePos && index2 <= endPos){
        if(value[index1] <= value[index2]){
            buffer[bufferIndex] = value[index1];
            index1++;
        }else{
            buffer[bufferIndex] = value[index2];
            index2++;
        }
        bufferIndex++;
    }
    while(index1 <= middlePos){
        buffer[bufferIndex] = value[index1];
        bufferIndex++;
        index1++;
    }
    while(index2 <= endPos){
        buffer[bufferIndex] = value[index2];
        bufferIndex++;
        index2++;
    }
    
    for(int i = startPos; i <= endPos; i++){
        value[i] = buffer[i];
    }
    
    printf("start-%d, middle-%d, end-%d, ", startPos, middlePos, endPos);
    for(int i = startPos; i <= endPos; i++){
        printf("%d ", value[i]);
    }
    printf("\n");
}