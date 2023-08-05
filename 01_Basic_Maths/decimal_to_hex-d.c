#include <stdio.h>
int main()
{
    printf("Akshit Rawat\n\n");
    int num;
    printf("Enter the decimal no. : ");
    scanf("%d",&num);

    char arr[10];
    int rem,i=0,temp;
    temp=num;

    while(num!=0)
    {
        rem=num%16;

        if(rem<=9)
        {
            arr[i]=rem+48; /// 48 is added if rem<=9
        }
        else
        {
           arr[i]=rem+55; ///  55 is added if rem>=9 && rem<=15
        }
        num=num/16;
            i++;
    }

        printf("The hexadecimal equivalent of %d is : ",temp);
        for(int j=i-1;j>=0;j--)
        {
            printf("%c",arr[j]);
        }

}










