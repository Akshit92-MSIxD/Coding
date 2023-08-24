// Memory efficient as compare to vector approach [ No extra links between parent and child are required just the first child link is required]

// Treated as BT

// Please refer to this GFG article for better understanding : https://www.geeksforgeeks.org/generic-treesn-array-trees/


#include <iostream>
using namespace std;

class Node
{
    public : 

    int data;

    Node* firstChild;
    Node* nextSibling;

    Node()
    {
        data = 0;
        firstChild = NULL;
        nextSibling = NULL;
    }

    Node(int data)
    {
        this->data = data;
        firstChild = NULL;
        nextSibling = NULL;
    }
};


int main()
{


  cout<<"Enter the root node : ";
  int data;
  cin>>data;

  Node* root = new Node(data);

// Make some child nodes of root node

root->firstChild = new Node(5);
root->firstChild->nextSibling = new Node(6);  // nextSibling is a node attached to the firstChild :)
root->firstChild->nextSibling->nextSibling = new Node(7);
root->firstChild->nextSibling->nextSibling->nextSibling = new Node(8);


cout<<"Root Node : "<<root->data<<endl;
cout<< "Child Nodes : ";

cout<<root->firstChild->data<<" ";
cout<<root->firstChild->nextSibling->data<<" ";
cout<<root->firstChild->nextSibling->nextSibling->data<<" ";
cout<<root->firstChild->nextSibling->nextSibling->nextSibling->data<<" ";


}

