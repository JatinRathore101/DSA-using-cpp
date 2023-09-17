#include<bits/stdc++.h>
using namespace std;

/* // TLE
int ReducingDishesRecur(int t,int i,int n,vector<int>& satisfaction)
{
    if(i>=n){return 0;}
    return max(t*satisfaction[i]+ReducingDishesRecur(t+1,i+1,n,satisfaction),ReducingDishesRecur(t,i+1,n,satisfaction));
}

int maxSatisfaction(vector<int>& satisfaction)
{
    sort(satisfaction.begin(),satisfaction.end());
    return ReducingDishesRecur(1,0,satisfaction.size(),satisfaction);
}
*/

/*
int ReducingDishesRecur(int t,int i,int n,vector<int>& satisfaction,vector<vector<int>> &dp)
{
    if(i>=n){return 0;}

    if(dp[t][i]!=-1){return dp[t][i];}

    return dp[t][i]=max(t*satisfaction[i]+ReducingDishesRecur(t+1,i+1,n,satisfaction,dp),ReducingDishesRecur(t,i+1,n,satisfaction,dp));
}

int maxSatisfaction(vector<int>& satisfaction)
{
    sort(satisfaction.begin(),satisfaction.end());

    int n=satisfaction.size();
    vector<vector<int>> dp(n+1,vector<int>(n,-1));

    return ReducingDishesRecur(1,0,n,satisfaction,dp);
}
*/

/* // tabulation

int maxSatisfaction(vector<int>& satisfaction)
{
    sort(satisfaction.begin(),satisfaction.end());
    int n=satisfaction.size();
    vector<vector<int>> dp(n+2,vector<int>(n+1,0));

    for(int t=n;t>0;t--)
    {
        for(int i=n-1;i>=0;i--)
        {
            dp[t][i]=max(dp[t][i+1],t*satisfaction[i]+dp[t+1][i+1]);
        }
    }
    return dp[1][0];
}
*/

// space optimization
int maxSatisfaction(vector<int>& satisfaction)
{
    sort(satisfaction.begin(),satisfaction.end());
    int n=satisfaction.size();

    vector<int> T1(n+1,0);
    vector<int> T0(n+1,0);

    for(int t=n;t>0;t--)
    {
        for(int i=n-1;i>=0;i--)
        {
            T0[i]=max(T0[i+1],t*satisfaction[i]+T1[i+1]);
        }
        T1=T0;
    }
    return T0[0];
}

int main()
{
    vector<int> satisfaction={-1,-8,0,5,-9};
    cout<<maxSatisfaction(satisfaction);
    return 0;
}

