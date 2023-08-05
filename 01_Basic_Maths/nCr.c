///  AKSHIT - RAWAT , SECTION - C, ROLL NO.= 7, ID = 20011236
/// Question - 4
#include <stdio.h>
void nCr_func(int n,int r)
{
unsigned long long  fact_n=1,fact_r=1,fact_n_r=1;
int i=n, j=r , k = n-r;
    while(i || j || k)
    {
        if(i>=1)
        {
            fact_n=fact_n*i--;
        }
        if(j>=1)
        {
             fact_r=fact_r*j--;
        }
        if(k>=1)
        {
           fact_n_r=fact_n_r*k--;
        }
    }
    double res = (1.0*fact_n)/(fact_r*fact_n_r);
    printf("Result of nCr is : %0.2lf\n",res);
}
int main()
{
    int t;
    printf("Enter the no. of test_cases : ");
    scanf("%d",&t);
    while(t--)
    {
 int n,r;
 printf("\nEnter the value of n : ");
 scanf("%d",&n);
 printf("Enter the value of r : ");
 scanf("%d",&r);
 nCr_func(n,r);
    }
}

