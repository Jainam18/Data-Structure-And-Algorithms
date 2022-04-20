#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct queue{
    int size;
    int front,rear;
    int *arr;
}que;

int isEmpty(que *q){
    if(q->front==q->rear){
        return 1;
    }
    return 0;
}

int isFull(que *q){
    if((q->rear+1)%q->size==q->front){
        return 1;
    }
    return 0;
}

void enqueue(que *q,int val){
    if(isFull(q)){
        printf("Queue Overflow\n");
    }
    else{
        q->rear = (q->rear+1)%q->size;
        q->arr[q->rear] = val;
    }
}

int dequeue(que *q){
    int val = -1;
    if(isEmpty(q)){
        printf("Queue Underflow");
    }
    else{
        q->front = (q->front+1)%q->size;
        val = q->arr[q->front];
    }
    return val;
}

void print(que *q){
    int temp = q->front;
    if(isEmpty(q)){
        printf("The Circular Queue is Empty\n");
    }
    else{
        printf("The Elements in Circular Queue are  : ");
        while(temp!=q->rear){
            printf("%d ",q->arr[temp]);
        }
        printf("\n");
    }
}

int main(){
    que *q;
    q->size = 5;
    q->front = q->rear = 0;
    q->arr = (int*)malloc((q->size)*sizeof(int));
    enqueue(q,45);
    enqueue(q,58);
    enqueue(q,22);
    enqueue(q,37);
    enqueue(q,32);
    printf("The Deleted Element in Circular queue is %d\n",dequeue(q));
    printf("The Deleted Element in Circular queue is %d\n",dequeue(q));
    enqueue(q,58);
    enqueue(q,45);
    getch();
    return 0;
}