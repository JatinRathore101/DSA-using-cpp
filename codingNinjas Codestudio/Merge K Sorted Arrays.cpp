#include<bits/stdc++.h>
using namespace std;

/* // naive
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    if(k<2){return kArrays[0];}

    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto it:kArrays)
    {
        for(auto gt:it)
        {
            pq.push(gt);
        }
    }

    vector<int> v;
    while(!pq.empty())
    {
        v.push_back(pq.top());
        pq.pop();
    }

    return v;
}
*/

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

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    if(k<2){return kArrays[0];}

    priority_queue<Node*,vector<Node*>,comparator> pq;

    for(int i=0;i<k;i++)
    {
        Node* temp=new Node(kArrays[i][0],i,0);
        pq.push(temp);
    }

    vector<int> v;
    while(!pq.empty())
    {
        Node* temp=pq.top();pq.pop();
        v.push_back(temp->data);

        int i=temp->i,j=temp->j;
        if(j+1<kArrays[i].size())
        {
            temp=new Node(kArrays[i][j+1],i,j+1);
            pq.push(temp);
        }
    }

    return v;
}

int main()
{
    vector<vector<int>> kArrays={{1,4,7,11},{2,9,13},{5,15,20,25,30,35},{10,14}};
    int k=4;
    vector<int>v=mergeKSortedArrays(kArrays,k);
    for(auto it:v){cout<<it<<"  ";}
    return 0;
}

