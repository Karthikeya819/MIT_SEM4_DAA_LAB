#include <stdio.h>

#define SIZE 5

void floyd(int graph[SIZE][SIZE]) {
    int *arr = (int*) graph;
    for(int i = 0; i < SIZE * SIZE; i++)
        arr[i] = arr[i] ? arr[i] : 99999999;

    for(int k = 0; k < SIZE; k++)
        for(int i = 0; i < SIZE; i++)
            for(int j = 0; j < SIZE; j++) {
                int temp = graph[i][k] + graph[k][j];
                graph[i][j] = temp < graph[i][j] ? temp : graph[i][j];
            }

    for(int i = 0; i < SIZE * SIZE; i++)
        arr[i] = arr[i] != 99999999 ? arr[i] : 0;

    printf("\nShortest paths:\n");
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
}

void main() {
    int graph[SIZE][SIZE] = {
        {0, 5, 3, 0, 0},
        {0, 0, 2, 6, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {8, 0, 0, 0, 0}
    };

    floyd(graph);
}