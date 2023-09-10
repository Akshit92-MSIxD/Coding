// https://leetcode.com/problems/diameter-of-binary-tree/( Diameter of Binary Tree)

// Diameter of a Tree : Maximum no. of edges between any two nodes in the given tree !!! 
// *** Those two nodes can be either "two leaf nodes" or "one root node and one leaf node" !!!
// Hint : related with maxDepth of tree !!!

#include <iostream>
#include<stack>
#include <vector>
#include <climits>
using namespace std;

class TreeNode{

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
          if(v[i] != -1 )
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


int getMaxDepth(TreeNode* root , int &maxDistance)
{

 
   if(root->children.size() == 0)
    return 0;

   if(root->children.size() == 1)
   {
       int maxDepth = getMaxDepth(root->children[0],maxDistance);

       if(maxDepth + 1 > maxDistance)
        maxDistance = maxDepth + 1;

       return maxDepth + 1;
   }
   

   int maxDepth = INT_MIN;
   int second_maxDepth = INT_MIN;

   for(TreeNode* child : root->children)
   {
       int childMaxDepth = getMaxDepth(child,maxDistance);

       if(childMaxDepth > maxDepth)
       {
        second_maxDepth = maxDepth;
        maxDepth = childMaxDepth;
       }
       else if(childMaxDepth > second_maxDepth)
       {
          second_maxDepth = childMaxDepth;
       }

   }

    int distance = maxDepth + 1 + second_maxDepth + 1;

    if(distance > maxDistance)
    maxDistance = distance;


    return maxDepth + 1;

}



int main()
{

  vector<int> tree =  {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1};

  TreeNode* root = create_GTree(tree);

  int  maxDistance = INT_MIN;

  int  maxDepth = getMaxDepth(root,maxDistance);

  cout<<"\n\nMax distance between any two node in a tree : "<<maxDistance;


}









