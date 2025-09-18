// https://nados.io/question/print-subsequence
// Better approach than get_subsequence wali approach!!!
// Jyada se Jyada  (n+1) function calls hi stack mai aaegi usse jyada ni ==> SC = O(n) (if stack space is considered!!!)
/* Step-by-step complexity

Recursive branching
At every character, you make 2 recursive calls →
Total calls = 2ⁿ.

Work inside each call

ques.substr(1) → takes O(n) (since substring creates a new string).

ans+ch and ans+"_" → also take up to O(n) in the worst case, because string concatenation copies characters.

So each call does O(n) work.

*** Time Complexity = Number of calls × work per call = O(n · 2ⁿ)
 
 */

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