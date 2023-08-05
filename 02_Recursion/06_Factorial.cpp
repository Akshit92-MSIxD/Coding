// https://nados.io/question/factorial?zen=true

#include<iostream>
using namespace std;

int factorial(int n){
    
    // base case
    if(n==1)
    {
      return 1;
    }

    // recursive case
    return factorial(n-1)*n;
}

int main(){
    int n; cin>>n;
    cout<<factorial(n);
}