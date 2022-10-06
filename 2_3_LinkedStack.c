#include<stdio.h>

#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};
struct node * top = NULL;
void push();
void pop();
void Display();
void main() {
    int choice;
    while (1) {
        printf("\nPress 1 for PUSH\nPress 2 for POP\nPress 3 To Display  :  ");
        scanf("%d", & choice);
        switch (choice) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            Display();
            break;
        default:
            printf("\n Invalid choice");
        }
    }
}
void push() {
    int key;
    printf("\nEnter the element to be inserted : ");
    scanf("%d", & key);
    struct node * newnode, * temp;
    newnode = (struct node * ) malloc(sizeof(struct node * ));
    newnode -> data = key;
    newnode -> next = NULL;
    temp = top;
    if (top == NULL) {
        top = newnode;
    } else {
        while (temp -> next != NULL)
            temp = temp -> next;
        temp -> next = newnode;
    }
}
void pop() {
    struct node * temp;
    temp = top;
    if (top == NULL)
        printf("\nEmpty Stack Nothing to POP");
    else if (top -> next == NULL)
        top = NULL;
    else {
        temp = top;
        while (temp -> next -> next == NULL)
            temp = temp -> next;
        temp -> next = NULL;
    }
}
void Display() {
    struct node * temp;
    temp = top;
    if (temp == NULL)
        printf("\nEmpty Stack ");
    else {
        while (temp != NULL) {
            printf("%d\t", temp -> data);
            temp = temp -> next;
        }
    }
}
