// Create and Display Generic Tree using Node(implemented using vector approach!!!)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Node
{
    public :

    int data;

    vector<Node*> children;

    Node()
    {
        data = 0;
    }

    Node(int data)
    {
        this->data = data;
    }

};


Node* createGTree(vector<int> &v)
{
    int size = v.size();
    stack<Node*> s;

    Node* root = new Node(v[0]);
    s.push(root);

    for(int i=1;i<size;i++)
    {
        if(v[i]!=-1)   // Go one level down + make this node a child node of current node(on stack top) :)
        {
            Node* newnode = new Node(v[i]);
            s.top()->children.push_back(newnode);
            s.push(newnode);
            continue;
        }

        s.pop();   // if v[i] == -1 ==> that means Go one level up (i.e to your parent :) )
    }

    s.pop();  // poping the last node(address) present in the stack i.e root;

    return root;
}


// Display nodes using Depth First Traversal aka Euler Path Traversal :)

void display(Node* root)
{
    cout<<"Children of "<<root->data<<" -> ";

    for(int i=0;i<root->children.size();i++)
    {
        cout<<root->children[i]->data<<",";
    }
    
    cout<<".\n";

    for(int i=0;i<root->children.size();i++)
    {
        display(root->children[i]);
    }

    return;
}


int main()
{
    vector<int> tree = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1}; // Note : here -1 is node a node !!!

    Node* root = NULL;

    root = createGTree(tree);

    display(root);


}