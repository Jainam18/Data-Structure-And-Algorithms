#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void LLT(node* head){
    node* p = head;
    do{
        printf("%d ",p->data);
        p = p->next;
    }while(p != head);
    //ALTERNATIVE METHOD    
    // while(p->next!=head){
    //     printf("%d ",p->data);
    //     p = p->next;
    // }
    // printf("%d",p->data);
}

node* InsertAtBeg(node* head,node* last,int data){
    node* ptr = (node*)malloc(sizeof(node));
    ptr->data = data;
    last->next = ptr;
    ptr->next = head;
    return ptr;
}

node* InsertAtBeg2(node*head,int data){
    node* ptr = (node*)malloc(sizeof(node));
    ptr->data = data;
    node* p = head;
    while(p->next!=head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return ptr;
}

int main(){
    node * first = (node *)malloc(sizeof(node));
    node * second = (node *)malloc(sizeof(node));
    node * third = (node *)malloc(sizeof(node));
    node * fourth = (node *)malloc(sizeof(node));

    first->data = 7;
    first->next = second;

    second->data = 9;
    second->next = third;

    third->data = 11;
    third->next = fourth;

    fourth->data = 13;
    fourth->next = first;  

    LLT(first);
    // first = InsertAtBeg(first,fourth,5);
    first = InsertAtBeg2(first,5);
    printf("\nAfter Insertion we get : \n");
    LLT(first);
    getch();
    return 0;
}