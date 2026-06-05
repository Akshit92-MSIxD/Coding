// https://www.geeksforgeeks.org/problems/children-sum-parent/1


/*
class Node{
    int data;
    Node left,right;

    Node(int key)
    {
        data = key;
        left = right = null;
    }
}
*/

// Approach : Normal DFS + Basic Logic
// TC : O(n)
// SC : O(n) [recursive stack space i.e height of the  binary tree in case degenrate binary tree]

class Solution {
    public boolean isSumProperty(Node root) {
         
         if(root == null || root.left == null && root.right == null)
         return true;
         
         if(!isSumProperty(root.left))
         return false;
         
         if(!isSumProperty(root.right))
         return false;
         
         
         if(root.left == null)
             return root.data == root.right.data;
         else if(root.right == null)
             return root.data == root.left.data;
             
         
         return root.data == root.left.data + root.right.data;
        
    }
}