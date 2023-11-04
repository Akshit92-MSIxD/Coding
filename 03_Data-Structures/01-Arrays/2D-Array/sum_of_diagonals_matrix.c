/// AKSHIT-RAWAT , SECTION-C , ROLL NO.- 7 , ID-20011236
///Question-2  
#include <stdio.h>
int main()
{
int t;
    printf("\nEnter the no. of test_cases : ");
    scanf("%d",&t);
    while(t--)
    {
    int r,c,sum1=0,sum2=0;
    printf("\nEnter the no. of rows and columns of array : ");
    scanf("%d %d",&r,&c);
    
    int arr[r][c];

    printf("Enter the elements inside 2D array : ");
    for(int i=0;i<r;++i)
    {
        for(int j=0;j<c;++j)
        {
            scanf("%d",&arr[i][j]);
            if(i==j)
            {
                sum1+=arr[i][j];
            }
            if(i+j==c-1)
            {
                sum2+=arr[i][j];
            }
        }
    }

        printf("Sum of Principal Diagonal is : %d\n",sum1);
        printf("Sum of Secondary Diagonal is : %d\n",sum2);

    }
    }


