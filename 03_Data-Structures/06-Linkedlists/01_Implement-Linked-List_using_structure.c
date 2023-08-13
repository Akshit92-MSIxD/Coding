// Note in this implementation I have not written code for insertion , deletion and printList. Please read those codes in 02_Implement-Linked-List_using_structure.cpp :)

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

int main()
{

int choice;
printf("\n\nEnter your choice(either 1 or 2) : ");
scanf("%d",&choice);

if(choice==1)
{
//Method 1 : Creating three nodes dynamically using three differnt pointers(method not useful to make large no. of nodes)

  struct node* head=(struct node*)malloc(sizeof(struct node));
  struct node* second=(struct node*)malloc(sizeof(struct node));
  struct node* third=(struct node*)malloc(sizeof(struct node));
  
  head->data=2;
  head->next=second;

  second->data=3;
  second->next=third;

  third->data=4;
  third->next=NULL;

//ery very important concept in case 2
/* head->data=5;
head->next=second;

(head->next)->data=4;
(head->next)->next=third;

(((head->next)->next))->data=1;
((((head->next)->next))->next)=NULL;*/
  
  struct node* access_ptr=head;
  
   printf("\n\nDisplay linked list data items : ");
  for(int i=0;i<=2;i++)
  {
      printf("%d ",access_ptr->data);
      access_ptr=access_ptr->next;
  }

}

else

{

  // Method 2 : Creating 4 nodes in heap with only two pointers(head and current)

  struct node* head=(struct node*)malloc(sizeof(struct node)); // creating first node and assigning its address to head pointer
  scanf("%d",&head->data);
  head->next=NULL;

  struct node* current=(struct node*)malloc(sizeof(struct node)); // creating second node and assigning its address to current pointer
  scanf("%d",&current->data);
  current->next=NULL;
  head->next=current;

  current=(struct node*)malloc(sizeof(struct node)); // creating third node but assigning its address to same current pointer
  scanf("%d",&current->data);
  current->next=NULL;
  head->next->next=current;

  current=(struct node*)malloc(sizeof(struct node)); // creating fourth node but assigning its address to same current pointer
  scanf("%d",&current->data);
  current->next=NULL;
  head->next->next->next=current;


  current=(struct node*)malloc(sizeof(struct node)); // creating fifth node but assigning its address to same current pointer
  scanf("%d",&current->data);
  current->next=NULL;
  head->next->next->next->next=current;

  // This way we create more two nodes using only head and current pointer

  struct node* access_ptr=head;

  printf("\n\nDisplay linked list items : ");
  while( (access_ptr->next) != NULL)
  {
     printf("%d ",access_ptr->data);
     access_ptr=access_ptr->next;
  }
  printf("%d",access_ptr->data);

}


}














