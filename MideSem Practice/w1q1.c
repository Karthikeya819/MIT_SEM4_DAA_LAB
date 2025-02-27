#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left,*right;
}*node_ptr;

node_ptr Create_Node(int data){
    node_ptr new_node = (node_ptr)malloc(sizeof(node_ptr));
    new_node->data = data;new_node->left = NULL;new_node->right = NULL;
    return new_node;
}

node_ptr Insert_BST(node_ptr root,int item){
    node_ptr new_node = Create_Node(item);
    if(root == NULL)return new_node;
    node_ptr cur_ptr,prev_ptr;
    prev_ptr = NULL;cur_ptr = root;
    while(cur_ptr != NULL){
        if(item > cur_ptr->data){
            prev_ptr = cur_ptr;cur_ptr = prev_ptr->right;
        }else if(item < cur_ptr->data){
            prev_ptr = cur_ptr;cur_ptr = prev_ptr->left;
        }else{
            printf("Duplicate Found!");
            exit(0);
        }
    }
    if(prev_ptr->data < item)prev_ptr->right = new_node;
    else if(prev_ptr->data > item)prev_ptr->right = new_node;
    return root;
}

void PreOrder(node_ptr root){
    if(root != NULL){
        printf("%d ",root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
void PostOrder(node_ptr root){
    if(root != NULL){
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ",root->data);
    }
}
void InOrder(node_ptr root){
    if(root != NULL){
        InOrder(root->left);
        printf("%d ",root->data);
        InOrder(root->right);
    }
}


int main(){
    node_ptr root;
    root = NULL;
    root = Insert_BST(root,2);
    root = Insert_BST(root,3);
    root = Insert_BST(root,4);
    root = Insert_BST(root,5);

    printf("PreOrder: ");PreOrder(root);printf("\n");
    printf("PostOrder: ");PostOrder(root);printf("\n");
    printf("InOrder: ");InOrder(root);printf("\n");

    return 0;
}