/* 
   LINKED STACK STRUCTURE IMPLEMENTATION
   DECIMAL TO BINARY CONVERTION
  */
#include<stdio.h>
#include<stdlib.h>
#define SIZE 100


void Push(int num, int *top, int StackArray[]); /* PUSH FUNCTION: ADDING AN ITEM TO THE STACK */
int Pop(int *top, int StackArray[]); /* POP FUNCTION: REMOVING AN ITEM FROM THE STACK */
int isStackEmpty(int top, int StackArray[]); /* CHECKING IF STACK IS EMPTY OR NOT */
void decimalToBinary(int item); /* FUNCTION TO CONVERT FROM DECIMAL TO BINARY */

/* CONVERTION FROM DECIMAL TO BINARY */
void decimalToBinary(int item)
{
  int linkedStack[SIZE];
  int top=-1;
  int temp;

  while(item!=0) {
    temp = item % 2;
    Push(temp, &top, linkedStack);
    item /= 2;
  }
  while(top!=-1)
    printf("%d", Pop(&top, linkedStack));
  printf("\n");
}
/* PUSH FUNCTION */
void Push(int num, int *top, int StackArray[])
{
  switch(*top == (SIZE-1)) {
    case 1:
      printf("Error! StackArray Overflow!\n\n");
      break;
    default:
      *top = *top + 1;
      StackArray[*top] = num;
  }
}
/* POP FUNCTION */
int Pop(int *top, int StackArray[])
{
  int num;
  switch(*top) {
    case -1:
      printf("StackArray Underflow\n");
      exit(1);
    default:
      num = StackArray[*top];
      *top = *top - 1;
      break;
  }
  return num;
}
/* MAIN FUNCTION */
int main()
{
  int item;
  printf("Enter a decimal number: ");
  scanf("%d",&item);
  printf("\n");
  printf("Binary representation: ");
  decimalToBinary(item);
  return 0;
}
