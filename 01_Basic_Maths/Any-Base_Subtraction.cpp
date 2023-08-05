// https://nados.io/question/any-base-subtraction?zen=true

#include<iostream>
using namespace std;

int getDifference(int b, int n1, int n2){
   
   int d1,d2,borrow = 0 , result=0 , multiplier = 1;

   while(n2>0)
   {
        d1 = n1%10;
        d2 = n2%10;

        int sub = d2-borrow-d1;

        if(sub<0)
        {
            sub +=b;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        result = result + sub*multiplier;

        multiplier*=10;

         n1/=10;
         n2/=10;

   }

   return result;
    
}


int main(){
    int b, n1, n2;
    cin>>b>>n1>>n2;
   cout<<getDifference(b,n1,n2);
}