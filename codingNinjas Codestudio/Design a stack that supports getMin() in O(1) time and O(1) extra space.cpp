#include<bits/stdc++.h>
using namespace std;

void disp(stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<"  ";s.pop();
    }
    cout<<endl;
}

class SpecialStack
{
    public:

        stack<int> st;
        //int mini=INT_MAX;
        int mini;

        void push(int data)
        {
            if(st.empty()){st.push(data);mini = data;}
            else
            {
                int x=data;
                if(mini>data){x=2*data-mini;mini=data;}
                st.push(x);
            }
        }

        int pop()
        {
            int x=-1;
            if(!st.empty())
            {
                x=st.top();
                if(mini>st.top())
                {
                    x=mini;
                    mini=2*mini-st.top();
                }
                st.pop();
            }
            return x;
        }

        /*
        int top()
        {
            if(!st.empty())
            {
                return max(st.top(),mini);
            }
            return -1;
        }
        */

        int top()
        {
            int x=-1;
            if(!st.empty())
            {
                x=st.top();
                if(mini>st.top())
                {
                    x=mini;
                    // mini not updated
                }
                // and no st.pop() // rest all is same
            }
            return x;
        }

        bool isEmpty()
        {return st.empty();}

        int getMin()
        {
            if(!st.empty()){return mini;}
            return -1;
        }
};

int main()
{
    SpecialStack s;
    stack<int> Ost;
    int i=50;

    cout<<"initialization"<<endl;
    cout<<"Orignal stack => ";disp(Ost);
    cout<<"Special stack => ";disp(s.st);
    cout<<"s.getmin() = "<<s.getMin()<<endl;
    cout<<"s.top()    = "<<s.top()<<endl<<endl<<endl;

    while(i>0)
    {
        if(rand()%2==1)
        {
            //int x=rand()%10000000-rand()%1000000;
            int x=(rand()%90+10)*((rand()%2)*2-1);
            //if(x==-1){x=0;}
            s.push(x);Ost.push(x);
            cout<<"after pushing "<<x<<" in the special stack"<<endl;
            cout<<"Orignal stack => ";disp(Ost);
            cout<<"Special stack => ";disp(s.st);
            cout<<"s.getmin() = "<<s.getMin()<<endl;
            cout<<"s.top()    = "<<s.top()<<endl<<endl<<endl;
        }
        else if(!s.isEmpty())
        {
            s.pop();Ost.pop();
            cout<<"after poping "<<s.top()<<" from the special stack"<<endl;
            cout<<"Orignal stack => ";disp(Ost);
            cout<<"Special stack => ";disp(s.st);
            cout<<"s.getmin() = "<<s.getMin()<<endl;
            cout<<"s.top()    = "<<s.top()<<endl<<endl<<endl;
        }
        i--;
    }

    return 0;
}
