// Merge Sort
#include <stdio.h>


void Merge(int Arr[],int low,int mid,int high){
    int l1 = mid - low +1;
    int l2 = high - mid;
    int R[l1],S[l2];
    for(int i=0;i<l1;i++)R[i]=Arr[low+i];
    for(int j=0;j<l2;j++)S[j]=Arr[mid+j+1];
    int i=0,j=0,k=0;
    while(i < l1 && j <l2){
        if(R[i]<S[j]){
            Arr[low+k] = R[i];i++;
        }else{
            Arr[low+k] = S[j];j++;
        }
        k++;
    }
    while(i<l1){
        Arr[low+k] = R[i];
        i++;k++;
    }
    while(j<l2){
        Arr[low+k]= S[j];
        j++;k++;
    }

}


void MergeSort(int Arr[],int low,int high){
    if(low < high){
        int mid = low + (high-low)/2;
        MergeSort(Arr,low,mid);
        MergeSort(Arr,mid+1,high);

        Merge(Arr,low,mid,high);
    }
}

int main(){
    int Arr[] = {5,4,3,2,1};
    MergeSort(Arr,0,4);
    for(int i = 0;i<5;i++)printf("%d ",Arr[i]);
    return 0;
}