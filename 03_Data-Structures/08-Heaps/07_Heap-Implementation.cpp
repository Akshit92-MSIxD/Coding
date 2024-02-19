
 // A heap is generally a CBT follows some special properties represented/implemented using an array/vector in code !!!
// It is of two types : Max-Heap : LeftChild <= Parent >= RightChild  , Min-Heap : LeftChild >= Parent <= RightChild
// Max-Heap gives max element , Min-Heap gives min element among n nodes present in the heap in O(1) time!!!
// Insertion and Deletion in Heap --> O(logn) TC , Looking for max/min element in heap --> O(1) TC

// It is generally implemented using array (because array is best for its implementation!!!)


#include <iostream>
using namespace std;


class Heap   // this is max-heap
{
   int* arr;
   int capacity; // max. possible size of this max-heap
   int size;

 public :

  Heap(int capacity){
    this->capacity = capacity;
    this->size = 0;
    this->arr = new int[capacity];
  }

 void heapify(int i)  // Down heapify the node present at index = i in the heap !!!
 {

     int leftChildIndex = 2*i + 1;
     int rightChildIndex = 2*i + 2;
     int largest = i;


     if(leftChildIndex <= (size - 1) &&  arr[leftChildIndex] > arr[largest])
      largest = leftChildIndex;

     if(rightChildIndex <= (size - 1) &&  arr[rightChildIndex] > arr[largest])
      largest = rightChildIndex;


      if(largest != i)
      {
        swap(arr[i],arr[largest]);
        heapify(largest); // recursively heapify the affected subtree also
      }

 }



 void insertKey(int key){
            
            if(size == capacity)
            {
                cout<<"Heap Overflow i.e heap is full , You can't insert key anymore!!! ";
                return;
            }

            size++;
            int last_index = size - 1;
            arr[last_index] = key;   // place the key at the last index of the heap !!! 


          // Then adjust its(key) position by comparing it with its parent node until this key reaches the root position or its parent becomes greater than it(key)
            for(int i=last_index;i>0;i = (i-1)/2)   // this is upheapify() means uppar ki taraf heapify kro !!!
            {
                int parent = arr[(i-1)/2]; // since for index i , its parent is at index (i-1)/2 !!!

                if(arr[i] <= parent)
                return;
                
                swap(arr[i],arr[(i-1)/2]);   // swap arr[i] with its parent
            }

            return;
 }



 void deleteKey(int i){        // delete the node present at index = i in the heap !!!

     if(size == 0)
     {
        cout<<"Heap Underflow i.e heap is empty!!!";
        return;
     }

     if(i > size - 1)
     {
      cout<<"Invalid index!!!";
     }

     int last_index = size - 1;
     arr[i] = arr[last_index];   // replace the node at index i with the last node !!!
     size--; // // delete the last node from the heap !!!

     heapify(i); // heapify for node at index = i !!! 
 }



 int getMaxKey()
 {
     if(size == 0)
     {
        cout<<"Heap Underflow i.e heap is empty!!!";
        return 0;
     }

     return arr[0];
 }



 int extractMaxkey()   // that means return and delete the max-key or max-element present in the heap simultaneously !!!
 {
    if(size == 0)
     {
        cout<<"Heap Underflow i.e heap is empty!!!";
        return 0;
     } 

     int maxKey = arr[0];
       
     int last_index = size - 1;
     arr[0] = arr[last_index];  // replace the root node of heap with the last node in the heap !!!
     size--;  // delete the last node from the heap !!!

     heapify(0);  // then heapify the tree for root node with index = 0 !!!

     return maxKey;
 }



 void display()
 {
     cout<<"Heap : ";

     for(int i=0;i<size;i++)
     {
      cout<<arr[i]<<" ";
     }
 }


};


int main()
{
      
      Heap h1(10);

      h1.insertKey(3);
      h1.insertKey(9);
      h1.insertKey(7);
      h1.insertKey(10);
      h1.insertKey(4);
      h1.insertKey(6);
      h1.insertKey(5);
      h1.insertKey(11);
      h1.insertKey(8);
      h1.insertKey(9);

      // h1.display();
      // cout<<endl;

      // cout<<"Extracted : "<<h1.extractMaxkey()<<endl;
      // cout<<"Extracted : "<<h1.extractMaxkey()<<endl;

      h1.display();
      cout<<endl;
      h1.deleteKey(2);
      h1.display();



        
}