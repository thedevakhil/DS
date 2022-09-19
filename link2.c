#include<stdio.h>

#include<stdlib.h>

struct node {
  int data;
  struct node * next;
};
struct node * head = NULL;
//function Declartions
void Display();
void InsertEnd();
void InsertAfterKeyElement();
void DeleteAfterKeyElement();

void main() {
  int n;
  printf("\n *****************OPERATIONS ON LINKEDLIST******************");
  while (1) { //the loop will always true
    printf("\n\n\nEnter Your Choice PRESS\n\t1 For INSERT \n\t2 For DISPLAY\n\t3 For ADD NODE AFTER KEY ELEMENT IN THE LIST\n\t4 FOR DELETE ELEMET AFTER KEY ELEMRNT\n\t5 TO EXIT\n");
    scanf("%d", & n);
    switch (n)
    {
    case 1:
      InsertEnd();
      break; 
    case 2:
      Display();
      break;
    case 3:
      InsertAfterKeyElement();
      break; 
    case 4:
      DeleteAfterKeyElement();
      break;
    case 5:
      exit(0);
      default:printf("\nInvalid Choice");
    }
  }
}
void InsertEnd() {
  struct node * ptr, * temp;
  ptr = (struct node * ) malloc(sizeof(struct node * ));
  int item;
  printf("\nEnter A number : ");
  scanf("%d", & item);
  if (head == NULL) 
  {
    head = ptr;
    ptr -> data = item;
    ptr -> next = NULL;

  } 
  else 
  {
    temp = head;
    while (temp -> next != NULL) 
    {
      temp = temp -> next;
    }
    temp -> next = ptr;
    ptr -> data = item;
    ptr -> next = NULL;
  }

}
void Display() {

  struct node * ptr;
  ptr = head;
  if (ptr == NULL) 
  {
    printf("Empty Linked List");
  } 
  else 
  {
    while (ptr != NULL) 
    {
      printf("%d\t", ptr -> data);
      ptr = ptr -> next;
    }
  }
}


void InsertAfterKeyElement()
{
  int key, item;
  if (head == NULL)
    printf("/n  Empty list");
  else 
  {
    printf("\nEnter A Key Element : ");
    scanf("%d", & key);
    printf("\nEnter The item to be inserted : ");
    scanf("%d", & item);
    struct node * ptr = head, * temp;
    temp = (struct node * ) malloc(sizeof(struct node * ));
    while (ptr != NULL) 
    {
      if (ptr -> data == key) 
      {
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
void DeleteAfterKeyElement()
{
int key;
if(head==NULL)
	printf("\n Empty List Key Can't find key");
else
	{
		printf("\nEnter a key element : ");
		scanf("%d",&key);
		struct node * ptr=head;
		while(ptr!=NULL)
		{
			if(ptr->data==key)
			{
				if(ptr->next==NULL)
					{
					printf("\n\t ! No Node After Key Element");
					break;
					}
				else
					{
					ptr->next=ptr->next->next;
					break;
					}
				}
				ptr=ptr->next;
		}
	}
}
