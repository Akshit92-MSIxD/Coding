#include <stdio.h>
void swap(int *ptr1, int *ptr2)
{
*ptr1=(*ptr1)+(*ptr2); // *ptr1=(*ptr1)^(*ptr2); or *ptr1=(*ptr1)*(*ptr2); |
*ptr2=(*ptr1)-(*ptr2); // *ptr2=(*ptr1)^(*ptr2); or *ptr2=(*ptr1)/(*ptr2); |--------> (*ptr1)^=(*ptr2),(*ptr2)^=(*ptr1),(*ptr1)^=(*ptr2)
*ptr1=(*ptr1)-(*ptr2); // *ptr1=(*ptr1)^(*ptr2); or *ptr1=(*ptr1)/(*ptr2); | 
return;
}

int main()
{
    printf("\nAKSHIT RAWAT\n\n");
    int t;
    printf("Enter the no. of testcases : ");
    scanf("%d",&t);
    while(t--)
    {
    int a,b;
    printf("\n\nEnter the value of a = ");
    scanf("%d",&a);
    printf("Enter the value of b = ");
    scanf("%d",&b);

    swap(&a,&b);

    printf("After swapping :- value of a = %d , value of b = %d",a,b);
    }
    printf("\n\n");
}
