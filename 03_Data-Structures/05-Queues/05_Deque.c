// Deque is also known as double ended queue because here insertion and deletion can occur from both ends of a queue :)
// Deque has all functionalities of a vector, stack and queue :)
// It also has a iterator support because deque has vector functionalities :)
// Watch this video contains deque stl c++ ==> https://www.youtube.com/watch?v=uY60z4ff5W4

#include <stdio.h>

void insert_front(int *deque,int *front,int *rear,int *size)
{

  int x;
  printf("Enter the element you want to insert at front of deque : ");
  scanf("%d",&x);

 if( (*rear==*(front)-1) || (*rear==*(size)-1) && *front==0)
 {
     printf("Sorry!! but the deque is full , you cannot insert any new element at front of deque!!! ");
 }

 else if(*(front)==-1 && *(rear)==-1)
 {
  *(front) = *(rear) = *(size)-1;
  deque[*front]=x;
 }

 else if(*front==0 && *rear!=*size-1)
 {
    *(front) = *(size)-1;
    deque[*front]=x;
 }

 else
 {
   (*front)--;
   deque[*front]=x;
 }

}


void delete_front(int *deque,int *front,int *rear)
{

   if(*front==-1 && *rear==-1)
   {
     printf("Sorry!!! but the deque is empty,there is no element available to be deleted!!! ");
   }

   else if(*front==*rear)
   {
     printf("Deleted element from front : %d",deque[*front]);
     *front=*rear=-1;
   }

   else
   {
     printf("Deleted element from front : %d",deque[*front]);
     (*front)++;
   }

}


void insert_rear(int *deque,int *front,int *rear,int *size)
{

  int x;
  printf("Enter the element you want to insert at rear of deque : ");
  scanf("%d",&x);

 if((*rear==*front-1) || (*rear==*size-1 && *front==0))
 {
    printf("Sorry!! but the deque is full , you cannot insert any new element at rear of deque!!! ");
 }

 else if(*front==-1 && *rear==-1)
 {
   *front=*rear=0;
   deque[*rear]=x;
 }

 else
 {
   *rear=( (*rear+1)%(*size) );
   deque[*rear]=x;
 }

}


void delete_rear(int *deque,int *front,int *rear)
{

    if(*front==-1 && *rear==-1)
   {
     printf("Sorry!!! but the deque is empty,there is no element available to be deleted!!! ");
   }
   else if(*rear==*front)
   {
        printf("Deleted element from rear : %d",deque[*rear]);
       *front=*rear=-1;
   }
   else
   {
     printf("Deleted item from rear : %d",deque[*rear]);
     (*rear)--;
   }

}


void display(int *deque,int *front,int *rear,int *size)
{
    if(*front==-1 && *rear==-1)
    {
  printf("Sorry , but the deque is empty and there is not even a single element available to be displayed!!!");
    }
    else
    {
  printf("Elements in a deque from front to rear is shown as : ");
  int i;
   for( i=*front ; i!=*rear ; i=((i+1)%(*size)) )
   {
     printf("%d  ",deque[i]);
   }
   printf("%d",deque[i]);

    }
}


void get_front(int *deque,int *front,int *rear)
{

  if(*front==-1 && *rear==-1)
  printf("Sorry , but the deque is empty and there is no element available to be displayed!!!");
  else
  printf("Front element in a deque : %d",deque[*front]);

}


void get_rear(int *deque,int *front,int *rear)
{

  if(*front==-1 && *rear==-1)
  printf("Sorry , but the deque is empty and there is no element available to be displayed!!!");
  else
  printf("Rear element in a deque : %d",deque[*rear]);
}

int main()
{
    int size,choice;
    printf("\nAkshit Rawat , Section : B , Student-ID = 20011236 \n\n");

    printf("Enter the size of deque : ");
    scanf("%d",&size);
    int deque[size] , front=-1,rear=-1;
    
    printf("\nEnter : 0 to exit the program\n");
    printf("Enter : 1 to insert element at front of deque\n");
    printf("Enter : 2 to delete an item from front of deque\n");
    printf("Enter : 3 to insert element at rear of deque\n");
    printf("Enter : 4 to delete an item from rear of deque\n");
    printf("Enter : 5 to display elements of a deque\n");
    printf("Enter : 6 to get the front element from deque\n");
    printf("Enter : 7 to get the rear element from deque");

  do
     {
         printf("\n\nEnter the choice : ");
         scanf("%d",&choice);

         switch(choice)
         {
             case 0 : printf("Program Ended Succesfully!!!\n\n");
                       break;
             case 1 : insert_front(deque,&front,&rear,&size);
                       break;
             case 2 : delete_front(deque,&front,&rear);
                       break;
             case 3 : insert_rear(deque,&front,&rear,&size);
                       break;
             case 4 : delete_rear(deque,&front,&rear);
                       break;
             case 5 : display(deque,&front,&rear,&size);
                       break;
             case 6 : get_front(deque,&front,&rear);
                       break;
             case 7 : get_rear(deque,&front,&rear);
                       break;
             Default : printf("Wrong choice!!!");
                       break;
         }
   
       } while(choice!=0);
 return 0;
}
