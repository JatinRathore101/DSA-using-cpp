#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node(int x)
        {
            data=x;
            next=NULL;
        }
};

class CircularQueue
{
    public:
        Node* front;
        Node* rear;
        int cap;

        CircularQueue(int n)
        {
            front=NULL;
            rear=NULL;
            cap=n;
        }

        bool enqueue(int value)
        {
            if(cap==0){return false;}

            cap--;Node* element=new Node(value);
            if(front==NULL){front=element;rear=element;}
            else{rear->next=element;rear=rear->next;rear->next=front;}
            return true;
        }

        int dequeue()
        {
            if(front==NULL){return -1;}

            cap++;Node* del=front;
            if(front==rear){front=NULL;rear=NULL;}
            else if(front->next==rear){rear->next=NULL;front=rear;}
            else {rear->next=front->next;front=rear->next;}
            del->next=NULL;
            int x=del->data;
            delete del;
            return x;
        }
};

int main()
{
    return 0;
}
