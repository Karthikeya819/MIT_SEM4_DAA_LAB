// heaps

#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void heapTopBottom(int heap[],int index){
    int parent = (index-1)/2;
    if(heap[parent] < heap[index]){
        swap(&heap[parent],&heap[index]);
        heapTopBottom(heap,parent);

    }
}
void insertHeap(int heap[], int *size, int item){
    heap[*size] = item;
    heapTopBottom(heap,*size);
    (*size)++;
}

int main(){
    int heap[20];
    int size = 0;
    insertHeap(heap,&size,56);
    insertHeap(heap,&size,6);
    insertHeap(heap,&size,5);
    insertHeap(heap,&size,84);
    for(int i=0;i<size;i++)printf("%d ",heap[i]);

}