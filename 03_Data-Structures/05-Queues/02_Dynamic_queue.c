// Dynamic queue : MaxCapacity(array size!!!) for queue can be increased or decreased depending upon the conditions :)

/* if (size of queue == maxCapacity of queue) ==> create a new array of size 2*maxCapacity and enqueue all the elements of current array into the new array
 and update the maxCapacity=2*maxCapacity */



#include <stdio.h>
#include <stdlib.h>

void enqueue(int *queue,int*front,int*rear,int size)
{ 

   if(size==0)
 {
    printf("You have entered the size of a queue equal to zero ,therefore, you can't perform the following operations in a queue!!!!");
 }

 else
 {
   int element;
   printf("Enter the element you want to enqueue : ");
   scanf("%d",&element);

  if(*front==-1 && *rear==-1)
  {
      *front=*rear=0;
      queue[*rear]=element;
      printf("Enqueued element is : %d",queue[*rear]);
  }

  else if(*rear==size-1)
  {
    printf("Sorry the Queue is full , You can't insert more elements from rear side !!!!");
  }

  else
  {
     (*rear)++;
     queue[*rear]=element;
     printf("Enqueued element is : %d",queue[*rear]);
  }
 }

}

void dequeue(int *queue,int*front,int*rear)
{

   if(*front==-1 && *rear==-1)
   {
   printf("Queue is empty!!!");
   }

   else if(*front==*rear)
   {
       printf("Dequeued element is : %d",queue[*front]);
      *front=*rear=-1;
   }

   else
   {
       printf("Dequeued element is : %d",queue[*front]);
       (*front)++;
   }

}

void display(int *queue,int*front,int*rear)
{
    if(*front==-1 && *rear==-1)
   {
   printf("Queue is empty !!!, first insert or enqueue atleast one element in a queue");
   }
   else
   {
     printf("Elements present in queue : ");
     for(int i=*front;i<=*rear;i++)
     printf("%d ",queue[i]);
   }
}

void check_front(int *queue,int*front)
{   
    if(*front==-1)
    printf("No front element present , because the queue is empty!!!");
    else
    printf("Front element in a queue is : %d",queue[*front]);

}

void check_rear(int *queue,int*rear)
{
    if(*rear==-1)
    printf("No front element present , because the queue is empty!!!");
    else
    printf("Rear element in a queue is : %d",queue[*rear]);

}

void size_queue(int *queue,int* size)
{

    printf("Enter the new size of dynamically allocated queue : ");
    scanf("%d",size);
   queue=(int *)realloc(queue,sizeof(int) * (*size));

   if(queue==NULL)
   printf("Sorry!!! memory is not reallocated successfully!!");
   else
   printf("Memory is reallocated successfully!!!");
}


int main()
{
    printf("\nAkshit Rawat , Section : B , Student-ID = 20011236 \n\n");
    printf("Enter : 0 to exit the program\n");
    printf("Enter : 1 to enqueue\n");
    printf("Enter : 2 to dequeue\n");
    printf("Enter : 3 to display the elements of a queue\n");
    printf("Enter : 4 to check front element of a queue\n");
    printf("Enter : 5 to check rear element of a queue\n");
    printf("Enter : 6 to change the size of queue!!!\n\n");

 
 int size,front=-1,rear=-1,choice;
 printf("Enter the size of dynamically allocated queue : ");
 scanf("%d",&size);

 int *queue=(int *)malloc(sizeof(int) * size);

 do
 {
    printf("\n\nEnter your choice : ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 0 : printf("Program ended successfully\n\n");
                 break;
        case 1 : enqueue(queue,&front,&rear,size);
                 break;
        case 2 : dequeue(queue,&front,&rear);
                 break;
        case 3 : display(queue,&front,&rear);
                 break;
        case 4 : check_front(queue,&front);
                 break;
        case 5 : check_rear(queue,&rear);
                 break;
        case 6 : size_queue(queue,&size);
                 break;
        default : printf("Wrong choice!!!");
                  break;
    }
 } while (choice!=0);

 return 0;
}
