#include<bits/stdc++.h>
using namespace std;

/*
long long noOfWays(int M,int N,int X)
{
    if(X==0&&N==0){return 1;}
    if(X==0||N==0){return 0;}
    if(X<0){return 0;}

    long long ans=0;
    for(int i=1;i<=M;i++)
    {
        ans+=noOfWays(M,N-1,X-i);
    }
    return ans;
}
*/

/* // memoisation
long long solve(int M,int N,int X,vector<vector<long long>>& dp)
    {
        if(X==0&&N==0){return 1;}
        if(X==0||N==0){return 0;}
        if(X<0){return 0;}
        if(dp[N][X]!=-1){return dp[N][X];}

        long long ans=0;
        for(int i=1;i<=M;i++)
        {
            ans+=solve(M,N-1,X-i,dp);
        }

        return dp[N][X]=ans;
    }

    long long noOfWays(int M,int N,int X)
    {
        vector<vector<long long>> dp(N+1,vector<long long>(X+1,-1));
        return solve(M,N,X,dp);
    }
*/

/* // tabulation
long long noOfWays(int M,int N,int X)
{
    vector<vector<long long>> dp(N+1,vector<long long>(X+1,0));
    dp[0][0]=1;

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=X;j++)
        {
            dp[i][j]=0;
            for(int k=1;k<=M;k++)
            {
                if(j>=k){dp[i][j]+=dp[i-1][j-k];}
            }
        }
    }

    return dp[N][X];
}
*/

long long noOfWays(int M,int N,int X)
{
    vector<long long> dpim1(X+1,0);
    vector<long long> dpi(X+1,0);
    dpim1[0]=1;

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=X;j++)
        {
            dpi[j]=0;
            for(int k=1;k<=M;k++)
            {
                if(j>=k){dpi[j]+=dpim1[j-k];}
            }
        }
        dpim1=dpi;
    }

    return dpim1[X];
}

int main()
{
    int M=6,N=3,X=12;
    cout<<noOfWays(M,N,X);
    return 0;
}

