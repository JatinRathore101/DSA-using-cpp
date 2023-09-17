#include<bits/stdc++.h>
using namespace std;

/* // TLE
int solve(int i,int N,int arr[],int X)
{
    // these basecase conditions are written in short below
    // if(X<0||i>N){return 0;}
    // if(X==0&&i<=N){return 1;}
    // if(i==N&&X!=0){return 0;}

    if(X<0||i>N){return 0;}
    if(X==0){return 1;}
    if(i==N){return 0;}

    int incl=solve(i+1,N,arr,X-arr[i]);
    int excl=solve(i+1,N,arr,X);

    if(incl==1||excl==1){return 1;}
    return 0;
}

int equalPartition(int N, int arr[])
{
    int X=0;for(int i=0;i<N;i++){X+=arr[i];}
    if(X%2==1){return 0;}X/=2;

    return solve(0,N,arr,X);
}
*/

/* // memoisation // TLE
int solve(int i,int N,int arr[],int X,vector<vector<int>>& dp)
{
    if(X<0||i>N){return 0;}
    if(X==0){return 1;}
    if(i==N){return 0;}
    if(dp[i][X]!=-1){return dp[i][X];}

    int incl=solve(i+1,N,arr,X-arr[i],dp);
    int excl=solve(i+1,N,arr,X,dp);

    if(incl==1||excl==1){return dp[i][X]=1;}
    return 0;
}

int equalPartition(int N, int arr[])
{
    int X=0;for(int i=0;i<N;i++){X+=arr[i];}
    if(X%2==1){return 0;}X/=2;

    vector<vector<int>> dp(N+1,vector<int>(X+1,-1));
    return solve(0,N,arr,X,dp);
}
*/

/* // tabulation // all test cases passed
int equalPartition(int N, int arr[])
{
    int X=0;for(int i=0;i<N;i++){X+=arr[i];}
    if(X%2==1){return 0;}X/=2;

    vector<vector<int>> dp(N+1,vector<int>(X+1,0));
    for(int i=0;i<=N;i++){dp[i][0]=1;}

    for(int i=N-1;i>=0;i--)
    {
        for(int j=1;j<=X;j++)
        {
            int incl=0;
            if(j>=arr[i]){incl=dp[i+1][j-arr[i]];}
            int excl=dp[i+1][j];
            dp[i][j]=0;
            if(incl==1||excl==1){dp[i][j]=1;}
        }
    }

    return dp[0][X];
}
*/

// space optimized tabulation
int equalPartition(int N, int arr[])
{
    int X=0;for(int i=0;i<N;i++){X+=arr[i];}
    if(X%2==1){return 0;}X/=2;

    vector<int> dpi0(X+1,0);
    vector<int> dpi1(X+1,0);
    dpi0[0]=dpi1[0]=1;

    for(int i=N-1;i>=0;i--)
    {
        for(int j=1;j<=X;j++)
        {
            int incl=0;
            if(j>=arr[i]){incl=dpi1[j-arr[i]];}
            int excl=dpi1[j];
            dpi0[j]=0;
            if(incl==1||excl==1){dpi0[j]=1;}
        }
        dpi1=dpi0;
    }

    return dpi0[X];
}

int main()
{
    int N=4,arr[]={1, 5, 11, 5};
    cout<<equalPartition(N,arr);
    return 0;
}

