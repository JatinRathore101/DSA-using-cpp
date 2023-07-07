#include<bits/stdc++.h>
using namespace std;

vector<int> findMedian(vector<int> &arr, int n)
{
    if(n<2){return arr;}

    priority_queue<int> maxPq;
    priority_queue<int,vector<int>,greater<int>> minPq;
    vector<int> median;

    maxPq.push(arr[0]);
    int maxPqSize=1,minPqSize=0;
    median.push_back(arr[0]);
    int m=arr[0];

    for(int i=1;i<n;i++)
    {
        if(arr[i]<m)
        {
            if(maxPqSize>minPqSize)
            {
                minPq.push(maxPq.top());
                maxPq.pop();
                minPqSize++;
                maxPqSize--;
            }
            maxPq.push(arr[i]);
            maxPqSize++;
        }
        else
        {
            if(minPqSize>maxPqSize)
            {
                maxPq.push(minPq.top());
                minPq.pop();
                maxPqSize++;
                minPqSize--;
            }
            minPq.push(arr[i]);
            minPqSize++;
        }

        if(maxPqSize==minPqSize)
        {
            m=(maxPq.top()+minPq.top())/2;
        }
        else if(maxPqSize>minPqSize)
        {
            m=maxPq.top();
        }
        else
        {
            m=minPq.top();
        }
        median.push_back(m);
    }

    return median;
}

int main()
{
    vector<int> arr={5,3,8};
    int n=arr.size();
    vector<int> v=findMedian(arr,n);
    for(auto it:v){cout<<it<<"  ";}
    return 0;
}

