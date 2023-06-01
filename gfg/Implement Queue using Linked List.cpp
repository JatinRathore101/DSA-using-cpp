#include<bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};



int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        MyQueue *sq = new MyQueue();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }
    }

void MyQueue:: push(int x)
{
    QueueNode* element=new QueueNode(x);
    if(front==NULL){front=element;rear=element;return;}
    rear->next=element;
    rear=rear->next;
    return;
}

int MyQueue :: pop()
{
    int x=-1;
    if(front==NULL){return x;}

    QueueNode*del=front;
    if(front==rear){front=NULL;rear=NULL;}
    else{front=front->next;}
    del->next=NULL;
    x=del->data;
    delete del;
    return x;
}

