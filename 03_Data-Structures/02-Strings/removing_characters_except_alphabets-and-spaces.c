/// AKSHIT-RAWAT , SECTION-C , ROLL NO.- 7 , ID-20011236
///Question-4
#include <stdio.h>
int main()
{
printf("\n\nAKSHIT RAWAT");
int t;
printf("\n\nEnter the no. of test_cases : ");
scanf("%d",&t);
printf("\n\n");
while(t--)
{
    fflush(stdin);
    char str[200];
    printf("Enter the string : ");
    scanf("%[^\n]s",str);
  int i,j;
  for(int i=0;str[i]!='\0';i++)
  {
      while( !((str[i]>='a' && str[i]<='z')  ||  (str[i]>='A' && str[i]<='Z')  ||  (str[i]==' ')  ||  (str[i]=='\0')) )
      {
          for(j=i;str[j]!='\0';j++)
          {
              str[j]=str[j+1];
          }
          str[j]='\0';
      }
  }
  printf(" \nAfter removing all punctuation characters :\n\nResulted string :  %s\n\n\n\n",str);
 }
}