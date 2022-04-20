//USINGARRAY
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct stack{
    int size;
    int top;
    int* arr;
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

int TopOfStack(struct stack *ptr){
    return ptr->arr[ptr->top];
}

int StackBottom(struct stack *ptr){
    return ptr->arr[0];
}

void push(struct stack *s,int value){
    if(isFull(s)){
        printf("Stack Overflow");
    }
    else{
        s->top++;
        s->arr[s->top] = value;
    }
}

int pop(struct stack *s){
    int value;
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

void print(struct stack *ptr){
    int max = ptr->top;
    printf("The Elements is the stack are : ");
    while(max!=-1){
        printf("%d ",ptr->arr[max]);
        max--;
    }
    printf("\n");
}

int peek(struct stack *ptr,int index){
    int stackInd = ptr->top-index+1;
    if(stackInd<0){
        printf("Not a Valid Position for the Stack\n");
        return -1;
    }
    else{
        return ptr->arr[stackInd];
    }
}

int main(){
    int val;
    struct stack *s;
    s->size = 100;
    s->top = -1;
    s->arr = (int *)malloc(s->size*sizeof(int));
    push(s,45);
    push(s,48);
    push(s,58);
    push(s,53);
    val = pop(s);
    print(s);
    printf("The Element deleted is %d\n",val);
    val = pop(s);
    printf("The Element deleted is %d\n",val);
    print(s);
    printf("The Element at the second index is %d",peek(s,2));
    getch();
    return 0;
}