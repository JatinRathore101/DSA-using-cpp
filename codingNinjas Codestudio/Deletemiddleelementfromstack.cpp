#include<bits/stdc++.h>
using namespace std;

void disp(stack<int> inputStack)
{
    while(!inputStack.empty())
    {
        cout<<inputStack.top()<<"  ";
        inputStack.pop();
    }
    cout<<endl;
}

void dm(stack<int>&inputStack, int n)
{
    if(n==0){inputStack.pop();return;}
    int t=inputStack.top();
    inputStack.pop();
    dm(inputStack,n-1);
    inputStack.push(t);
    return;
}

void deleteMiddle(stack<int>&inputStack, int N)
{
    int n=N/2;
    dm(inputStack,n);
    return;
}

int main()
{
    stack<int> inputStack;
    vector<int> v={1,3,4,6};
    int N=v.size(),i=0;
    while(i<N){inputStack.push(v[i]);i++;}

    disp(inputStack);
    deleteMiddle(inputStack,N);
    disp(inputStack);

    return 0;
}

