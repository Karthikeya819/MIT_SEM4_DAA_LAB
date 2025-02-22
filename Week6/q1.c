// Find total number of nodes in a binary tree and analyze its efficiency. Obtain the
// experimental result of order of growth and plot the result.

#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *left, *right;
};
typedef struct node *NODE;
NODE root=NULL;
int opcount = 0;

NODE insert(int ele, NODE node){
    NODE temp;
    if(node == NULL){
        temp= (NODE)malloc(sizeof(struct node));
        temp->val=ele;
        temp->left = temp->right = NULL;
        if(root == NULL)root=temp;
        return temp;
    }else if(ele < node->val){
        node->left = insert(ele, node->left);
        return node;
    }else if(ele > node->val){
        node->right = insert(ele,node->right);
        return node;
    }else {
        printf("Duplicate element found while inserting. Insertion failed\n");
        return NULL;
    }
}

int node_count(NODE node){
    opcount++;
    if(node==NULL)return 0;
    else return node_count(node->left) + node_count(node->right) + 1;
}

void main() {
    int choice,ele;
    printf("1. Insert an element\n");
    printf("2. Find No of Nodes of BST\n");
    printf("3. Exit\n");
    do{
        printf("Please enter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: 
                printf("    Please enter an element: ");
                scanf("%d", &ele);
                insert(ele,root);
        break;
            case 2:
                opcount = 0;
                printf("    HNumber of Nodes : %d\n",node_count(root));
                printf("    Opcount=%d \n",opcount);
        break;
            case 3: 
                break;
            default: printf("Invalid choice. Please enter valid choice\n");
        break;
        }
    }while(choice != 3);
}