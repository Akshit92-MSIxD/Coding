// Note : This is not the implementation of Generic tree(N-ary tree) but a approach that how individual Node of a Generic tree stores the address of its child nodes using a vector :) 

// Please refer to this GFG article for better understanding : https://www.geeksforgeeks.org/generic-treesn-array-trees/

#include <iostream>
using namespace std;
#include <vector>


// Not memory efficient :( 
class Node
{

public :

 int data;

 vector<Node*> children;    // will store the addresses(not data!!!) of the child nodes !!!

 Node(int data)
 {
    this->data = data;
 }

};



int main()
{
    cout<<"\nEnter the root node : ";
    int x;
    cin>>x;
    Node* root = new Node(x) ;   // Note : new node(x) will return the address of the node that would be created in heap !!!

   
    //==> Made some nodes and insert their addresses in root node's children vector :)
       
       /* Inefficient way */

     // root->children.push_back(new Node(7));
    // root->children.push_back(new Node(8));
    // root->children.push_back(new Node(9));
    // root->children.push_back(new Node(10));
    // root->children.push_back(new Node(11));


    /* Efficient way */

     char choice = '\0';

    do{
        cout<<"\nWant a children node(y/n) : ";
        cin>>choice;

        if(choice == 'y')
        {
            cout<<"\nEnter the children node : ";
            int data;
            cin>>data;
            root->children.push_back(new Node(data));
            cout<<data<<" is now children of root node "<<root->data<<" !!!\n";
            continue;
        }

    }
    while(choice!='n');


    cout<<"\nRoot node : "<<root->data<<endl;
    cout<<"Children of root node : ";

    for(int i=0;i<root->children.size()-1;i++)
    {
        cout<<root->children[i]->data<<" ";
    }


}