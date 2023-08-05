/* Time Complexity : O(n+k) ( around O(n)  for arr[]  and O(k) for freq[])
   Space Complexity : O(n+k) (Two arrays one farr[] of k length and another ans[] of n length were used.) */

// Note - Condition : if range of numbers is very less or does not vary much 
// Benefit : stable sort(maintains relative order of same value elements!!!)



#include <iostream>
#include <vector>
using namespace std;


void count_sort(vector<int> &arr)
{
   // Find the max and min element

    int max , min;

    max=min=arr[0]; 

    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>max)
        {
            max =arr[i];
        }

        if(arr[i]<min)
        {
            min = arr[i];
        }
    }  



  // Create a freq[] of size max - min + 1

   vector<int>  freq(max-min+1,0);

 

 // Increment the freq of each element in freq[] and take care of arr_elm--freq_index mapping!!!

  for(int i=0;i<arr.size();i++)
  {
    int elm = arr[i];
    freq[elm-min]++;  
  }


 // Convert the freq[] into prefix sum array for listing the last index at which particular arr_elm will reside 

 for(int i=0;i<freq.size();i++)
 {
    if(i==0)
    {
        freq[i]--;
    }
    else{
        freq[i] = freq[i-1] + freq[i];
    }
   
    
 }


 // Create a res[] of same size as arr[] and travel arr[] from reverse order

 int arr_size = arr.size();

 vector<int> res(arr_size,0);


 for(int i=arr_size-1 ; i>=0 ;i--)
 {
    int elm = arr[i];
    
    int last_index = freq[elm-min];

    res[last_index] = elm;

    freq[elm-min]--; // Now the last index of particular arr_elm will be one less!!!
 }

 
 // Fill the actual arr[] with the res[]

 for(int i=0;i<arr_size;i++)
 {
    arr[i] = res[i];
 }
 
 return;

}

int main()
{
    int n;

    cout<<"Enter the size of array : ";
    cin>>n;

    vector<int> arr(n,0);
     
    cout<<"Enter the elements into the array : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

   count_sort(arr);

    cout<<"Sorted array : ";

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}