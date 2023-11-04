/// AKSHIT-RAWAT , SECTION-C , ROLL NO.- 7 , ID-20011236
///Question-1
#include<stdio.h>
int tripose_square_matrix(int n,int arr[][n])
{
    int temp;
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            temp=arr[i][j];
          arr[i][j]=arr[j][i];
          arr[j][i]=temp;
        }
    }
    printf("The elements inside tripose of 2D array in case of square matrix are represented as : \n");
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            printf("%d  ",*(*(arr+i)+j));
            
        }
        printf("\n");
    }
}

int tripose_non_square_matrix(int r,int c,int arr[][c])
{
      int tripose[c][r];
      for(int i=0;i<r;++i)
      {
          for(int j=0;j<c;j++)
          {
              tripose[j][i]=arr[i][j];
          }
      }
     printf("The elements inside tripose of 2D array in case of non-square matrix are represented as : \n");
     for(int i=0;i<c;++i)
      {
        for(int j=0;j<r;++j)
        {
            printf("%d  ",tripose[i][j]);
            
        }
        printf("\n");
      }

}

int main()

{
    int t;
    printf("\nEnter the no. of test_cases : ");
    scanf("%d",&t);
    while(t--)
    {
    int r,c;
    printf("\nEnter the no. of rows and columns : ");
    scanf("%d %d",r,c);
    
    int arr[r][c];
    

    printf("Enter the elements inside 2D array : ");
    for(int i=0;i<r;++i)
    {
        for(int j=0;j<c;++j)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    if(r==c)
    {
        tripose_square_matrix(c,arr);
    }
    
    else
    {
        tripose_non_square_matrix(r,c,arr);
    }
     printf("\n");
    }
   

    }
    
