// Akshit Rawat , Section : B , Student-ID = 20011236
// Question-2
#include <stdio.h>
#include <stdlib.h>
void stack_push(int *stack,int size,int *top)
{
    if(*top==size-1)
    {

        printf("Sorry!! the stack is full , you can't add more elements!!!");
    }
    else
    {
    *top+=1;
    int element;
    printf("Enter the element you would like to push in the stack : ");
    scanf("%d",&element);
    stack[*top]=element;
    printf("%d pushed to the stack!!", element);
    }
}




void stack_pop(int stack[],int *top)
{
  if(*top==-1)  
  printf("Sorry!! the stack is empty i.e UnderFlow Condition!!!");
  else{
       printf("%d popped out from stack!!",stack[*top]);
       *top-=1; }
}

void stack_peek(int stack[],int *top)
{
   if(*top==-1)
printf("Sorry!! the stack is empty , so there is no peek element");
   else
printf("Peek element in stack : %d",stack[*top]);
}

void stack_display(int stack[],int *top)
{
    if(*top==-1){
printf("Sorry!! but there is no element available in the stack!!!") ; }
else{
    printf("Elements available in the stack : ");
    for(int i=*top;i>=0;i--)
    printf("%d ",stack[i]);}
}

void stack_checkEmpty(int *top)
{
    *top==-1?printf("Yes,the stack is empty , Underflow Condition!!!"):printf("No, the stack is not empty!!!");
    
}

void stack_checkFull(int size,int *top)
{

     *top==size-1?printf("Yes,the stack is Full!!! , Overflow Condition!!!"):printf("No, the stack is not full!!!");
}

int main()
{
    printf("\n\nAkshit Rawat , Section : B , Student-ID = 20011236\n");
    int n;
    printf("\n\nEnter the maximum size that stack can take so that no stack overflow condition occurs  : ");
    scanf("%d",&n);
    
int stack[n], top=-1,choice;

printf("\n\nEnter 0 to stop execution\n");
printf("Enter 1 to push an element into the stack\n");
printf("Enter 2 to pop an element into the stack\n");
printf("Enter 3 to check peek element of the stack\n");
printf("Enter 4 to display the total elements available in the stack\n");
printf("Enter 5 to check if stack is empty or not\n");
printf("Enter 6 to check if stack is full or not\n");

        do{

               printf("\n\nEnter your choice : ");
               scanf("%d",&choice);
               switch(choice)
               {
                   case 0 : break;
                   case 1: stack_push(stack,n,&top);
                            break;
                   case 2: stack_pop(stack,&top);
                            break;
                   case 3: stack_peek(stack,&top);
                            break;
                   case 4: stack_display(stack,&top);
                            break;
                   case 5: stack_checkEmpty(&top);
                            break;
                   case 6: stack_checkFull(n,&top);
                            break;
                    default: printf("Invalid option\n");
                             break;
               }
           }
            while(choice!=0);
        return 0;
}