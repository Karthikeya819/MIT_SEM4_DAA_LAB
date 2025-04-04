#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int item;
    struct node *left,*right;
}*node_ptr;

node_ptr Create_Node(int x){
    node_ptr new_node = (node_ptr) malloc(sizeof(struct node));
    new_node->item = x;
    new_node->left = NULL;
    new_node->right = NULL;
}
node_ptr Insert_BST(node_ptr root, int x){
    node_ptr new_node = Create_Node(x);
    if(root == NULL) return new_node;
    node_ptr ptr,prev_ptr;
    prev_ptr = NULL;ptr = root;
    while(ptr != NULL){
        prev_ptr = ptr;
        if(ptr->item < x)ptr = ptr->right;
        else if(ptr->item > x)ptr = ptr->left;
        else{
            printf("%d already exists in BST!\n",x);
            return root;
        }
    }
    if(prev_ptr->item > x)prev_ptr->left = new_node;
    else if(prev_ptr->item < x)prev_ptr->right = new_node;
    return root;
}

void InOrder(node_ptr root){
    if(root != NULL){
        InOrder(root->left);
        printf("%d ",root->item);
        InOrder(root->right);
    }
}

int main(){
    node_ptr root = NULL;
    root = Insert_BST(root, 5);
    root = Insert_BST(root, 10);
    root = Insert_BST(root, 30);
    root = Insert_BST(root, 58);
    root = Insert_BST(root, 1);

    InOrder(root);

    return 0;
}