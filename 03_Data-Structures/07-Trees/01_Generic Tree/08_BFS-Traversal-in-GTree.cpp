// Please refer to this GFG article for better understanding : https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/

// BFS traversal is also known as Level Order Traversal (level by level nodes traversal from L->R) :)

// BFS/level order traversal is related with queue :)

// https://leetcode.com/problems/n-ary-tree-level-order-traversal/ (N-ary Tree Level Order Traversal Leetcode!!!)
// https://leetcode.com/problems/binary-tree-level-order-traversal/ (Binary Tree Level Order Traversal Leetcode!!!)
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/ (Binary Tree Zig Zag Level Order Traversal Leetcode!!!)


#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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
     TreeNode* root =  new TreeNode(v[0]);

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


// Iterative BFS traversal  [Note : Recursive BFS traversal technique left!!!]
void bfs_traversal(TreeNode* root)
{
    
    cout<<"BFS traversal : ";

    queue<TreeNode*> q;
    q.push(root);

// Remove Node -> Print Node -> Add children to/from queue  until it is empty :)
    while(!q.empty())
    {
        TreeNode* front = q.front();
        q.pop();

        cout<<front->data<<" ";

        for(TreeNode* child : front->children)
        {
            q.push(child);
        }
    }

    return;

}




int main()
{
    vector<int> tree = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1};  // tree provided in preorder form

    TreeNode* root = create_GTree(tree);

    bfs_traversal(root);
}