// Approaches left :  Iterative DFS traversal, Recursive BFS traversal , Iterative BFS traversal !!!!

#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

class TreeNode
{
 
 public :

 int data;

 vector<TreeNode*> children;

 TreeNode()
 {
    data = 0;
 }

 TreeNode(int data)
 {
    this->data = data;
 }


};


TreeNode* create_GTree(vector<int> &v)  // TC : O(n) , where n is the no. of nodes in the GTree :)
{
    stack<TreeNode*> s;
    TreeNode* root = new TreeNode(v[0]);
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

        s.pop();      // backtrack to one level up to the parent node if -1 is encountered :)
    }

    s.pop(); // poping the last node(address) present in the stack i.e root;

    return root;

}




// Recursive DFS traversal technique to find max node in tree :)   [Note : We can also find max using iterative DFS traveral technique by using stack]

int  get_max(TreeNode* root) // TC depends on type of the tree :) 
{
    if(root->children.size() == 0)
    {
        return root->data;
    }
     

     int  max = INT_MIN;

     for(int i=0;i<root->children.size();i++) // faith on sub branches that they will return their individual max :)
     {
        int temp_max = get_max(root->children[i]);

        if(temp_max > max)
        max = temp_max;
     }

     if(root->data > max)
     max = root->data;

     return max;
}


int main()
{

 vector<int> tree =  {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1}; // tree provided in preorder form

 TreeNode* root = create_GTree(tree);
  
 cout<<"Max node in a tree : "<<get_max(root);




}