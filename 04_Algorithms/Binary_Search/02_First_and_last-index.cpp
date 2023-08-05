// Implement  lower bound and upper bound of an element in an sorted array. wali approach in next revision !!!!!
// https://nados.io/question/first-index-and-last-index?zen=true

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
    int data;
    cin>>data;


// We will implement BS two times :-


// First time to find first index 

    int l1=0 , h1=n-1 , first=-1;

    while(l1<=h1)
    {
      int mid = l1 + (h1-l1)/2;

      if(data>arr[mid])
      {
          l1 = mid+1;
      }
      else if(data<arr[mid])
      {
          h1 = mid-1;
      }
      else
      {
          first = mid;

          h1 = mid - 1; // element mil ke baad , left subarray traverse krna hai
      }
    }



// Second time to find last index

 int l2=0 , h2=n-1 , last = -1;

    while(l2<=h2)
    {
      int mid = l2 + (h2-l2)/2;

      if(data>arr[mid])
      {
          l2 = mid+1;
      }
      else if(data<arr[mid])
      {
          h2 = mid-1;
      }
      else
      {
          last = mid;

          l2 = mid + 1; // element mil ke baad , right subarray traverse krna hai
      }
    }

    cout<<first<<endl<<last;
}



 // BS + 2LS approarch :-
         
 // index mil chuka hai ab dekho uske left or right mai LS lagake!!! (What if whole element of array = d??? ==> T = O(n))
    //    if(arr[mid] == data)
    //    {
    //      first = last = mid;

    //      int i=mid-1 , j=mid+1; 

    //      while(arr[i]==arr[mid])
    //      {
    //          first = i;
    //          i--;
    //      }

    //      while(arr[j]==arr[mid])
    //      {
    //          last = j;
    //          j++;
    //      }

    //      break;

    //    }
