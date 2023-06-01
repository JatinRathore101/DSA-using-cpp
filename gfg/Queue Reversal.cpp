#include<bits/stdc++.h>
using namespace std;

void reve(queue<int>& q)
{
    if(q.size()<=1){return;}
    int x=q.front();
    q.pop();
    reve(q);
    q.push(x);
    return;
}

queue<int> rev(queue<int> q)
{
    reve(q);
    return q;
}

int main()
{
    queue<int> q;
    int n=rand()%10+10;
    cout<<n<<endl;//cin>>n;
    while(n--)
    {
        int x=rand()%9+1;
        cout<<x<<"  ";//cin>>x;
        q.push(x);
    }
    cout<<endl;
    queue<int> a=rev(q);
    while(!a.empty())
    {
        cout<<a.front()<<"  ";
        a.pop();
    }
    cout<<endl;
    return 0;
}
