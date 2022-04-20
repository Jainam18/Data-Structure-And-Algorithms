#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node{
    int data;
    struct node *before;
    struct node *next;
}node;

void printLL(node *head){
    node *p = head;
    printf("\nThe Elements in the Linked List Are : \n");
    while(p->next!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("%d\n",p->data);
    // printf("\nThe Elements in the Linked List in Reverse Order Are : \n");
    // while(p->before!=NULL){
    //     printf("%d ",p->data);
    //     p = p->before;
    // }
    // printf("%d\n",p->data);
}

node *InsertAtBeg(node *head,int data){
    node *ptr = (node*)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = head;
    ptr->before = NULL;
    return ptr;
}

node *InsertAtEnd(node *head,int data){
    node *ptr = (node*)malloc(sizeof(node));
    node *p = head;
    ptr->data = data;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->before = p;
    ptr->next = NULL;
    return head;
}

node* deleteAtBeg(node *head){
    node *ptr = head;
    head = head->next;
    head->before = NULL;
    free(ptr);
    return head;
}

node* deleteAtEnd(node *head){
    node *p = head;
    while(p->next!=NULL){
        p = p->next;
    }
    p->before->next = NULL;
    free(p);
    return head;
}

int main(){
    node *first = (node*)malloc(sizeof(node));
    node *second = (node*)malloc(sizeof(node));
    node *third = (node*)malloc(sizeof(node));
    node *fourth = (node*)malloc(sizeof(node));

    first->data = 45;
    first->before = NULL;
    first->next = second;

    second->data = 48;
    second->before = first;
    second->next = third;

    third->data = 50;
    third->before = second;
    third->next = fourth;

    fourth->data = 52;
    fourth->before = third;
    fourth->next = NULL;

    printLL(first);
    first = deleteAtEnd(first);
    printf("After Deletion : ");
    printLL(first);
    getch();
    return 0;
}