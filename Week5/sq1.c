#include <stdio.h>
#include <stdlib.h>

// int insertionSort(int *Array, int n){
//     int OpsCount = 0;
//     int j;
//     for(int i = 1; i < n; i++){
//         int key = Array[i];
//         j = i - 1;
//         while(OpsCount++ && j >= 0 && Array[j] > key){
//             Array[j+1] = Array[j];
//             j = j - 1;
//         }
//         Array[j+1] = key;
//     }
//     return OpsCount;
// }
int insertionSort(int *a,int n){
    int i, j, v;
    int opcount=0;
    for(i=1;i<n;i++){
        v=a[i];
        j=i-1;
        while(++opcount && j>=0 && a[j]> v){
            a[j+1]=a[j];
            j=j-1;
        }   
        a[j+1]=v;
    }
    return opcount;
}

int main(){
    int NoOfTestCases = 5;
    int size = 5;
    for(int i = 0;i<NoOfTestCases;i++){
        int *Array = (int*)malloc(size*(i+1)*sizeof(int));
        for(int j = 0;j<(size*(i+1));j++)Array[j] = (size*(i+1))-j;
        printf("Elements are :");
        for(int j = 0;j<(size*(i+1));j++)printf("%d ",Array[j]);
        int OpsCount = insertionSort(&Array[0],size*(i+1));
        printf("OpsCount: %d ",OpsCount);
        printf("Sorted Elements are :");
        for(int j = 0;j<(size*(i+1));j++)printf("%d ",Array[j]);
        printf("\n");
    }
}