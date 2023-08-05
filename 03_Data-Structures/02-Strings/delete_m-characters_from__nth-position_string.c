/// AKSHIT-RAWAT , SECTION-C , ROLL NO.- 7 , ID-20011236
///Question-5
#include <stdio.h>
char* get_string(char str[],int n,int m,int str_length)
{
    for(int i=m+n;i<=str_length;i++)
    {
        str[i-m]=str[i];
    }
    return str;
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
    char str[200];
    int m,n;
    printf("Enter the string : ");
    scanf("%[^\n]s",str);
    printf("Enter the position from where you would like to start deletion in a string : ");
    scanf("%d",&n);
    printf("Enter the no. of characters you would like to delete from a string : ");
    scanf("%d",&m);
    int str_length=0;
    for(int i=0;str[i]!='\0';++i)
    {
        str_length++;
    }
    printf("Resulted string : %s\n\n", get_string(str,n-1,m,str_length));
}
}