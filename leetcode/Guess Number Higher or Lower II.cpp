#include<bits/stdc++.h>
using namespace std;

/* // TLE
int solve(int i,int j)
{
    if(i>=j){return 0;}

    int ans=INT_MAX;
    for(int k=i;k<=j;k++)
    {
        ans=min(ans,k+max(solve(i,k-1),solve(k+1,j)));
    }
    return ans;
}

int getMoneyAmount(int n)
{
    if(n<4){return n-1;}
    return solve(1,n);
}
*/

/* // memoisation
int solve(int i,int j,vector<vector<int>>& dp)
{
    if(i>=j){return 0;}
    if(dp[i][j]!=-1){return dp[i][j];}

    int ans=INT_MAX;
    for(int k=i;k<=j;k++)
    {
        ans=min(ans,k+max(solve(i,k-1,dp),solve(k+1,j,dp)));
    }
    return dp[i][j]=ans;
}

int getMoneyAmount(int n)
{
    if(n<4){return n-1;}
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return solve(1,n,dp);
}
*/

/*
///////////////
int getMoneyAmount(int n)
{
    if(n<4){return n-1;}
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    for(int i=n;i>=1;i--)
    {
        for(int j=i;j<=n;j++)
        {
            if(i==j){continue;}
            else
            {
                int ans=INT_MAX;
                for(int k=i;k<=j;k++)
                {
                    ans=min(ans,k+max(dp[i][k-1],dp[k+1][j]));
                }
                dp[i][j]=ans;
            }
        }
    }

    return dp[1][n];
}
*/

// tabulation
int getMoneyAmount(int n)
{
    if(n<4){return n-1;}
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    for(int i=n-1;i>=1;i--)
    {
        for(int j=i+1;j<=n;j++)
        {
            int ans=INT_MAX;
            for(int k=i+1;k<=j;k++)
            {
                ans=min(ans,k+max(dp[i][k-1],dp[k+1][j]));
            }
            dp[i][j]=ans;
        }
    }

    return dp[1][n];
}

int main()
{
    int n=10;
    cout<<getMoneyAmount(n);
    return 0;
}

