// https://nados.io/question/print-kpc

/*  for ex : 6 -> pqr and 7 -> st;
 
      67 -> {ps , pt , qs, qt ,  rs , rt} (no. of combinations = 3 X 2)    */

// TIME COMPLEXITY : O(2^n) This time complexity is exponential.

// SPACE COMPLEXITY : O(1) , if we consider the space in recursive stack then --> O(n)



#include <iostream>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string ques, string asf){
   

   if(ques=="")
   {
       cout<<asf<<endl;
       return;
   }

   char ch = ques[0];

   string roq = ques.substr(1);

   int ch_to_int = (int)(ch - '0');

   string key_to_ch = codes[ch_to_int];

   for(int i=0;key_to_ch[i]!='\0';i++)
   {
       printKPC(roq,asf+key_to_ch[i]);
   }
     
}

int main(){
    string str;
    cin >> str;
    printKPC(str, "");
}