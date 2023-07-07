#include<bits/stdc++.h>
using namespace std;

void disp(int arr[], int l, int r)
{
    while(l<=r){cout<<arr[l]<<"  ";l++;}
    cout<<endl<<endl;
}

void heapify(int arr[], int l, int r, int i)
{
    int j=i;
    int c1=i*2-l+1;
    int c2=i*2-l+2;

    if(c1<=r&&arr[c1]>arr[j]){j=c1;}
    if(c2<=r&&arr[c2]>arr[j]){j=c2;}

    if(i!=j)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        heapify(arr,l,r,j);
    }
}

int kthSmallest(int arr[], int l, int r, int k)
{
    int m=r+1-k/2;
    while(m>=r-k+1)
    {
        heapify(arr,r-k+1,r,m);
        m--;
    }

    m=r-k;
    while(m>=l)
    {
        if(arr[m]<arr[r-k+1])
        {
            int temp=arr[m];
            arr[m]=arr[r-k+1];
            arr[r-k+1]=temp;
            heapify(arr,r-k+1,r,r-k+1);
        }
        m--;
    }

    return arr[r-k+1];
}

int main()
{
    int arr[10]={20,17,21,15,13,19};
    //disp(arr,l,r);
    cout<<kthSmallest(arr,0,5,3);
    return 0;
}

