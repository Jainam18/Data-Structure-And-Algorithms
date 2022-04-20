#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node{
    int data;
    struct node *next;
}node;

void LLT(node *ptr){
    while(ptr!= NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}
int main(){
    // allocate memory for the the node in the link list in the heap
    node * head = (node *)malloc(sizeof(node));
    node * second = (node *)malloc(sizeof(node));
    node * third = (node *)malloc(sizeof(node));
    node * fourth = (node *)malloc(sizeof(node));

    //Link the 1st and 2nd Nodes
    printf("Enter the value of 1st Element : ");
    scanf("%d",&(head->data));
    head->next = second;

    //Link the 2nd and 3rd Nodes
    printf("Enter the value of 2nd Element : ");
    scanf("%d",&(second->data));
    second->next = third;

    //Link the 3rd and 4th Nodes
    printf("Enter the value of 3rd Element : ");
    scanf("%d",&(third->data));
    third->next = fourth;

    //Link the 4th npode to Null
    printf("Enter the value of 4th Element : ");
    scanf("%d",&(fourth->data));
    fourth->next = NULL;

    LLT(head);
    getch();
    return 0;
}