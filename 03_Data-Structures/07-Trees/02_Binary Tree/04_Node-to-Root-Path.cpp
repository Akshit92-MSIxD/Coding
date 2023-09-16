// Note : I have written two functions/approaches for this problem below . Please read both from top to bottom for better understanding :)

#include <iostream>
#include <stack>
#include <vector>
using namespace std;


class TreeNode
{
   public :

  int data;

  TreeNode* left;
  TreeNode* right;

  TreeNode(int data)
  {
    this->data = data;
    left = NULL;
    right = NULL;
  }


};



TreeNode* create_BTree(vector<int> &v)
{
      stack<pair<TreeNode*,int>> s;

      TreeNode* root = new TreeNode(v[0]);

      s.push({root,1});

      for(int i=1;i<v.size();i++)
      {
          TreeNode* topNode = s.top().first;
          int state = s.top().second;

           if(v[i] != NULL)
           {
                TreeNode* newnode = new TreeNode(v[i]);

                if(state == 1)
                {
                    topNode->left = newnode;
                    s.top().second +=1;
                    s.push({newnode,1});
                }
                else if(state == 2)
                {
                    topNode->right = newnode;
                    s.pop();
                    s.push({newnode,1});
                }
           }
           else
           {
                if(state == 1)
                {
                    topNode->left = NULL;
                    s.top().second +=1;
                }
                else if(state == 2)
                {
                    topNode->right = NULL;
                    s.pop();
                }
           }
    
      }
      return root;

}

// Approach 1 
// Travel and Return Stratergy / Expectation-Faith Stratergy :) [ But not better than Travel and Update Stratergy!!! :)]
// TC : O(n)
// AS : O(H) [recursive stack space]
vector<int> getNodeToRootPath(TreeNode* root , int &tnode)
{
     if(root == NULL)
     return {};

     if(root->data == tnode)
      return {tnode};

     vector<int>  lpath = getNodeToRootPath(root->left,tnode);

     if(lpath.size() != 0)
     {
        lpath.push_back(root->data);
        return lpath;
     }

     vector<int> rpath = getNodeToRootPath(root->right,tnode);

     if(rpath.size() != 0)
     {
        rpath.push_back(root->data);
        return rpath;
     }

     return {};
}



// Approach 2 
// Travel and Update Stratergy :) 
// Pura Euler Nahi Chalega (Jese hi val mil jaega sidha ghar-ki-taraf(root) bhagega :) )
// TC : O(n)
// AS : O(H) [recursive stack space] 

// bool  NodeToRootPath(TreeNode* root , int tnode , vector<int> &path)
// {
        
//         if(root == NULL)
//         return false;

//         if(root->data == tnode)
//         {
//           path.push_back(root->data);
//           return true;
//         }


//         bool l = NodeToRootPath(root->left,tnode,path);

//         if(l == true)
//         {
//           path.push_back(root->data);
//           return true;
//         }

//         bool r = NodeToRootPath(root->right,tnode,path);

//         if(r == true)
//         {
//           path.push_back(root->data);
//           return true;
//         }


//         return true;
// }


int main()
{

 vector<int> tree = {50,25,12,NULL,NULL,37,30,NULL,NULL,NULL,75,62,NULL,70,NULL,NULL,87,NULL,NULL}; // tree in form of preorder sequence :)

 TreeNode* root = create_BTree(tree);

 int tnode;
 cout<<"Enter the target node : ";
 cin>>tnode;

 vector<int> ntrp = getNodeToRootPath(root,tnode);

 if(ntrp.size() == 0)
 {
    cout<<"Target Node is not present in the tree!!!";
    return 0;
 }

 cout<<"\nTarget Node to Root Path : ";

  for(int node : ntrp)
  {
    cout<<node<<"->";
  }

 return 0;

}