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

// TC : O(n) , SC : O(n) [recursive stack space when H = n , where n is total no. of nodes in a GTree]
// Pura Euler Nahi Chalega (Jese hi val mil jaega sidha ghar-ki-taraf(root) bhagega :) )
bool  find(TreeNode* root  , int val)
{
    if(root->data == val)
    return true;


    bool ans = false;

    for(TreeNode* child : root->children)
    {
        bool exist = find(child,val);

        if(exist == true)
        {
            ans = true;
            break;
        }
    }

    return ans;
}


int main()
{
    vector<int> tree = {10,20,50,-1,60,-1,70,-1,-1,30,80,120,-1,-1,-1,40,90,-1,100,-1,110,-1,-1};

    TreeNode* root = create_GTree(tree);

    cout<<"Enter the val : ";
    int val;
    cin>>val;

    bool exist = find(root,val);

    if(!exist)
    {
        cout<<" Value : "<<val<<" is not present inside the tree!!!";
    }
    else
    {
           cout<<" Value : "<<val<<" is present inside the tree!!!";
    }

}

 

