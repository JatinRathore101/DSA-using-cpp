#include<bits/stdc++.h>
using namespace std;

// this code depicts implementation max heap in an array using 0 based indexing

void disp(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

void heapify(int arr[],int n,int largest) // to put the given node at its correct position
{
    if(n<2){return;}

    int i=largest;
    int c1=2*i+1;
    int c2=c1+1;

    if(c1<n&&arr[c1]>arr[i]){i=c1;}
    if(c2<n&&arr[c2]>arr[i]){i=c2;}

    if(i!=largest){swap(arr[i],arr[largest]);heapify(arr,n,i);}
}

void insertion(int arr[],int &n,int x)
{
    arr[n]=x;n++;
    int i=n-1;

    while((i-1)/2>=0)
    {
        if(arr[i]>arr[(i-1)/2])
        {
            swap(arr[i],arr[(i-1)/2]);
            i=(i-1)/2;
        }
        else
        {
            break;
        }
    }
}

void deletion(int arr[],int &n) // only root node is deleted
{
    if(n<1){return;}
    swap(arr[0],arr[n-1]);
    n--;
    heapify(arr,n,0);
}


void heapSort(int arr[],int n)
{
    for(int i=n/2;i>=0;i--)
    {heapify(arr,n,i);}

    while(n>0)
    {
        swap(arr[0],arr[n-1]);
        n--;
        heapify(arr,n,0);
    }
}


int main()
{
    int n=20;
    int arr[100];   // node index = i // left child index = 2i+1 // right child index = 2i+2 // parent index = (i-1)/2 //
    unordered_set<int> s;
    while(s.size()<n){s.insert(rand()%100);}
    int i=0;
    for(auto it:s)
    {
        arr[i++]=it;
    }
    disp(arr,n);

    for(i=n/2;i>=0;i--){heapify(arr,n,i);}
    disp(arr,n);

    insertion(arr,n,100);
    disp(arr,n);

    deletion(arr,n);
    disp(arr,n);
    deletion(arr,n);
    disp(arr,n);
    deletion(arr,n);
    disp(arr,n);





    cout<<endl;
    int arr2[10]={10, -1, -54, 100, -29, 31, 55, -5, 67, 0};
    disp(arr2,10);
    heapSort(arr2,10);
    disp(arr2,10);

    return 0;
}

