#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

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

int isFull(struct stack *s){
    if(s->top==s->size-1){
        return 1;
    }
    return 0;
}

int topOfStack(struct stack *s){
    return s->exp[s->top];
}

void push(struct stack *s,char val){
    if(isFull(s)){
        printf("Stack Overflow\n");
    }
    else{
        s->top++;
        s->exp[s->top] = val;
    }
}

int pop(struct stack *s){
    char val;
    if(isEmpty(s)){
        printf("Stack Underflow\n");
    }
    val = s->exp[s->top];
    s->top--;
    return val;
}

int checkPrecedence(char ch){
    if(ch=='^'){
        return 4;
    }
    else if(ch=='*' || ch=='/'){
        return 3;
    }
    else if(ch=='+' || ch=='-'){
        return 2;
    }
    else{
        return 0;
    }
}

int isOperator(char ch){
    if(ch=='+' || ch=='/' || ch=='*' || ch=='^' || ch=='-'){
        return 1;
    }
    return 0;
}

char *infixToPrefix(char *exp){
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    int i,j,p=0;
    char ch,n,temp;
    s->size = 20;
    s->top = -1;
    s->exp = (char*)malloc(sizeof(char));
    char *prefix_exp = (char*)malloc((strlen(exp)+1)*sizeof(char));
    for(i=strlen(exp)-1;i>=0;i--){
        ch = exp[i];
        switch(ch){
            case ')':
                push(s,ch);
                break;
            case '(':
                if((n=pop(s))!=')')
                    prefix_exp[p++] = n;
                break;
            case '+':
                while(!isEmpty(s) && checkPrecedence(s->exp[s->top])> checkPrecedence(ch)){
                    prefix_exp[p++] = pop(s);
                }
                push(s,ch);
                break;
            case '-':
                while(!isEmpty(s) && checkPrecedence(s->exp[s->top])> checkPrecedence(ch)){
                    prefix_exp[p++] = pop(s);
                }
                push(s,ch);
                break;
            case '*':
                while(!isEmpty(s) && checkPrecedence(s->exp[s->top])> checkPrecedence(ch)){
                    prefix_exp[p++] = pop(s);
                }
                push(s,ch);
                break;
            case '/':
                while(!isEmpty(s) && checkPrecedence(s->exp[s->top])> checkPrecedence(ch)){
                    prefix_exp[p++] = pop(s);
                }
                push(s,ch);
                break;
            case '^':
                while(!isEmpty(s) && checkPrecedence(s->exp[s->top])> checkPrecedence(ch)){
                    prefix_exp[p++] = pop(s);
                }
                push(s,ch);
                break;
            default: 
                prefix_exp[p++] = ch;
                break;
        }
    }
    while(!isEmpty(s)){
        prefix_exp[p++] = pop(s); 
        prefix_exp[p] = '\0'; 
    }
    for(i=0,j=p-1;i<j;i++,j--){ 
        temp=prefix_exp[i]; 
        prefix_exp[i]=prefix_exp[j]; 
        prefix_exp[j]=temp; 
    } 
    prefix_exp[j]='\0';
    return prefix_exp;
}

int main(){
    char *exp = "7-(8*9)+3";
    printf("The Prefix expression of %s is %s\n",exp,infixToPrefix(exp));  
    return 0;
}