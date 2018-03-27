#include <stdio.h>

float printQueue[100];
int queueSize=0;

void addToPrintQueue(float n){
    printQueue[queueSize] = n;
    queueSize++;
}

void printEverything(){
    for(int i=0; i < queueSize; i++){
        printf("%.2f\n", printQueue[i]);
    }
}