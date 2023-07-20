#include<bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n)
{
    priority_queue<long long,vector<long long>,greater<long long>> pq;
    for(long long i=0;i<n;i++){pq.push(arr[i]);}

    long long cost=0;
    while(n>1)
    {
        long long subCost=0;
        subCost+=pq.top();pq.pop();
        subCost+=pq.top();pq.pop();
        cost+=subCost;
        pq.push(subCost);
    }

    return cost;
}

int main()
{
    return 0;
}

