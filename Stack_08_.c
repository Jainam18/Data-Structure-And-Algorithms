// MULTIPLE PARENTHESIS USING LINKEDLIST
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node{
    char exp;
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

node *push(node *ptr,char exp){
    node *p = (node*)malloc(sizeof(node));
    if(isFull(ptr)){
        printf("Stack Overflow");
    }
    else{
        p->exp = exp;
        p->next = ptr;
        ptr = p;
        return ptr; 
    }
}

char pop(node **ptr){
    node *p = *ptr;
    char popped;
    if(isEmpty(*ptr)){
        printf("Stack Overflow");
        return 0;
    }
    else{
        popped = p->exp;
        *ptr = p->next;
        free(p);
        return popped;
    }
}

int match(char pop,char exp){
    if(pop=='(' && exp==')'){
        return 1;
    }
    if(pop=='[' && exp==']'){
        return 1;
    }
    if(pop=='{' && exp=='}'){
        return 1;
    }
    return 0;
}

int CheckParenthesis(char *exp){
    node *ptr=NULL;
    int i;
    char popped;
    for(i=0;exp[i]!='\0';i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(ptr,exp[i]);
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(isEmpty(ptr)){
                return 0;
            }
            popped = pop(&ptr);
            if(!match(popped,exp[i])){
                return 0;
            }
        }
    }
    if(isEmpty(ptr)){
        return 1;
    }
    return 0;
}
int main(){
    char *exp = "{9+(5*2)-[4-3]}";
    if(CheckParenthesis(exp)){
        printf("The Parenthesis of this Expression is Balanced");
    }
    else{
        printf("It is not Balanced");
    }   
    getch();
    return 0;
}