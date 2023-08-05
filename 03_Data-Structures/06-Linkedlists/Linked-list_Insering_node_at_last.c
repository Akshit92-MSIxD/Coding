#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

int main()
{
    struct node* head=(struct node*)malloc(sizeof(struct node));
    head->data=45;
    head->next=NULL;

    struct node* current=(struct node*)malloc(sizeof(struct node));
    current->data=98;
    current->next=NULL;
    head->next=current;

    current=(struct node*)malloc(sizeof(struct node));
    current->data=3;
    current->next=NULL;
    head->next->next=current;

    struct node* access1_ptr=head;
 printf("\n\nDisplay data items of linked-list before inserting a node at last position : ");
    while(access1_ptr!=NULL)
    {
        printf("%d ",access1_ptr->data);
        access1_ptr=access1_ptr->next;


    }
  // Creating a new node to be inserted at last position into  above linkedin-list
   struct node* temp=(struct node*)malloc(sizeof(struct node));
   temp->data=67;
   temp->next=NULL;

   // Now inserting a just above node at last position without using current pointer/ with traversal;

   struct node* access2_ptr=head;

   while(access2_ptr->next!=NULL) // traversing the whole linded-list just to obtain the last node address 
   {
       access2_ptr=access2_ptr->next;

   }
  
   access2_ptr->next=temp; // Update the value of pointer in last node from NULL to Address of the  inserted node;

 printf("\n\nDiplay data items of linkedin-list after inserting a node at last position : ");
 access2_ptr=head;
     while(access2_ptr!=NULL)
    {
        printf("%d ",access2_ptr->data);
        access2_ptr=access2_ptr->next;

    }

    













    
    
    

}
