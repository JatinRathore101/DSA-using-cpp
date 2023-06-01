#include<bits/stdc++.h>
using namespace std;

void disp(stack<int> myStack)
{
    while(!myStack.empty())
    {
        cout<<myStack.top()<<"  ";
        myStack.pop();
    }
    cout<<endl;
}

void pushAtBottom(stack<int> &stack,int x)
{
    if(stack.empty()){stack.push(x);return;}
    int y=stack.top();
    stack.pop();
    pushAtBottom(stack,x);
    stack.push(y);
    return;
}

void reverseStack(stack<int> &stack)
{
    if(stack.empty()){return;}
    int x=stack.top();
    stack.pop();
    reverseStack(stack);
    pushAtBottom(stack,x);
    return;
}

int main()
{
    stack<int> myStack;
    vector<int> v={1,2,3,4};
    int n=v.size(),i=0;
    while(i<n)
    {
       myStack.push(v[i]);i++;
    }

    disp(myStack);
    reverseStack(myStack);
    disp(myStack);

    return 0;
}

