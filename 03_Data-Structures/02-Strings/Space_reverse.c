#include <stdio.h>


void reverse(char str[],int left,int right)
{
    while(left<right)
    {
        char temp;
        
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
    return;
}


int main()
{
   int n;
   scanf("%d",&n);

   fflush(stdin); // In some places , this might not work so create a variable just to digest ('\n') character !!!!
    
   char str[n+1];
   scanf("%[^\n]s",str);
   
   int left = 0, right =-1;
   
  for(int i=0;str[i]!='\0';i++)
  { 
      
          if(str[i]!=' ' && str[i-1]==' ')
          {
                left = i;
          }
       
          if(str[i]!=' ' && (str[i+1]==' ' || str[i+1] == '\0') )
          {
                right = i;
                reverse(str,left,right);
          }
       
  }
   
printf("Output : %s",str); 
 
}