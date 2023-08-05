#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *left , *right;
};

 struct node* create() // It will return the addressof root node created dynamically
{
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    int x , choice;

    cout<<"\nPress 0 for no more node!!!\n";
    cout<<"Press 1 for more node!!!\n\n";


    cout<<"Enter the choice : ";
    cin>>choice;

    if(choice == 0)
    {
        return NULL;
    }

    else
    {
        cout<<"Enter the data : ";
        cin>>x;
        newnode->data = x;

        cout<<"\nEnter the left child of "<<x<<":";
        newnode->left = create();

        cout<<"\nEnter the right child of "<<x<<":";
        newnode->right = create();

        return newnode;

    }
}

int main()
{
   struct node *root;
   root = NULL;

   root = create();
}


