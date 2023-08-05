// Good Question 

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;

   int count_digit=0 , digit , divider; // power = count_digit
   int temp=n;

    while(temp!=0)
    {
      count_digit++;
      temp/=10; 
    }

    for(int i=count_digit;i>=1;i--)
    {
       divider = (int) (pow(10,i-1) + 1e-9); // so many f calls , use div/=10 instead (in below solution)
       digit = (n/divider) % 10;
       cout<<digit<<endl;
    }
    
}

/* 

 while(...)
 {

 }

 divider = (int)(pow(10,count_digit-1) + 1e-9);

   temp=n;

  for(divider!=0)
  {
      digit = temp / divider;
      cout<<digit<<endl;
      temp=temp % divider;
      divider/=10;
  }                  
  */
