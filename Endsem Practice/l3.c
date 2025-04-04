#include <stdio.h>

void BuubleSort(int Arr[],int n){
    for(int j = 0;j<n-1;j++){
        for(int i = 0;i<n-1-j;i++){
            if(Arr[i] > Arr[i+1]){
                int temp = Arr[i];
                Arr[i] = Arr[i+1];
                Arr[i+1] = temp;
            }
        }
    }
}

void SelectionSort(int Arr[], int n){
    for(int i = 0;i<n;i++){
        int maxi = i;
        for(int j =i+1;j<n;j++)if(Arr[j] < Arr[maxi])maxi = j;
        int temp = Arr[maxi];
        Arr[maxi] = Arr[i];
        Arr[i] = temp;
    }
}

int isPartition(int Arr[], int n){
    if(n % 2 != 0)return 0;
    int total = 0;
    for(int i=0;i<n;i++)total+=Arr[i];
    if(total %2 != 0)return 0;
    int goal = total /2;
    int TotalSubsets = 1 << n;
    for(int i = 1;i<TotalSubsets-1;i++){
        int sum = 0;
        for(int j=0;j<n;j++)if(i &(1<<j))sum += Arr[j];
        if(sum == goal)return 1;
    }
}

int main(){
    printf("Hello World!");
    int Arr[] = {6,5,4,3,2,1};
    SelectionSort(Arr,6);
    for(int i = 0;i<6;i++)printf("%d ",Arr[i]);

    return 0;
}