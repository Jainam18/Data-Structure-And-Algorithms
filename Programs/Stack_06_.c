#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int size;
    int top;
    char *exp;
};

int isEmpty(struct stack *s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr){
  if(ptr->top==ptr->size-1){
      return 1;
  }
  return 0;
}

int topOfStack(struct stack *s){
    return s->exp[s->top];
}

void push(struct stack *s,char exp){
    if(isFull(s)){
        printf("StackOverflow");
    }
    else{
        s->top++;
        s->exp[s->top] = exp;
    }
}

int pop(struct stack *s){
    char val;
    if(isEmpty(s)){
        printf("StackUnderflow");
        return -1;
    }
    else{
        val = s->exp[s->top];
        s->top--;
        return val;
    }
}

int CheckPrecedence(char exp){
    if(exp=='^'){
        return 4; 
    }
    else if(exp=='/' || exp=='*'){
        return 3;
    }
    else if(exp=='+' || exp=='-'){
        return 2;
    }
    else
        return 0;
}

int isOperator(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
        return 1;
    }
    else
        return 0;
}

char *infixToPostfix(char *exp){
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    int i=0,j=0;
    s->size = 10;
    s->top = -1;
    s->exp = (char*)malloc(sizeof(char));
    char *postfix = (char *)malloc((strlen(exp)+1)*sizeof(char));;
    while(exp[i]!='\0'){
        if(!isOperator(exp[i])){
            postfix[j] = exp[i];
            i++,j++;
        }
        else{
            if(CheckPrecedence(exp[i])>CheckPrecedence(topOfStack(s))){
                push(s,exp[i]);
                i++;
            }
            else{
                postfix[j] = pop(s);
                j++;
            }
        }
    }
    while(!isEmpty(s)){
        postfix[j] = pop(s);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}

int main(){
    char *exp = "7-8*9+3";
    printf("The Postfix expression of %s is %s\n",exp,infixToPostfix(exp));
    return 0;
}