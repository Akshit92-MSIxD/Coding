

// In this problem for each ith step on staircase can have different jump values given in the form of array
// Problem video : https://www.youtube.com/watch?v=uNqoQ0sNZCM&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=3


// Approach 1 : Normal Recursive Solution
// TC : O(n^n)  [assume from from every step on staircase we can make upto n jumps]
// SC : O(n) [recursive stack space]

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int getTotalNumberOfWays(vector<int> &jumps , int start , int end)
{
    if(start == end)
    return 1;

    if(jumps[start] == 0 || start > end)
    return 0;
        
     int total_ways = 0;

    for(int jmp = 1 ; jmp <= jumps[start] ; jmp++)
     total_ways = total_ways + getTotalNumberOfWays(jumps,start+jmp,end);

     return total_ways;
}


int main()
{

 int n; // number of stairs = n , and nth step on staircase  is the destination place !!!
 n = 6; // so there are total 6 stair steps on staircase and we have to find no.of ways of climbing 6 stairs from ground !!!

 vector<int> jumps = {3,3,0,2,2,3}; // from 0th step i.e ground you can make upto 2 jumps , from 1th step --> upto 4 jumps , from 2th step --> upto 1 jump ,...........from 5th step upto 3 jumps and the 6th step is the destination place/step on staircase !!!

 int total_ways = getTotalNumberOfWays(jumps,0,n);

 cout<<"\nTotal number of ways of climbing "<<n<<" stairs from ground : "<<total_ways<<endl<<endl;

}




/*----------------------------------------------------------------------------------------------------------------------------*/




// Approach 2 : DP(memoization)(recursive)
// TC : O(n^2)  [assume from from every step on staircase we can make upto n jumps]
// SC : O(n) [recursive stack space]

// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;


// int getTotalNumberOfWays(vector<int> &jumps , int start , int end , unordered_map<int,int> &dp)
// {
//     if(start == end)
//     return 1;

//     if(jumps[start] == 0 || start > end)
//     return 0;

//     if(dp.find(start) != dp.end())
//     return dp[start];
        
//      int total_ways = 0;

//     for(int jmp = 1 ; jmp <= jumps[start] ; jmp++)
//      total_ways = total_ways + getTotalNumberOfWays(jumps,start+jmp,end,dp);

//      dp[start] = total_ways;

//      return total_ways;
// }


// int main()
// {

//  int n; // number of stairs = n , and nth step on staircase  is the destination place !!!
//  n = 6; // so there are total 6 stair steps on staircase and we have to find no.of ways of climbing 6 stairs from ground !!!

//  vector<int> jumps = {3,3,0,2,2,3}; // from 0th step i.e ground you can make upto 2 jumps , from 1th step --> upto 4 jumps , from 2th step --> upto 1 jump ,...........from 5th step upto 3 jumps and the 6th step is the destination place/step on staircase !!!

//  unordered_map<int,int> dp;

//  int total_ways = getTotalNumberOfWays(jumps,0,n,dp);

//  cout<<"\nTotal number of ways of climbing "<<n<<" stairs from ground : "<<total_ways<<endl<<endl;

// }




/*----------------------------------------------------------------------------------------------------------------------------*/




// Approach 3 : DP(tabulation)(iterative)
// TC : O(n^2)  [assume from from every step on staircase we can make upto n jumps]
// SC : O(n) [vector space]

// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;

// int main()
// {

//  int n; // number of stairs = n , and nth step on staircase  is the destination place !!!
//  n = 6; // so there are total 6 stair steps on staircase and we have to find no.of ways of climbing 6 stairs from ground !!!

//  vector<int> jumps = {3,3,0,2,2,3}; // from 0th step i.e ground you can make upto 2 jumps , from 1th step --> upto 4 jumps , from 2th step --> upto 1 jump ,...........from 5th step upto 3 jumps and the 6th step is the destination place/step on staircase !!!


//  vector<int> dp(n+1,0);   // assume each index i represent no. of ways to reach nth stair from ith stair 

//  dp[n] = 1;

//  for(int i = n-1 ; i>=0 ; i--)   // In this case smaller subproblem will exist RHS and main problem will exist on LHS of dp vector so we traverse the dp vector in reverse direction !!!
//  {
       
//        for(int jmp = 1; jmp<=jumps[i];jmp++)
//        {
//            if(i+jmp > n)
//            break;

//            dp[i] = dp[i] + dp[i+jmp];
//        }

//  }



//  cout<<"\nTotal number of ways of climbing "<<n<<" stairs from ground : "<<dp[0]<<endl<<endl;

// }




