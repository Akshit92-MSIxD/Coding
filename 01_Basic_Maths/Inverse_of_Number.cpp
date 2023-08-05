//Good Question
#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;

  int sum=0,inverse,position=0,digit;

  while(n!=0)
  {
     position++;
     digit=n%10;
     sum=sum + position*( (int) pow(10,digit-1) + 1e-9) ; 
     n/=10;
  }

  inverse=sum;

  cout<<inverse;
    
}