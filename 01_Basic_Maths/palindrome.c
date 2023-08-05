/// AKSHIT-RAWAT , SECTION-C , ID-20011236
/// Question-4
#include <stdbool.h>

bool palin_fun(int num)
{
    int temp=num,rev=0,rem;
    while(num!=0)
    {
        rem=num%10;
        rev=rev*10+rem;
        num=num/10;
    }
  if(temp==rev)
 {
     return true;
 }
 else
 {
 return false;
 }

}
int main()
{
    int t;
    printf("Enter the no. of test_cases : ");
    scanf("%d",&t);
    while(t--)
    {
    int num;
    printf("\nEnter the no. : ");
    scanf("%d",&num);

    palin_fun(num) ? printf("%d is palindrome\n",num) : printf("%d is not a palindrome\n",num);
    }
}
