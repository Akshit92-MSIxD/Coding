/// AKSHIT-RAWAT , SECTION-C , ROLL-NO.= 7 , ID = 20011236
/// QUESTION-5
#include <stdio.h>
int gcd_fun(int n1, int n2)
{
    if(n1==0)
    {
        return n2;
    }
    else if (n2==0)
    {
        return n1;
    }
    else
    {
        if(n1<n2)
            return gcd_fun(n1,n2%n1);
        else
            return gcd_fun(n1%n2,n2);
    }
}
int main()
{
    int t;
    printf("Enter the no. of test_cases : ");
    scanf("%d",&t);
    while(t--)
    {
    int n1,n2;
    printf("\nEnter the two no.s : ");
    scanf("%d%d",&n1,&n2);

    printf("Gcd of %d and %d is : %d\n",n1,n2,gcd_fun(n1,n2));
    }
}
