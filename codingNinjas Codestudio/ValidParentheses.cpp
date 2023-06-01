#include<bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string expression)
{
    stack<char> s;s.push('a');
    for(int i=0;i<expression.size();i++)
    {
        if(expression[i]=='}')
        {
            if(s.top()=='{'){s.pop();}
            else{return false;}
        }
        else if(expression[i]==']')
        {
            if(s.top()=='['){s.pop();}
            else{return false;}
        }
        else if(expression[i]==')')
        {
            if(s.top()=='('){s.pop();}
            else{return false;}
        }
        else
        {
            s.push(expression[i]);
        }
    }s.pop();

    return s.empty();

}

int main()
{
    string expression="{{}}[]";
    cout<<::boolalpha<<isValidParenthesis(expression);
    return 0;
}

