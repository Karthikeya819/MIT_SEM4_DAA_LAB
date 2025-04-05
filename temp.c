// Quick Sort
#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[],int low, int high){
    int pivot = low,i = low + 1,j = high;
    while(i < high && arr[i] < arr[pivot])i++;
    while(arr[j] > arr[pivot])j--;
    
    if(i < j)swap(&arr[i],&arr[j]);
    else swap(&arr[pivot],&arr[j]);

    return j;
}

void quickSort(int arr[],int low, int high){
    if(low < high){
        int part = partition(arr, low, high);
        quickSort(arr, low, part);
        quickSort(arr,part+1,high);
    }
}

void merge(int arr[],int low, int mid, int high){
    int len1 = mid - low + 1;
    int len2 = high - mid;

    int arr1[len1],arr2[len2];
    for(int i =0;i<len1;i++)arr1[i] = arr[low+i];
    for(int i = 0;i<len2;i++)arr2[i] = arr[mid+i+1];

    int i = 0,j = 0,k = 0;
    while(i < len1 && j < len2){
        if(arr1[i] < arr2[j]){
            arr[low+k] = arr1[i];
            k++;i++;
        }else if(arr1[i] >= arr2[j]){
            arr[low+k] = arr2[j];
            k++;j++;
        }
    }
    while(i < len1){
        arr[low+k] = arr1[i];
        i++;k++;
    }
    while(j < len2){
        arr[low+k] = arr2[j];
        j++;k++;
    }
}

void mergeSort(int arr[],int low,int high){
    if(low < high){
        int mid = low + (high-low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);

        merge(arr,low,mid,high);
    }
}

int main(){
    int arr[] = {6,5,4,3,2,1};
    mergeSort(arr,0,6);
    for(int i = 0;i<6;i++)printf("%d ",arr[i]);

    return 0;
}

