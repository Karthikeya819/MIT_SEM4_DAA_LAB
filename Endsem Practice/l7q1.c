#include <stdio.h>
#include <stdlib.h>

int max(int m, int n){
    return (m > n)?m:n;
}

struct Node{
    int item;
    struct Node *left,*right;
    int height;
};

int getHeight(struct Node *root){
    if(root == NULL)return 0;
    return root->height;
}
int getBalanceFactor(struct Node *root){
    if(root == NULL)return 0;
    return getHeight(root->left) - getHeight(root->right);
}
struct Node* create_node(int x){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->item = x;
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->height = 1;
    return newNode;
}

struct Node* leftRotate(struct Node *x){
    struct Node *y = x->left;
    struct Node *T2 = y->right;

    y->right = x;
    x->left = T2;

    x->height = 1 + max(getHeight(x->left),getHeight(x->right));
    y->height = 1 + max(getHeight(y->left),getHeight(y->right));
    return y;
}

struct Node* rightRotate(struct Node *y){
    struct Node *x = y->left;
    struct Node *T2 = x->left;

    x->left = y;
    y->right = T2;

    y->height = 1 + max(getHeight(y->left),getHeight(y->right));
    x->height = 1 + max(getHeight(x->left),getHeight(x->right));
    return x;
}

struct Node* insertBST(struct Node *root, int item){
    if(root == NULL)return create_node(item);
    if(root->item > item)root->left = insertBST(root->left,item);
    else if(root->item < item)root->right = insertBST(root->right,item);
    else return root;

    root->height = 1 + max(getHeight(root->left),getHeight(root->right));
    int bf = getBalanceFactor(root);
    // Left Left
    if(bf > 1 && item < root->left->item)return rightRotate(root);
    // Right Right
    if(bf < -1 && item > root->right->item)return leftRotate(root);
    // Left Right
    if(bf > 1 && item > root->right->item){
        root->right = rightRotate(root);
        return leftRotate(root);
    }
    // Right Left
    if(bf < -1 && item < root->left->item){
        root->left = leftRotate(root);
        return rightRotate(root);
    }
    return root;
}

void preOrder(struct Node *root){
    if(root != NULL){
        printf("%d ", root->item);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
    struct Node *root = NULL;
    root = insertBST(root, 10);
    root = insertBST(root, 20);
    root = insertBST(root, 30);
    root = insertBST(root, 40);
    root = insertBST(root, 50);
    root = insertBST(root, 25);
  
    printf("Preorder traversal : \n");
    preOrder(root);
    printf("\n");
    return 0;
  }