#include<bits/stdc++.h>
using namespace std;

// think these as pointers in linked lists
// arr[i] holds data of ith node
// next[i] is next pointer of ith node
// front[i] is tail of ith linked lists // pop()
// rear[i] is head of ith linked lists // push()

void disp(int* a,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"  ";
    }
    cout<<endl;
}

class NQueue
{
    public:
        int* arr;
        int* next;
        int* front;
        int* rear;
        int freeindex;
        int N;
        int S;
        NQueue(int n, int s)
        {
            N=n;S=s;
            arr=new int[s];
            next=new int[s];
            front=new int[n];
            rear=new int[n];
            for(int i=0;i<s;i++){arr[i]=0;next[i]=i+1;}next[s-1]=-1;
            for(int i=0;i<n;i++){front[i]=-1;rear[i]=-1;}
            freeindex=0;
            cout<<"initialization"<<endl;
            cout<<"arr   => ";disp(arr,S);
            cout<<"next  => ";disp(next,S);
            cout<<"front => ";disp(front,N);
            cout<<"rear  => ";disp(rear,N);
            cout<<"freeindex = "<<freeindex<<endl<<endl<<endl;
        }

        bool enqueue(int x,int m)
        {
            if(m>N||m<1||freeindex==-1){return false;}
            int pushindex=freeindex;
            freeindex=next[pushindex];
            arr[pushindex]=x;

            if(front[m-1]==-1&&rear[m-1]==-1)
            {front[m-1]=pushindex;rear[m-1]=pushindex;next[pushindex]=-1;}
            else
            {next[rear[m-1]]=pushindex;rear[m-1]=pushindex;}

            cout<<"After pushing 1 in queue number "<<m<<endl;
            cout<<"arr   => ";disp(arr,S);
            cout<<"next  => ";disp(next,S);
            cout<<"front => ";disp(front,N);
            cout<<"rear  => ";disp(rear,N);
            cout<<"freeindex = "<<freeindex<<endl<<endl<<endl;

            return true;
        }

        int dequeue(int m)
        {
            if(front[m-1]==-1&&rear[m-1]==-1){return -1;}

            int popindex=front[m-1];
            int x=arr[popindex];arr[popindex]=0;

            if(front[m-1]==rear[m-1])
            {front[m-1]=-1;rear[m-1]=-1;}
            else{front[m-1]=next[front[m-1]];}

            next[popindex]=freeindex;
            freeindex=popindex;

            cout<<"after poping from queue number "<<m<<endl;
            cout<<"arr   => ";disp(arr,S);
            cout<<"front => ";disp(front,N);
            cout<<"rear  => ";disp(rear,N);
            cout<<"next  => ";disp(next,S);
            cout<<"freeindex = "<<freeindex<<endl<<endl<<endl;


            return x;
        }
};

int main()
{
    NQueue nq(3,4);
    nq.enqueue(1,2);
    nq.enqueue(1,1);
    nq.enqueue(1,2);
    nq.enqueue(1,2);
    nq.dequeue(1);
    nq.dequeue(2);
    nq.enqueue(1,3);
    nq.dequeue(2);
    nq.enqueue(1,1);
    nq.enqueue(1,3);
    nq.dequeue(2);
    nq.enqueue(1,1);
    nq.dequeue(3);
    nq.dequeue(1);
    nq.dequeue(3);
    nq.dequeue(1);
    return 0;
}

/*
class NQueue
{
    public:
        int* arr;
        int* next;
        int* front;
        int* rear;
        int freeindex;
        int N;
        int S;
        NQueue(int n, int s)
        {
            N=n;S=s;
            arr=new int[s];
            next=new int[s];
            front=new int[n];
            rear=new int[n];
            for(int i=0;i<s;i++){arr[i]=0;next[i]=i+1;}next[s-1]=-1;
            for(int i=0;i<n;i++){front[i]=-1;rear[i]=-1;}
            freeindex=0;
        }

        bool enqueue(int x, int m)
        {
            if(m>N||m<1||freeindex==-1){return false;}
            int pushindex=freeindex;
            freeindex=next[pushindex];
            arr[pushindex]=x;

            if(front[m-1]==-1&&rear[m-1]==-1)
            {front[m-1]=pushindex;rear[m-1]=pushindex;next[pushindex]=-1;}
            else
            {next[rear[m-1]]=pushindex;rear[m-1]=pushindex;}
            return true;
        }

        int dequeue(int m)
        {
            if(front[m-1]==-1&&rear[m-1]==-1){return -1;}

            int popindex=front[m-1];

            if(front[m-1]==rear[m-1])
            {front[m-1]=-1;rear[m-1]=-1;}
            else{front[m-1]=next[front[m-1]];}

            next[popindex]=freeindex;
            freeindex=popindex;
            return arr[popindex];
        }
};
*/
