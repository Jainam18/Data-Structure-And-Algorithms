#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node{
    int coefficient;
    int power;
    struct node* next;
}node;

node *InsertTerm(node *poly,int coeff,int pow){
    node *ptr = (node*)malloc(sizeof(node));
    node *p = poly; 
    ptr->power = pow;
    ptr->coefficient = coeff;
    if(poly == NULL){
        poly = ptr;
        poly->next = NULL;
    }
    else if(pow > poly->power){
        ptr->next = poly;
        poly = ptr;
    }
    else{
		while (p->next != NULL && p->next->power >= pow){
			p = p->next;
		}
		if (p->power == pow){
			p->coefficient += ptr->coefficient;
            }
		else{
			ptr->next = p->next;
			p->next = ptr;
		}
    }
    return poly;
}

node *CreatePoly(node *poly){
    int i,n,coeff,pow;
    printf("Enter the Number of Terms in the Polynomial : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the Coefficient of %d term : ",i+1);
        scanf("%d",&coeff);
        printf("Enter the Power of %d term : ",i+1);
        scanf("%d",&pow);
        poly = InsertTerm(poly,coeff,pow);
    }
    return poly;
}


void PrintPoly(node *poly){
    node *ptr = poly;
    while(ptr!=NULL){
        printf("(%dx^%d)",ptr->coefficient,ptr->power);
        ptr = ptr->next;
        if(ptr!=NULL){
            printf(" + ");
        }
    }
    printf("\n");
}

void AddPoly(node *poly1,node *poly2){
    node *ptr1 = poly1;
    node *ptr2 = poly2;
    node *result = NULL;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->power == ptr2->power){
            result = InsertTerm(result,(ptr1->coefficient+ptr2->coefficient),ptr1->power);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->power>ptr2->power){
            result = InsertTerm(result,ptr1->coefficient,ptr1->power);
            ptr1 = ptr1->next;
        }
        else if(ptr1->power<ptr2->power){
            result = InsertTerm(result,ptr2->coefficient,ptr2->power);
            ptr2 = ptr2->next;
        }
    }
    while(ptr1!=NULL){
        result = InsertTerm(result,ptr1->coefficient,ptr1->power);
        ptr1 = ptr1->next;
    }
    while(ptr2!=NULL){
        result = InsertTerm(result,ptr2->coefficient,ptr2->power);
        ptr2 = ptr2->next;
    }
    printf("The Addition of Polynomial 1 and 2 is : \n");
    PrintPoly(result);
}

void SubractPoly(node *poly1,node *poly2){
    node *result = NULL;
    node *ptr1 = poly1;
    node *ptr2 = poly2;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->power==ptr2->power){
            result = InsertTerm(result,((ptr1->coefficient)-(ptr2->coefficient)),ptr1->power);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->power>ptr2->power){
            result = InsertTerm(result,ptr1->coefficient,ptr1->power);
            ptr1 = ptr1->next;
        }
        else if(ptr1->power<ptr2->power){
            result = InsertTerm(result,ptr2->coefficient,ptr2->power);
            ptr2 = ptr2->next;
        }
    }
    while(ptr1!=NULL){
        result = InsertTerm(result,ptr1->coefficient,ptr1->power);
        ptr1 = ptr1->next;
    }
    while(ptr2!=NULL){
        result = InsertTerm(result,ptr2->coefficient,ptr2->power);
        ptr2 = ptr2->next;
    }
    printf("THE Subraction of Polynomial 1 and 2 is  : \n");
    PrintPoly(result);
}

int main(){
    node *poly1,*poly2;
    poly1 = NULL;
    poly2 = NULL;
    int ch;
    printf("First Polynomial : \n");
    poly1 = CreatePoly(poly1);
    printf("The Entered First Polynomial is :  \n");
    PrintPoly(poly1);
    printf("Second Polynomial : ");
    poly2 = CreatePoly(poly2);
    printf("The Entered Second Polynomial is :  \n");
    PrintPoly(poly2);
    do{
        printf("Enter:\n1)Addition Of Polynomials\n2)Substraction Of Polynomials\n3)Exit\n");
        scanf("%d",&ch);
        switch(ch){ 
            case 1: 
                AddPoly(poly1,poly2);
                break;
            case 2:
                SubractPoly(poly1,poly2);
                break;
            case 3:break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    }while(ch!=3);
    getch();
    return 0;
}