#include <stdio.h>
// Merge Sort

void merge(int arr[],int low, int mid, int high){
    int len1 = mid - low + 1;
    int len2 = high - mid;

    int arr1[len1],arr2[len2];
    for(int i=0;i<len1;i++)arr1[i] = arr[low+i];
    for(int j=0;j<len2;j++)arr2[j] = arr[mid+j+1];

    int i = 0,j = 0,k=low;
    while(i < len1 && j < len2){
        if(arr1[i] <= arr2[j]){
            arr[k++] = arr1[i];
            i++;
        }else if(arr1[i] >= arr2[j]){
            arr[k++] = arr1[j];
            j++;
        }
    }
    while(i < len1)arr[k++] = arr1[i++];
    while(j < len2)arr[k++] = arr2[j++];

}



void MergeSort(int arr[], int low, int high){
    if(low < high){
        int mid = low + (high - low)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);

        merge(arr,low,mid,high);
    }
}

int main(){
    int Arr[] = {6,5,4,3,2,1};
    MergeSort(Arr,0,6);
    for(int i = 0;i<6;i++)printf("%d ",Arr[i]);
    return 0;
}