
// We can also say that construct a CBT from the level order traversal sequence !!! 

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode{

public :

int val;
TreeNode *leftChild , *rightChild;

 TreeNode()
 {
    val = 0;
    leftChild = NULL;
    rightChild = NULL;
 }

 TreeNode(int val)
 {
    this->val = val;
    leftChild = NULL;
    rightChild = NULL;
 }

 TreeNode(int val , int leftChildVal , int rightChildVal)
 {
    this->val = val;
    leftChild = new TreeNode(leftChildVal);
    rightChild = new TreeNode(rightChildVal);
 }

};

void bfs(TreeNode* root)
{
    
    queue<TreeNode*> q;
    q.push(root);


    while(!q.empty())
    {
       
      TreeNode* Node = q.front();
      q.pop();

      cout<<Node->val<<" ";

      if(Node->leftChild)
      q.push(Node->leftChild);

      if(Node->rightChild)
      q.push(Node->rightChild);

    }

    return;

}

// TC = O(n) , where n is the no. of elements in the array
// SC = O(logn) [recursive stack space] + O(n) [ extra space taken n nodes]
TreeNode* constructCBT(vector<int> &nums , int si , int ei)
{

    if(si > ei)
    return NULL;
               
     TreeNode* root = new TreeNode(nums[si]);
     root->leftChild = constructCBT(nums,2*si + 1,ei);
     root->rightChild = constructCBT(nums,2*si + 2,ei);

     return root;

}


int main(){


vector<int> nums = {3,9,2,1,4,5,6,7};

TreeNode* root = constructCBT(nums,0,nums.size()-1);

  bfs(root);
}