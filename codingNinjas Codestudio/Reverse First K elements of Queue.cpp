#include<bits/stdc++.h>
using namespace std;

void disp(queue<int> q)
{
    while(!q.empty())
    {
        cout<<q.front()<<"  ";q.pop();
    }
    cout<<endl;
}

void re(queue<int> &q, int k)
{
    if(k==0||q.empty()){return;}
    int x=q.front();
    q.pop();
    re(q,--k);
    q.push(x);
    return;
}

queue<int> reverseElements(queue<int> q, int k)
{
    re(q,k);
    int n=q.size();
    while(n>k)
    {
        int x=q.front();
        q.pop();
        q.push(x);
        n--;
    }
    return q;
}


int main()
{
    queue<int> q;
    int n=20;
    while(n>0){q.push(21-n);n--;}
    disp(q);
    q=reverseElements(q,7);
    disp(q);
    return 0;
}
