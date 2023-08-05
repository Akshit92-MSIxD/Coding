#include <stdio.h>
#include <stdbool.h>

bool issorted(int arr[],int size)
{
    // base case
    if(size==1 || size==0)
    {
        return true;
    }

    // recursive case

    if(arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        issorted(arr+1,size-1);  // baaki ka kaam function khud kr lega
    }


}

int main()

    {
        int n;

        scanf("%d",&n);
        int arr[n];

        for(int i=0;i<=n-1;i++)
        {
            scanf("%d",&arr[i]);
        }

        issorted(arr,n) ? printf("true") : printf("False");
    }