#include <iostream>   // Swapping alternate numbers
using namespace std;
void swap_alternate(int arr[],int n)
{
    int temp;
     if(n%2==0)
    {
        for(int i=0;i<=n-1;i=i+2)
        {
        temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
        }
    }
    else
    {
        for(int j=0;j<=n-2;j=j+2)
        {
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
        }
    }
    for(int k=0;k<=n-1;k++)
    {
        cout<<arr[k]<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<=n-1;i++)
    {
        cin>>arr[i];
    }
    swap_alternate(arr,n);
}
