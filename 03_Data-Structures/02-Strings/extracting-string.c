/// AKSHIT-RAWAT , SECTION-C , ROLL NO.- 7 , ID-20011236
///Question-3
#include <stdio.h>
void string_extract(char str[], int n,int m , int str_length)
{
    char ex_str[str_length+1];
    if(m<=str_length-n)
    {
    int i,j=0;
    for( i=n;i<n+m;i++)
    {
        ex_str[j++]=str[i]; 
    }
    ex_str[j]='\0';
    printf("Extracted string is : %s\n\n",ex_str);
    }
    else
    {
        printf("Error!!! Invalid extraction of some no. of characters present outside the string length boundary\n\n ");
    }
}
int main()
{
printf("\n\nAKSHIT RAWAT");
int t;
printf("\n\nEnter the no. of test_cases : ");
scanf("%d",&t);
while(t--)
 {
         fflush(stdin);
         char str[50];
         int str_length=0;
         printf("\n\nEnter the string : ");
         scanf("%[^\n]s",str);
         fflush(stdin);
         int m,n;
         printf("Enter the position from where you want to start extraction of characters : ");
         scanf("%d",&n);
         printf("Enter the number of characters to be extracted : ");
         scanf("%d",&m);
         for(int i=0;str[i]!='\0';i++)
         {
             str_length++;
         }
         string_extract(str,n-1,m,str_length);
  }
}

