// Name : Akshit Rawat , Section : B, Student-ID : 20011236
#include <stdio.h>
#include <math.h>
int check_Armstrong(int *arr,int i)
{
    int num1=arr[i],sum=0,rem,power=0;
   int num2=arr[i];
    while(num1!=0)
    {
        power++;
        num1/=10;
    }
   while(num2!=0)
    {
       rem=num2%10;
       sum=sum+(int)(pow(rem,power)+0.5);
       num2/=10;
    }
    
    if(sum==arr[i] ||arr[i]==0) 
    return 1; 
    else
    return 0; 
}
int main()
{
printf("\n\nName : Akshit Rawat , Section : B , Student ID : 20011236");
    int t;
    printf("\n\nEnter the number of testcases : ");
    scanf("%d",&t);
    while(t--){
    int n;
    printf("\nEnter the size of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements inside array : ");
    for(int i=0;i<=n-1;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    for(int i=0;i<=n-1;i++)
    {
        if(check_Armstrong(arr,i))
        printf("%d is a armstrong number\n",arr[i]);
        else
        printf("%d is not an armstrong number\n",arr[i]);
    }
    }
    
    
}