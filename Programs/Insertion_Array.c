#include<stdio.h>
#include<conio.h>

void display(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int indInsert(int arr[],int size,int capacity,int index,int element){
    if(size>=capacity){
        return -1;
    }
    else{
        for (int i = size-1; i >= index; i--)
        {
            arr[i+1] = arr[i];
        }
        arr[index] = element;
        return 1;
    }
}

int main(){
    int size = 4,capacity = 100,index = 1,element = 33;
    int arr[100] = {5,56,98,100};
    display(arr,size);    
    int a = indInsert(arr,size,capacity,index,element);
    if(a==-1){
        printf("The Element has failed to get inserted in the array");
    }
    else{
        size += 1;
        printf("The Element is sucessfully inserted : \n");
        display(arr,size); 
    }
    getch();
    return 0;
}