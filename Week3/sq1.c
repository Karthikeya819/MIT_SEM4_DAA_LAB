// Write a program to sort a set of integers using selection sort algorithm and analyze its
// time efficiency. Obtain the experimental result of order of growth. Plot the result for the
// best and worst case.

#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int *Array,int length){
    int OpsCount = 0;
    for (int i = 0; i < length; i++)printf("%d ",Array[i]);
    for(int i = 0; i < length; i++){
        int small_index = i;
        for(int j = i+1; j < length; j++){
            if(Array[j]<Array[small_index])small_index=j;
            OpsCount++;
        }
        int temp = Array[i];
        Array[i] = Array[small_index];
        Array[small_index] = temp;
    }
    printf(" OpsCount: %d \n",OpsCount);
}


int main(){
    // int Arr[] = {5,4,3,2,1};
    // SelectionSort(&Arr[0],5);
    int N = 5;
    int NoOfSamples;printf("Enter No of Samples:");scanf("%d",&NoOfSamples);
    for(int i = 0; i < NoOfSamples;i++){
        int *Arr = (int*)malloc(N*sizeof(int));
        for(int j = 0;j<N;j++)Arr[j] = N-j;
        SelectionSort(Arr,N);
        N += 5;
    }
    
    return 0;
}