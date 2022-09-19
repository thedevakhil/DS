#include<stdio.h>

#include<stdlib.h>

struct node {
  int data;
  struct node * next;
};
struct node * head = NULL;
//function Declartions
void Display();
void InsertBeginning();
void InsertEnd();
void DeleteEnd();
void DeleteBegnning();
void InsertAfterKeyElement();

void main() {
  int n;
  printf("\n *****************OPERATIONS ON POINTERS******************");
  while (1) { //the loop will always true
    printf("\n\n\nEnter Your Choice PRESS\n1 For Display\n2 For INSERT  A NODE AT BEGINNING\n3 For INSERT A NODE AT END\n4 For DELETE NODE FROM END\n5 For DELETE NODE FROM BEGENNING\n6 For ADD NODE AFTER KEY ELEMENT IN THE LIST\nPRESS ANY OTHER KEY TO EXIT\n: ");
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
    case 5:
      DeleteBegnning();
      break; //Delete the node from the first or begnning of linked list
    case 6:
      InsertAfterKeyElement();
      break; // adding an element after a key element
    default:
      exit(0);

    }

  }
}

void Display() {

  struct node * ptr;
  ptr = head;
  if (ptr == NULL) {
    printf("Empty Linked List");
  } else {

    while (ptr != NULL) {
      printf("%d\t", ptr -> data);
      ptr = ptr -> next;
    }
  }
}

void InsertBeginning() {
  struct node * ptr; //creating a node named ptr 
  ptr = (struct node * ) malloc(sizeof(struct node * )); //allocating memory for node ptr
  int item;

  printf("\nEnter A number :");
  scanf("%d", & item);
  if (head == NULL) { //checking the list is empty and if emty just add the new node
    head = ptr;
    ptr -> data = item;
    ptr -> next = NULL;

  } else {
    /*the list is not empty,the new data(item) is placed in datapart of ptr,Then the next of ptr(link of ptr
        is assigned with the address in head,then the head is re asigned with the adress of new node*/
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
  struct node * ptr; // here we nees to travel to the end of linked list hence a node 

  if (head == NULL) //if list is empty
    printf("\nNothing to Delete");
  else if (head -> next == NULL) { //if the linked list has only one Element
    head = NULL;
  } else {
    ptr = head;
    while (ptr -> next -> next != NULL) {
      ptr = ptr -> next;
    }

    ptr -> next = NULL;
  }
}
void DeleteBegnning() {

  if (head == NULL)
    printf("\nNothing to Delete");
  else {
    head = head -> next;
  }
}
void InsertAfterKeyElement() {
  int key, item;
  if (head == NULL)
    printf("/n  Empty list");
  else {
    printf("\nEnter A Key Element");
    scanf("%d", & key);
    printf("\nEnter The item to be inserted : ");
    scanf("%d", & item);
    struct node * ptr = head, * temp;
    temp = (struct node * ) malloc(sizeof(struct node * ));
    while (ptr != NULL) {
      if (ptr -> data == key) {

        temp -> next = ptr -> next;
        temp -> data = item;
        ptr -> next = temp;
        break;
      }
      ptr = ptr -> next;
      if (ptr == NULL)
        printf("\nNo key Element found in list");
    }
  }
}
 
