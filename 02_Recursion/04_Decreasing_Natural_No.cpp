// https://nados.io/question/print-decreasing?zen=true

#include <iostream>
using namespace std;

// T = O(n);
// S = O(1);

void printDecreasing(int n){  
   
   if(n==0) // Base Case
   {
       return;
   }

// Recursive case
   cout<<n<<endl; // self work
   printDecreasing(n-1); // faith
    
}

int main(){
    int n;
    cin >> n;
    printDecreasing(n);
}

// Method 2 : 

//    if(n>=1)
//    {
//        cout<<n<<endl;
//        printDecreasing(n-1);
//    }
//    return;