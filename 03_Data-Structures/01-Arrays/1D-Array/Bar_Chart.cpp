#include<iostream>
using namespace std;


int main(){
   
   int n;
   cin>>n;

   int arr[n];
   int large;

   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }

   large = 0;
   
   for(int i=1;i<n;i++)
   {

       if(arr[i]>arr[large])
       {
           large = i;
       }

   }

// my approach
   for(int i=0;i<arr[large];i++)
   {
       for(int j=0;j<n;j++)
       {
           if(i<arr[large]-arr[j])
           {
               cout<<"\t";
           }
           else
           {
               cout<<"*\t";
           }
       }
       cout<<endl;
   }
   
}


/* New approach building-floor concept */


// for(int i=large;i>=1;i--) /// trick : set the loop in reverse order
// {
//     for(int j=0;j<n;j++)
//     {
//         if(arr[j]>=i) interpret arr[j] as height of building j and i as height=i from where person is checking
//         {
//             cout<<"*\t";
//         }
//         else
//         {
//             cout<<"\t";
//         }
//     }
// }