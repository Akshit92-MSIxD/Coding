// Good question , Brute force

#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char **argv){                                                 
    int n;
    cin >> n;
    bool isprime=true;

    if(isprime)           
    {

        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                isprime=false;
                break;
            }
        }

    }

  if(!isprime)

  {
      for(int i=2;i<=n;i++)
      {
          while(n%i==0)
          {
              cout<<i<<" ";
              n/=i;
          }
      }

  }
  return 0;

}

 // Best Optimal approach

/* just write : 

   bool isprime=true;

   for(int i=2;i<=sqrt(n);i++)    // i*i<=n  == i<=sqrt(n)
   {
       while(n%i==0)
       {
           n/=i;
           cout<<i<<" ";
           isprime=false;
       }

   }

   if(n!=1 && !isprime)
   {
       cout<<n;
   }
   else
   {
       cout<<"Inputted number is a prime no. , thatswhy no factorisation is possible !!!!"
   }
                         
            */



