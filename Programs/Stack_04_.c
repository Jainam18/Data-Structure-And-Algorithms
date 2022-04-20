// PARENTHESIS MATCHING USING ARRAYS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct stack{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    return 0;
}

void push(struct stack *s,char val){
    if(isFull(s)){
        printf("Stack Overflow");
    }
    else{
        s->top++;
        s->arr[s->top] = val;
    }
}

char pop(struct stack *s){
    char value;
    if(isEmpty(s)){
        printf("Stack Underflow");
        return -1;
    }
    else{
        value = s->arr[s->top];
        s->top--;
        return value; 
    }
}

int checkParenthesis(char *exp){
    int i;
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size*sizeof(char));
    for(i=0;exp[i]!='\0';i++){
        if(exp[i]=='('){
            push(sp,exp[i]);
        }
        else if(exp[i]==')'){
            if(isEmpty(sp)){
                return 0;
            }
            pop(sp);
        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){ 
    char *exp = "7-(8(3*9)+11+12))-8";
    if(checkParenthesis(exp)){
        printf("The Parenthesis of this expression is Balanced");
    }
    else{
        printf("The Parenthesis of this expression is not Balanced");
    }
    getch();
    return 0;
}