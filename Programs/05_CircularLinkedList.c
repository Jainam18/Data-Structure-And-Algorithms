#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void printList(node* head){
    node* ptr = head;
    while(ptr->next!=head){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    } 
    printf("%d\n",ptr->data);
}

node *InsertAtBeginning(node *head,int data){
    node *ptr = (node*)malloc(sizeof(node));
    node *p = head;
    ptr->data = data;
    while(p->next!=head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;;
    return ptr;
} 

// node* InsertAtEnd(node *head,int data){
//     node *ptr = (node*)malloc(sizeof(node));
//     node *p = head;
//     ptr->data = data;
//     while(p->next!=head){
//         p = p->next;
//     }
//     p->next = ptr;
//     ptr->next = head;
//     return ptr;
// }

node *InsertAtIndex(node *head,int pos,int data){
    node *ptr = (node*)malloc(sizeof(node));
    ptr->data = data;
    node *p = head;
    int i;
    for(i=1;i<pos;i++){
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
} 

node* DeleteAtBeg(node *head){
    node* ptr = head;
    node *p = head;
    while(p->next!=head){
        p = p->next;
    }
    head = head->next;
    p->next = head;  
    free(ptr);
    return head;
}

node *DeleteAtEnd(node *head){
    node *ptr = head;
    node *p =head->next;
    while(p->next!=head){
        p = p->next;
        ptr = ptr->next;
    }
    ptr->next = head;
    free(p);
    return head; 
}

node *DeleteAtIndex(node* head,int pos){
    node* ptr = head; 
    node* p;
    int i = 0;
    while(i!=pos-1){
        ptr = ptr->next;
        i++;
    }
    p = ptr->next;
    ptr ->next = p->next;
    free(p);
    return head;
}

void count(node *head){
    int count;
    count = 0;
    node *p = head;
    while(p->next!=head){
        p = p->next;
        count++;
    }
    printf("The Number of Nodes in the Circular Linked List is %d",count);
}

int main(){
    node* first = (node*)malloc(sizeof(node));    
    node* second = (node*)malloc(sizeof(node));    
    node* third = (node*)malloc(sizeof(node));    
    node* fourth = (node*)malloc(sizeof(node));    
    
    first->data = 54;
    first->next = second;

    second->data = 56;
    second->next = third;

    third->data = 58;
    third->next = fourth;

    fourth->data = 60;
    fourth->next = first;

    printList(first);
    // first = InsertAtBeginning(first,52);
    // printList(first);
    first = DeleteAtEnd(first);
    printList(first);
    getch();
    return 0;
}