#include<bits/stdc++.h>
using namespace std;

void disp(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() <<" ";
    s.pop(); // dont call stack disp by reference, since pop operation is involved
    }
    cout<<endl;
}

int main()
{
    stack<int> s;
    s.push(21);// The values pushed in the stack should be of the same data which is written during declaration of stack
    s.push(22);
    disp(s);
    s.push(24);
    s.push(25);
    disp(s);
    int num=0;
    s.push(num);
    disp(s);
    s.pop();
    s.pop();
    disp(s);
    s.pop();
    disp(s);
}
