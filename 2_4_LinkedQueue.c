#include<stdio.h>

#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};
struct node * rear = NULL;
struct node * front = NULL;
void Insert();
void Delete();
void Display();
void main() {
    int choice;
    while (1) {
        printf("\nPress 1 for INSERT\nPress 2 for DELETE\nPress 3 To VIEW QUEUE  :  ");
        scanf("%d", & choice);
        switch (choice) {
        case 1:
            Insert();
            break;
        case 2:
            Delete();
            break;
        case 3:
            Display();
            break;
        default:
            printf("\n Invalid choice");
        }
    }
}
void Insert() {
    int key;
    printf("\nEnter the element to be inserted : ");
    scanf("%d", & key);
    struct node * newnode, * temp;
    newnode = (struct node * ) malloc(sizeof(struct node * ));
    newnode -> data = key;
    newnode -> next = NULL;
    temp = rear;
    if (rear == NULL || front == NULL) {
        rear = front = newnode;

    } else {
        while (temp -> next != NULL)
            temp = temp -> next;
        temp -> next = newnode;
    }
}
void Delete() {
    struct node * temp;
    temp = front;
    if (front == NULL)
        printf("\nEmpty Queue");
    else if (front -> next == NULL)
        front = NULL;
    else
        front = front -> next;
}
void Display() {
    struct node * temp;
    temp = front;
    if (temp == NULL)
        printf("\nEmpty Queue ");
    else {
        while (temp != NULL) {
            printf("%d\t", temp -> data);
            temp = temp -> next;
        }
    }
}
