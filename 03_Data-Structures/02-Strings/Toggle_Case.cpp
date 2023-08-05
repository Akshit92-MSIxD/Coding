#include<iostream>
#include<string>
using namespace std;

// Refer to ASCII code table !!!
// Approach 1 : 

  // for(int i=0;i<=length-1;i++)
  // {
  //   if(str[i]>='a' && str[i]<='z')
  //   {
  //       str[i] = int(str[i]) - 32; 
  //   }
  //   else if(str[i]>='A' && str[i])<='Z')
  //   {
  //     str[i] = int(str[i]) + 32;
  //   }
  // }



// Approach 2 : 
// Note :  lc - 'a' == upc - 'A'

void togglecase(string &str)
{
  int length = str.length();

  for(int i=0;i<=length-1;i++)
  {
    if(str[i]>='a' && str[i]<='z')
    {
      char lc = str[i];
      char upc = (char)('A' + lc - 'a');
      str[i] = upc;
    }
    else if(str[i]>='A' && str[i]<='Z')
    {
      char upc = str[i];
      char lc = (char)('a' + upc - 'A');
      str[i] = lc;
    }
  }

}

void display(string str)
{
  int length = str.length();

  for(int i=0;i<=length-1;i++)
  {
    cout<<str[i];
  }
}

int main() {
  string str;
  getline(cin, str);
  togglecase(str);
  display(str);
  return 0;
}