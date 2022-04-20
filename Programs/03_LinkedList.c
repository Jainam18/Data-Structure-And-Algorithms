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

node * deleteFirst(node * head){
    node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

node* deleteAtPos(node* head,int index){
    node* ptr = head; 
    node* p;
    int i = 0;
    while(i!=index-1){
        ptr = ptr->next;
        i++;
    }
    p = ptr->next;
    ptr ->next = p->next;
    free(p);
    return head; 
}

node* deleteAfterNode(node* head,node* afterNode){
    node* p = head;
    node* q = head->next;
    while(q!=afterNode->next){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

node* deleteBeforeNode(node* head,node* beforeNode){
    node* p = head;
    node* q = head->next;
    while(q->next!=beforeNode){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

node* deleteAtEnd(node* head){
    node* p = head;
    node* q = head->next;
    while(q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

node* deleteAtValue(node* head,int value){
    node* p = head;
    node* q = head->next;
    while(q->data!=value && q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    if(q->data==value){
        p->next = q->next;
        free(q);
    }
    return head;
} 

int main(){
    node* first = (node*)malloc(sizeof(node));
    node* second = (node*)malloc(sizeof(node));
    node* third = (node*)malloc(sizeof(node));
    node* fourth = (node*)malloc(sizeof(node));
    node* fifth = (node*)malloc(sizeof(node));
    node* sixth = (node*)malloc(sizeof(node));

    first->data = 15;
    first->next = second;

    second->data = 23;
    second->next = third;

    third->data = 7;
    third->next = fourth;

    fourth->data = 45;
    fourth->next = fifth;

    fifth->data = 54;
    fifth->next == sixth;

    sixth->data = 76;
    sixth->next = NULL;

    LLT(first);
    first = deleteFirst(first);
    // first = deleteAtPos(first,2);
    // first = deleteAtEnd(first);
    // first = deleteAtValue(first,21);
    // first = deleteAfterNode(first,fourth);
    //first = deleteBeforeNode(first,fourth);
    
    getch();
    return 0;
}