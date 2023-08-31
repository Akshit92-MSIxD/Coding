// Prerequisite : 12_Find-an-element-in-Generic-Tree :)

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

// Prerequisite : 12_Find-an-element-in-Generic-Tree :)
// TC : O(n) , SC : O(n) [recursive stack space when H = n , where n is total no. of nodes in a GTree]
// Pura Euler Nahi Chalega (Jese hi val mil jaega sidha ghar-ki-taraf(root) bhagega :) )
vector<int>  get_node_to_root(TreeNode* root  , int val)
{
   
   if(root->data == val)
   {
      return {root->data};
   }

   for(TreeNode* child : root->children)
   {
       vector<int> path = get_node_to_root(child,val);

       if(path.size() >=1)
       {
         path.push_back(root->data);
          return path;
       }

   }

   return {};

}


int main()
{
    vector<int> tree = {10,20,50,-1,60,-1,70,-1,-1,30,80,120,-1,-1,-1,40,90,-1,100,-1,110,-1,-1};

    TreeNode* root = create_GTree(tree);

    cout<<"Enter the val : ";
    int val;
    cin>>val;

    vector<int> path = get_node_to_root(root,val);
     
     if(path.size() == 0)
     {
        cout<<"Target Node is not present in the tree!!!";
        return 0
        ;
     }
     cout<<"Node to root path : ";
      
     for(int node : path)
     {
        cout<<node<<"->";
     }
}

 

