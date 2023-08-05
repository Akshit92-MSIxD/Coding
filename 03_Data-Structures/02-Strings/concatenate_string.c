/// AKSHIT-RAWAT , SECTION-C , ROLL NO.- 7 , ID-20011236
///Question-2
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
   char str1[100] , str2[100] , str3[100];
   printf("Enter the string s1 : ");
   scanf("%[^\n]s",&str1);

   fflush(stdin);

   printf("Enter the string s2 : ");
   scanf("%[^\n]s",&str2);

   int i,j;

   for(i=0;str1[i]!='\0';i++)
   {
       str3[i]=str1[i];
   }
   str3[i++]=' ';

   for(j=0;str2[j]!='\0';j++)
   {
       str3[i++]=str2[j];
   }
   str3[i]='\0';

   printf("Concatenated string s3 : %s\n\n",str3);

    }

    }

 