// https://nados.io/question/print-increasing-decreasing?zen=true

// T = O(n)
// S : O(1)
// As no extra space is required, therefore space complexity is constant. However, if we include the space used in the recursive stack then 
// the space complexity is O(n).

#include<iostream>
using namespace std;

void printIncDec(int n){

    if(n == 0) // Base case
    {
        return;
    }

   // Recursive case
    cout<<n<<endl;
    printIncDec(n-1); // faith
    cout<<n<<endl;   
}


int main(){
    int n; cin>>n;
    printIncDec(n);
}