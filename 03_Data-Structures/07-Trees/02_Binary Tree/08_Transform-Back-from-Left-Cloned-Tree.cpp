// In this problem we are told to tranform back a left cloned tree to its non cloned state
// https://www.youtube.com/watch?v=YCd-jyAF0CM [Watch this problem statement video by sumeet sir!!!]

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


// Note : We can also do this problem using expectation-faith technique !!! [ both with or without return type :)]

// TC : O(n) , SC : O(H)
void transformBack(TreeNode* root)
{
     if(root == NULL)
     return;
     
     TreeNode* leftleftChild = root->left->left;
     delete root->left;
     root->left = leftleftChild;

     transformBack(root->left);
     transformBack(root->right);
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
    vector<int> tree = {10,10,20,20,NULL,NULL,NULL,NULL,30,30,NULL,NULL,NULL}; // tree in form of preorder sequence :)

    TreeNode* root = create_BTree(tree);

    transformBack(root);

    displayPreorder(root);

    return 0;

}