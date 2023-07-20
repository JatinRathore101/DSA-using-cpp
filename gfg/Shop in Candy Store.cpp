#include<bits/stdc++.h>
using namespace std;

vector<int> candyStore(int candies[], int N, int K)
{
    sort(candies,candies+N);
    vector<int> ans={0,0};

    N--;K++;int n=N/K;

    for(int i=0;i<=n;i++)
    {
        ans[0]+=candies[i];
        ans[1]+=candies[N-i];
    }

    return ans;
}

int main()
{
    int candies[]={35,1,70,25,79,59,63,65,6,46,82,28,62,92,96,43,28,37,92,5,3,54,93,83,22,17,19,96,48,27,72,39,70,13,68,100,36,95,4,12,23,34};
    int N=42,K=29;
    vector<int> ans=candyStore(candies,N,K);
    cout<<ans[0]<<"  "<<ans[1];
    return 0;
}
