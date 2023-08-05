///  AKSHIT - RAWAT , SECTION - C, ROLL NO.= 7, ID = 20011236
/// Question - 2

#include <stdio.h>

void factor_func(int num)
{
    int i=1;
    printf("The factors of %d are : ",num);
    while(i<=num)
        {
            if(num%i==0)
            {
                printf("%d ",i);
            }
            i++;
        }
        return;
}

int main()
{
    int t;
    printf("Enter the no. of test_cases : ");
    scanf("%d",&t);
    while(t--)
    {
        int num;
        printf("\n\nEnter the value of num : ");
        scanf("%d",&num);
        factor_func(num);
    }
    printf("\n\n");
}
