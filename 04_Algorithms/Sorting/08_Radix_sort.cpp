/* Time Complexity : O(d(n+b)) ( d : no. of digits of max no. in array  , b : base size of freq[10])
   Space Complexity : O(n+b) (Two arrays one farr[] of b(base-10) length and another ans[] of n length were used.) */

#include <iostream>
#include <vector>
using namespace std;


void countSort(vector<int> &arr , int place)
{
        int n = arr.size();

        // create a freq[] of size 10 (for radix = 10 ==> (0-9) digits)

        vector<int> freq(10,0);


        
        // Increment the freq of each element in freq[] based on pth place!!!

        for(int i=0;i<n;i++)
        {
            int place_digit = (arr[i]/place)%10;
            freq[place_digit]++;
        } 


        // convert the freq[] into prefix sum array

        for(int i=1;i<=9;i++)
        {
            freq[i] = freq[i-1] + freq[i];
        }



       // create a res[] of same size as arr[] and travel arr[] from reverse order

        vector<int> res(n,0);

        for(int i=n-1;i>=0;i--)
        {
            int place_digit = (arr[i]/place)%10;
            
            int last_index = freq[place_digit] - 1;;

            res[last_index] = arr[i];

            freq[place_digit]--;
        }


        // Fill the arr[] with res[]

        for(int i=0;i<n;i++)
        {
            arr[i] = res[i];
        }

        for(int i=0;i<n;i++)
        {
           cout<<arr[i]<<" ";
        }
        cout<<endl;


    return;


}



void radixSort(vector<int> &arr)
{
       // Find the max element
        
        int max = arr[0];

        for(int i=0 ; i<arr.size();i++)
        {
            if(arr[i]>max)
            {
            max = arr[i];
            }
        }

      // Run the loop until nth place's of max element

      int place = 1;

      while(place<=max)
      {
        countSort(arr,place);
        place*=10;
      }

      return;
}



int main()
{
    int n;

    cout<<"Enter the size of array : ";
    cin>>n;

    vector<int> arr(n,0);
    
    cout<<"Enter the elements inside the array : ";

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    radixSort(arr);

     cout<<"Sorted array : ";

     for(int i=0;i<n;i++)
     {
        cout<<arr[i]<<" ";
     }

}