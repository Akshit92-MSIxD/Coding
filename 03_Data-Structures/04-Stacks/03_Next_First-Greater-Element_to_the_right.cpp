// https://leetcode.com/problems/next-greater-element-i/solutions/3791039/crack-the-code-next-greater-element-magic/ (Related question)
// https://leetcode.com/problems/next-greater-element-ii/solutions/ (Related question)

// TC : O(n) (easy think about it :) )
// SC : O(n) (stack will take O(n) in worst case(array sorted in asc order) and res[] will take O(n))

#include <iostream>
#include <stack>
#include <vector>
using namespace std;


vector<int>  get_next_greater(vector<int> &nums)
{

   int n = nums.size();

   stack<int> s;

   vector<int> nge(n,0);

   for(int i=n-1;i>=0;i--)     // Traverse nums[] in reverse order
   {
         if(s.empty())        // if stack is empty that means for current num there is no next greater number in the stack
         {
            nge[i] = -1;
            s.push(nums[i]);    // push that num in stack because it may become next greater elm of some elements on its left side!!!

         }
         else                                        // If stack is not empty
         {
            while(!s.empty() && s.top()<=nums[i])   // run the loop until we get the greater number in the stack than current num
            {
                s.pop();       // bhai why poping stack-numbers<current_num (current num is greater than stack top then it may become the next possible greater no. for the numbers on its left side!!!)
            } 
            if(s.empty())   //  if stack is empty that means for current num there is no next greater number in the stack
            {
                nge[i] = -1;
                s.push(nums[i]);
                continue;
            }
            nge[i] =  s.top();  // If we get the stack top > current_num then it(stack_top) becomes the next greater no. for cuurent num
            s.push(nums[i]);   // then we push the cuurent_num without poping stack_top (Why??? bhai obvious hai soch ke dekh :))
         }
   }


   return nge;
         
}


int main()
{
 
 cout<<"Enter the size of array : ";
 int n;
 cin>>n;

 vector<int> nums(n,0);

 cout<<"Enter the numbers inside the array : ";
 for(int i=0;i<n;i++)
 {
    cin>>nums[i];
 }

 vector<int> nge = get_next_greater(nums);

cout<<endl;

 for(int i=0;i<n;i++)
 {
    cout<<"Next greater element of "<<nums[i]<<" is : "<<nge[i]<<endl;
 }

 cout<<endl;

}