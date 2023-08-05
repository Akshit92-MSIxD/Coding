// https://nados.io/question/string-compression?zen=true
// T = O(n)
#include<iostream>
#include<string.h>
using namespace std;

// input : wwwwaaadexxxxxx

void String_compression01(string str) // output : wadex
{
  int length = str.length();

  for(int i=0;i<length;i++)
  {
     if(str[i]!=str[i+1])
     {
        cout<<str[i];
     }
  }
  cout<<endl;
}


void String_compression02(string str) // output : w4a3dex6
{
   int length = str.length();
   int count = 1;

   for(int i=0;i<length;i++)
   {
      if(str[i]!=str[i+1])
      {
         cout<<str[i];

         if(count>1)
         {
         cout<<count;
         count = 1;
         }

      }
      else
      {
         count++;
      }
   }
}


int main()
{
    string str;
    getline(cin,str);
    String_compression01(str);
    String_compression02(str);
}