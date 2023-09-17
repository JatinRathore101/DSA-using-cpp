#include<bits/stdc++.h>
using namespace std;

/*
int solvem(vector<int>& dp,vector<int>& cost,int n)
{
    if(n<2){return cost[n];}
    else if(dp[n]!=-1){return dp[n];}
    return dp[n]= min(solvem(dp,cost,n-2),solvem(dp,cost,n-1))+cost[n];
}

int minCostClimbingStairs(vector<int>& cost)
{
    int n=cost.size();
    vector<int> dp(n+1,-1);

    return min(solvem(dp,cost,n-2),solvem(dp,cost,n-1));
}
*/

/*
int minCostClimbingStairs(vector<int>& cost)
{
    int n=cost.size();
    vector<int> dp(n,-1);
    dp[0]=cost[0];dp[1]=cost[1];

    for(int i=2;i<n;i++)
    {
        dp[i]=min(dp[i-1],dp[i-2])+cost[i];
    }

    return min(dp[n-1],dp[n-2]);
}
*/

int minCostClimbingStairs(vector<int>& cost)
{
    int n=cost.size();
    int dp0=cost[0],dp1=cost[1],dp2;

    for(int i=2;i<n;i++)
    {
        dp2=min(dp1,dp0)+cost[i];
        dp0=dp1;dp1=dp2;
    }

    return min(dp0,dp1);
}

int main()
{
    vector<int> cost={1,100,1,1,1,100,1,1,100,1};
    cout<<minCostClimbingStairs(cost);
    return 0;
}

