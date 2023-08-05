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

   int count=0,count_word,i=0;

   while(str[i]!='\0')
   {
        if(str[i]==' ' && str[i+1]!=' ')
        {
            count++;
        }
        i++;
   }

   count_word=count+1;
   printf("No. of words in a string : %d\n\n",count_word);
  }
}