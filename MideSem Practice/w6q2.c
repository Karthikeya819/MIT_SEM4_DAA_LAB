// Quick Sort
#include <stdio.h>

void swap(int *num1,int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int Parition(int Arr[],int low,int high){
    int pivot = low;
    int i=low+1,j=high;

    while(i<high && Arr[i]<Arr[pivot])i++;
    while(j>low && Arr[j]>Arr[pivot])j--;

    if(i < j)swap(&Arr[i],&Arr[j]);
    else swap(&Arr[pivot],&Arr[j]);

    return j;
}
void QuickSort(int Arr[],int low,int high){
    if(low < high){
        int pivot = Parition(Arr,low,high);
        QuickSort(Arr,0,pivot-1);
        QuickSort(Arr,pivot+1,high);
    }
}

int main(){
    int Arr[] = {6,5,4,3,2,1};
    QuickSort(Arr,0,6);
    for(int i = 0;i<6;i++)printf("%d ",Arr[i]);
    return 0;
}