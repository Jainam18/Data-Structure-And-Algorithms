#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

node *createNode(int data){
    node *ptr = (node*)malloc(sizeof(node));
    ptr->data = data;
    ptr->left = ptr->right = NULL;
    return ptr;
}

void inorderTraversal(node *root){
    if(root!=NULL){
        inorderTraversal(root->left);
        printf("%d ",root->data);
        inorderTraversal(root->right);
    }
}

int isBST(node *root){
    static node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
    
}

node *search(node *root,int element){
    if(root==NULL){
        return NULL;
    }
    if(element==root->data){
        return root;
    }
    else if(element<root->data){
        search(root->left,element);
    }
    else{
        search(root->right,element);
    }
}

node *searchIter(node *root,int key){
    while(root!=NULL){
        if(key==root->data){
            return root;
        }
        if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }   
    return NULL;
}

void Insert(node *root,int val){
    node *prev = NULL;
    node *new = createNode(val);
    while(root!=NULL){
        prev = root;
        if(root->data==val){
            printf("Cannot insert Duplicate Value in a BST\n");
            return;
        }
        else if(val<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }  
    if(val<prev->data){
        prev->left = new;
    }
    else{
        prev->right = new;
    }
}

int main(){
    node *n;
    node *p1 = createNode(8); 
    node *p2 = createNode(6);
    node *p3 = createNode(10);
    node *p4 = createNode(3);
    node *p5 = createNode(7);
    p1->left = p2;
    p1->right = p3;

    p2->left = p4;
    p2->right = p5;

    inorderTraversal(p1);
    if(isBST(p1)){
        printf("\nThe Tree is Binary Search Tree\n");
    }
    else{
        printf("\nThe Tree is not Binary Search Tree\n");
    }
    n = search(p1,10);
    if(n!=NULL){
        printf("Found\n");
    }
    else{
        printf("Not Found\n");
    }
    Insert(p1,8);
    inorderTraversal(p1);
    getch();
    return 0;
}