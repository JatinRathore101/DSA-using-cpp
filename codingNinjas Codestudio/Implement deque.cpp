#include<bits/stdc++.h>
using namespace std;

// deque implementation using doubly linked list

class Node
{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int x)
        {
            data=x;
            next=NULL;
            prev=NULL;
        }
};

class Deque
{
    public:
        Node* front;
        Node* rear;
        int cap;

        Deque(int n)
        {
            front=NULL;
            rear=NULL;
            cap=n;
        }

        bool pushFront(int x)
        {
            if(cap==0){return false;}

            cap--;Node* element=new Node(x);
            if(front==NULL){front=element;rear=element;}
            else{element->next=front;front->prev=element;front=element;}
            return true;
        }

        bool pushRear(int x)
        {
            if(cap==0){return false;}

            cap--;Node* element=new Node(x);
            if(front==NULL){front=element;rear=element;}
            else{element->prev=rear;rear->next=element;rear=element;}
            return true;
        }

        int popFront()
        {
            if(front==NULL){return -1;}

            cap++;Node* del=front;
            if(front==rear){front=NULL;rear=NULL;}
            else{front=front->next;front->prev=NULL;del->next=NULL;}
            int x=del->data;
            delete del;
            return x;
        }

        int popRear()
        {
            if(front==NULL){return -1;}

            cap++;Node* del=rear;
            if(front==rear){front=NULL;rear=NULL;}
            else{rear=rear->prev;rear->next=NULL;del->prev=NULL;}
            int x=del->data;
            delete del;
            return x;
        }

        int getFront()
        {
            if(front==NULL){return -1;}
            return front->data;
        }

        int getRear()
        {
            if(front==NULL){return -1;}
            return rear->data;
        }

        bool isEmpty()
        {
            if(front==NULL){return true;}
            return false;
        }

        bool isFull()
        {
            if(cap==0){return true;}
            return false;
        }
};

int main()
{
    return 0;
}
