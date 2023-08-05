// Infix expression : jo humans ko samaj aaye!!!

/* Modified Shunting yard Algo :  https://www.geeksforgeeks.org/expression-evaluation/ (read it please!!!!imp!!!!) 
 
 -- Make two stacks one for storing operators and one for storing operands.
 -- Traverse the string expression from left to right.
 -- If '(' is encountered ==> push inside the operators stack
 -- If  nums '0-9' is encountered push inside operands stack after converting into integer i.e ('num' -'0')
 -- If ')' is encountered pop till '(' is found and simultaneously perform the operations in the operands stack
 -- If '+' || '-'|| '/' || '*' is encountered then pop till operator stack is empty && '(' is encountered && precedence of top 'opr' is greater than equal to current opr.

 -- Question - Why we are poping those operators whose precendence > = precedence of current operator found in str_expression???
 -- Answer - Beacause jinki precendence jyada hai unka hak banta hai pehle evaluate hone ka aur jab precedence equal hai tab jo pehle stack mai aaya ho uska bhi hak banata hai ki wo pehle evaluate ho!!!

 -- Finally after the whole string_expression traversal => if there is some operators/operator present inside operator stack then pop them until the operators stack is not empty and simultaneously simultaneously perform the operations in the operands stack

*/


// TC : O(n) , SC : O(n) (operator stack space + operand stack space)

// ***NOTE*** : This is basic algorithm which works only for non-unary operators ( cases like -5 , -(-5) ) will not work
// *** I have kept this algorithm as simple as possible and according to given constraints you can modify the above algorithm.
//Solve Question : Basic Calculator and Basic Calculator 2 on leetcode with optimal approach when you will come to DSA LEVEL-2 sheet

#include <iostream>
#include <stack>
#include <vector>
using namespace std;


int precedence(char ch)
{
    int pvalue;
    switch(ch)
    {
     case '+' : pvalue = 1;
                break;
     case '-' : pvalue = 1;
                break;
     case '*' : pvalue = 2;
                break;
     case '/' : pvalue = 2;
                break;
    }

    return pvalue;
}

int operation(int left , int right , char opr)
{
    int res;

         if(opr == '+')
        res = left + right;

        else if(opr == '-')
        res = left - right;

        else if(opr == '*')
        res = left * right;

        else
        res = left/right;
        
        return res;
}
 

int evaluate_infix(string s) {


    stack<int> operands;
    stack<char> operators;

    for(int i=0;i<s.length();i++)
    {
        char ch = s[i];

        if(ch==' ')
        {
            continue;
        }

        if(ch == '(')
        {
        operators.push(ch);
        }
        else if(ch==')')
        {
              while(operators.top()!='(')
            {
                int res;

                char opr = operators.top();
                operators.pop();

                int right = operands.top();
                operands.pop();

                int left = operands.top();
                operands.pop();

                res = operation(left,right,opr);  
 
                operands.push(res);

            }

            operators.pop();
        }

        else if(ch=='-' || ch=='+' || ch=='*' || ch=='/')
        {
             while( !operators.empty() && precedence(operators.top()) >= precedence(ch)  && operators.top()!='(' )
             {
                 int res;

                 char opr = operators.top();
                 operators.pop();

                 int right  = operands.top();
                 operands.pop();

                 int left = operands.top();
                 operands.pop();

                 res = operation(left,right,opr);      

                operands.push(res);
             }
             operators.push(ch);
        }
        else
        {
            int val = ch-'0';
            operands.push(val); 
        }
        // If given expression consists of more than one digit integers then use this and remove above one!!!!

        //  int val = 0;

        //    while(i<s.length() && isdigit(s[i]))
        //    {
        //        val = val*10 + (s[i] - '0');
        //        i++;
        //    }
        //    i--;

        //    operands.push(val);
    }



     while(!operators.empty())
     {
             int res;

                char opr = operators.top();
                operators.pop();

                int right = operands.top();
                operands.pop();


                int left = operands.top();
                operands.pop();

                res = operation(left,right,opr); 

                operands.push(res); 
     }
          
      int answer = operands.top();
      operands.pop();

    return answer;

}

        
    


int main()
{
    string str_exp;
    cout<<"Enter the string expression : ";
    getline(cin,str_exp);
   
    int answer = evaluate_infix(str_exp);

    cout<<"Evaluation of string expression evaluate to : "<<answer;

}