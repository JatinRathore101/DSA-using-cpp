#include<bits/stdc++.h>
using namespace std;

/* // TLE //
int MinSquares(int n)
{
    if(n==0){return 0;}

    int ans=10001;
    for(int i=1;i*i<=n;i++)
    {
        if(i*i>n){break;}
        ans=min(ans,1+MinSquares(n-i*i));
    }
    return ans;
}
*/

/* // memoisation //
int MinSquaresRecur(int n,vector<int> &dp)
{
    if(n==0){return 0;}
    if(dp[n]!=-1){return dp[n];}

    dp[n]=10001;
    for(int i=1;i*i<=n;i++)
    {
        dp[n]=min(dp[n],1+MinSquaresRecur(n-i*i,dp));
    }
    return dp[n];
}

int MinSquares(int n)
{
    vector<int> dp(n+1,-1);
    return MinSquaresRecur(n,dp);
}
*/

int MinSquares(int n) // tabulation
{
    vector<int> dp(n+1,10001);dp[0]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j*j<=i;j++)
        {
            dp[i]=min(dp[i],1+dp[i-j*j]);
        }
    }

    return dp[n];
}

int main()
{
    int n=6;
    cout<<MinSquares(n);
    return 0;
}

