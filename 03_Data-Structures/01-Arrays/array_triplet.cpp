#include <iostream>
using namespace std;
int  pairSum(int arr[],int n, int X)
{
    int count_pair=0;
for(int i=0;i<=n-1;i++)
    {
        for(int j=1;j<=n-1;j++)
        {
        if(i<j)
        {
            if( (arr[i]+arr[j])==X)
            {
                         count_pair++;
            }
        }

        }
    }
    return count_pair;
    }

int main()
{
    int n,X;
    cin>>n;
    int arr[n];
    for(int i=0;i<=n-1;i++)
    {
        cin>>arr[i];
    }
    cin>>X;
    cout<<pairSum(arr,n,X);
}
