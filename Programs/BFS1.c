#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct node {
    int data;
    struct node* link;
} node;

typedef struct Q {
    node *front;
    node *rear;
} Q;

void enqueue(Q *q,int value)
{
    node *ptr = (node*) malloc(sizeof(node));
    ptr -> data = value;
    ptr -> link = NULL;
    if(q -> rear == NULL){
        q -> front = q -> rear = ptr;
    }
    else{
        q -> rear -> link = ptr;
        q -> rear = ptr;
        ptr -> link = NULL;
    }
}

int dequeue(Q* q)
{
    node *ptr;
    int a = 0;
    if(q -> front ==NULL){
        printf("Underflow!");
        return -1;
    }
    ptr = q -> front;
    q -> front = q -> front -> link;
    if(q -> front == NULL)
        q -> rear = NULL;
    a = ptr -> data;
    free(ptr);
    return a;
}

void readGraph(node *graph[],int numberOfNodes){
    int i, j, edges;
    int edge1, edge2; 
    for(i = 0; i < numberOfNodes; i++){
        graph[i] = (node*) malloc(sizeof(node));
        node *temp = (node*) malloc(sizeof(node));
        node *ptr;
        graph[i] -> link = NULL;
        graph[i] -> data = i;
        printf("For Vertex %d:\n", i);
        printf("Enter Number Of Edges: ");
        scanf("%d", &edges); 
        for(j = 0; j < edges; j++){
            printf("Enter edge in this format: 0 1: ");
            scanf("%d %d", &edge1, &edge2);
            temp -> data = edge2;
            temp -> link = NULL;
            ptr = graph[i];
            while(ptr -> link != NULL)
                ptr = ptr -> link;
            ptr -> link = temp;
        }
    }
}

void printAdjacencyList(node *graph[],int numberOfNodes){
    int i;
    printf("Adjacency List:\n");
    for(i = 0; i < numberOfNodes; i++){
        node *p = graph[i];
        for(p = graph[i]; p -> link != NULL; p = p -> link)
        {
            printf("%d --> ", p -> data);
        }
        printf("%d --> NULL", p -> data);
        printf("\n");
    }
}

void printAdjacencyMatrix(node *graph[],int numberOfNodes){
    int adjacencyMatrix[numberOfNodes][numberOfNodes],i,j;
    printf("Adjacency List:\n");
    for(i = 0; i < numberOfNodes; i++){
        for(int j = 0; j < numberOfNodes; j++){
            adjacencyMatrix[i][j] = 0;
        }
    }
    for(i = 0; i < numberOfNodes; i++){
        node *p = graph[i];
        if(graph[i] -> link != NULL){
            for(p = graph[i] -> link; p != NULL; p = p -> link){
                adjacencyMatrix[i][p -> data] = 1;
                adjacencyMatrix[p -> data][i] = 1;
            }
        }
    }  
    for(i = 0; i < numberOfNodes; i++){
        for(j = 0; j < numberOfNodes; j++){
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

void bfs(Q *q,node *graph[],int numberOfNodes,int i)
{
    printf("Breadth First Search:\n");
    int visited[numberOfNodes];
    int x, a, j; 
    for(j = 0; j < numberOfNodes; i++)
        visited[j] = 0;
    node *p;
    enqueue(q,i);
    printf("%d ", i);
    visited[i] = 1;

    while(q -> front != NULL)
    {
        i = dequeue(q);
        for(p = graph[i]; p != NULL; p = p -> link)
        {
            x = p -> data;
            if(visited[x] == 0)
            {
                enqueue(q,x);
                visited[x] = 1;
                printf("%d ", x);
            }
        }
    }
    printf("\n");
}

int main(){
    int numberOfNodes, choice;
    node *graph[MAX];
    Q* q;
    q = (Q*) malloc(sizeof(Q));
    q -> front = q -> rear = NULL;
    printf("Enter Number Of vertex For Graph: ");
    scanf("%d", &numberOfNodes);
    readGraph(graph,numberOfNodes);
    printf("\n\n");
    printAdjacencyList(graph,numberOfNodes);
    printf("\n\n");
    printAdjacencyMatrix(graph,numberOfNodes);
    printf("\n\nEnter the vertex for BFS:\n");
    scanf("%d", &choice);
    if(choice < 0 || choice >= numberOfNodes)
        printf("Invalid Choice!");
    else{
        bfs(q,graph,numberOfNodes,choice);
        printf("\nThank You!");
    } 
    return 0;
}
