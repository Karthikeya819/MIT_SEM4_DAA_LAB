#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}*node_ptr;
node_ptr create_node(int data){
    node_ptr ptr = (node_ptr) malloc(sizeof(node_ptr));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
}
void display(node_ptr head){
    node_ptr ptr;
    ptr = head;
    while(ptr->next != NULL){
        printf("%d -> ",ptr->data);
        ptr = ptr->next;
    }
    printf("%d \n",ptr->data);
}
node_ptr insert_end(node_ptr head,int item){
    node_ptr new_node = create_node(item);
    if(head == NULL)return new_node;
    node_ptr ptr;
    ptr = head;
    while(ptr->next != NULL)ptr = ptr->next;
    new_node->prev = ptr;
    ptr->next = new_node;
    return head;
}
node_ptr insert_beg(node_ptr head,int item){
    node_ptr new_node = create_node(item);
    if(head == NULL)return new_node;
    new_node->next = head;
    head->prev = new_node;
    return new_node;
}
node_ptr insert_left(node_ptr head, int key, int item){
    node_ptr new_node = create_node(item);
    if(head == NULL)return NULL;
    node_ptr ptr,ptr1;
    ptr = NULL;ptr1 = head;
    while(ptr1 != NULL){
        if(ptr1->data == key){
            if(ptr == NULL){
                ptr1->prev = new_node;
                new_node->next = ptr1;
                return new_node;
            }
            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = ptr1;
            ptr1->prev = new_node;
            return head;
        }
        ptr = ptr1;
        ptr1 = ptr1->next;
    }
}
void search_item(node_ptr head, int item){
    node_ptr ptr;
    int count = 0;
    ptr = head;
    while(ptr != NULL){
        if(ptr->data == item)count++;
        ptr = ptr->next;
    }
    printf("Found Element %d at %d Instances!\n",item,count);
}
void delete_all(node_ptr head, int item){
    node_ptr ptr,ptr_prev;
    ptr_prev = NULL;ptr = head;
    while(ptr != NULL){
        if(ptr->data == item){
            if(ptr != NULL){
                ptr_prev->next = ptr->next;
                if(ptr->next != NULL)ptr->next->prev = ptr_prev;
            }
            free(ptr);
            ptr = ptr_prev;
        }
        ptr_prev = ptr;
        ptr = ptr->next;
    }
}
int main(){
    node_ptr head;
    head = NULL;
    head = insert_beg(head,2);
    head = insert_beg(head,3);
    head = insert_beg(head,4);
    head = insert_beg(head,1); 
    display(head);
    head = insert_left(head,3,8);
    display(head);
    search_item(head,8);
    delete_all(head, 8);
    display(head);
    return 0;
}