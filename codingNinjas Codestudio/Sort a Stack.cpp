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

void pushAtCorrectPosition(stack<int> &stack,int x)
{
    if(stack.empty()){stack.push(x);return;}
    else if(stack.top()<=x){stack.push(x);return;}

    int y=stack.top();
    stack.pop();
    pushAtCorrectPosition(stack,x);
    stack.push(y);
    return;
}

void sortStack(stack<int> &stack)
{
    if(stack.empty()){return;}

    int x=stack.top();
    stack.pop();
    sortStack(stack);
    pushAtCorrectPosition(stack,x);
    return;
}

int main()
{
    stack<int> myStack;
    vector<int> v={1,3,-1,0,-13,41};
    int n=v.size(),i=0;
    while(i<n)
    {
       myStack.push(v[i]);i++;
    }

    disp(myStack);
    sortStack(myStack);
    disp(myStack);

    return 0;
}

