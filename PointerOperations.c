#include<stdio.h>

#include<stdlib.h>

struct node {
  int data;
  struct node * next;
};
struct node * head = NULL;

void Display();
void InsertBeginning();
void InsertEnd();
void DeleteEnd();

void main() {
  int n;
  printf("\n *****************OPERATIONS ON POINTERS******************");
  while (1) {
    printf("\n\n\nEnter Your Choice PRESS\n1 for Display\n2 FOR INSERT AT BEGINNING\n3 for INSERT AT END\n4 for DELETE FROM END\n");
    scanf("%d", & n);
    switch (n) {
    case 1:
      Display();
      break; // call the display function
    case 2:
      InsertBeginning();
      break; //insert a node at begnning
    case 3:
      InsertEnd();
      break; //insert a node at end
    case 4:
      DeleteEnd();
      break; //Delete node from end

    }

  }
}
void InsertBeginning() {
  struct node * ptr; //creating a node ptr 
  ptr = (struct node * ) malloc(sizeof(struct node * )); //allocating memory
  int item;

  printf("\nEnter A number :");
  scanf("%d", & item);
  if (head == NULL) { //checking the list is empty and if emty just add the node
    head = ptr;
    ptr -> data = item;
    ptr -> next = NULL;

  } else {
    ptr -> data = item;
    ptr -> next = head;
    head = ptr;

  }

}
void InsertEnd() {
  struct node * ptr, * temp;
  ptr = (struct node * ) malloc(sizeof(struct node * ));
  int item;

  printf("\nEnter A number :");
  scanf("%d", & item);
  if (head == NULL) {
    head = ptr;
    ptr -> data = item;
    ptr -> next = NULL;

  } else {
    temp = head;
    while (temp -> next != NULL) {
      temp = temp -> next;
    }
    temp -> next = ptr;
    ptr -> data = item;
    ptr -> next = NULL;
  }

}
void DeleteEnd() {
  struct node * ptr;

  if (head == NULL) //if list is empty
    printf("\nNothing to Delete");
  else if (head -> next == NULL) {
    head = NULL;
  } else {
    ptr = head;
    while (ptr -> next -> next != NULL) {
      ptr = ptr -> next;
    }
    ptr -> next = NULL;
  }
}
void Display() {
  struct node * ptr;
  ptr = head;
  if (ptr == NULL) {
    printf("Nothing to print");
  } else {

    while (ptr != NULL) {
      printf("%d\t", ptr -> data);
      ptr = ptr -> next;
    }
  }
}
