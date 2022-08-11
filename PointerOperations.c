#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
struct node *head=NULL;
void InsertBeginning();
void Display();


void main(){
int n;
printf("\n *****************OPERATIONS ON POINTERS******************");
while (1){
printf("\nEnter Your Choice\n1 FOR INSERT AT BEGINNING\n2 for Display");
scanf("%d",&n);
switch(n){
case 1: InsertBeginning();break;
case 2: Display();break;
}

}
}
void InsertBeginning(){
struct node *ptr;
ptr = (struct node *) malloc(sizeof(struct node *));  
int item;

printf("\nEnter A number :");
scanf("%d",&item);
if(head==NULL){
head=ptr;
ptr->data=item;
ptr->next=NULL;

}
else{
ptr->data=item;
ptr->next=head;
head=ptr;

}

}
void Display()  
{  
    struct node *ptr;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("Nothing to print");  
    }  
    else  
    {  
        
        while (ptr!=NULL)  
        {  
            printf("%d\t",ptr->data);  
            ptr = ptr -> next;  
        }  
    }  
} 
