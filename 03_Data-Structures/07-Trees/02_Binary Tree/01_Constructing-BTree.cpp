// In this we will see how to construct a binary tree from a given input(in form of preorder traversal)

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

int main()
{
    vector<int> tree = {50,25,12,NULL,NULL,37,30,NULL,NULL,NULL,75,62,NULL,70,87,NULL,NULL}; // tree in form of preorder sequence :)

    TreeNode* root = create_BTree(tree);

}