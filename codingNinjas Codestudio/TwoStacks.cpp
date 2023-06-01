#include<bits/stdc++.h>
using namespace std;

class TwoStack
{
    public:
        int arr[100001];
        int cap;
        int top1;
        int top2;
        TwoStack(int s)
        {
            cap=s;
            top1=-1;
            top2=s;
        }

        void push1(int num)
        {
            if(top1<top2-1)
            {
                top1++;
                arr[top1]=num;
            }
        }

        void push2(int num)
        {
            if(top1<top2-1)
            {
                top2--;
                arr[top2]=num;
            }
        }

        int pop1()
        {
            if(top1>-1)
            {
                top1--;
                return arr[top1+1];
            }
            return -1;
        }

        int pop2()
        {
            if(top2<cap)
            {
                top2++;
                return arr[top2-1];
            }
            return -1;
        }
};

int main()
{
    return 0;
}
