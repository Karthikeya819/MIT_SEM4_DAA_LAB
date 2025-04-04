#include <stdio.h>

// Topological Sorting using Source removal technique
int queue[50],k=0;

int main(){
    printf("Hello World!");
    int AdjacencyMatrix[][] = {{ 0, 1, 1, 0, 0, 0 },{ 0, 0, 0, 1, 0, 0 },{ 0, 0, 0, 1, 0, 0 },{ 0, 0, 0, 0, 1, 0 },{ 0, 0, 0, 0, 0, 1 },{ 0, 0, 0, 0, 0, 0 }};
    int n = 6;
    int InOrder[n];
    for(int i=0;i<n;i++)InOrder[i] = 0;
    for(int i =0;i<n;i++)for(int j=0;j<n;j++)if(AdjacencyMatrix[i][j] == 1)InOrder[j] += 1
    int counter = 0;
    while(1){
        for(int i = 0;i<n;++i){if(InOrder[i] == 0){InOrder[i] = -1;break;}}
        if(InOrder[i] == -1){
            queue[k++] = i;
            for(int j= 0;j<n;j++){
                if(AdjacencyMatrix[i][j] == 1)InOrder[j] -= 1;
            }
        }
        counter ++;
        if(counter >= n)break;
    }

    return 0;
}