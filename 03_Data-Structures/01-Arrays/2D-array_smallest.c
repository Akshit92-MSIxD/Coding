/// AKSHIT-RAWAT , SECTION-C , ROLL NO.- 7 , ID-20011236
///Question-3
 
#include <stdio.h>

int minimum(int r,int c, int array[r][c],int *ptr)
{
    int small=array[0][0];

        for(ptr=&array[0][0] ; ptr<=&array[r-1][c-1] ; ptr++)
        {
           if(small>*ptr)
           {
               small=*ptr;
           }
        }
        return small;
}
int main()
{
    printf("\nAKSHIT RAWAT\n");
    int t;
    printf("\n\nEnter the no. of test cases : ");
    scanf("%d",&t);
    printf("\n\n");
    while(t--)
    {
        int r,c;
        printf("Enter the row and column size of 2D array : ");
        scanf("%d%d",&r,&c);
        int array[r][c];
        int *ptr;

        printf("Enter the elements inside 2D array : \n");
        for(ptr=&array[0][0] ; ptr<=&array[r-1][c-1] ; ptr++)
        {
            scanf("%d",ptr);
        }
        
        printf("\nSmallest element : %d\n\n",minimum(r,c,array,ptr));
        

    }

}