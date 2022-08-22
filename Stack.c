#include<stdio.h>
#include<stdlib.h>
#define max 5
void Push();
void Pop();
void Display();
int stack[max], top = -1;
void main() {
  //Stack Using Array
  int Choice;
  while (1) {
    printf("\nEnter Your Choice\nPress 1 For Display\nPress 2 for Push\npress 3 For Pop\nPress 4 to exit    :   ");
    scanf("%d", & Choice);
    switch (Choice) {
    case 1:
      Display();
      break;
    case 2:
      Push();
      break;
    case 3:
      Pop();
      break;
 
      break;
    case 4:
      exit(0);
      break;
    default:
      printf("\nInvalid Choice");
    }
  }
}
void Push() {
  if (top == max - 1)
    printf("\n**********Stack Overflow**********");
  else {
    printf("\n Enter The Item : ");
    scanf("%d", & stack[++top]);
  }
}
void Display() {
printf("\nElements in STACK\n\n");
  int i;
  if (top == -1)
    printf("\n**********Stack UnderFlow**********");
  for (i = top; i >= 0; i--)
    printf("%d\t", stack[i]);
}
void Pop() {
  if (top == -1)
    printf("\n**********Stack UnderFlow **********");
  else
    printf("\nDeleted Element Is %d", stack[top--]);
}
