#include <stdio.h>
#include <stdlib.h>

int count_nodes=0;


typedef struct node
{
    int data;
    struct node* next;
}node;



void insert_beg(node** head,int data)
{
   node* new=(node*)malloc(sizeof(node));
   new->next=NULL;
   new->data=data;

   new->next=*head;
   *head=new;
   count_nodes++;

   return ;
}



void insert_last(node** head,int data)
{
  node *new=(node*)malloc(sizeof(node));
  new->next=NULL;
  new->data=data;

  if(*head==NULL)  // or *head==NULL (linkedlist is empty)
   {
       *head=new;
   }
   else
   {
       node* temp=*head;
       while(temp->next!=NULL)
       {
           temp=temp->next;
       }
       temp->next=new;  
   }
   count_nodes++;
   return ;
}



void insert_nth(node **head,int data,int pos)
{
 
 if( pos==1)
 
 {
     insert_beg(head,data);
 }

 else if(pos <= count_nodes+1)
 {
 node *new=(node*)malloc(sizeof(node));
 new->next=NULL;
 new->data=data;

 node* prev=*head;

   for(int i=0;i<pos-2;i++)
   {
      prev=prev->next;
   }

   new->next=prev->next;
   prev->next=new;
   count_nodes++;
 }

 else
 {
     printf("Sorry but you cant insert node at wrong position that does not exist!!!!!\n");
 }
 
 return ;

}



void print(node **head)
{
    printf("Displayed nodes : ");
    node *temp=*head;

    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }

 return ;
}



int main()
{
    node* head=NULL;
    int choice,data,pos;

    printf("\n\nEnter 0 to exit the program\n");
    printf("Enter 1 to add a node at front\n");
    printf("Enter 2 to add a node at last\n");
    printf("Enter 3 to add a node at nth positon\n");
    printf("Enter 4 to print all the available nodes of linkedlist\n");
    printf("Enter 5 to exit the program successfully\n\n\n");

   do
   {
       
     printf("Enter the choice : ");
     scanf("%d",&choice);
     switch(choice)
     {
         case 0 :
         printf("Program ended successfully!!!\n\n");
         break;

         case 1 : 
         printf("Enter the data : ");
          scanf("%d",&data);                    
         insert_beg(&head,data);
         break;

         case 2 : 
         printf("Enter the data : ");
          scanf("%d",&data);  
          insert_last(&head,data);
          break;

         case 3 : 
          printf("Enter the data : ");
          scanf("%d",&data);  
          printf("Enter the position : ");
          scanf("%d",&pos);
          insert_nth(&head,data,pos);
          break;

          case 4 : 
          print(&head);
          break;

          default :
          printf("Wrong choice entered !!!");
          break;

     }
     printf("\n\n");
   } while(choice!=0);
   
    return 0;    
}

