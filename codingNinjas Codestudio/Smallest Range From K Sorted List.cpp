#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    int i;
    int j;
    Node(int data,int i,int j)
    {
        this->data=data;
        this->i=i;
        this->j=j;
    }
};

class comparator
{
public:
    bool operator()(Node* a,Node* b)
    {
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n)
{
    priority_queue<Node*,vector<Node*>,comparator> pq;
    int Max=INT_MIN,Min=INT_MAX,Range=INT_MAX;

    for(int i=0;i<k;i++)
    {
        Node* temp=new Node(a[i][0],i,0);
        Max=max(Max,a[i][0]);
        pq.push(temp);
    }

    int f=0,MinLimit=INT_MAX;
    while(!pq.empty())
    {
        Node* temp=pq.top();pq.pop();
        Min=temp->data;
        Range=min(Range,Max-Min);

        if(temp->j==n-1){break;}
        else if(temp->j<n-1)
        {
            temp=new Node(a[temp->i][temp->j+1],temp->i,temp->j+1);
            pq.push(temp);
            Max=max(Max,temp->data);
        }
    }

    return Range+1;
}

int main()
{
    vector<vector<int>> a={{4,7,30},{1,2,12},{20,40,50}};
    int k=3,n=3;
    cout<<kSorted(a,k,n);
    return 0;
}

