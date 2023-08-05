#include <stdbool.h>           /// AKSHIT-RAWAT , SECCTION-C , ID : 20011236
bool perfect_fun(int num)      /// Question-2
{
    int sum=0;
    for(int i=1;i<=num/2;i++)
    {
        if(num%i==0)
        {
        sum=sum+i;
        }
    }
        if(sum==num)
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
    printf("\n");
    while(t--)
    {
  int num;
  printf("Enter the number : ");
  scanf("%d",&num);

  if(perfect_fun(num))
  {
      printf("%d is a perfect no.\n\n",num);
  }
  else
  {
      printf("%d is not a perfect no.\n\n",num);
  }
    }
}
