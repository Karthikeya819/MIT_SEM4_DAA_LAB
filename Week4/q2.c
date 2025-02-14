// Write a program for depth-first search of a graph. Identify the push and pop order of vertices.

#include <stdio.h>

int Stack[30],tos=-1;

void DFS(int N,int AdjacencyMatrix[][N],int Start){
    int PopOrder[20],PushOrder[20],popc=0,pushc=0;
    Stack[++tos] = Start;
    PushOrder[pushc++] = Start;
    int VisitedNodes[N];
    for(int i=0;i<N;i++)VisitedNodes[i]=0;
    while(tos >= 0){
        int CurNode = Stack[tos--];
        PopOrder[popc++] = CurNode;
        if(VisitedNodes[CurNode] == 1)continue;
        for(int i = 0;i<N;i++){
            if(AdjacencyMatrix[CurNode][i] == 1 && VisitedNodes[i] == 0){
                Stack[++tos]=i;
                PushOrder[pushc++] = i;
            }
        }
        VisitedNodes[CurNode] = 1;
    }
    // printf("popc: %d, pushc: %d \n",popc,pushc);
    printf("Pop Order: ");
    for(int i = 0;i<popc;i++)printf("%d ",PopOrder[i]);
    printf("\n");
    printf("Push Order: ");
    for(int i = 0;i<pushc;i++)printf("%d ",PushOrder[i]);
    printf("\n");
}

int main(){
    int N;
    printf("Enter No of Nodes:");scanf("%d",&N);
    int AdjacencyMatrix[N][N];
    for(int i = 0; i<N;i++)for(int j = 0; j<N;j++)scanf("%d",&AdjacencyMatrix[i][j]);
    DFS(N,AdjacencyMatrix,0);
    return 0;
}
