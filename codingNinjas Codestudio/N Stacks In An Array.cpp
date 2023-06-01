#include<bits/stdc++.h>
using namespace std;

// think these as pointers in linked lists
// arr[i] holds data of ith node
// next[i] is next pointer of ith node
// top[i] is head of ith linked lists

void disp(int* a,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<setw(5)<<a[i];
    }
    if(n==3){cout<<"     ";}
    cout<<"      size = "<<n<<endl;
}

class NStack
{
    public:
        int* arr;
        int* next;
        int* top;
        int freeindex;
        int A;
        int B;

        NStack(int N, int S)
        {
            A=N;
            B=S;
            arr=new int[S];
            next=new int[S];
            top=new int[N];
            for(int i=0;i<S;i++){next[i]=i+1;arr[i]=0;}next[S-1]=-1;
            for(int i=0;i<N;i++){top[i]=-1;}
            freeindex=0;
            cout<<"initialization"<<endl;
            disp(arr,B);
            disp(next,B);
            disp(top,A);
            cout<<"                          freeindex  =  "<<freeindex<<endl<<endl;
        }

        bool push(int x, int m)
        {
            if(freeindex==-1){cout<<"stack overflow"<<endl<<endl;return false;}

            int pushindex=freeindex;
            arr[pushindex]=x;
            freeindex=next[pushindex];
            next[pushindex]=top[m-1];
            top[m-1]=pushindex;
            cout<<"After pushing "<<x<<" in stack number "<<m<<endl;
            disp(arr,B);
            disp(next,B);
            disp(top,A);
            cout<<"                          freeindex  =  "<<freeindex<<endl<<endl;
        }

        int pop(int m)
        {
            if(top[m-1]==-1){cout<<"stack underflow"<<endl<<endl;return -1;}

            int popindex=top[m-1];
            int x=arr[popindex];
            arr[popindex]=0;
            top[m-1]=next[popindex];
            next[popindex]=freeindex;
            freeindex=popindex;
            cout<<"After poping an element from stack number "<<m<<endl;
            disp(arr,B);
            disp(top,A);
            disp(next,B);
            cout<<"                          freeindex  =  "<<freeindex<<endl<<endl;
            return x;
        }
};

int main()
{
    NStack nst(3,4);
    nst.push(1,2);
    nst.push(1,1);
    nst.push(1,2);
    nst.push(1,2);
    nst.pop(1);
    nst.pop(2);
    nst.push(1,3);
    nst.pop(2);
    nst.push(1,1);
    nst.push(1,3);
    nst.pop(2);
    nst.push(1,1);
    nst.pop(3);
    nst.pop(1);
    nst.pop(3);
    nst.pop(1);
    return 0;
}

