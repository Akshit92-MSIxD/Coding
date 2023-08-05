/// AKSHIT-RAWAT , SECTION-C , ROLL NO.- 7 , ID-20011236
///Question-3
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

    int str_length=0,i=0;

    while(str[i++]!='\0')
    {
        str_length++;
    }

    for(int i=0;i<((str_length)/2);++i)
    {
        char temp;
        temp=str[i];
        str[i]=str[(str_length-1)-i];
        str[(str_length-1)-i]=temp;
    }

    printf("reversed string : %s\n\n",str);
}

}