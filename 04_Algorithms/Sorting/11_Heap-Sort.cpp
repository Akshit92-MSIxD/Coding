// PREREQUISITE :  buildHeap() and heapify() !!! 
// For getting array sorted in ascending order --> use Max-Heap
// For getting array sorted in descending order --> use Min-Heap
// TC for Heap Sort : O(n) [for building heap from normal array] + O(nlogn) [for sorting the heap] ====> O(nlogn) 
// Note : Quick Sort also has O(nlogn) TC (except the worst case) but still it is faster than Heap sort because no. of operations in heap sort are slightly more than the operations in quick sort !!!

#include <iostream>
#include <vector>
using namespace std;


void heapify(vector<int> &arr , int i , int n)
{
    int left = 2*i + 1;
    int right = 2*i + 2;
    int largest = i;

    if(left <= n - 1 && arr[left] > arr[largest])
    largest = left;

    if(right <= n-1 && arr[right] > arr[largest])
    largest = right;

    if(largest != i)
    {
        swap(arr[i],arr[largest]);
        heapify(arr,largest,n);
    }
}

void buildHeap(vector<int> &arr)
{
  int n = arr.size();

  for(int i=(n/2 - 1); i >=0 ; i--)
  {
    heapify(arr,i,n);
  }

}


void heapSort(vector<int> &heap)
{
        int size = heap.size();

        while(size > 1)
        {
            swap(heap[0],heap[size-1]);  // swap first(root) and last node of the heap so this way maximum node will place at the last index in heap(array) !!!
            size--;  // decrement the heap size and now only consider new updated size for heap !!!
            heapify(heap,0,size); // heapify the first(root) node [because it is the replaced one !!!]
        }
}

void display(vector<int> &arr)
{
   cout<<"Sorted array : ";

   for(int i=0;i<arr.size();i++)
   {
      cout<<arr[i]<<" ";
   }
}



int main()
{

    vector<int> arr = {7,2,9,3,11,8,-100,90,17,-17,1000,3278 ,-38,2983,87,-9 ,-9,6238,876,-87,12,4,5,6,-1,0};

    // Convert the array into heap
     buildHeap(arr);

     // Perform Heap sort on heap
     heapSort(arr);

     display(arr);
     
}