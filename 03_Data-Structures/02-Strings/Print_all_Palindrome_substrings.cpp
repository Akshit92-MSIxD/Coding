// https://nados.io/question/print-all-palindromic-substrings?zen=true
// Please try this question different approaches!!!

#include<iostream>
#include<string.h>
using namespace std;


bool palindrome(string s)
{
  int length = s.length();

   int left = 0 , right = length - 1;

   while(left<right)
   {
     if(s[left] != s[right])
     {
       return 0;
     }
     left++ ;
     right--;
   }

   return 1;
}


void printallpalindrome(string str) // T = O(n^3) , SC = O(n)
{
  
   int  length = str.length();

    for(int i=0;i<=length-1;i++) // substring starting from specific index
    {
      for(int j = 1 ; j <= length - i ; j++ ) // substring of length j starting from specific index
      {
          string s = str.substr(i,j);
          
          if(palindrome(s))
          {
            cout<<s<<endl;
          }
      }
    }
}


int main()
{
    string str;
    getline(cin,str);
    printallpalindrome(str);
    return 0;
}