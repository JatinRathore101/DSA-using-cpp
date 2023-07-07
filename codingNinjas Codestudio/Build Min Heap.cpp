#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr,int n,int i)
{
    int j=i;

    if(2*i+1<n&&arr[2*i+1]<arr[j]){j=2*i+1;}

    if(2*i+2<n&&arr[2*i+2]<arr[j]){j=2*i+2;}

    if(i!=j){swap(arr[i],arr[j]);heapify(arr,n,j);}
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int n=arr.size();
    if(n<2){return arr;}
    for(int i=n/2;i>=0;i--)
    {
        heapify(arr,n,i);
    }
    return arr;
}

int main()
{
    return 0;
}

