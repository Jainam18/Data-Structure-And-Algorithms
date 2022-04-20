#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node{
    int data;
    struct node* next;
}node;


void LLT(node* head){
    while(head!=NULL){
        printf("%d ",head->data);
        head = head->next;
    }
}

node* InsertAtBeg(node* head,int data){
    node* ptr = (node*)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

node* InsertAtIndex(node* head,int data,int index){
    node* ptr = (node*)malloc(sizeof(node));
    node* p = head;
    int i=0;
    ptr->data = data;
    while(i!=index-1){
        p = p->next;
        i++; 
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;  
}

node* InsertAtEnd(node*head,int data){
    node* ptr = (node*)malloc(sizeof(node));
    node* q = head;
    ptr->data = data;
    while(q->next!=NULL){
        q = q->next; 
    }
    q->next = ptr;
    ptr->next = NULL;
    return head;
}

void SortList(node* head){
    node* ptr = head;
    node* p = NULL;
    int temp;
    while(ptr!=NULL){
        p = ptr->next;
        while(p!=NULL){
            if(ptr->data>p->data){
                temp = ptr->data;
                ptr->data = p->data;
                p->data = temp;
                }
            p = p->next;
        }
        ptr = ptr->next;
    }
}

node* deleteAtBeg(node* head){
        node* ptr = head;
        head = head->next;
        free(ptr);
        return head; 
} 

node* deleteAtPos(node* head,int index){
        node* ptr = head; 
        node* p;
        int i = 0;
        while(i!=index-1){
            ptr = ptr->next;
            i++;
        }
        p = ptr->next;
        ptr ->next = p->next;
        free(p);
        return head; 
    
}

node* deleteAtEnd(node* head){
        node* p = head;
        node* q = head->next;
        while(q->next!=NULL){
            p = p->next;
            q = q->next;
        }
        p->next = NULL;
        free(q);
        return head;
}

node* deleteAtValue(node* head,int value){
        node* p = head;
        node* q = head->next;
        while(q->data!=value && q->next!=NULL){
            p = p->next;
            q = q->next;
        }
        if(q->data==value){
            p->next = q->next;
            free(q);
        }
        return head;
}

void maxNum(node* head){
    struct node *p = head;  
    int max;  
    max = head->data;  
          
    while(p!= NULL){    
        if(max<p->data) {  
            max = p->data;  
        }  
        p = p->next;  
    }               
    printf("Maximum value node in the list: %d\n", max);  
}

int count(node* head){
    int i=0;
    node* ptr = head;
    while(ptr!=NULL){
        ptr = ptr->next;
        i++;
    }
    return i;
}

int main(){
    node * start,*p;
    int  i,n,value,choice,pos,maxN,j;
    p = start =  (node*)malloc(sizeof(node));
    printf("Enter the number of Nodes : ");
    scanf("%d",&n);
    printf("Enter the value of node 1 : ");
    scanf("%d",&start->data);
    start->next = NULL;
    for(i=1;i<n;i++){
        p->next = (node*)malloc(sizeof(node*));
        p = p->next;
        printf("Enter the value of node %d : ",i+1);
        scanf("%d",&p->data);
        p->next = NULL;
    }
    do{
        printf("\nOPERATIONS : \n1)DISPLAY LIST\n2)INSERT AT BEGINNING \n3)INSERT AT THE END\n4)INSERT AT POSITION\n5)DELETE AT BEGINNING\n6)DELETE AT END\n7)DELETE A VALUE\n8)DELETE AT POSITION\n9)SORT THE LIST\n10)COUNT NUMBER OF NODES IN THE LIST\n11)MAXIMUM ELEMENT IN THE LIST\n12)Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                LLT(start);
                break;
            case 2:
                printf("Enter the Value to be Entered Into the List :\n");
                scanf("%d",&value);
                start = InsertAtBeg(start,value);
                printf("The Linked List After Insertion is : \n");
                LLT(start);
                break;
            case 3:
                printf("Enter the Value to be Entered Into the List :\n");
                scanf("%d",&value);
                start = InsertAtEnd(start,value);
                printf("The Linked List After Insertion is : \n");
                LLT(start);
                break;
            case 4:
                printf("Enter the Value to be Entered Into the List :\n");
                scanf("%d",&value);
                printf("Enter the Position to Insert the value : ");
                scanf("%d",&pos);
                start = InsertAtIndex(start,value,pos);
                printf("The Linked List After Insertion is : \n");
                LLT(start);
                break;  
            case 5:
                deleteAtBeg(start);
                printf("The Linked List After Deletion is : \n");
                LLT(start);
                break;
            case 6:
                deleteAtEnd(start);
                printf("The Linked List After Deletion is : \n");
                LLT(start);
                break;
            case 7:
                printf("Enter the value to be Deleted: \n");
                scanf("%d",&value);
                deleteAtValue(start,value);
                printf("The Linked List After Deletion is : \n");
                LLT(start);
                break;
            case 8:
                printf("Enter the Position from which the value is to be deleted  : \n");
                scanf("%d",&pos);
                deleteAtPos(start,pos);
                printf("The Linked List After Deletion is : \n");
                LLT(start);
                break;
            case 9:
                SortList(start);
                printf("The Linked List After Sorting is : \n");
                LLT(start); 
                break;
            case 10:
                j = count(start);
                printf("The Number of Nodes in the list are : %d\n",j);
                break;
            case 11:
                maxNum(start);
                break;
            case 12:
                break;     
            default:
                printf("Invalid Choice\n");                                
        }
    }while(choice!=12);
    getch();
    return 0;
}