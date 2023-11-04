//https://nados.io/question/rotate-an-array?zen=true

#include <iostream>
using namespace std;

void reverse(int *arr,int left,int right)
{
    while(left<right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}


void rotate(int *arr,int n , int k)
{
    k = k % n;
    if(k<0)
    {
        k+=n;
    }

  // reverse the array!!!
   reverse(arr,0,n-1);

  // reverse first k elements!!!
   reverse(arr,0,k-1);

  //  reverse remaining n-k elements!!!
   reverse(arr,k,n-1);
}


int main()
{
    int n;
    cin>>n;
    
    int* arr = new int[n];

    for(int i=0;i<=n-1;i++)
    {
        cin>>arr[i];
    }

    int k;
    cin>>k; 

    rotate(arr,n,k);


    for(int i=0;i<=n-1;i++)
    {
        cout<<arr[i]<<" ";
    }
}