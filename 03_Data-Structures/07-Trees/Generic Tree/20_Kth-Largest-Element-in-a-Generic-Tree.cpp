// https://leetcode.com/problems/kth-smallest-element-in-a-bst/?envType=list&envId=r62yz9dt (kth smallest element in BST)
// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1 (kth largest element in BST)

// Approach 1 : Create a vector and store a preorder traversal path of nodes in it ==> then sort the vector and find the kth largest :)

/* Approach 2 : Find the floor of infinity => 1th largest number => find floor of 1th largest number => 2th largest number => ......so on [Do this activity k times you will get the kth largest number :)] 
  Note : This approach will use  Find_Floor() multiple times so TC bohot hojaegi dhayan rakhna :)
  {Prerequisite : Find Floor of a given number in a generic tree}  */

// Approach 3 : Using priority queue {Prerequisite : kth largest in a array/vector}

