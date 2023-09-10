// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/ (Flatten Binary Tree to Linked List Leetcode !!!)


// Note : I have written two Linearize_GTree() functions for this problem !!!(Dono dekh lena niche!!!)

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
     TreeNode* root = new TreeNode(v[0]);

     stack<TreeNode*> s;

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



// Recursive DFS(Postorder) TC : O(n^2)
// // Note : We are traversing from rightmost child to the leftmost child here!!!! :)
// Convert the Gtree into a LinkedList of Preorder Sequence :)
// SC : O(n) [recursive stack space if H = n , where n is the total no. of nodes in a tree]
void Linearize_GTree(TreeNode* root)
{    
    // faith that childrens of root node will get flatten

    for(TreeNode* child : root->children)
    {
          Linearize_GTree(child); 
    }

    // break the links between root-node(parent) and child-nodes one by one and join the tail of second-last-children flatten list to the head of last-children flatten list one by one :)
    while(root->children.size() > 1)
    {
       TreeNode* lc = root->children.back(); // last child (Remember it is a complete sub flatten list!!! )
       root->children.pop_back(); // break the link of last child with the root node(parent)
       TreeNode* sc = root->children.back(); // second last child (Remember it is a complete sub flatten list!!! )
       
       TreeNode* tail = sc;

       while(tail->children.size() == 1)
       {
         tail = tail->children[0];
       }

       tail->children.push_back(lc);
    }

    return;
}


// // Recursive DFS(Postorder) TC : O(n)
// // Note : We are traversing from rightmost child to the leftmost child here!!!! :)
// // Convert the Gtree into a LinkedList of Preorder Sequence and return the tail of LinkedList :)
//  SC : O(n) [recursive stack space if H = n , where n is the total no. of nodes in a tree]
// TreeNode* Linearize_GTree(TreeNode* root)
// { 
//   if(root->children.size() == 0)
//   return root;
        
      // Note : tail of entire linearized tree = tail of Linearized last child subtree
//    TreeNode* tail_lc = Linearize_GTree(root->children.back()); // Linaerize the last child subtree + return the tail of that linearized last child subtree :) 

//    while(root->children.size()>1)
//    {
//       TreeNode* lc = root->children.back();
//        root->children.pop_back();
//       TreeNode* sc = root->children.back();
//       TreeNode* tail_sc = Linearize_GTree(sc);

//       tail_sc->children.push_back(lc);
//    }

//     return tail_lc;
// }




int main()
{
    vector<int> tree = {10,20,50,-1,60,-1,70,-1,-1,30,80,120,-1,-1,-1,40,90,-1,100,-1,110,-1,-1};

    TreeNode* root = create_GTree(tree);
    Linearize_GTree(root);


    // print the flatten linkedlist 
    cout<<"Flatten List : ";
    while(root->children.size()==1)
    {
       cout<<root->data<<"-->";
       
       root = root->children[0];
    }
    cout<<root->data;



}