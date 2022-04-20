#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void display(int *ptr,int n){
    printf("The Elements in array are : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",ptr[i]);
    }
    printf("\n");
}

int insert(int *ptr,int size,int n,int num,int index){
    if(n>=size){
        return -1;
    }
    for (int i = size-1; i >=index; i--)
    {
        ptr[i+1]=ptr[i];
    }
    ptr[index]=num;
    return 1;
}

void delete(int *ptr,int n,int index){
    for (int i = index; i < (n-1); i++)
    {
        ptr[i] = ptr[i+1];
    }
    
}

int linnearSearch(int *ptr,int n,int element){
    for (int i = 0; i < n; i++)
    {
        if(ptr[i]==element){
            return i;
        }
    }
    return -1;
}

int main(){
    int *ptr,size,n,choice,num,index;
    char repeat='Y';
    printf("Enter the Size Of The Array : ");
    scanf("%d",&size);
    ptr = (int *) malloc(size * sizeof(int));
    printf("Enter the Number Of Elements in Array : ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the elements %d : \n",i+1);    
        scanf("%d",&ptr[i]);
    }
    while (repeat!='N'){
        printf("Enter\n1:Display Array\n2:Insert Number in Array\n3:Delete a Number in Array\n4:Search For Number\n");
        printf("Your Choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            display(ptr,n);
            break;
        case 2:
            printf("Enter the Number To be Inserted : \n");
            scanf("%d",&num);
            printf("Enter the Index at which you want to Insert the Number: \n");
            scanf("%d",&index);
            insert(ptr,size,n,num,index);
            n = n+1;
            display(ptr,n);
            break;
        case 3:
            printf("Enter the Index at which you want to Delete the Number: \n");
            scanf("%d",&index);
            delete(ptr,n,index);
            n = n-1;
            display(ptr,n);
            break;
        case 4:
            printf("Enter the Number To be Searched : \n");
            scanf("%d",&num);
            int i = linnearSearch(ptr,n,num);
            printf("The index where Number %d is Found In the Array is %d\n",num,i);
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
        scanf("%c",&repeat);
    }
        
    
    
    
    getch();
    return 0;
}