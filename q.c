#include<stdio.h>
#include<stdlib.h>
#define max 5
void Display();
void Insert();
void Delete();
void Reset();
int front = -1, rear = -1, Q[max];
void main() {
  int Choice;
  while (2 > 1) {
    printf("\n\nEnter Your Choice\nPress 1 For Display\nPress 2 for Insert \npress 3 For Delete\npress 4 to Reset \nPress 5 to exit    :   ");
    scanf("%d", & Choice);
    switch (Choice) {
    case 1:
      Display();
      break;
    case 2:
      Insert();
      break;
    case 3:
      Delete();
      break;
      case 4: Reset();break;
    case 5:
      exit(0);
      break;
    default:
      printf("\n***********Invalid Choice***********");
    }
  }
}
void Insert() {
  if (front == -1 || rear == -1)
    front++, rear++;
  if (rear == max - 1)
    printf("\n***********Queue Is Full***********");
  else {
    printf("\nEnter the item  : ");
    scanf("%d", & Q[rear++]);
  }
}
void Display() {
  int i;
  if (rear == -1 || front == -1||front>=rear)
    printf("\n***********Empty Queue nothing To deisplay***********");
  else {
    for (i = front; i < rear; i++)
      printf("%d\t", Q[i]);
  }
}
void Delete(){
if(front==-1||front>=rear)
printf("\n***********Empty Queue Nothing to delete ***********\n");
else
printf("\nDeleted Element is %d",Q[front++]);
}
void Reset(){
front=-1;
rear=-1;}
