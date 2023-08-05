// https://nados.io/question/print-encodings

/* Time Complexity:

   We can make atmax 2 decisions (1-length number or 2-length number), hence the time complexity will be O(2n) (exponential in nature). 


   Space Complexity :

   If we consider the space taken by the recursion call stack, then space complexity will be O(n) as the maximum depth of the recursion stack at    
   any point can be equal to the length of the numeric string. */


#include <iostream>
#include<string>
using namespace std;

string encode = " abcdefghijklmnopqrstuvwxyz";

void printEncoding(string str, string asf){
    
  if(str=="")
  {
      cout<<asf<<endl;
      return;
  }

  if(str[0]=='0')
  {
      return;
  }


    char ch = str[0];
    printEncoding(str.substr(1),asf+encode[ch-'0']);

    if(str.size()>=2)
    {
    string stol2 = str.substr(0,2);

     int stol2_to_int = stoi(stol2);

     if(stol2_to_int<=26)
     {
         printEncoding(str.substr(2),asf+encode[stol2_to_int]);
     } 
    }

    
}

int main(){
    string str;
    cin>>str;
    printEncoding(str,"");
    
}






// --------------------------------------------------------------------------------------------------------------------------------------------------






// #include <iostream>
// #include<string>
// using namespace std;


// void printEncoding(string str, string asf){
    
//   if(str=="")
//   {
//       cout<<asf<<endl;
//       return;
//   }

//   if(str[0]=='0')
//   {
//       return;
//   }


//     char ch = str[0];
//     printEncoding(str.substr(1),asf+('a' + (ch-'0') - 1);

//     if(str.size()>=2)
//     {
//     string stol2 = str.substr(0,2);

//      int stol2_to_int = stoi(stol2);

//      if(stol2_to_int<=26)
//      {
//          printEncoding(str.substr(2),asf+('a'+ stol2_to_int - 1));
//      } 
//     }

    
// }

// int main(){
//     string str;
//     cin>>str;
//     printEncoding(str,"");
    
// }
