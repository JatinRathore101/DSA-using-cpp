#include<bits/stdc++.h>
using namespace std;

// prints true if redundant brackets exist

bool findRedundantBrackets(string &s)
{
    int n=s.size();
    stack<char> st;st.push('a');
    for(int i=0;i<n;i++)
    {
        if(s[i]=='('||s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            if(st.top()=='('){return true;}
            else{while(st.top()!='('){st.pop();}st.pop();}
        }
    }
    return false;
}

int main()
{
    string s="((b-c+a/c))";
    cout<<s<<"           "<<::boolalpha<<findRedundantBrackets(s)<<endl;
    s="(a)";
    cout<<s<<"           "<<::boolalpha<<findRedundantBrackets(s)<<endl;
    s="(a+(b-c))";
    cout<<s<<"           "<<::boolalpha<<findRedundantBrackets(s)<<endl;
    return 0;
}

