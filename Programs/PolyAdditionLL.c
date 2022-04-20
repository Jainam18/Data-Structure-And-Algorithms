#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct node{
	int coef;
	int power;
	struct node *next;
} node;

node *insertPoly(node *poly, int coef, int power){
	node *newnode = (node *)malloc(sizeof(node));
	node *p;
	newnode->coef = coef;
	newnode->power = power;
	if(poly == NULL){
		poly = newnode;
		poly->next = NULL;
	}
	else if(power > poly->power){
		newnode->next = poly;
		poly = newnode;
	}
	else{
		p = poly;
		while (p->next != NULL && p->next->power >= power){
			p = p->next;
		}
		if (p->power == power){
			p->coef += newnode->coef;
		}
		else{
			newnode->next = p->next;
			p->next = newnode;
		}
	}
	return poly;
}

// Creating a polynomial
node *createPoly(node *poly){
	int i, n, coef, power;
	printf("Enter the number of terms: ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		printf("Enter the coefficient of term %d: ", i);
		scanf("%d", &coef);
		printf("Enter power of term %d: ", i);
		scanf("%d", &power);
		poly = insertPoly(poly, coef, power);
	}
	return poly;
}

void printPoly(node *poly){
	node *p = poly;
	while (p != NULL){
		printf("(%dx^%d)", p->coef, p->power);
		p = p->next;
		if (p != NULL)
			printf(" + ");
	}
	printf("\n");
}

// Addition of polynomial
void addition(node *poly1, node *poly2){
	node *ptr1 = poly1;
	node *ptr2 = poly2;
	node *poly3 = NULL;
	while (ptr1 != NULL && ptr2 != NULL){
		if (ptr1->power == ptr2->power){
			poly3 = insertPoly(poly3, ptr1->coef + ptr2->coef, ptr1->power);
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		else if (ptr1->power > ptr2->power){
			poly3 = insertPoly(poly3, ptr1->coef, ptr1->power);
			ptr1 = ptr1->next;
		}
		else if (ptr1->power < ptr2->power){
			poly3 = insertPoly(poly3, ptr2->coef, ptr2->power);
			ptr2 = ptr2->next;
		}
	}
	while (ptr1 != NULL){
		poly3 = insertPoly(poly3, ptr1->coef, ptr1->power);
		ptr1 = ptr1->next;
	}
	while (ptr2 != NULL){
		poly3 = insertPoly(poly3, ptr2->coef, ptr2->power);
		ptr2 = ptr2->next;
	}
	printf("Addition of the polynomials is: ");
	printPoly(poly3);
}

void subtraction(node *poly1, node *poly2){
	node *ptr1 = poly1;
	node *ptr2 = poly2;
	node *poly3 = NULL;
	while (ptr1 != NULL && ptr2 != NULL){
		if (ptr1->power == ptr2->power){
			poly3 = insertPoly(poly3, ptr1->coef - ptr2->coef, ptr1->power);
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		else if (ptr1->power > ptr2->power){
			poly3 = insertPoly(poly3, ptr1->coef, ptr1->power);
			ptr1 = ptr1->next;
		}
		else if (ptr1->power < ptr2->power){
			ptr2->coef = -(ptr2->coef);
			poly3 = insertPoly(poly3, ptr2->coef, ptr2->power);
			ptr2 = ptr2->next;
		}
	}
	while (ptr1 != NULL){
		poly3 = insertPoly(poly3, ptr1->coef, ptr1->power);
		ptr1 = ptr1->next;
	}
	while (ptr2 != NULL){
		ptr2->coef = -(ptr2->coef);
		poly3 = insertPoly(poly3, ptr2->coef, ptr2->power);
		ptr2 = ptr2->next;
	}
	printf("Subtraction of the polynomials is: ");
	printPoly(poly3);
}

int main(){
	node *poly1 = NULL;
	node *poly2 = NULL;
	node *poly3 = NULL;
	printf("For First Polynomial:\n");
	poly1 = createPoly(poly1);
	printf("The polynomial entered is: ");
	printPoly(poly1);
	printf("For Second Polynomial:");
	poly2 = createPoly(poly2);
	printf("The polynomial entered is: ");
	printPoly(poly2);
	int ch;
	do{
		printf("**MENU**\n");
		printf("1.Addition\n2.Subtraction\n3.Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch (ch){
			case 1:addition(poly1, poly2); break;
			case 2:subtraction(poly1, poly2); break;
			case 3:break;
			default: break;
		};
	}while(ch!=3);	
	return 0;
}
