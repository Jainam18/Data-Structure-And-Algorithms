// PARENTHESIS MATCHING USING LINKEDLIST
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node{
    char expression;
    struct node *next;
}node;

int isEmpty(node *top){
    if(top==NULL){
        return 1;
    }
    return 0;
}

int isFull(node *top){
    node *ptr = (node*)malloc(sizeof(node));
    if(ptr == NULL){
        return 1;
    }
    return 0;
}

node *push(node *top,char exp){
    node *p = (node*)malloc(sizeof(node));
    if(isFull(top)){
      printf("Stack Overflow");
    }
    else{
        p->expression = exp;
        p->next = top;
        top = p;
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

int CheckParenthesis(char *exp){
    node *top = NULL;
    int i;
    for(i=0;exp[i]!='\0';i++){
        if(exp[i]=='('){
            push(top,exp[i]);
        }
        else if(exp[i]==')'){
            if(isEmpty(top)){
                return 0;
            }
            pop(top);
        }
    }
    if(isEmpty(top)){
        return 1;
    }
    return 0;
}

int main(){
    // char *exp = (char*)malloc(sizeof(char));
    // printf("Enter the Expression : \n");
    // scanf("%s",exp);
    char *exp="(3*9)-8";
    if(CheckParenthesis(exp)){
        printf("The Parenthesis of this expression is Balanced");
    }
    else{
        printf("The Parenthesis of this expression is not Balanced");
    }
    getch();
    return 0;
}