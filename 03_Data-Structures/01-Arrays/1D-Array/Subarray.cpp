// https://nados.io/question/subarray-problem?zen=true

#include<iostream>
using namespace std;

// T = O(n^3) analyse it on paper !!!! 

// total no. of subarrays = n*(n+1)/2

// subarray must be contigous!!!

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }

    
    
  // Pick starting point
  for(int i=0;i<=n-1;i++)     
     
  {
      // Pick ending point
      for(int j=i;j<=n-1;j++)
      {
          // Print subarray between current starting and ending point
         for(int k=i ; k<=j;k++)
         {
             cout<<arr[k]<<"\t";
         }
         cout<<endl;
      }
  }
}