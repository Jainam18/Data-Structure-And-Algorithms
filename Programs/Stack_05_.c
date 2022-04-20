// MULTIPLE PARENTHESIS USING ARRAYS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct stack{
    int size;
    int top;
    char *arr;
}s;

int isEmpty(s *sp){
    if(sp->top==-1){
        return 1;
    }
    return 0;
}

int isFull(s *sp){
    if(sp->top==sp->size-1){
        return 1;
    }
    return 0;
}

void push(s *sp,char exp){
    if(isFull(sp)){
        printf("StackOverflow");
    }
    else{
        sp->top++;
        sp->arr[sp->top] = exp;
    }
}

int pop(s *sp){
    char val;
    if(isEmpty(sp)){
        printf("StackUnderflow");
    }
    else{
        val = (sp)->arr[(sp)->top];
        (sp)->top--;
        return val;
    } 
}

int match(char pop,char exp){
    if(pop=='(' && exp==')'){
        return 1;
    }
    else if(pop=='[' && exp==']'){
        return 1;
    }
    else if(pop=='{' && exp=='}'){
        return 1;
    }
    return 0;
}

int checkParenthesis(char *exp){
    int i;
    char popchar;
    s *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char*)malloc(sizeof(char));
    for(i=0;exp[i]!='\0';i++){
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{'){
            push(sp,exp[i]);
        }
        else if(exp[i]==')' || exp[i]==']' || exp[i]=='}'){
            if(isEmpty(sp)){
                return 0;
            }
            popchar = pop(sp);
            if(!match(popchar,exp[i])){
                return 0;
            }
        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    return 0;
}

int main(){
    char *exp = "[9+(2*5)+4{2/1]";
    if(checkParenthesis(exp)){
        printf("The Parenthesis is Balanced");
    }
    else{
        printf("The Parenthesis is Not Balanced");
    }
    getch();
    return 0;
}