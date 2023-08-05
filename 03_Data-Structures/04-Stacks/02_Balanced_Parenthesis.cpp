#include <iostream>
#include <stack>
using namespace std;

bool  check_balanced(stack<char> &s , string &str_exp)
{
         for(char ch : str_exp)
         {
            if(ch==']' || ch=='}' || ch==')')
            {
                   if(s.empty())  // if this is true ==> that means no corresponding opening bracket is found for closing bracket
                   {
                    return false;
                   }
                   else     
                   {
                    char opening_bracket;

                       if(ch==']')
                       opening_bracket = '[';

                       if(ch=='}')
                       opening_bracket = '{';

                       if(ch==')')
                       opening_bracket = '(';


                       while(!s.empty() && s.top()!=opening_bracket) // pop till corresponding opening bracket is found
                       {
                           s.pop();
                       }

                       if(s.empty())  // if stack becomes empty that means no corresponding opening bracket is found for closing bracket
                       return false;
                       
                       s.pop();     //  If stack does not becomes empty that means we have one char left in the stack and i.e corresponding opening bracket
                   }
            }
            else
            {
                s.push(ch);
            }
         }

         return s.empty();   // If all corresponding closing characters are matched with corresponding opening characters then stack must be empty that means ==> string expression is balanced
}

int main()
{
    string str_exp;
    cout<<"Enter the string expression : ";
    getline(cin,str_exp);

    stack<char> s;

    cout<<"Status : ";

    if(check_balanced(s,str_exp))
    {
       cout<<"Balanced";
    }
    else{
        cout<<"Not Balanced";
    }


}