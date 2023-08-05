/// AKSHIT-RAWAT , SECTION-C , ROLL NO.- 7 , ID-20011236
///Question-5
#include <stdio.h>
int main()
{
 printf("\nAKSHIT RAWAT\n");
    int t;
    printf("\n\nEnter the no. of test cases : ");
    scanf("%d",&t);
    printf("\n\n");

  while(t--)
  {
   fflush(stdin);
   char str[100];
   printf("Enter the string : ");
   scanf("%[^\n]s",str);

    int str_length=0,i=0,flag=1;

    while(str[i++]!='\0')
    {
        str_length++;
    }

    for(int i=0;i<(str_length/2) ; ++i)
    {     
         if(str[i]!=str[(str_length-1)-i])
         {
          flag=0;
          break;
         }   
    }
       flag?printf("String is Palindrome\n\n") :  printf("String is not Palindrome\n\n");
    }
}