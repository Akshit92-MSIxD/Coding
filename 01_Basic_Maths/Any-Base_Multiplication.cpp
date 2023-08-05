// https://nados.io/question/any-base-multiplication?zen=true
// Good Question

#include<iostream>
using namespace std;


int getProduct(int b, int n1, int n2){

int sum_indi_product = 0 , i_multiplier=1;

  while(n2!=0)
  {
     int temp = n1;

     int carry = 0 , individual_product=0 , multiplier=1;

     while(temp!=0 || carry!=0)
     {
         int d1 = temp % 10;
         int d2 = n2 %10;

         int p = d1 * d2 + carry;

         if(p>=b)
         {
             carry = p / b;
             p = p % b;
         }
         else
         {
             carry  = 0;
         }

         individual_product = individual_product + p*multiplier;

         multiplier*=10;
          temp/=10;
     }


      individual_product*=i_multiplier; // giving place to individual product


      // Statements for addition 

      if(sum_indi_product == 0)
      {
         sum_indi_product+=individual_product;
      }
      else
      {
          int num1 = individual_product , num2 = sum_indi_product , sum = 0 , place = 1;

          while(num1 || num2 || carry) // loop for adding the individual product
          {
             int d1 = num1 % 10;
             int  d2 = num2 % 10;

              int add = d1 + d2 + carry;
              
              carry = add/b;
              add = add % b;

              sum = sum + add*place;

              num1/=10;
              num2/=10;
              place*=10;  
          }

          sum_indi_product = sum;
      }

      i_multiplier*=10;

      n2/=10;

  }

return sum_indi_product;


} 

int main(){
    int b, n1, n2;
    cin>>b>>n1>>n2;
    cout<<getProduct(b,n1,n2)<<endl;
}
