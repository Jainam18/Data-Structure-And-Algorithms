#include<stdio.h>
#include<conio.h>

int binarySearch(int arr[],int size,int element){
    int low = 0,mid,high = size-1;
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]==element){
            return mid;
        }
        if(arr[mid]<element){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}

int linearSearch(int arr[],int size,int element){
    int i;
    for(i=0;i<size;i++){
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {21,56,97,108,35};
    int size = sizeof(arr)/sizeof(int);
    int element,index,choice;
    do{
        printf("Enter the element which you want to search for : ");
        scanf("%d",&element);
        index = binarySearch(arr,size,element);
        if(index==-1){
            printf("%d is not found in the Array\n",element);
        }
        else{
            printf("Index at which %d is found in the Array is : %d\n",element,index);
        }
        printf("Enter\n1:To Search a element Again\n2:To Exit\n");
        scanf("%d",&choice);
    }while(choice!=2);
    getch();
    return 0;
}
