/// AKSHIT-RAWAT , SECTION-C , ROLL NO.- 7 , ID-20011236
///Question-1

#include <stdio.h>

void swap_cyclic(int *ptr1, int *ptr2 , int *ptr3)
{
    int temp1,temp2;
    
    temp1=*ptr2;
    *ptr2=*ptr1;
    temp2=*ptr3;
    *ptr3=temp1;
    *ptr1=temp2;
}

int main()
{
     printf("\nAKSHIT RAWAT\n");
    int t;
    printf("\nEnter the no. of test cases : ");
    scanf("%d",&t);
    printf("\n\n");
    while(t--)
    {
    int a,b,c;
    printf(" Enter a, b and c respectively : ");
    scanf("%d %d %d",&a,&b,&c);

    printf("\n Values before swapping :\n a = %d\n b = %d\n c = %d\n",a,b,c);
    swap_cyclic(&a,&b,&c);
    printf("\n Values after swapping :\n a = %d\n b = %d\n c = %d\n\n\n",a,b,c);
    }

}