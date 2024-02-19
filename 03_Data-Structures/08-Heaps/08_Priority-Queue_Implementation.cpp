
// We can implement priority Queue using normal array , linkedlist list and heap(array)

/*   By using Array/Vector:

   -- if you make TC of push() as O(1) , then TC for both pop() and top() is O(n)
   -- if you make TC of push() as O(n) , then TC for both pop() and top() is O(1)  */


/*   By using LinkedList :

   -- if you make TC of push() as O(1) , then TC for both pop() and top() is O(n)
   -- if you make TC of push() as O(n) , then TC for both pop() and top() is O(1)  */


/*   By using Heap(in form of array/vector) :

    -- TC for push() and pop() is O(logn) and top() is O(1)
                                                                   */


// So from the above implementations we can see Priority queue must be implemented using heaps for better TC !!!

 

 // Priority Queue Implementation using max-heap !!! [that means priority will be given to the maximum number first in the PQ !!!]
 // **** PREREQUISITE : 07_Heap-Implementation.cpp
 
#include <iostream>
using namespace std;


class Priority_Queue   // using max-heap
{

 int size;
 int capacity;
 int *heap_arr;


 public :

 Priority_Queue(int capacity)
 {
      size = 0;
      this->capacity = capacity;
      heap_arr = new int[capacity];
 }



 void heapify(int i)
 {
      int leftChildIndex = 2*i + 1;
      int rightChildIndex = 2*i + 2;
      int largest = i;

      if(leftChildIndex <= size - 1 && heap_arr[leftChildIndex] > heap_arr[largest])
      largest = leftChildIndex;

      if(rightChildIndex <= size - 1 && heap_arr[rightChildIndex] > heap_arr[largest])
      largest = rightChildIndex;

      if(largest != i)
      {
        swap(heap_arr[i],heap_arr[largest]);
        heapify(largest);
      }
 }



 void push(int key)
 {
     if(size == capacity)
     {
        cout<<" Priority Queue is full !!! , couldn't push key!!!";
        return;
     }

     size++;
     int last_index = size - 1;
     heap_arr[last_index] = key;


     for(int i=last_index;i>0;i=(i-1)/2)
     {
        int parent = heap_arr[(i-1)/2];

        if(heap_arr[i] <= parent)
        return;

        swap(heap_arr[i],heap_arr[(i-1)/2]);
     }

     return;

 }

 void pop()
 {
       if(size == 0)
       {
          cout<<"Priority Queue is empty!!! , could not pop!!!";
       }
       
       int last_index = size - 1;
       heap_arr[0] = heap_arr[last_index];
       size--;

       heapify(0);
 }



 int top()
 {
        if(size == 0)
       {
          cout<<"Priority Queue is empty!!!;";
          return 0;
       } 

       return heap_arr[0];
 }



 void display()
 {
    cout<<"Priority Queue : ";

    for(int i=0;i<size;i++)
    {
        cout<<heap_arr[i]<<" ";
    }

 }

};


int main(){

   Priority_Queue pq(10);

      pq.push(3);
      pq.push(9);
      pq.push(7);
      pq.push(10);
      pq.push(4);
      pq.push(6);
      pq.push(5);
      pq.push(11);
      pq.push(8);
      pq.push(9);

      cout<<"\nMax element : "<<pq.top()<<endl;
      pq.display();

      pq.pop();

      cout<<"\n After Popping 11 :";
       cout<<"\nMax element : "<<pq.top()<<endl;
      pq.display();

}








