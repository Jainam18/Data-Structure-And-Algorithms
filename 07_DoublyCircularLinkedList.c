#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
}node;

void printLL(node *head){
    node *p =head;
    printf("The Elements in the linked list : \n");
    do{
        printf("%d ",p->data);
        p = p->next;
    }while(p!=head);
    printf("\nThe Elements in the linked list in Reverse Order : \n");
    do{
        p = p->prev;
        printf("%d ",p->data);
    }while(p!=head);
}

node *insertAtBeg(node *head,int data){
    node *ptr = (node*)malloc(sizeof(node));
    node *p = head;
    while(p->next!=head){
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->prev = head->prev;
    ptr->next = head;
    head->prev = ptr;
    head = ptr;
    return head;
}

node *deleteAtBeg(node *head){
    node* ptr = head;
    node *p = head;
    while(p->next!=head){
        p = p->next;
    }
    head = head->next;
    p->next = head;
    head->prev = p;  
    free(ptr);
    return head;
}
int main(){
    node *first = (node*)malloc(sizeof(node));
    node *second = (node*)malloc(sizeof(node));
    node *third = (node*)malloc(sizeof(node));
    node *fourth = (node*)malloc(sizeof(node));

    first->data = 45;
    first->prev = fourth;
    first->next = second;

    second->data = 48;
    second->prev = first;
    second->next = third;

    third->data = 50;
    third->prev = second;
    third->next = fourth;

    fourth->data = 52;
    fourth->prev = third;
    fourth->next = first;

    printLL(first);
    printf("\n");
    first = insertAtBeg(first,42);
    printLL(first);
    printf("\n");
    first = deleteAtBeg(first);
    printLL(first);
    getch();
    return 0;
}