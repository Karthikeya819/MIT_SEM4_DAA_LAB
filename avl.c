// Insertion into AVL Tree
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left,*right;
    int height;
}*node_ptr;

int height(struct Node *N){
    if (N == NULL)return 0;
    return N->height;
}

int max(int a, int b){
    return (a > b)? a : b;
}

int balancefactor(node_ptr root){
    if(root == NULL)return 0;
    return height(root->left) - height(root->right);
}

node_ptr createNode(int x){
    node_ptr new_node = (node_ptr)malloc(sizeof(struct Node));
    new_node->data = x;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 1;
}

struct Node *rightRotate(struct Node *y){
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    x->right = y;
    y->left = T2;

    y->height = max(height(y->left),height(y->right)) + 1;
    x->height = max(height(x->left),height(x->right)) + 1;

    return x;
}

struct Node *leftRotate(struct Node *x){
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left),height(x->right)) + 1;
    y->height = max(height(y->left),height(y->right)) + 1;

    return y;
}

node_ptr insertBST(node_ptr root, int item){
    if(root == NULL)return createNode(item);
    if(root->data > item)root->left = insertBST(root->left, item);
    else if(root->data < item)root->right = insertBST(root->right, item);
    else return root;

    root->height = 1 + max(height(root->left),height(root->right));
    int bf = balancefactor(root);

    // Left Left
    if(bf > 1 && item < root->left->data)return rightRotate(root);
    // Right Right
    if(bf < -1 && item > root->right->data)return leftRotate(root);
    // Left Right
    if(bf > 1 && item > root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // Right left
    if(bf < -1 && item < root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void InOrder(node_ptr root){
    if(root){
        InOrder(root->left);
        printf("%d ",root->data);
        InOrder(root->right);
    }
}


int main(){
    node_ptr root = NULL;
    root = insertBST(root, 2);
    root = insertBST(root, 56);
    root = insertBST(root, 34);
    root = insertBST(root, 1);

    InOrder(root);


    return 0;
}