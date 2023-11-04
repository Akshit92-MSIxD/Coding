
#include <stdio.h>
int main()
{
    int t;
    printf("\nEnter the no. of test_cases : ");
    scanf("%d",&t);
    while(t--)
    {
    int r1,c1,r2,c2;
    printf("\nEnter the rows and columns  of first array : ");
    scanf("%d %d",&r1,&c1);
    printf("Enter the rows and columns  of second array : ");
    scanf("%d %d",&r2,&c2);

    int A[r1][c1] , B[r2][c2] , C[r1][c2] , sum=0;
    
    printf("\nEnter the elements inside first 2D array : ");
    for(int i=0;i<r1;++i)
    {
        for(int j=0;j<c1;++j)
        {
            scanf("%d",&A[i][j]);
        }
    }

    printf("\nEnter the elements inside second 2D array : ");
    for(int i=0;i<r2;++i)
    {
        for(int j=0;j<c2;++j)
        {
            scanf("%d",&B[i][j]);
        }
    }

    for(int i=0;i<=r1-1;++i)
    {
        for(int j=0;j<=c2-1;j++)
        {
           for(int k=0;k<=c1-1;k++)
           {
               sum+=A[i][k]*B[k][j];
           }
           C[i][j]=sum;
           sum=0;
        }
    }

    printf("\nResultant matrix after multiplication of first_matrix(%dx%d) and second_matrix(%dx%d) is shown as : \n\n",r1,c1,r2,c2);
    for(int i=0;i<=r1-1;++i)
    {
        for(int j=0;j<=c2-1;++j)
        {
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
    printf("\nOrder of resultant matrix is : %dx%d\n\n",r1,c2);
    }
}
