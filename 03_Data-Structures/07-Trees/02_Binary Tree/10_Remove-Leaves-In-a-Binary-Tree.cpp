// Hint : Think about DFS preorder || DFS postorder to remove leaves and decide which one is correct for this problem :)
// Note : I have written comments ans approach for this problem below . Please read it :)

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
        this->left = NULL;
        this->right = NULL;
    }

    TreeNode(int data,TreeNode *left , TreeNode* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};




TreeNode* create_BTree(vector<int> &v)
{
     TreeNode* root = new TreeNode(v[0]);

     stack<pair<TreeNode*,int>> s;   // node and its state (state = 1 ==> first children daalo , state = 2 ==> second children daalo)

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
                    s.top().second+=1;  // increasing the state from 1 to 2
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
                    s.top().second+=1;
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

// DFS Preorder Approach [When we do preorder traversal then only legit leave nodes are deleted :)]
// TC : O(n) , SC : O(H)
// If we use DFS postorder for this problem whole binary tree will get deleted :(
TreeNode* removeLeaves(TreeNode* root)
{
    if(root == NULL)
    return NULL;

   if(root->left == NULL && root->right == NULL) // If current node is a leave node then delete it and return NULL
   {
    delete root;
    return NULL;
   }

   root->left = removeLeaves(root->left); // updating the root's left pointer (pointer can be updated with NULL or node_address)
   root->right = removeLeaves(root->right); // updating the root's right pointer  (pointer can be updated with NULL or node_address)

   return root;

}



void displayPreorder(TreeNode* root)
{
    if(root == NULL)
    {
        cout<<"NULL ";
        return;
    }

    cout<<root->data<<" ";
    displayPreorder(root->left);
    displayPreorder(root->right);
}

int main()
{
    vector<int> tree = {50,25,12,NULL,NULL,37,30,NULL,NULL,NULL,75,62,NULL,70,NULL,NULL,87,NULL,NULL}; // tree in form of preorder sequence :)

    TreeNode* root = create_BTree(tree);

    root = removeLeaves(root);

    displayPreorder(root);

    return 0;

}