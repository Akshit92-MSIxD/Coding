// https://nados.io/question/print-increasing?zen=true

#include<iostream>
using namespace std;

// T = O(n); (since , no. of func calls = n calls)
// S = O(1)

void printIncreasing(int n){
   
   if(n==0) // base case
   {
       return;
   }
   else  // Recursive case
   {
      printIncreasing(n-1); // faith
      cout<<n<<endl; 
   }
    
}


int main(){
    int n; cin>>n;
    printIncreasing(n);
}
