/// AKSHIT-RAWAT , SECTION-C , ROLL NO.- 7 , ID-20011236
///Question-2
#include <stdio.h>
int main()
{
 printf("\nAKSHIT RAWAT\n");
    int t;
    printf("\n\nEnter the no. of test cases : ");
    scanf("%d",&t);
    printf("\n\n");
    while(t--)
    {
    int n;
    printf("Enter the size of one-dimesional array : ");
    scanf("%d",&n);

    int arr[n],freq[n];
    
    printf("Enter the elements inside one-dimesional array : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        freq[i]=-1;   /// -1 in freq[i] means frequency of (element at index i) or arr[i] is not counted  
    }
    int count;

    for(int i=0;i<n;++i)
    {
       count = 1;
       for(int j=i+1;j<n;++j)
       {
           if(arr[i]==arr[j])
           {
               count++;
               freq[j]=0;      /// 0 in freq[i] means frequency of (element at index i) or arr[i] is counted already 
           }
          
       }
       if(freq[i]!=0)    // if frequency of arr[i] is not counted or gonna be counted first time then :-         
       {                          
         freq[i]=count;
       }
    }

    printf("\nFrequency of all elements of array : \n");
    for(int i=0; i<n; i++)
    {
        if(freq[i] != 0)
        {
            printf("%d occurs %d times\n", arr[i], freq[i]);
        }
    }
    printf("\n\n");
}
}
