#include<bits/stdc++.h>
using namespace std;

int findMinimumCost(string str)
{
    int n=str.size();
    if(n%2!=0){return -1;}
    stack<char> s;s.push('a');
    for(int i=0;i<n;i++)
    {
        if(str[i]=='}'&&s.top()=='{'){s.pop();}
        else{s.push(str[i]);}
    }

    int i=0,j=0;
    while(s.top()!='a')
    {
        if(i%2==0&&s.top()=='{'){j++;}
        else if(i%2==1&&s.top()=='}'){j++;}
        i++;s.pop();
    }
    return j;
}

int main()
{
    string s="{{}}{{}}{{{{";
    cout<<findMinimumCost(s);
    return 0;
}

