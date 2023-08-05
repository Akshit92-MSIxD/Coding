#include <iostream>
using namespace std;

int main()
{
    int b,n1,n2;
    cin>>b>>n1>>n2;
    
    int digit1, digit2;
    int sum_digits,carry=0,rem,result=0,power=1;
    
    
    while(n1 || n2 || carry)
    {
        digit1=n1%10;
        digit2=n2%10;
        
        sum_digits = digit1 + digit2 + carry;
        
        rem = sum_digits % b;      // 1                             
        carry = sum_digits/b;      // 2
        
        result = result + rem*power;                            
        power*=10;
                                                                  
           n1/=10;                                                      
           n2/=10;                                                   
     }   
                                                                         
         cout<<result;  
                                                                                            
        }          
 

  /* this below code do same function as 1 and 2 in above code */
            
         // if(sum_digits>=b)
        // {
        //     rem = sum_digits - b;
        //     carry=1;
        // }
        // else
        // {
        //     carry = 0;
        //     rem = sum_digits;
        // }