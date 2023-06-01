#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[],int n)
{
    int j=0,k=0,l=0; // j => balance  // k = deficit
    for(int i=0;i<n;i++)
    {
        j+=p[i].petrol-p[i].distance;
        if(j<0){k+=j;j=0;l=i+1;}
    }
    if(j+k>0){return l;}
    return -1;
}

int main()
{
    return 0;
}

