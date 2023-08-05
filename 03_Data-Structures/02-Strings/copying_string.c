/// AKSHIT-RAWAT , SECTION-C , ROLL NO.- 7 , ID-20011236
///Question-1
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
   char str1[100] , str2[100] ;
   printf("Enter the string s1 : ");
   scanf("%[^\n]s",&str1);
 
 int i;
   for(i=0;str1[i]!='\0';i++)
   {
       str2[i]=str1[i];
   }
   str2[i]='\0';

   printf("String s1 : %s\n",str1);
   printf("String s2 : %s\n\n",str2);

    }
}



