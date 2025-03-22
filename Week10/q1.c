#include <stdio.h>

#define SIZE 5

void floyds(int graph[SIZE][SIZE]) {
    for(int k = 0; k < SIZE; k++)
        for(int i = 0; i < SIZE; i++)
            for(int j = 0; j < SIZE; j++)
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
}

int main() {
    int graph[SIZE][SIZE] = {
        {0, 5, 3, 0, 0},
        {0, 0, 2, 6, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {8, 0, 0, 0, 0}
    };
    floyds(graph);
    return 0;
}