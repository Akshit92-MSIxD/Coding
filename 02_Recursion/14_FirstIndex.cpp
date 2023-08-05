// https://nados.io/question/first-index?zen=true
// T = O(n)

#include<iostream>
using namespace std;

int firstIndex(int arr[], int idx, int x, int n){
   
//  base case

   if(idx>n-1)
   {
       return -1;
   }

   // Self work (chalo check kr leta hu ki kahi meri first index pe to ni rakha wo elemnt jo main() maang raha)
   if(arr[idx]==x)
   {
     return idx;
   }

   int fi = firstIndex(arr,idx+1,x,n); // faith
   return fi;
}

int main()
{
    int n;
    cin >> n;
    int d;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> d;
    int p = firstIndex(arr, 0, d, n);
    cout << p << endl;
}