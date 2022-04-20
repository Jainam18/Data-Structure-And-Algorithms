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
void bubbleSort(int *ptr,int n){
    int i,j,temp;
    for (i = 0; i<n; i++)
    {
        for ( j = 0; j < n-i-1; j++)
        {
            if(ptr[j]>ptr[j+1]){
                temp = ptr[j];
                ptr[j] = ptr[j+1];
                ptr[j+1] = temp;
            }
        }
        
    }
    
}

void adaptiveBubbleSort(int* p,int n){
    int i,j,temp,isSorted=0;
    for(i=0;i<n;i++){
        printf("Pass Number %d\n",i+1);
        isSorted = 1;
        for(j=0;j<n-1-i;j++){
            if(p[j]>p[j+1]){
                temp  = p[j];
                p[j] =p [j+1];
                p[j+1] = temp;
                isSorted = 0;
            }
            if(isSorted){
                return;
            }           
        }
    }
}

int main(){
    int *p,max,n,i,j;
    printf("Enter the size of array : ");
    scanf("%d",&max);
    p = (int *)malloc(max*sizeof(int));
    printf("Enter the number of elements required : ");
    scanf("%d",&n);
    getElement(p,n);
    display(p,n);
    // bubbleSort(p,n);
    adaptiveBubbleSort(p,n);
    printf("After Adaptive Sorting : \n");
    display(p,n);
    getch();
    return 0;
}