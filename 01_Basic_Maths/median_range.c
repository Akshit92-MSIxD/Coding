/// AKSHIT-RAWAT , SECTION-C , ROLL NO.- 7 , ID-20011236
///Question-4

#include <stdio.h>
void selection_sort(int *ptr,int n)
{
    int temp;
    for(int i=0;i<=n-2;++i)
    {
         int min_index=i;
        for(int j=min_index+1 ; j<=n-1;++j)
        {
            if(*(ptr+j) < (*(ptr+min_index)))
            {
                min_index=j;
            }
        }
         temp=*(ptr+i);
        *(ptr+i)=*(ptr+min_index);
        *(ptr+min_index)=temp;  
    }
    printf("Sorted array elements : ");
    for(int i=0;i<=n-1;++i)
    {
        printf("%d ",*(ptr+i));
    }   
}

float median(int *ptr,int n)
{
  float med;
  if(n%2==0)
  {
      med = (*(ptr+(n/2)-1) + *(ptr+(n/2))) / 2.0 ;
  }
  else
  {
      med = *(ptr+n/2);
  }
  return med;
}

int range(int *ptr,int n)
{
    int ran = *(ptr+n-1) - *(ptr);
    return ran;
}

int main() 
{
     printf("\nAKSHIT RAWAT\n");
    int t;
    printf("\n\nEnter the no. of test cases : ");
    scanf("%d",&t);
    while(t--)
    {
    int n;
    printf("\nEnter the size of one-dimesional array : ");
    scanf("%d",&n);

    int arr[n];
    int *ptr=arr;
    printf("Enter the elements inside one-dimesional array : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",ptr+i);
    }
    selection_sort(ptr,n);
    printf("\nMedian : %0.1f\n",median(ptr,n));
    printf("Range : %d\n\n",range(ptr,n));

    }
 return 0;
}




    
    