// Quick Sort
#include <stdio.h>

int partition(int arr[], int low, int high){
    int pivot = low;
    int i = low+1,j = high;
    while(i < high && arr[i]<arr[pivot])i++;
    while(arr[j] > arr[pivot])j--;
    if(i < j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }else{
        int temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
    }
    return j;
}

void QuickSort(int arr[], int low, int high){
    if(low < high){
        int pivot = partition(arr,low,high);
        QuickSort(arr,low, pivot - 1);
        QuickSort(arr,pivot+1,high);
    }
}

int main(){
    int Arr[] = {6,5,4,3,2,1};
    QuickSort(Arr,0,6);
    for(int i = 0;i<6;i++)printf("%d ",Arr[i]);
    return 0;
}