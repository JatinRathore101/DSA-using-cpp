#include<bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n)
{
    if(n==1){return 0;}
    priority_queue<long long,vector<long long>,greater<long long>> pq;

    for(int i=0;i<n;i++){pq.push(arr[i]);}

    long long cost=0;
    long long cost1=0;
    cost1+=pq.top();pq.pop();
    cost1+=pq.top();pq.pop();
    cost+=cost1;

    while(!pq.empty())
    {
        pq.push(cost1);cost1=0;
        cost1+=pq.top();pq.pop();
        cost1+=pq.top();pq.pop();
        cost+=cost1;
    }
    return cost;
}

int main()
{
    long long arr[]={4, 2, 7, 6, 9};
    long long n=5;

    cout<<minCost(arr,n);
    return 0;
}

