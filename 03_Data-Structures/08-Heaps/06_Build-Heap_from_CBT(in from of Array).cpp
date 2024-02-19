
// ***NOTE : PLEASE READ ALL THE COMMENTS WRITTEN IN THIS PROBLEM (EVERYTIME YOU ARRIVE AT THIS PROGRAM!!!!)

// A heap is generally a CBT follows some special properties represented/implemented using an array/vector in code !!!
// It is of two types : Max-Heap : LeftChild <= Parent >= RightChild  , Min-Heap : LeftChild >= Parent <= RightChild
// Max-Heap gives max element , Min-Heap gives min element among n nodes present in the heap in O(1) time!!!
// In this problem we just have to build a heap(max-heap) by converting the given cbtree(array) to max-heap(array) [in-place!!! i.e without using any extra space] 


#include <iostream>
#include <vector>
using namespace std;


// Note : To 'heapify a node' means to reorder the nodes of a tree starting from that node (as a root) to restore/maintain heap properties !!!
// Note : Reordering the nodes is done by comparing a node with its left and right child nodes
// Note*** : To heapify a particular node , make sure its left and right subtree must be a heap , otherwise heapify will not work for that node :(

void heapify(vector<int> &cbtree , int i)  // max-heapify()
{
    int n = cbtree.size();

   int ilc = 2*i + 1; // index i's left child index
   int irc = 2*i + 2; // index i's right child index

   int largest = i;

   if(ilc < n && cbtree[ilc] > cbtree[i])   // if left child node is greater than parent node
   largest = ilc;
   
   if(irc < n && cbtree[irc] > cbtree[i]) // if right child node is greater than parent node
   largest = irc;

   if(largest != i)
   {
    swap(cbtree[i],cbtree[largest]);  // swap the parent node with with its largest child node
    heapify(cbtree,largest); // recursively heapify the affected subtree also
   }

}



// Start by calling heapify(reordering) only for the internal nodes(non-leaf nodes) in reverse order(bottom to top in a tree)!!! [Reason ==> Because each individual leaf node is already a heap in itself, there's no need to heapify those nodes + heapifying each internal node in reverse order(bottom to top in a tree) will maintain the important property for heapifying i.e Note***(heapify() func ke uppar dekh) :) )  ]
// ( 0 ---> (n/2) - 1 ) ==> Internal Nodes indexes in a cbtree  [ Since there are always n/2 internal nodes in a CBT , you can check by making a random CBT on paper :)]
// ( (n/2) ---> n-1 ) ==> Leaf Nodes indexes in a cbtree 
// Note : In a Complete Binary Tree , " no. of leaf nodes = no. of internal nodes + 1 "
// TC = O(n) [How ???] ===> (((n/2^2) +1)* 1) + (((n/2^3) +1)* 2) + (((n/2^4) +1)* 3) + (((n/2^5) +1)* 4) +......................+ (1) * logn
// *****Here in TC expression , every individual term  represent --> (no._of_nodes_in_that_level) * (work_done_by_indi_node_in_that_level or height_of_nodes_present_at_that_level) [since we know that heapify() takes O(height of node) TC for heapifying that node situated at height h]
// AS = O(1)

void buildHeap(vector<int> &cbtree)
{   
 
  int n = cbtree.size();

  // heapify each internal node in cbtree(array) in reverse order i.e ( (n/2) - 1 ---> 0) [these are the indexes of internal nodes in a cbtree(array)]
     
  for(int i = n/2 - 1 ; i>=0 ; i--)
  {
    heapify(cbtree,i);
  }

}

void printHeap(vector<int> heap)
{
    cout<<"Heap Tree : ";
    for(int i=0;i<heap.size();i++)
    {
        cout<<heap[i]<<" ";
    }
}


int main(){

 vector<int> cbtree = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};  // After the ordinary cbtree becomes heap(max-heap) , then representation --> {17,15,13,9,6,5,10,4,8,3,1}
 
 buildHeap(cbtree);

 printHeap(cbtree);

}