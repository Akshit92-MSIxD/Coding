/// AKSHIT-RAWAT , SECTION-C , ROLL NO.- 7 , ID = 20011236
/// QUESTION-2
#include <stdio.h>
int fibo(int term)
{
 if(term==1)
 {
     return 0;
 }
 else if(term==2 || term==3)
 {
      return 1;
 }
 else
 {
 return fibo(term-1)+fibo(term-2);
 }
}
int main()
{
    int t;
    printf("Enter the no. of test_cases : ");
    scanf("%d",&t);
    while(t--)
    {
    int no_of_terms;
    printf("\nEnter the no. of terms : ");
    scanf("%d",&no_of_terms);

    printf("Fibonacci series : ");

    for(int term=1 ; term <= no_of_terms ; term++)
    {
        printf("%d ",fibo(term));
    }
    printf("\n");
    }
}
