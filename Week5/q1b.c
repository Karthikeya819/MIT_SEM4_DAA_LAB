#include <stdio.h>
#include <stdlib.h>

int queue[100], k_1 = 0, k = 0, arr[100][100], n, indegree[100],counter = 0;

int main(){
    int i,j;
    printf("Enter the Number of Vertices : ");scanf("%d", &n);
    printf("Enter the Adjacency Matrix : \n");
    for(i = 0; i<n; i++)for(j = 0; j<n; j++)scanf("%d", &arr[i][j]);
    for(i=0; i<n; ++i)indegree[i]=0;

    for(i = 0; i < n; ++i)for(j = 0; j < n; ++j)if(arr[j][i]==1)indegree[i]++;

    while(1){
        for(i =0 ;i<n; ++i){
            if(indegree[i]==0){
                indegree[i]=-1;
                break;
            }
        }
        if(indegree[i]==-1){
            queue[k++] = i;
            for(j = 0; j<n; ++j)if(arr[i][j]==1)indegree[j]--;
        }
        counter++;
        if(counter >= n)break;
    }
    printf("\n");
    for(i=0;i<n;++i)printf("%d ",queue[i]);
    printf("\n");
    return 0;
}