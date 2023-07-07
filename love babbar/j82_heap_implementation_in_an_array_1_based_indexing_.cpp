#include<bits/stdc++.h>
using namespace std;

// this code depicts implementation min heap in an array using 1 based indexing

void disp(int arr[],int n)
{
    for(int i=0;i<=n;i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

void heapify(int arr[],int n,int smallest) // to put the given node at its correct position
{
    if(n<2){return;}

    int i=smallest;
    int c1=2*i;
    int c2=c1+1;

    if(c1<n&&arr[c1]<arr[i]){i=c1;}
    if(c2<n&&arr[c2]<arr[i]){i=c2;}

    if(i!=smallest){swap(arr[i],arr[smallest]);heapify(arr,n,i);}
}

void insertion(int arr[],int &n,int x)
{
    arr[n]=x;n++;
    int i=n-1;

    while(i/2>=1)
    {
        if(arr[i]<arr[i/2])
        {
            swap(arr[i],arr[i/2]);
            i/=2;
        }
        else
        {
            break;
        }
    }
}

void deletion(int arr[],int &n) // only root node is deleted
{
    if(n<2){return;}
    swap(arr[1],arr[n-1]);
    n--;
    heapify(arr,n,1);
}


void heapSort(int arr[],int n)
{
    arr[n]=arr[0];
    arr[0]=-1;

    n++;
    int N=n;
    for(int i=n/2;i>=1;i--){heapify(arr,n,i);}

    while(n>1)
    {
        swap(arr[1],arr[n-1]);
        n--;
        heapify(arr,n,1);
    }

    int i=0,j=N-1;
    while(i<j)
    {
        swap(arr[i],arr[j]);
        i++;j--;
    }

}


int main()
{
    int n=20;
    int arr[100];   // node index = i // left child index = 2i // right child index = 2i+1 // parent index = i/2 //
    arr[0]=-1;
    unordered_set<int> s;
    while(s.size()<n){s.insert(rand()%100);}
    int i=1;
    for(auto it:s)
    {
        arr[i++]=it;
    }
    disp(arr,n);

    for(i=n/2;i>=1;i--){heapify(arr,n,i);}
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
    int arr2[100]={10, -2, -54, 100, -29, 31, 55, -5, 67, 0};
    disp(arr2,9);
    heapSort(arr2,10);
    disp(arr2,9);

    return 0;
}

