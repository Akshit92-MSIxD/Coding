// https://nados.io/question/power-logarithmic?zen=true
// logarithmic complexity solution for calculating x^n
// T = O(log2 n)
// S = O(1) , if  the recursion call stack is taken into account, then space complexity will be O(log2 n) as there are k = (log2 n) recursive calls.
// for large values of n
// Method : Take modulo arithmetic (Bit manipulation)
// Try other approaches too!!!!

#include<iostream>
using namespace std;

int  powerLogarithmic(int x,int n){

   // base case

   if(n==0)
   {
       return 1;
   }
      // recursive case
    int ans;
    int xpnb2 = powerLogarithmic(x,n/2);   
    
    ans = xpnb2 * xpnb2;

    if(n%2!=0)
    {
        ans = ans * x;
    }

    return ans;
    
}

int main(){
    int x,n; cin>>x>>n;
    cout<<powerLogarithmic(x,n);
}


// Method 2 by SSir!!!!(prefered)

//  int xpnb2 = powerLogarithmic(x,n/2);

//  int xn = xpnb2 * xpnb2;

//  if(n%2!=0)
//  {
//     xn = xn * x;
//  }

//  return xn;


