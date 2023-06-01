#include<bits/stdc++.h>
using namespace std;

void POP(queue<char> &q,char x)
{
    vector<char> v;
    while(!q.empty())
    {
        if(q.front()!=x)
        {
            v.push_back(q.front());
        }
        q.pop();
    }
    if(v.size()==0){return;}
    for(auto it:v){q.push(it);}
    return;
}

string FirstNonRepeating(string A)
{
    queue<char> q;int Map[26]={0};
    int i=0,n=A.size();

    while(i<n)
    {
        if(Map[A[i]-'a']==0){Map[A[i]-'a']=1;q.push(A[i]);}
        else if(Map[A[i]-'a']==1){Map[A[i]-'a']=2;POP(q,A[i]);}

        if(!q.empty()){A[i]=q.front();}
        else{A[i]='#';}
        i++;
    }
    return A;
}

int main()
{
    string A="aabc";
    cout<<A;
    A=FirstNonRepeating(A);
    cout<<endl<<A;
    return 0;
}
