#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct Queue{
    int size;
    int front;
    int rear;
    int *arr;
}que;

int isEmpty(que *q){
    if(q->front==q->rear){
        return 1;
    }
    return 0;
}

int isFull(que *q){
    if(q->rear==(q->size)-1){
        return 1;
    }
    return 0;
}

void enqueue(que *q,int data){
    if(isFull(q)){
        printf("Queue Overflow");
    }
    else{
        q->rear++;
        q->arr[q->rear] = data;
    }
}

int dequeue(que *q){
    int a = -1;
    if(isEmpty(q)){
        printf("QueueUnderflow");
    }
    else{
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}

void print(que *q){
    int temp = q->front;
    if(isEmpty(q)){
        printf("There are no elements in the Queue");
    }
    else{
        printf("The Elements in the Queue are  : ");
        while(temp!=q->rear){
            temp++;
            printf("%d ",q->arr[temp]);
        }
        printf("\n");
    }
}

int main(){ 
    que *q;
    int value;
    q->size = 10;
    q->front = 0;
    q->rear = 0;
    q->arr = (int*)malloc((q->size)*sizeof(int));
    enqueue(q,42);
    enqueue(q,22);
    enqueue(q,12);
    enqueue(q,15);
    enqueue(q,19);
    print(q);
    printf("The deleted element is %d\n",dequeue(q));
    printf("The deleted element is %d\n",dequeue(q));
    print(q);
    getch();
    return 0;
}