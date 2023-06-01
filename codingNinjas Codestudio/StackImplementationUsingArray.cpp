#include<bits/stdc++.h>
using namespace std;

class Stack
{
    public:
        int arr[1001];
        int t;
        int c;

        Stack(int capacity)
        {
            c=capacity;
            t=-1;
        }

        void push(int num)
        {
            if(t<c-1)
            {
                t++;
                arr[t]=num;
            }
        }

        int pop()
        {
            if(t>-1)
            {
                return arr[t--];
            }
            return -1;
        }

        int top()
        {
            if(t>-1)
            {
                return arr[t];
            }
            return -1;
        }

        int isEmpty()
        {
            if(t>-1)
            {
                return 0;
            }
            return 1;
        }

        int isFull()
        {
            if(t<c-1)
            {
                return 0;
            }
            return 1;
        }
};

int main()
{
    Stack s(100);
    s.push(10);
    s.push(-11);
    s.push(13);
    s.push(20);
    s.push(-12);
    s.push(33);
    int x=s.pop();x=s.pop();

    while(!s.isEmpty())
    {
        cout<<s.top()<<"  ";s.pop();
    }

    return 0;
}

