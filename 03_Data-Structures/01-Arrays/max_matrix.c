/// AKSHIT-RAWAT , SECTION-C , ROLL NO.- 7 , ID-20011236
///Question-5

#include <stdio.h>
int main()
{
    int t;
    printf("\nEnter the number of test_cases : ");
    scanf("%d",&t);
    printf("\n");
    while(t--)
    {
     int r,c;
     printf("Enter the row size and column size of array : ");
     scanf("%d %d",&r,&c);
     int arr[r][c], *p;

     printf("Enter the elements in array : \n");
     for(p=&arr[0][0]; p<=&arr[r-1][c-1] ; p++)
     {
         scanf("%d",p);
     }

     int max=arr[0][0];
     for(p=&arr[0][0]; p<=&arr[r-1][c-1] ; p++)
     {
         if(*p>max)
         {
             max=*p;
         }
     }

     printf("Biggest element of %dx%d matrix array is : %d\n\n",r,c,max);
    }

}