#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
  
void display(int *ptr,int n){
    int i;
    printf("THE Elements are : \n");
    for(i=0;i<n;i++){
        printf("%d ",ptr[i]);
    }
    printf("\n");
}

void insertSort(int *ptr,int n){
    int i,j,key;
    for(i=1;i<=n-1;i++){
        key = ptr[i];
        j = i-1;
        while (j>=0 && ptr[j]>key);
        {
            ptr[j+1]=ptr[j];
            j--;
        }
        ptr[j+1]=key;
    }
}

int main(){
    int *ptr,max,n,i;
    printf("Enter the size of elements : ");
    scanf("%d",&max);
    ptr = (int*)malloc(max*sizeof(int));
    printf("Enter the no of elements : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&ptr[i]);
    }
    display(ptr,n);
    insertSort(ptr,n);
    display(ptr,n);
    getch();
    return 0;
}