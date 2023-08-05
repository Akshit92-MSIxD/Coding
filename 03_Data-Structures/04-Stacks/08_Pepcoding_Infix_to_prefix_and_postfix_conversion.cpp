// TC : O(n) , SC : O(n)
// Note : We have used same modified shunt yard algorithm here(used in infix evaluation!!!)
// Prefix and Postfix are notations for mathematical expressions
// Prefix rule : operator operand1 operand2
// Postfix rule : operand1 operand2 operator



#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int precedence(char opr)
{
    int val = -1;
    if(opr == '-' || opr=='+')
     val = 1;

    if(opr == '/' ||  opr=='*')
     val =  2;

     return val;

}


vector<string> get_prefix_postfix(string &str_exp)
{
     stack<string> prefix;  
     stack<string> postfix;
     stack<char> operators;

       for(int i=0;i<str_exp.length();i++)
       {

         char ch = str_exp[i];

         if(ch == ' ')
         {
            continue;
         }

         if(ch == '(')
         {
            operators.push('(');
         }
         else if( ch>='a' && ch<='z' || ch>='A' && ch<='Z' || ch>='0' && ch<='9')
         {
            string val = "";
            val = val + ch;
            prefix.push(val);
            postfix.push(val);
         }
         else if(ch == ')')
         {
                   while(operators.top()!='(')
                   {
                       char opr = operators.top();
                       operators.pop();

                       string pre_val2 = prefix.top();
                       prefix.pop();
                       string pre_val1 = prefix.top();
                       prefix.pop();

                       string post_val2 = postfix.top();
                       postfix.pop();
                       string post_val1 = postfix.top();
                       postfix.pop();

                       string pre_res = opr + pre_val1 + pre_val2 ;  // prefix : oprv1v2

                       string post_res = post_val1 + post_val2 + opr; // postfix : v1v2opr

                       prefix.push(pre_res);
                       postfix.push(post_res);

                   }
                   operators.pop();
         }
         else  // '+' || '-' || '*' || '/'
         {
               while(!operators.empty() && operators.top()!='(' && precedence(operators.top())>= precedence(ch) )
                   {
                       char opr = operators.top();
                       operators.pop();

                       string pre_val2 = prefix.top();
                       prefix.pop();
                       string pre_val1 = prefix.top();
                       prefix.pop();

                       string post_val2 = postfix.top();
                       postfix.pop();
                       string post_val1 = postfix.top();
                       postfix.pop();

                       string pre_res = opr + pre_val1 + pre_val2 ;  // prefix : oprv1v2

                       string post_res = post_val1 + post_val2 + opr; // postfix : v1v2opr

                       prefix.push(pre_res);
                       postfix.push(post_res);

                   }
                   operators.push(ch);
         }

       }

       while(!operators.empty())
       {

            char opr = operators.top();
            operators.pop();

            string pre_val2 = prefix.top();
            prefix.pop();
            string pre_val1 = prefix.top();
            prefix.pop();

            string post_val2 = postfix.top();
            postfix.pop();
            string post_val1 = postfix.top();
            postfix.pop();

            string pre_res = opr + pre_val1 + pre_val2 ;  // prefix : oprv1v2

            string post_res = post_val1 + post_val2 + opr; // postfix : v1v2opr

            prefix.push(pre_res);
            postfix.push(post_res);
       }

        vector<string> conversions;

        conversions.push_back(prefix.top()); 
        prefix.pop();

        conversions.push_back(postfix.top()); 
        postfix.pop();

        return conversions;

}

int main()
{
    string str_exp;
    cout<<"\nEnter the infix expression : ";
   getline(cin,str_exp);


    vector<string> conversions = get_prefix_postfix(str_exp);

   cout<<"Corresponding Prefix Expression : "<<conversions[0]<<endl;
   cout<<"Corresponding Postfix Expression : "<<conversions[1];


}