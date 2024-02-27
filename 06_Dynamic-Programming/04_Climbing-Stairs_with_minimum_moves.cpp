
// In this problem for each ith step on staircase can have different jump values given in the form of array
// We have to find minimum no. of moves it takes to "climb n stairs from ground" or "reach nth stair from ground" , considering 1 jump = 1 move , 2 jumps = 1 move and ...x jump = 1 move !!!
// Problem video : https://www.youtube.com/watch?v=d42uDPBOXSw&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=4&t=3s



// Approach 1 : Normal Recursive Solution
// TC : O(n^n)  [assume from every step on staircase we can make upto n jumps]
// SC : O(n) [recursive stack space]

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

 int getMinMoves(vector<int> &jumps,int start ,int end)
 {
     
     if(start == end)
     return 0;

     if(start > end || jumps[start] == 0)
     return INT_MAX - 1;


     int min_moves = INT_MAX;

     for(int jmp=1;jmp<=jumps[start];jmp++)
      min_moves = min(getMinMoves(jumps,start+jmp,end) + 1 , min_moves);

      return min_moves;

 }

int main()
{

 int n; // number of stairs = n , and nth step on staircase  is the destination place !!!
 n = 6; // so there are total 6 stair steps on staircase and we have to find minimum moves it takes to "climb 6 stairs from ground" or "to reach 6th stair from ground" !!!

 vector<int> jumps = {3,3,0,2,2,3}; // from 0th step i.e ground you can make upto 2 jumps , from 1th step --> upto 4 jumps , from 2th step --> upto 1 jump ,...........from 5th step upto 3 jumps and the 6th step is the destination place/step on staircase !!!

 int  min_moves = getMinMoves(jumps,0,n);

cout<<"\nMinimum number of moves to \"climb "<<n<<" stairs from ground\" or \"reach "<<n<<"th stair from ground\" : "<<min_moves<<endl<<endl;


}




/*----------------------------------------------------------------------------------------------------------------------------*/




// Approach 2 : DP(memoization)(recursive)
// TC : O(n^2)  [assume from every step on staircase we can make upto n jumps]
// SC : O(n) [recursive stack space]

// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;


//  int getMinMoves(vector<int> &jumps,int start ,int end , unordered_map<int,int> &dp)
//  {
     
//      if(start == end)
//      return 0;

//      if(start > end || jumps[start] == 0)
//      return INT_MAX - 1;

//      if(dp.find(start) != dp.end())
//       return dp[start];

//      int min_moves = INT_MAX;

//      for(int jmp=1;jmp<=jumps[start];jmp++)
//       min_moves = min(getMinMoves(jumps,start+jmp,end,dp) + 1 , min_moves);

//       dp[start] = min_moves;

//       return min_moves;

//  }



// int main()
// {

//  int n; // number of stairs = n , and nth step on staircase  is the destination place !!!
//  n = 6; // so there are total 6 stair steps on staircase and we have to find minimum moves it takes to "climb 6 stairs from ground" or "to reach 6th stair from ground" !!!

//  vector<int> jumps = {3,3,0,2,2,3}; // from 0th step i.e ground you can make upto 2 jumps , from 1th step --> upto 4 jumps , from 2th step --> upto 1 jump ,...........from 5th step upto 3 jumps and the 6th step is the destination place/step on staircase !!!

//  unordered_map<int,int> dp;

//  int  min_moves = getMinMoves(jumps,0,n,dp);

// cout<<"\nMinimum number of moves to \"climb "<<n<<" stairs from ground\" or \"reach "<<n<<"th stair from ground\" : "<<min_moves<<endl<<endl;
// }




/*----------------------------------------------------------------------------------------------------------------------------*/




// Approach 3 : DP(tabulation)(iterative)
// TC : O(n^2)  [assume from every step on staircase we can make upto n jumps]
// SC : O(n) [vector space]

// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;

// int main()
// {

//  int n; // number of stairs = n , and nth step on staircase  is the destination place !!!
//  n = 6; // so there are total 6 stair steps on staircase and we have to find minimum moves it takes to "climb 6 stairs from ground" or "to reach 6th stair from ground" !!!

//  vector<int> jumps = {3,3,0,2,2,3}; // from 0th step i.e ground you can make upto 2 jumps , from 1th step --> upto 4 jumps , from 2th step --> upto 1 jump ,...........from 5th step upto 3 jumps and the 6th step is the destination place/step on staircase !!!

//  vector<int> dp(n+1,INT_MAX-1); // assume each index i represent minimum no. of moves to reach nth stair from ith stair 

//  dp[n] = 0; // it takes 0 moves to reach nth stair from same nth stair !!!

//  for(int i=n-1 ; i>=0 ; i--)  // In this case smaller subproblem will exist RHS and main problem will exist on LHS of dp vector so we traverse the dp vector in reverse direction !!!
//  {
  
//    for(int jmp = 1 ; jmp<=jumps[i] ; jmp++)
//    {
//         if(i+jmp > n)
//         break;

//        dp[i] = min(dp[i+jmp] + 1 , dp[i]);
//    }
   
//  }

//  cout<<"\nMinimum number of moves to \"climb "<<n<<" stairs from ground\" or \"reach "<<n<<"th stair from ground\" : "<<dp[0]<<endl<<endl;

// }




