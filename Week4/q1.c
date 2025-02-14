// Write a program for assignment problem by brute-force technique and analyze its time efficiency. 
// Obtain the experimental result of order of growth and plot the result.

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int ans[1000], min = INT_MAX, opcount;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void permuter(int l, int r, int arr[][r + 1], int per[]){
    int i;
    if (l == r){
        int sum = 0;
        for (i = 0; i <= r; i++){
            opcount++;
            int idx = per[i];
            sum += arr[i][idx];
        }
        if (sum < min){
            for (i = 0; i <= r; i++){
                int idx = per[i];
                ans[i] = arr[i][per[i]];
            }
            min = sum;
        }
    }
    else{
        for (i = l; i <= r; i++){
            swap((per + l), (per + i));
            permuter(l+1, r, arr, per);
            swap((per + l), (per + i));
        }
    }
}
int main(){
    int i, j, n;
    printf("Enter the size of the square matrix : ");
    scanf("%d", &n);
    int arr[n][n];
    printf("Enter the matrix : \n");
    for (i = 0; i < n; i++)for (j = 0; j < n; j++)scanf("%d", &arr[i][j]);
    int per[n];
    for (i = 0; i < n; i++)per[i] = i;
    permuter(0, n - 1, arr, per);
    printf("Combination for minimum cost : ");
    for (i = 0; i < n; i++)printf("%d ", ans[i]);
    printf("\nThe Minimum Cost is : %d\n", min);
    printf("Opcount = %d\n", opcount);
    return 0;
}