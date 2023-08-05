// Akshit Rawat , Section : B , Student-ID = 20011236 
// Question-1

#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{   
     int top;
     int size;
     int * data;
}stack;


void stack_push(stack *s1)
{
    if(s1->top == s1->size - 1)
    {
        printf("Sorry!! the stack is full , you can't add more elements!!!");
    }
    else
    {
    (s1->top)++;
    
    int element;
    printf("Enter the element you would like to push in the stack : ");
    scanf("%d",&element);
    s1->data[s1->top] = element;
    printf("%d pushed to the stack!!", element);
    }
}


void stack_pop(stack *s1)
{
  if(s1->top ==-1)  
  printf("Sorry!! the stack is empty i.e UnderFlow Condition!!!");
  else{
       printf("%d popped out from stack!!",s1->data[s1->top]);
       (s1->top)--; }
}


void stack_peek(stack *s1)
{
   if(s1->top==-1)
printf("Sorry!! the stack is empty , so there is no peek element");
   else
printf("Peek element in stack : %d",s1->data[s1->top]);
}


void stack_display(stack *s1)
{
    if(s1->top == -1){
printf("Sorry!! but there is no element available in the stack!!!") ; }
else{
    printf("Elements available in the stack : ");
    for(int i=s1->top;i>=0;i--)
    printf("%d ",s1->data[i]); 
}
}


void stack_checkEmpty(stack *s1)
{
    s1->top == -1 ? printf("Yes,the stack is empty , Underflow Condition!!!") : printf("No, the stack is not empty!!!");
    
}


void stack_checkFull(stack *s1)
{

     s1->top == s1->size-1 ? printf("Yes,the stack is Full!!! , Overflow Condition!!!") : printf("No, the stack is not full!!!");
}


void main()
{
  printf("\n\nAkshit Rawat , Section : B , Student-ID = 20011236\n\n");

  stack s1;
  s1.top = -1;
  printf("Enter the size of stack : ");
  scanf("%d",&s1.size);

  s1.data = (int *)calloc(s1.size,sizeof(int));
  int choice;

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
                   case 1: stack_push(&s1);
                            break;
                   case 2: stack_pop(&s1);
                            break;
                   case 3: stack_peek(&s1);
                            break;
                   case 4: stack_display(&s1);
                            break;
                   case 5: stack_checkEmpty(&s1);
                            break;
                   case 6: stack_checkFull(&s1);
                            break;
                    default: printf("Invalid option\n");
                             break;
               }
           }
            while(choice!=0);
}