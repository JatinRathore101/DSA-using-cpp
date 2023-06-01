#include<bits/stdc++.h>
using namespace std;

void disp(queue < int >q)
{
    while(!q.empty())
    {
        cout<<q.front()<<"  ";
        q.pop();
    }
    cout<<endl;
}

void interLeaveQueue(queue < int > & q)
{
    int n=q.size();n/=2;
    queue<int> q1,q2;
    while(n>0)
    {
        q1.push(q.front());q.pop();
        n--;
    }
    while(!q.empty())
    {
        q2.push(q.front());q.pop();
    }
    while(!q1.empty())
    {
        q.push(q1.front());q1.pop();
        q.push(q2.front());q2.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(1);q.push(2);q.push(3);
    q.push(4);q.push(5);q.push(6);
    disp(q);
    interLeaveQueue(q);
    disp(q);
    return 0;
}
