// Please refer to this GFG article for better understanding : https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/


// In this problem we will learn about DFS Traversal Techniques for Trees [DFS is a recursive algorithm that uses backtracking :)]

// DFS traversal techniques - Preorder Traversal and Postorder Traversal [Note : Inorder Traversal only valid for for BT :)]

/* Preorder Technique :-

  -- Root is visited/printed first then childrens are visited/printed
  -- "Pre" means "Before call" i.e  while going deep in recursion!!!
  -- To get Pretorder for given tree ==> Print nodes only when going from node's left side in Euler Path
  
*/

/* Postorder Technique :-

  -- Root is visited/printed last and its childrens are visited/printed first
  -- "Post" means "After call" !!! while coming out of recursion :)
  -- To get Postorder for given tree ==> Print nodes only when going from node's right side in Euler Path

*/

#include <iostream>
#include <vector>
#include <stack>
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
     TreeNode* root =  new TreeNode(v[0]);

     s.push(root);

    for(int i=1;i<v.size();i++)
    {
        if(v[i]!=-1)
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


void traversal(TreeNode* root)
{
    if(root == NULL)
    return;
          
     cout<<"Node Pre "<<root->data<<endl;   // Pre/Before call + Preorder print :)
    
    for(int i=0;i<root->children.size();i++)
    {
        cout<<"Edge Pre "<<root->data<<" - "<<root->children[i]->data<<endl;  // edge meaning call , Pre egde ==> Pre call(will print the edge)
        traversal(root->children[i]);
        cout<<"Edge Post "<<root->data<<" - "<<root->children[i]->data<<endl; // Post egde ==> Post call(will print the edge)
        
    }

    cout<<"Node Post "<<root->data<<endl;  // Post/After Call +  Postorder print :)
}

int main()
{
    vector<int> tree = {10,20,-1,30,50,-1,60,-1,-1,40,-1};

    TreeNode* root = create_GTree(tree);

    traversal(root);
}