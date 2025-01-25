// Write a program to implement solution to partition problem using brute-force
// technique and analyze its time efficiency theoretically. A partition problem takes
// a set of numbers and finds two disjoint sets such that the sum of the elements in
// the first set is equal to the second set. [Hint: You may generate power set]

#include <stdio.h>
#include <stdlib.h>

char isPartition(int arr[], int len, int sum, int *opCount) {
    (*opCount)++;
    if(sum == 0) return 1;
    else if(len == 0) return 0;
    else if(arr[len - 1] > sum) return isPartition(arr, len - 1, sum, opCount);
    return isPartition(arr, len - 1, sum, opCount) || isPartition(arr, len - 1, sum - arr[len - 1], opCount);
}
void main() {
    int opCount, sum, trCount = 50, *arr;
    for(int len = 2; len <= 10; len++) {
        opCount = 0;
        arr = calloc(len, sizeof(int));
        for(int trial = 0; trial < trCount; trial++) {
            sum = 0;
            for(int i = 0; i < len; i++) {
                arr[i] = rand() * trial * (i + 1);
                sum += arr[i];
            }
            for(int i = len - 1; i > 0; i--) {
                int w = rand() % i;
                int t = arr[i];
                arr[i] = arr[w];
                arr[w] = t;
            }
            isPartition(arr, len, sum / 2, &opCount);
        }
        free(arr);
        printf("Op. count: %d for size %d\n", opCount / trCount, len);
    }
}