#include <iostream>
using namespace std;
int main(int argc, char **argv){

    int num1, num2;
    cin >> num1 >> num2;


                                                         // T = O(min(n1,n2))                                                         

    // for(int i = (num1<num2 ? num1:num2) ; i>=1 ; i--) //  for GCD (brute force)
    // {
    //     if(num1%i==0 && num2%i==0)
    //     {
    //         gcd = i;
    //         break;
    //     }
    // }

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    
                                                          // T = O(log(min(n1,n2)) 

    // Euclids algorithm for GCD (method-1)                                                        /// Euclids algorithm function to find GCD of two no.s(method-2)
                                                                                                 
   int gcd;                                                                                         //  int gcd_fun(int n1, int n2)
                                                                                                    //     {
   int divisor = (num1<num2 ? num1 : num2);                                                         //        while(n1&&n2)  or (n1!=0 && n2!=0)   
   int  divident = (num1>num2 ? num1 : num2);                                                       //         {
   int rem = divident % divisor;                                                                    //           if(n1>n2)
                                                                                                    //               n1=n1%n2;
   while(rem!=0)                                                                                    //           else
   {                                                                                                //               n2=n2%n1;
      divident = divisor;                                                                           //          }
      divisor = rem;                                                                                //           return n1==0?n2:n1;
      rem = divident % divisor;
   }                                                                                                //     }                                                                                                  
   gcd = divisor;


/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
   int lcm;

    if(num1%num2==0 || num2%num1==0)      // for LCM  or just lcm = (num1 * num2)/gcd;
    {
        lcm = num1>num2 ? num1 : num2;
    }
    else
    {
        for(int i=((num1>num2 ? num1 : num2) ) ; i<=(num1*num2) ; i++)
        {
            if(i%num1==0 && i%num2==0)
            {
                lcm = i;
                break;
            }
        }
    }

    cout<<gcd<<endl<<lcm;
}






