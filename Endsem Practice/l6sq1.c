#include <stdio.h>

int max(int m,int n){
    return (m>n)?m:n;
}

int heightBST(struct Node *root){
    if(root == NULL) return -1;
    return 1 + max(heightBST(root->left),heightBST(root->right));
}
int TotalNodes(struct Node *root){
    if(root == NULL)return 0;
    return 1 + TotalNodes(root->left) + TotalNodes(root->right);
}

int main(){
    printf("Hello World!");

    return 0;
}