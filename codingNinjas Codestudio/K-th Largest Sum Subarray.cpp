#include<bits/stdc++.h>
using namespace std;

void putSum(int sum,int i,int j,int k,priority_queue<int,vector<int>,greater<int>> &pq)
{
    if(pq.size()<k){pq.push(sum);}
    else if(pq.top()<sum){pq.pop();pq.push(sum);}
}

int getKthLargest(vector<int> &arr, int k)
{
    int n=arr.size();
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++)
    {
		int sum=0;
        for(int j=i;j<n;j++)
        {
			sum+=arr[j];
            putSum(sum,i,j,k,pq);
        }
    }
    return pq.top();
}

int main()
{
    vector<int> arr={-1,2,-8,6};
    int k=9;
    cout<<getKthLargest(arr,k);
    return 0;
}

