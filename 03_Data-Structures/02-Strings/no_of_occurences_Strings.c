/// AKSHIT-RAWAT , SECTION-C , ROLL NO.- 7 , ID-20011236
///Question-2
#include <stdio.h>
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
         int i=0,j=0;
         while(str[i]!='\0')
         {
             str_length++;
             i++;
         }
 int freq[str_length] , count, k,l;
 while(j<str_length)
 {
   freq[j]=-1;
   j++;
 }
 for(k=0;k<str_length;++k)
 {
  if(freq[k]!=0 && str[k]!=' ')
    {
        count=1;
     for(l=k+1;l<str_length;++l)
      {
         if(str[k]==str[l])
         {
             freq[l]=0;
             count++;
         }
      }
      freq[k]=count;
    }
 }
printf("Occurences of alphabets : \n");
for(int m=0;m<str_length;++m)
  {
    if(freq[m]>=1)
        {
            printf("%c - %d\n",str[m],freq[m]);
        }
  }
 }
printf("\n\n");
return 0;
}

     
  

 



         

