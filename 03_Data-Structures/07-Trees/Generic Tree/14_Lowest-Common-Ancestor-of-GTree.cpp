// Note : I have written two functions for this problems one is brute force and another one is optimal one  bewlow :)
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/ (Lowest Common Ancestor of a Binary Tree Leetcode)

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



vector<int> getRootToNodePath(TreeNode* root , int &p)
{
          
  if(root->data == p)
   return {p};


   for(TreeNode* child : root->children)
   {
     vector<int> path = getRootToNodePath(child,p);

     if(path.size()>=1)
     {
        path.insert(path.begin(),root->data);
        return path;
     }
   }

   return {};

}


// Brute Force (by finding the NodeToRoot path :))
// Prerequisite : Node to Root Path / Root to Node Path :)
// TC : O(n) , SC : O(H) + extra space(for storing paths) [where n is the total no. of nodes in a Tree , H is the height of the Tree]
int getLCA(TreeNode* root , int &p , int &q)
{
    vector<int> path_p = getRootToNodePath(root,p);
    vector<int> path_q = getRootToNodePath(root,q);

    int c1 = 0 , c2 = 0;
    int lca;

    while(c1<path_p.size() && c2<path_q.size())
    {
         if(path_p[c1] == path_q[c2])
         {
            lca = path_p[c1];
            c1++;
            c2++;
            continue;
         }

         break;
         
    }

    return lca;
}



// // Optimal Solution
//  // Note : Assume A node can be a LCA of itself :)
//  // Hint : Apply DFS and if in midway from one of the nodes from p or q is found return it to its parent(root) and traverse to the remaining right subtrees of root [Baaki ka khud soch :)]
// // TC : O(n) , SC : O(H) [where n is the total no. of nodes in a Tree , H is the height of the Tree]
// int getLCA(TreeNode* root,int p , int q)
// {

//   if(root->data == p || root->data == q)  // Note : a node can be a LCA of itself
//   return root->data;

//   vector<int> anc;  // O(1) constant space i.e anc vector containing 2 values at maximum :)
//   for(TreeNode* child : root->children)
//   {
//       int lca = getLCA(child,p,q);

//       if(lca != INT_MIN)
//       {
//          anc.push_back(lca);
//       }

//   }

//   if(anc.size() == 2)  
//   return root->data;
  
//   if(anc.size() == 1)
//   return anc[0];

//   return INT_MIN;// if no lca is found in current root tree !!!

// }



int main()
{
    vector<int> tree = {10,20,50,-1,60,-1,70,-1,-1,30,80,120,-1,-1,-1,40,90,-1,100,-1,110,-1,-1};

    TreeNode* root = create_GTree(tree);

    cout<<"Enter the value of p and q (consider that both values exist in the above tree!!!) : ";
    int p,q;
    cin>>p>>q;

    int lca = getLCA(root,p,q);

    cout<<"Lowest common ancestor of node : "<<p<<" and node "<<q<<" is : "<<lca;
}

 

