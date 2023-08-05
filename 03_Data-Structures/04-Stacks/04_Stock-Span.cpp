// https://leetcode.com/problems/online-stock-span/


// Stock span is defined as the number of days passed between the current day and the first day before today when price was higher than today.
// Hint : We have to calculate next greater element on the left side

// TC : O(n) (easy think about it :) )
// SC : O(n) (stack will take O(n) in worst case(array sorted in desc order) and res[] will take O(n) and map will take O(n))

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;



vector<int> get_stock_span(vector<int> &nums)
{

    int n = nums.size();

     stack<int> s;

     unordered_map<int,int> mp;   // it will store the nums[i] and its corresponding indexes in the map

     vector<int> stock_span(n,0);  // You can also store indexes of nums inside stack instead of numbers ==> then no need of mp used above!!!

     for(int i=0;i<n;i++)
     {
        mp[nums[i]] = i;
     }

     for(int i=0;i<=n-1;i++)
     {
        while(!s.empty() &&  s.top()<=nums[i])
        {
            s.pop();
        }
        if(s.empty())
        {
              stock_span[i] = i+1;   // storing  stock_span[i]=i+i for nums[i] stock price beacause (sample test case se check kr!!!)
              s.push(nums[i]);
        }
        else
        {
            stock_span[i] = i - mp[s.top()];  // storing  stock_span[i]= i - mp[s.top()] for nums[i] stock price beacause (sample test case se check kr!!!)
            s.push(nums[i]);
        }

     }

     return stock_span;

     
}

int main()
{
  
  int n;
  cout<<"Enter the size of array : ";
  cin>>n;

  vector<int> nums(n,0);

  cout<<"Enter the numbers inside the array : ";

  for(int i=0;i<n;i++)
  {
    cin>>nums[i];
  }

  vector<int> stock_span = get_stock_span(nums);

  for(int i=0;i<n;i++)
  {
    cout<<"Stock span for day"<<i<<" is  : "<<stock_span[i]<<endl;
  }

}
