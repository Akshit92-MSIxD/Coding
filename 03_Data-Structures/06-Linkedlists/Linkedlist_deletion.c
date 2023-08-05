#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

void create_list(node** head,int data)
{
    node* new_node=(node*)malloc(sizeof(node));
    static node* last;
    new_node->next=NULL;
    new_node->data=data;

    if(*head==NULL)
    {
        *head=new_node;
        last=new_node;
    }
    else
    {
       last->next=new_node;
       last=new_node;
    }
    return;
}

void delete(node ** head,int pos)
{
    node* temp=*head;
    node* prev=NULL;

    if(*head==NULL)
    {
      printf("No node is available to be deleted ");
      return;
    }
  
  if(pos==1)
  {
      *head = ((*head)->next) ;
      free(temp);
      return;
  }
  else if(pos!=0)
  {
    for(int i=0;i<pos-1;i++)
    {
      prev=temp;
      temp=temp->next;
      if(temp==NULL)
        {
            printf("Wrong position entered by you !!!");
            return;
        }

    }

    prev->next=temp->next;

    free(temp);
  }
    return;
}

void print(node** head)
{
    node* temp=*head;
    
    while(temp!=NULL)
    {
     printf("%d ",temp->data);
     temp=temp->next;
    }
       return;
}

int main()
{
    node* head=NULL;
    int n,pos,data;

    printf("Enter the no. of node you would like to create in a linked-list : ");
    scanf("%d",&n);

    while(n--)
    {
        printf("Enter the data : ");
        scanf("%d",&data);
        create_list(&head,data);
    }
    print(&head);

    printf("Enter the positon of node to be deleted : ");
    scanf("%d",&pos);
    delete(&head,pos);

    print(&head);

}


