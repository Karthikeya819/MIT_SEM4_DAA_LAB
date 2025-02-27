#include <stdio.h>
#include <stdlib.h>
#define Max_Size 100

typedef struct Queue{
    int Arr[Max_Size];int rear;int front;
}*queue;

queue Queue_Init(){
    queue que = (queue)malloc(sizeof(queue));
    que->rear = -1;que->front = -1;
    return que;
}
void enqueue(queue que,int item){
    
}


int main(){
    printf("Hello World!");
    return 0;
}