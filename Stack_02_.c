// USING LINKED LIST
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node{
    int data;
    struct node *next;
}node;

int isEmpty(node *ptr){
    if(ptr==NULL){
        return 1;
    }
    return 0;
}

int isFull(node *ptr){
    node *p = (node*)malloc(sizeof(node));
    if(p==NULL){
        return 1;
    }
    return 0;
}

node *push(node *top,int data){
    node *ptr = (node*)malloc(sizeof(node));
    if(isFull(top)){
        printf("Stack Overflow\n");
    }
    else{
        ptr->data = data;
        ptr->next = top;
        top = ptr;
        return top;
    }
}

node *pop(node *top){
    node *p = top;
    if(isEmpty(top)){
        printf("Stack Underflow");
    }
    else{
        top = top->next;
        free(p);
        return top;
    }
}

void StackTraversal(node *top){
    printf("The Elements of The Stack are : ");
    while(top!=NULL){
        printf("%d ",top->data);
        top = top->next;
    }
    printf("\n");
}

int TopOfStack(node *ptr){
    return ptr->data;
}

int StackBottom(node *top){
    while(top->next!=NULL){
        top = top->next; 
    }
    return top->data;
}

void peek(node *top,int index){
    int i = 0;
    node *ptr = top;
    while(i<index-1 && ptr!=NULL){
        ptr = ptr->next;
        i++;
    }
    if(ptr!=NULL){
        printf("The Element at index %d is %d\n",index,ptr->data);
    }
    else{
        printf("The Index Given Is Invalid\n");
    }
}

int main(){
    node *top = NULL;
    top = push(top,45);
    top = push(top,48);
    top = push(top,50);
    top = push(top,53);
    top = push(top,55);
    StackTraversal(top);
    top = pop(top);
    top = pop(top);
    top = pop(top);
    StackTraversal(top);
    peek(top,2);
    printf("The First Element of stack is %d and Last Element of stack is %d\n",TopOfStack(top),StackBottom(top));
    getch();
    return 0;
}