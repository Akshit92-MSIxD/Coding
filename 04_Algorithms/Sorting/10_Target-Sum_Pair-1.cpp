 // Note : This question's concept is linked with two sum problem of leetcode , but here we have to find all possible pairs
 // inside the array who sum = target
 // Two approaches : sorting approach(summet sir) and hashmap approach(trying to find complement)




/* Sorting Approach (sumeet malik sir) (TC : O(nlogn) and SC : O(1)) */

// Assume that arr[] contains distinct numbers

 #include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;


 void target_sum_pair(vector<int> &nums , int target)
 {
      // sort the nums
      sort(nums.begin(),nums.end());   // TC : O(nlogn)

      // find the pairs
      int left = 0 , right = nums.size()-1;

     bool is_pair_exist  = false;

      while(left<right)
      {
        int sum = nums[left] + nums[right];

        if(sum>target)
        {
               right--;
        }
        else if(sum<target)
        {
            left++;
        }
        else
        {
            is_pair_exist = true;
            cout<<"("<<nums[left]<<","<<nums[right]<<") ";
           left++;
           right--;
        }
      }

      if(!is_pair_exist)
      {
        cout<<"No such pair exist!!!"<<endl;
      }

      return;
 }


 int main()
 {
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
   
    vector<int> nums(n,0);
    cout<<"Enter the elements inside the array : ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
 
      cout<<"Enter the target : ";
    int target;
    cin>>target;

    cout<<endl<<"Possible pairs : ";

    target_sum_pair(nums,target);
 
 }



 /*  Optimal approach : Use hashap (TC : O(n) and SC : O(n))  */

//  see this :  https://leetcode.com/problems/two-sum/





 