/// AKSHIT-RAWAT , SECTION-C , ROLL NO.- 7 , ID-20011236
///Question-2

#include <stdio.h>
int main()
{
    int n,small;
    printf("Enter the size of one-dimesional array : ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the elemenenst inside one-dimesional array : ");
    for(int i=0;i<n;++i)
    {
        scanf("%d",&arr[i]);
        if(i==0)
        {
         small=arr[0];
        }
        else if(arr[i]<small)
        {
           small=arr[i];
        }
    }
printf("Smallest element present inside array is : %d",small);
}