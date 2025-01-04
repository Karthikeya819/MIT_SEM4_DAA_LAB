#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}*node_ptr;
typedef struct NodeArray{
    int data;
    struct NodeArray *next;
    struct Node *right;
}*nodearr_ptr;

void GenerateGraph(){
    int nov;
    printf("Enter total no of vertices: ");scanf("%d",&nov);
    nodearr_ptr AdjacencyList;
    AdjacencyList = NULL;
    for(int i = 0;i<nov;i++){
        nodearr_ptr new_node = (nodearr_ptr) malloc(sizeof(nodearr_ptr));
        new_node->data = i;
        new_node->next = NULL;
        if(AdjacencyList == NULL)AdjacencyList = new_node;
        else{
            nodearr_ptr ptr = AdjacencyList;
            while(ptr->next != NULL)ptr = ptr->next;
            ptr->next = new_node;
        }
    }
    int AdjacencyMatrix[nov][nov];
    for(int i=0;i<nov;i++)for(int j=0;j<nov;j++)AdjacencyMatrix[i][j] = 0;
    // Adding Nodes
    nodearr_ptr ptr_trav;ptr_trav = AdjacencyList;
    for(int i=0; i<nov;i++){
        int deg;
        node_ptr ptr1_trav;
        printf("    Enter %d Node degree: ",i);scanf("%d",&deg);
        for(int j=0;j<deg;j++){
            int value;
            printf("        Enter %d Node %d Connection: ",i,j);scanf("%d",&value);
            node_ptr new_node = (node_ptr) malloc(sizeof(node_ptr));
            new_node->data = value;
            new_node->next = NULL;
            AdjacencyMatrix[i][value] = 1;
            if(j == 0){ptr1_trav = new_node;ptr_trav->right = new_node;}
            else{ptr1_trav->next = new_node;ptr1_trav=new_node;}
        }
        ptr_trav = ptr_trav->next;
    }
    //Printing Adjacency MAtrix
    printf("Adjacency Matrix: \n");
    for(int i=0;i<nov;i++){for(int j=0;j<nov;j++)printf("%d ",AdjacencyMatrix[i][j]);printf("\n");}

    //Printing Adjacency List
    printf("\n AdjacencyList: \n");
    nodearr_ptr ptr;
    ptr = AdjacencyList;
    while(ptr != NULL){
        printf("%d",ptr->data);
        node_ptr ptr1 = ptr->right;
        while(ptr1->next != NULL){
            printf(" -> %d",ptr1->data);
            ptr1 = ptr1->next;
        }
        printf(" -> %d \n",ptr1->data);
        ptr = ptr->next;
    }
}


int main(){
    GenerateGraph();

    return 0;
}