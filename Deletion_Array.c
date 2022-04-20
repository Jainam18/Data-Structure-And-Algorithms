#include<stdio.h>
#include<conio.h>

void display(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void indDelete(int arr[],int size,int index){
    for (int i = index; i < (size-1); i++)
    {
        arr[i]=arr[i+1];
    }
}

int main(){
    int arr[100]={7,8,94,88,90,50};
    int size = 6,index = 2;
    display(arr,size);
    indDelete(arr,size,index);
    size -= 1;
    display(arr,size);
    getch();
    return 0;
}