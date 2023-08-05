// https://nados.io/question/print-permutations
// TC = O(n!) how?? please read the tutorial
// SC = O(1) , if we consider recursive stack space then it is O(length of string)


#include <iostream>
#include <string>
using namespace std;

void printPermutations(string str, string asf){
    

  if(str=="")
  {
      cout<<asf<<endl;
      return;
  }

  string temp_ques = str;

    for(int ch = 0 ; str[ch]!='\0';ch++)
    {
           temp_ques = str;

           temp_ques.erase(ch,1);

           printPermutations(temp_ques,asf+str[ch]);
        
    }

}

int main(){
    string str;
    cin>>str;
    printPermutations(str,"");
    
}
