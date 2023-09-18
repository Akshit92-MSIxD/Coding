// In this problem we are told to add a clone node in a tree for each individual node and that clone node must be placed on the left side of individual node :)
// https://www.youtube.com/watch?v=jEYKDu4iyik [Watch this problem statement video by sumeet sir!!!]

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
void transformToLeftClone(TreeNode* root)
{
     if(root == NULL)
     return;
      
    TreeNode* actual_leftChildren = root->left;
    TreeNode* cloneNode = new TreeNode(root->data);
    root->left = cloneNode;
    cloneNode->left = actual_leftChildren;

    transformToLeftClone(actual_leftChildren);
    transformToLeftClone(root->right);
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
    vector<int> tree = {10,20,NULL,NULL,30,NULL,NULL}; // tree in form of preorder sequence :)

    TreeNode* root = create_BTree(tree);

    transformToLeftClone(root);

    displayPreorder(root);

    return 0;

}