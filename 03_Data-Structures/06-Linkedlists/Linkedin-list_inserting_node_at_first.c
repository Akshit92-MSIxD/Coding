#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

// Pass by value case : function to add new node at the beginning and returning new head containing new node address

struct node* add_beg(struct node* head,int data)
{
    struct node* inserted =(struct node*)malloc(sizeof(struct node));
    inserted->data=data;
    inserted->next=NULL;

    inserted->next=head;
    head=inserted;

    return head;
}

// Pass by reference case : function to add new node at the beginning and returning new head containing new node address

void add_first(struct node **head,int data)
{
     struct node* inserted=(struct node*)malloc(sizeof(struct node));
     inserted->data=data;
     inserted->next=NULL;

     inserted->next=*head;
     *head=inserted;
}



int main()
{
    struct node* head=(struct node*)malloc(sizeof(struct node));
    head->data=45;
    head->next=NULL;

    struct node* current=(struct node*)malloc(sizeof(struct node));
    current->data=98;
    current->next=NULL;
    head->next=current;

    printf("Displayed data items of linkedin-list : ");
    struct node* access_ptr=head;

    while(access_ptr!=NULL)
    {
        printf("%d ",access_ptr->data);
        access_ptr=access_ptr->next;
    }

    struct node* inserted=(struct node*)malloc(sizeof(struct node));
    inserted->data=3;
    inserted->next=NULL;

    //Inserting newly made above node at the beginning without using function :

    inserted->next=head;
    head=inserted;

    printf("Displayed data items of linkedin list after adding a new node at the beginning : ");

    access_ptr=head;

    while(access_ptr!=NULL)
    {
        printf("%d ",access_ptr->data);
        access_ptr=access_ptr->next;
    }

    // Pass by value case : Inserting newly made above node at the beginning  using function add_beg(head,data) 

    int data;

    printf("\nEnter the value of data  in new node : ");
    scanf("%d",&data);


    head=add_beg(head,data);

    access_ptr=head;

   printf("Displayed data items of linkedin list after adding a new node at the beginning : ");

    while(access_ptr!=NULL)
    {
        printf("%d ",access_ptr->data);
        access_ptr=access_ptr->next;
    }


     // Pass by reference case : Inserting newly made above node at the beginning  using function add_beg(head,data) 

     int data;

    printf("\nEnter the value of data  in new node : ");
    scanf("%d",&data);


     add_first(&head,data);
     access_ptr=head;

     printf("Displayed data items of linkedin list after adding a new node at the beginning : ");
     
     while(access_ptr!=NULL)
     {
          printf("%d ",access_ptr->data);
          access_ptr=access_ptr->next;
     }

}