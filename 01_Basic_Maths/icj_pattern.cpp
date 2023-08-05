#include <iostream>
using namespace std;

// Brute Force Solution
int main(int argc, char **argv){
    int n;
    cin >> n;
    int Ncx=1,num=1,den=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            
           int loop = j;

           int k = i;
           int l = j;

           while(loop--)
           {
               num = num * (k--);
               den = den * (l--);  
           }

           Ncx = num/den;
           cout<<Ncx<<"\t"; 
           num=1,den=1;
        }

        cout<<endl;
        
    }
    
    
}

// Optimised Solution

/*


for(int i=0;i<n;i++)
{
    int icj=1;
    for(int j=0;j<=i;j++)
    {
      cout<<icj;
      icj = icj * ((i-j)/(j+1)); // icj ko icj+1 samaj !!!!
    }
} */
