// https://leetcode.com/problems/valid-parentheses/description/ (related question : valid parenthesis)

// TC : O(n) , SC : O(n)(size of string)
#include <iostream>
#include <stack>
using namespace std;


void check_duplicacy(stack<char> &s , string str_exp)
{
   
 for(char ch : str_exp)     // check every char of string expression with the stack
 {
    if(ch==')')          // If ')' pop till '('
    {
            if(s.top()=='(')  // if '(' is encountered on top of stack that means ki closing aur opening bracket ke paas apna content hai hi ni ==> duplicacy hogi
            {
                cout<<"true";
                return;
            }
            else{     // pop till '(' is found

                while(s.top()!='(')
                {
                    s.pop();
                }
                s.pop();   // popping '('
            }
 
    }
    else        // If normal characters like alphabet,operator and '(' just push them into stack
    {
        s.push(ch);
    }

 }

 cout<<"false";
 return;

}

int main()
{
    stack<char> s;


    cout<<"Enter the string expression : ";
    string str_exp;
    getline(cin,str_exp);
  
   cout<<"Duplicacy : ";
   check_duplicacy(s,str_exp);


}