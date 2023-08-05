// Note : First you should know how to Evaluate postfix expressions and  its conversions using pen , paper and your mind :)
//  Then only you can solve this problem using Data structures(stack)!!!

/* Note : I have written methods for conversions and evaluations using pen , paper and your mind below!!!! Please read those first
      then implement its algorithm and code */

/*Concept : Postfix expressions are easier to evaluate than infix expressions because there is no precedence and associativity rule
            here to be followed*/

/* Note : if you are facing any difficulty then watch "codesnippets youtube channel" infix/postfix/prefix conversions and evaluation videos :) */



#include <iostream>
#include <stack>
#include <vector>
using namespace std;


string postfix_to_infix(string postfix) // Without stack method :  Traverse from left to right and find 'first instance' of "two operands followed by a one operator" then pick that operator and place it in between those two operands!!!
{

stack<string> infix;

for(int i=0;i<postfix.length();i++)
    {
        if(postfix[i]>='0' && postfix[i]<='9') // push the operands in stack
        {
            string s;
            s+=postfix[i];
            infix.push(s);
        }
        else
        {
            if(postfix[i]==' ')
            continue;
        
            char opr = postfix[i];

            string val2 = infix.top();
            infix.pop();

            string val1 = infix.top();
            infix.pop();

            string res;

            res = res + '(' + val1 + opr + val2 + ')'; // when operator is encountered pop the first two values from stack and place the operator accordingly(think!!:) )

            infix.push(res);
        }
}

string answer = infix.top();
infix.pop();

return answer;
  
}




string postfix_to_prefix(string postfix) // Without stack method :  Traverse from left to right and find 'first instance' of "two operands followed by a one operator" then pick that operator and place it in front of those two operands!!!
{

stack<string> prefix;

for(int i=0;i<postfix.length();i++)
{
        if(postfix[i]>='0' && postfix[i]<='9') // push the operands in stack
        {
            string s;
            s+=postfix[i];
            prefix.push(s);
        }
        else
        {
            if(postfix[i]==' ')
            continue;
        
            char opr = postfix[i];

            string val2 = prefix.top();
            prefix.pop();

            string val1 = prefix.top();
            prefix.pop();

            string res;

            res = res + opr + val1 + val2; // when operator is encountered pop the first two values from stack  and place the operator accordingly(think!!:) )

            prefix.push(res);
        }
}

string answer = prefix.top();
prefix.pop();

return answer;

}




int evaluate_postfix(string postfix) // Without stack method :  Traverse from left to right and find 'first instance' of "two operands followed by a one operator" then pick that operator and place it in between those two operands and find value!!!
{
    stack<int> operands;

    for(int i=0;i<postfix.length();i++)
    {
            if(postfix[i]>='0' && postfix[i]<='9')
            {
                operands.push(postfix[i]-'0'); // push the operands in the stack
            }
            else
            {
                if(postfix[i]==' ')
                continue;

                int val2 = operands.top();
                operands.pop();
                int val1 = operands.top();
                operands.pop();  

                int res = 0;  // when operator is encountered pop the first two values from stack and apply operations on those operands and find value and then push that value into stack back(think!!:) )

                if(postfix[i]=='+')
                res = val1 + val2;

                else if(postfix[i]=='-')
                res = val1 - val2;

                else if(postfix[i]=='*')
                res = val1 * val2;

                else
                res = val1 / val2;

                operands.push(res);
        }
    }

    int answer = operands.top();
    operands.pop();

    return answer;
}


int main()
{
    cout<<"\nEnter the postfix expression : ";
    string postfix;
    getline(cin,postfix);

    int post_res = evaluate_postfix(postfix);
    string infix = postfix_to_infix(postfix);
    string prefix = postfix_to_prefix(postfix);

    cout<<"\nEvaluation of postfix expression : "<<post_res<<endl;
    cout<<"Corresponding infix expression : "<<infix<<endl;
    cout<<"Corresponding prefix expression : "<<prefix<<endl<<endl;
 
}