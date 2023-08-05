// Time Complexity:

// O(2n) This time complexity is exponential because for each state, 2 recursion calls are made.


// Space Complexity:

// O(1) As no extra space is required, therefore space complexity is constant. However, if we include the space used in the recursive stack then
// the space complexity is O(n). Here, we conclude our question "Target Sum Subsets" by Recursion. In the further sections you will see more approaches
// to solve this problem like using Dynamic Programming. But you don't need to worry about that right now.




#include<bits/stdc++.h>
using namespace std;

    // set is the subset
    // sos is sum of subset
    // tar is target
  void printTargetSumSubsets(vector<int> arr, int idx, string set, int sos, int tar){
    
    if(sos>tar)
    {
      return;
    }

    if(idx==arr.size())
    {
      if(sos==tar){
      cout<<set<<"."<<endl;
      }
      return;
    }


    // for(int i=idx;i<arr.size();i++)  (Would not work in case of 0's present in list !!!)
    // { 
    //   int ele = arr[i];
    //   printTargetSumSubsets(arr,i+1,set+to_string(ele)+", ",sos+ele,tar);
    // }

    printTargetSumSubsets(arr,idx+1,set+to_string(arr[idx])+", ",sos+arr[idx],tar);
    printTargetSumSubsets(arr,idx+1,set,sos,tar);
    }


int main(){

  int n;
  cin>>n;

  vector<int> arr(n,0);

  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }

  int tar;
  cin>>tar;

  printTargetSumSubsets(arr,0,"",0,tar);

}