
// Ceil : Just Greater (Smaller among all the greater numbers for a given number) 
// Floor : Just Smaller (Larger among all the greater numbers for a given number) 

// Note : Niche wali BST wali problems tab hi dekhna jab tu Generic tree wali krlega revise !!! :)
// Ceil in BST : [https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1]
// Floor in BST : [https://practice.geeksforgeeks.org/problems/floor-in-bst/1]

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


// Recursive DFS (Preorder) [Travel and update stratergy :)]
// TC = O(n) , SC : O(H)
// This problem can also bve solved usinf BFS (bus thoda sa modify krna hai :) )
void dfs(TreeNode* root , int &num , int &ceil , int &floor)
{
       if(root->data > num)
       {
            if(root->data < ceil)
            ceil = root->data;
       }

       if(root->data < num)
       {
          if(root->data > floor)
          floor = root->data;
       }

       if(root->children.size() == 0)
       return;

       for(TreeNode* child : root->children)
       {
          dfs(child,num,ceil,floor);
       }

}



int main()
{

  vector<int> tree = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1};

  TreeNode* root = create_GTree(tree);

  int ceil = INT_MAX , floor = INT_MIN;  // Note if from the given ceil/floor is not found then ceil/floor will be -+infinity :)
  int num;

  cout<<"Enter the number : ";
  cin>>num;

  dfs(root,num,ceil,floor);

  cout<<"\nCeil of "<<num<<" : ";
  ceil == INT_MAX ? cout<<"+infinity" : cout<<ceil;

  cout<<"\nFloor of "<<num<<" : ";
  floor == INT_MIN ? cout<<"-infinity" : cout<<floor;
  cout<<endl<<endl;





}









