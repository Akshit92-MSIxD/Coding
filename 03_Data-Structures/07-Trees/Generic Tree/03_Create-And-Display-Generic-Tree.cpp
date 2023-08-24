// *** Imp : Please read about Depth First Creation of GTree [maine isi program mai sabse niche likha hua detail mai iske baare mai pad lena use bhi !!!!]

// Depth First is related with stack !!!! :)
// Breadth First is related with Queue !!!! :)

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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

    ~Node()
    {
        for(Node* child : children)
        {
            delete child;
        }
    }

};


// Creating GTree using Depth First Creation (iterative)  [Note : Recursive one left]

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



// Display nodes using Depth First Traversal aka Euler Path Traversal recursively :) [Note : iterative one left]

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

    delete root;


}



/* Very Very Important information about Depth First Creation of Generic Tree */


// Depth-first creation of a tree is a method for constructing a tree data structure in a way that explores as deeply as possible along a branch of the tree before backtracking. This means that it starts at the root node, creates its children, then goes deeper into the children's children, and so on, until it reaches a leaf node or a node with no more unprocessed children. When it reaches a leaf or a node with no unprocessed children, it backtracks to the nearest unprocessed ancestor node and continues the process there.

// Here's a high-level description of how depth-first creation of a tree typically works:

// Start with the root node.
// Create the root node and initialize it.
// If there are child nodes to be added, create the first child node and attach it to the root node.
// Recursively apply the same process to the newly created child node (i.e., create its children if any).
// Repeat steps 3 and 4 until all nodes in the branch have been created.
// Backtrack to the nearest unprocessed ancestor node (parent node) and continue the process for its remaining children.
// Repeat steps 3 to 6 until the entire tree has been created.

// Depth-first creation is often used when you have a hierarchical or recursive structure like a tree, where you want to explore one branch of the tree as deeply as possible before moving on to the next branch. It is a common approach in various tree-based algorithms and data structures.

//Depth-first creation is commonly used when constructing data structures like trees and graphs from a list of elements or when building hierarchical structures, as it often naturally follows the recursive or iterative exploration of the data.




