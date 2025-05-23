#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}*node_ptr;

node_ptr create_node(int data){
    node_ptr ptr = (node_ptr) malloc(sizeof(node_ptr));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
}

node_ptr insert_BT(node_ptr head, int item){
    node_ptr new_node = create_node(item);
    if(head == NULL)return new_node;
    node_ptr ptr,ptr_prev;
    ptr = head; ptr_prev = NULL;
    while(ptr != NULL){
        ptr_prev = ptr;
        if(ptr->data > item)ptr = ptr->left;
        else if(ptr->data < item) ptr = ptr->right;
        else{
            printf("Key %d already Exists! \n",item);
            return head;
        }
    }
    if(ptr_prev->data > item)ptr_prev->left = new_node;
    else ptr_prev->right = new_node;
    return head;
}
void recInOrder(node_ptr ptr){
    if(ptr != NULL){
        recInOrder(ptr->left);
        printf("%d ",ptr->data);
        recInOrder(ptr->right);
    }
}
void recPreOrder(node_ptr ptr){
    if(ptr != NULL){
        printf("%d ",ptr->data);
        recPreOrder(ptr->left);
        recPreOrder(ptr->right);
    }
}
void recPostOrder(node_ptr ptr){
    if(ptr != NULL){
        recPostOrder(ptr->left);
        recPostOrder(ptr->right);
        printf("%d ",ptr->data);
    }
}
int main(){
    node_ptr root;
    root = NULL;
    root = insert_BT(root,2);
    root = insert_BT(root,3);
    root = insert_BT(root,4);
    root = insert_BT(root,4);
    printf("RecInOrder: ");recInOrder(root);
    printf("\nRecPreOrder: ");recPreOrder(root);
    printf("\nRecPostOrder: ");recPostOrder(root);printf("\n");
    return 0;
}