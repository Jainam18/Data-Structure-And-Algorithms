#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node{
    int data; 
    struct node* next;
}node;

void LLT(node* ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

node* InsertAtBeg(node* head,int data){
    node *ptr = (node*)malloc(sizeof(node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

node* InsertatPos(node* head,int data,int pos){
    node *ptr = (node*)malloc(sizeof(node));
    node *p = head;
    ptr->data = data;
    int i=0;
    while(i!=(pos-1)){
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

node* InsertAfterNode(node* head,int data,node* prevNode){
    node* ptr = (node*)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

node* InsertBeforeNode(node* head,int data,node* afterNode){
    node* ptr = (node*)malloc(sizeof(node));
    ptr->data = data;
    node *r = head;
    while(r->next!=afterNode){
         r = r->next;
    }
    ptr->next = r->next;
    r->next = ptr;
    return head;
 }

node* InsertAtEnd(node *head,int data){
    node *ptr = (node*)malloc(sizeof(node));
    ptr->data = data;
    node *q = head;
    while(q->next!=NULL){
        q = q->next;
    }
    q->next = ptr;
    ptr->next = NULL;   
    return head;
}

int main(){
    node* first = (node *)malloc(sizeof(node));
    node* second = (node *)malloc(sizeof(node));
    node* third = (node *)malloc(sizeof(node));
    node* fourth = (node *)malloc(sizeof(node));

    first->data = 7;
    first->next = second;

    second->data = 9;
    second->next = third;

    third->data = 21;
    third->next = fourth;

    fourth->data = 2;
    fourth->next = NULL;

    LLT(first);
    first = InsertBeforeNode(first,34,second);
    LLT(first);
    getch();
    return 0;
}