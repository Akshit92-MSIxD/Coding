/// AKSHIT-RAWAT , SECTION-C , ROLL NO.- 7 , ID-20011236
///Question-6
#include <stdio.h>
#include <math.h>

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
    printf("Enter the size of array : ");
    scanf("%d",&n);

    float arr[n],sum1=0.0, mean,std_dev,sum2=0.0;
    float *ptr;
    ptr=arr;
    printf("Enter the elements inside array : ");
    for(int i=0;i<n;++i)
    {
    scanf("%f",ptr+i);
    sum1+=*(ptr+i);
    }
    mean=sum1/n;

    for(int i=0;i<n;++i)
    {
        sum2+=(*(ptr+i) - mean) * (*(ptr+i) - mean);
    }

    printf("Standard deviation of given integers present in array is : %0.2f\n\n",sqrt(sum2/n));
    }
    
}


    



