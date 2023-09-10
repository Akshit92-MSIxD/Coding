
// Remember Predecessor of a node does not always mean the parent node !!!
// Predecessor of a particular node is a node that comes just before that node in a DFS traversal path(can be Preorder , Postorder and Inorder!!!)
// Predecessor of a particular node can vary depending upon which type of DFS traversal technique we are implementing.

// Remember Successor of a node does not always mean the child node !!!
// Successor of a particular node is a node that comes just after that node in a DFS traversal path(can be Preorder , Postorder and Inorder!!!)
// Successor of a particular node can vary depending upon which type of DFS traversal technique we are implementing.

// https://faculty.salisbury.edu/~ealu/COSC320/Lectures/succ_pred_rules.pdf (Please refer to this for better understanding !!!)


// Note in this problem : We are told to find the Preorder Predecessor and Preorder Successor of a given node !!!


#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class TreeNode
{
    public :

    int data;
    vector<TreeNode*> children;

    TreeNode(int data)
    {
        this->data = data;
    }
};



TreeNode* create_GTree(vector<int> &v)
{
    stack<TreeNode*> s;
    TreeNode* root = new TreeNode(v[0]);
    s.push(root);

     for(int i=1;i<v.size();i++)
     {
        if(v[i]!= -1)
        {
        TreeNode* newnode = new TreeNode(v[i]);
        s.top()->children.push_back(newnode);
        s.push(newnode);
        continue;
        }

        s.pop();
     }

     s.pop();

     return root;
}


/* 

  Brute force :
   --> Create a vector which will store the preorder traversal path of nodes -> then find the target node by traversing
       through the vector and once the target node is found then its previous index node will become Predecessor
       and successive index node will become Successor :)               */


// Optimal Approach
// Recursive DFS traversal (preorder) [since we are told to implement Preorder predecessor and successor ==> We will use preorder traversal for this problem]
// TC : O(n) , SC : O(H) [recursive stack space / tree max depth]

TreeNode* Predecessor = NULL;  // global variable
TreeNode* Successor = NULL; // global variable

void dfs(TreeNode* root , int &tnode , bool &is_found)
{   

    if(is_found == true)    // additional condition to handle successor of a target node (this condition will run after the target node is found )
    {
        Successor = root;
        return;
    }

    if(root->data == tnode) // if target node is found then update is_found = true (that indicates that target node is found but its successor node has not been found till now)
     is_found = true;

    if(root->data != tnode) // update the Predecessor to current node  if current node is not a target node
    Predecessor = root;

    if(root->children.size() == 0)  
    return;

    for(TreeNode* child : root->children)
    {
        dfs(child,tnode,is_found);

        if(Successor != NULL)  // if successor node is already found in previous child subtree then dont not to travel other child subtrees :)
        return;
    }

}



int main()
{
    vector<int> tree = {10,20,50,-1,60,-1,70,-1,-1,30,80,120,-1,-1,-1,40,90,-1,100,-1,110,-1,-1};

    TreeNode* root = create_GTree(tree);
     
    cout<<"\nEnter the target node for which you want to find its Predecessor and Successor : ";
    int tnode;
    cin>>tnode;

    bool is_found = false;

    dfs(root,tnode,is_found);
    
    cout<<"\nPreorder Predecessor of target node "<<tnode<<" : ";
    Predecessor == NULL ? cout<<"NULL" : cout<<Predecessor->data;
    cout<<endl;

    cout<<"Preorder Successor of target node "<<tnode<<" : ";
    Successor == NULL ? cout<<"NULL" : cout<<Successor->data;
    cout<<endl;
}

 

