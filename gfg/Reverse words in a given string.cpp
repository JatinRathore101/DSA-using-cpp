#include<bits/stdc++.h>
using namespace std;

string reverseWords(string S)
{
    string ans="";
    string subStr="";

    for(auto it:S)
    {
        if(it!='.')
        {
            subStr+=it;
        }
        else
        {
            subStr='.'+subStr;
            ans=subStr+ans;
            subStr="";
        }
    }

    return subStr+ans;
}

int main()
{
    return 0;
}

