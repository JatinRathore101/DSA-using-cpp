#include<bits/stdc++.h>
using namespace std;

// array implementation

class CircularQueue
{
    public:
        int arr[1001];
        int front;
        int rear;
        int cap;

        CircularQueue(int n)
        {
            front=-1;
            rear=-1;
            cap=n;
        }

        bool enqueue(int value)
        {
            if(front==rear+1||(front==0&&rear==cap-1)){return false;}
            else if(rear==cap-1){rear=0;arr[0]=value;return true;}

            if(front==-1){front++;}rear++;arr[rear]=value;return true;
        }

        int dequeue()
        {
            if(front==-1){return -1;}
            else if(front==rear){int x=arr[front];front=-1;rear=-1;return x;}
            else if(front==cap-1){front=0;return arr[cap-1];}
            int x=arr[front];front++;return x;
        }
};

int main()
{

}
