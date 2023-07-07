#include<bits/stdc++.h>
using namespace std;

string reArrangeString(string &s)
{
    if(s.size()<2){return s;}

    int n=s.size()/2;if(s.size()%2!=0){n++;}
    int m=0;char ch;
    unordered_map<char,int> Map;
    for(auto it:s)
    {
        Map[it]++;
        if(Map[it]>m){m=Map[it];ch=it;}
    }
    if(m>n){return "not possible";}

    n=s.size();int i;
    for(i=0;i<m;i++)
    {
        s[i*2]=ch;
    }
    Map.erase(ch);

    i*=2;
    for(auto it:Map)
    {
        while(it.second>0)
        {
            if(i>=n){i=1;}
            s[i]=it.first;
            i+=2;
            it.second--;
        }
    }
    return s;
}

int main()
{
    string s="abaab";
    cout<<reArrangeString(s);
    return 0;
}

