/// AKSHIT-RAWAT , SECTION-C , ROLL NO.- 7 , ID-20011236
#include <stdio.h>
#define MAX_VALUE 20
int strcmp(char str1[MAX_VALUE], char str2[MAX_VALUE])
{
        int i=0 , flag=1;
        while(str1[i]!='\0' || str2[i]!='\0')
        {
            if(str1[i]!=str2[i])
            {
                flag=0;
                break;
            }
            i++;
        }
   return flag;
}
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
         char str1[MAX_VALUE] , str2[MAX_VALUE];
         printf("Enter the string 1 : ");
         scanf("%[^\n]s",str1);
         fflush(stdin);
         printf("Enter the string 2 : ");
         scanf("%[^\n]s",str2);
         strcmp(str1,str2) ? printf("Result : Both strings are identical\n\n") : printf("Result : Both strings are not identical\n\n") ;   
    }
    return 0;
}