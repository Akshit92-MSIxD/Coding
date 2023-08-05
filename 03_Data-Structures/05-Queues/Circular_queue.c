// Akshit Rawat , Section : B , Student-ID = 20011236 
// Question-2

#include <stdio.h>

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

 if( (*rear==*front-1) || (*front==0 && *rear==size-1) )
  {
    printf("Sorry the Queue is full , You can't insert more elements from rear side !!!!");
  }

 else
  {
      if(*front==-1) *front=0;
      *rear=( (*rear+1) % size);
      queue[*rear]=element;
      printf("Enqueued element is : %d",queue[*rear]);
  }
 }
}


void dequeue(int *queue,int*front,int*rear,int size)
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
       *front=( (*front+1) % size );
   }

}

void display(int *queue,int*front,int*rear,int size)
{
    if(*front==-1 && *rear==-1)
   {
   printf("Queue is empty !!!, first insert or enqueue atleast one element in a queue");
   }
   else
   {
     printf("Elements present in queue : ");
     for(int i=*front;i!=*rear;i=( (i+1) % size))
     {
     printf("%d ",queue[i]);
     }
     printf("%d",queue[*rear]);
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


int main()
{
    printf("\nAkshit Rawat , Section : B , Student-ID = 20011236 \n\n");
    printf("Enter : 0 to exit the program\n");
    printf("Enter : 1 to enqueue\n");
    printf("Enter : 2 to dequeue\n");
    printf("Enter : 3 to display the elements of a queue\n");
    printf("Enter : 4 to check front element of a queue\n");
    printf("Enter : 5 to check rear element of a queue\n\n");
 
 int size,front=-1,rear=-1,choice;
 printf("Enter the size of circular Queue : ");
 scanf("%d",&size);

 int queue[size];

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
        case 2 : dequeue(queue,&front,&rear,size);
                 break;
        case 3 : display(queue,&front,&rear,size);
                 break;
        case 4 : check_front(queue,&front);
                 break;
        case 5 : check_rear(queue,&rear);
                 break;
        default : printf("Wrong choice!!!");
                  break;
    }
    
 } while (choice!=0);
  return 0;
}
