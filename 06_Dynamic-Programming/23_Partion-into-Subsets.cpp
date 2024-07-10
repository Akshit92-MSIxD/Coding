

// *** Note : In this problem we have to find number of ways to partition a set with N elements into K subsets !!!

/* 
 1) The previous n – 1 elements are divided into k partitions, i.e f(n-1, k) ways. Put this nth element into one of the previous k partitions. So, count = k * f(n-1, k)
 2) The previous n – 1 elements are divided into k – 1 partitions, i.e f(n-1, k-1) ways. Put the nth element into a new partition ( single element partition).So, count = f(n-1, k-1)
 3) Total count = k * f(n-1, k) + f(n-1, k-1).  
                                                */


// Approach 1 : DP(memoization)(recursive)
// TC = O(n*k) 
// SC = O(n*k) [extra dp vector space] + O(n) [recursive stack space]

#include <iostream>
#include <vector>
using namespace std;

class Solution {

 private :

 int countTotalWays(int n , int k , vector<vector<int>> &dp)
 {
    if(n == 0 || k == 0 || k > n)
    return 0;

    if(k == 1 || k == n)
    return 1;

    if(dp[n][k] != -1) return dp[n][k];

    return dp[n][k] = k * countTotalWays(n-1,k,dp) + countTotalWays(n-1,k-1,dp);
 }
 
 public :

 int countTotalWaysToPartitionNintoK(int n , int k)
 {
      vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
      return countTotalWays(n,k,dp);
 }


};


int main(){

    Solution S;

    int n , k;

    cout<<"\nEnter the count of total elements(n) : ";
    cin>>n;

    cout<<"Enter the count of partitions(k) : ";
    cin>>k;

    int totalWays = S.countTotalWaysToPartitionNintoK(n,k);

    cout<<"Total number of ways to partition a set with "<<n<<" elements into "<<k<<" subsets : "<<totalWays<<endl<<endl;
}




/*--------------------------------------------------------------------------------------------------------------------------------------*/




// // Approach 2 : DP(tabulation)(iterative)
// // TC = O(n*k) 
// // SC = O(n*k) [extra dp vector space]

// #include <iostream>
// #include <vector>
// using namespace std;


// class Solution {
 
//  public :

//  int countTotalWaysToPartitionNintoK(int n , int k)
//  {
//       vector<vector<int>> dp(n+1,vector<int>(k+1,0));

//       for(int i = 1; i <= n ; i++)
//       {
//            for(int j = 1 ; j <= i && j <= k ; j++)
//            {
//                  if(i == j || j == 1) dp[i][j] = 1;
//                  else dp[i][j] = j * dp[i-1][j] + dp[i-1][j-1];
//            }
//       }

//       return dp[n][k];

//  }


// };

// int main(){

//     Solution S;

//     int n , k;

//     cout<<"\nEnter the count of total elements(n) : ";
//     cin>>n;

//     cout<<"Enter the count of partitions(k) : ";
//     cin>>k;

//     int totalWays = S.countTotalWaysToPartitionNintoK(n,k);

//     cout<<"Total number of ways to partition a set with "<<n<<" elements into "<<k<<" subsets : "<<totalWays<<endl<<endl;

// }




/*-------------------------------------------------------------------------------------------------------------------------------------*/




// // Approach 3 : Optimal version of DP(tabulation)(iterative) [Since ith row is only taking the help of i-1 th row so use only two rows !!!]
// // TC = O(n*k) 
// // SC = O(2*k) [using two extra dp vectors]

// #include <iostream>
// #include <vector>
// using namespace std;


// class Solution {
 
//  public :

//  int countTotalWaysToPartitionNintoK(int n , int k)
//  {
//       vector<int> prev(k+1,0);
//       vector<int> curr(k+1,0);

//       for(int i = 1; i <= n ; i++)
//       {
//            for(int j = 1 ; j <= i && j <= k ; j++)
//            {
//                  if(i == j || j == 1) curr[j] = 1;
//                  else curr[j] = j * prev[j] + prev[j-1];
//            }

//            prev = curr;
//       }

//       return curr[k];

//  }


// };

// int main(){

//     Solution S;

//     int n , k;

//     cout<<"\nEnter the count of total elements(n) : ";
//     cin>>n;

//     cout<<"Enter the count of partitions(k) : ";
//     cin>>k;

//     int totalWays = S.countTotalWaysToPartitionNintoK(n,k);

//     cout<<"Total number of ways to partition a set with "<<n<<" elements into "<<k<<" subsets : "<<totalWays<<endl<<endl;
// }




/*-------------------------------------------------------------------------------------------------------------------------------------*/




// // Approach 4 : Optimal version of Approach 3
// // TC = O(n*k) 
// // SC = O(k) [using only one dp vector]

// #include <iostream>
// #include <vector>
// using namespace std;


// class Solution {
 
//  public :

//  int countTotalWaysToPartitionNintoK(int n , int k)
//  {
//       vector<int> dp(k+1,0);
//       int prev = 0;

//       for(int i = 1; i <= n ; i++)
//       {
//            for(int j = 1 ; j <= i && j <= k ; j++)
//            {
//                 int temp = dp[j];

//                  if(i == j || j == 1) dp[j] = 1;  
//                  else dp[j] = j * dp[j] + prev; 

//                  prev = temp;
//            }   
//       }

//       return dp[k];

//  }

// };

// int main(){

//     Solution S;

//     int n , k;

//     cout<<"\nEnter the count of total elements(n) : ";
//     cin>>n;

//     cout<<"Enter the count of partitions(k) : ";
//     cin>>k;

//     int totalWays = S.countTotalWaysToPartitionNintoK(n,k);

//     cout<<"Total number of ways to partition a set with "<<n<<" elements into "<<k<<" subsets : "<<totalWays<<endl<<endl;
// }