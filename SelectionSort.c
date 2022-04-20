#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void getElement(int* ptr,int n){
    int i;
    for(i=0;i<n;i++){
        printf("Enter Element %d :",i+1);
        scanf("%d",&ptr[i]);
    }
}

void display(int *ptr,int n){
    int i;
    printf("The Array is :");
    for(i=0;i<n;i++){
        printf("%d ",ptr[i]);
    }
    printf("\n");
}

void selectionSort(int *p,int n){
    int i,j,temp,min;
    for ( i = 0; i < n-1; i++)
    {   min = i; 
        for(j=i+1;j<n;j++){
            if(p[j]<p[min]){
                min = j;
            }
        }
        temp = p[i];
        p[i] = p[min];
        p[min] = temp;
    }
    
}

void insertSort(int *ptr,int n){
    int i, j, key;
    for(i = 1;i < n;i++){
        key = ptr[i];
        j = i-1;
        while (j >= 0 && ptr[j]<key);
        {
            ptr[j+1] = ptr[j];
            j = j-1;
        }
        ptr[j+1]=key;
    }
}

int main(){
    int *p,max,n,i,j,choice;
    printf("Enter the size of array : ");
    scanf("%d",&max);
    p = (int *)malloc(max*sizeof(int));
    printf("Enter the number of elements required : ");
    scanf("%d",&n);
    getElement(p,n);
    printf("Enter\n1:To Implement Selection Sort\n2:To Implement Insertion Sort\n");
    scanf("%d",&choice);
    if(choice==1){
        printf("Before Sorting : ");
        display(p,n);
        printf("After Sorting : ");
        selectionSort(p,n);
        display(p,n);
    }
    else if(choice==2){
        printf("Before Sorting : ");
        display(p,n);
        printf("After Sorting : ");
        insertSort(p,n);
        display(p,n);
    }
    else{
        printf("Invalid Command\n");
    }
    getch();
    return 0;
}