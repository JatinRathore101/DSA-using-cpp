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

stack<int> pushAtBottom(stack<int>& myStack, int x) // by recurssion
{
    if(myStack.empty()){myStack.push(x);return myStack;}
    int y=myStack.top();
    myStack.pop();
    pushAtBottom(myStack,x);
    myStack.push(y);
    return myStack;
}

stack<int> pushAtBottom2(stack<int>& myStack, int x) // by iteration
{
    if(myStack.empty()){myStack.push(x);return myStack;}
    stack<int> temp;
    while(!myStack.empty())
    {
        temp.push(myStack.top());
        myStack.pop();
    }
    myStack.push(x);
    while(!temp.empty())
    {
        myStack.push(temp.top());
        temp.pop();
    }
    return myStack;
}

int main()
{
    stack<int> myStack;
    vector<int> v={1,2,3,4};
    int n=v.size(),i=0,x=7;
    while(i<n)
    {
       myStack.push(v[i]);i++;
    }

    disp(myStack);
    disp(pushAtBottom(myStack,x));
    disp(pushAtBottom2(myStack,x));
    return 0;
}

