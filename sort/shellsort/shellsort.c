#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void shellInsertionSort(int value[], int count, int interval){
    if(count <= 1) return;
    if(interval < 1) return;

    for(int i = interval; i <= count - 1; i++){
        int item = value[i];
        int j = i;
        while(!(j < interval || value[j - interval] <= item)){
            value[j] = value[j-interval];
            j -= interval;
        }
        if(j != i) value[j] = item;
    }

}

void printArray(int value[], int count){
    if(count <= 0) return;
    for(int i = 0; i < count; i++){
        printf("%d ", value[i]);
    }
    printf("\n");
}

void shellSort(int value[], int count){
    if(count <= 0) return;
    int interval = count / 2;
    while(true){
        if(interval < 1) break;
        shellInsertionSort(value, count, interval);

        printf("Interval-%d, ", interval);
        printArray(value, count);

        interval /= 2;
    }
}
