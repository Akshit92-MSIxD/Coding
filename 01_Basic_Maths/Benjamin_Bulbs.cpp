// Good Question
#include <iostream>
using namespace std;
int main(int argc, char**argv){
    int n;
    cin>>n;
    
 
    for(int i=1;i*i<=n;i++)  // just find the squares of natural number upto (best optimal approach)
    {                         // ex : bulb numbers at 1 , 4 , 9 , 16 , 25 position in case n = 30 bulbs
                             // fluctuates odd number of times , since they have odd no. of factors !!!                             
        cout<<i*i<<endl;     // While remaining other bulbs fluctuate even no. of times , since they have 
    }                        // even no. of factors !!!
                             // Conclusion : even times fluctuate krenge bulbs ko to OFF hojaenge
                             // and agar odd time krenge to on hojaega;
                             // bulbs position_number other than position(perfect-square) are OFF !!!
    
}


/*  brute force only for small values of n (sabse Wahiyaad lol!!!)
int main(int argc, char**argv){
    int n;
    cin>>n;
    
 class Bulb
 {
    public :  

    bool status;
 
    Bulb()
    {
      status = false;         // false for OFF , true for ON
    }
 };

 Bulb bulb[n];

 for(int i=0;i<n;i++)
 {
     int k = i+1;
     for(int j=i;j<n;j+=k)
     {
         if(bulb[j].status==true) // if ON
         {
            bulb[j].status=false;
         }
         else
         {
             bulb[j].status=true;
         }
     }
 }

  for(int i=0;i<=n-1;i++)
  {
      if(bulb[i].status==true)
      {
          cout<<i+1<<endl;;
      }
  }
    */