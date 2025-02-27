#include <stdio.h>

void BubbleSort(int *Arr, int length){
    for(int i=0;i<length-1;i++){
        for(int j = 0;j<length-i-1;j++){
            if(Arr[j+1] < Arr[j]){
                int temp = Arr[j+1];
                Arr[j+1] = Arr[j];
                Arr[j] = temp;
            }
        }
    }

}

int main(){
    int len;
    printf("Enter Length of Arr:");scanf("%d",&len);
    int Arr[len];
    for(int i =0;i<len;i++){
        printf("    Enter %d Element:",i);scanf("%d",&Arr[i]);
    }
    BubbleSort(Arr,len);
    for(int i =0;i<len;i++){
        printf("%d ",Arr[i]);
    }

    return 0;
}