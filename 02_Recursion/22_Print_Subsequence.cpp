// https://nados.io/question/print-subsequence
// Better approach than get_subsequence wali approach!!!
// Jyada se Jyada  (n+1) function calls hi stack mai aaegi usse jyada ni ==> SC = O(n) (if stack space is considered!!!)
// TC = O(n)

// Watch video again or read tutorial for better understanding!!!



#include <iostream>
using namespace std;

void printSS(string ques, string ans){

if(ques=="")
{
    cout<<ans<<endl;;
    return;
}

char ch = ques[0];

string roq = ques.substr(1);

printSS(roq,ans+ch);  // ek baar pehla character string ka aaega 

printSS(roq,ans+"_");     // ek baar ni aaega 

    
}

int main(){
    string str;
    cin >> str;
    printSS(str, "");
}