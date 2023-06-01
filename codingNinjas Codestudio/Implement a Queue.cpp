#include<bits/stdc++.h>
using namespace std;

//using an integer array

class Queue
{
    public:
        int arr[5001];
        int i;
        int j;
        Queue()
        {
            i=-1;
            j=-1;
        }

        bool isEmpty()
        {
            if(i==-1){return true;}
            return false;
        }

        void enqueue(int data)
        {
            if(i==-1){i++;}
            j++;
            arr[j]=data;
        }

        int dequeue()
        {
            if(i==-1)
            {return -1;}
            else if(i==j)
            {int x=arr[i];i=-1;j=-1;return x;}
            int x=arr[i];i++;return x;
        }

        int front()
        {
            if(i==-1){return -1;}
            return arr[i];
        }
};

int main()
{
    return 0;
}
