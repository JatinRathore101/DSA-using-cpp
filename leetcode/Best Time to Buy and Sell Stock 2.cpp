#include<bits/stdc++.h>
using namespace std;

/* // TLE
int solve(int i,int n,int canBuy,vector<int>& prices)
{
    if(i>=n){return 0;}

    if(canBuy==1)
    {
        int Buy=solve(i+1,n,0,prices)-prices[i];
        int dontBuy=solve(i+1,n,1,prices);
        return max(Buy,dontBuy);
    }
    else
    {
        int Sell=solve(i+1,n,1,prices)+prices[i];
        int dontSell=solve(i+1,n,0,prices);
        return max(Sell,dontSell);
    }
}

int maxProfit(vector<int>& prices)
{
    int n=prices.size();
    return solve(0,n,1,prices);
}
*/

/* // memoisation
int solve(int i,int n,int canBuy,vector<int>& prices,vector<vector<int>>& dp)
{
    if(i>=n){return 0;}
    if(dp[canBuy][i]!=-1){return dp[canBuy][i];}

    if(canBuy==1)
    {
        int Buy=solve(i+1,n,0,prices,dp)-prices[i];
        int dontBuy=solve(i+1,n,1,prices,dp);
        return dp[canBuy][i]=max(Buy,dontBuy);
    }
    else
    {
        int Sell=solve(i+1,n,1,prices,dp)+prices[i];
        int dontSell=solve(i+1,n,0,prices,dp);
        return dp[canBuy][i]=max(Sell,dontSell);
    }
}

int maxProfit(vector<int>& prices)
{
    int n=prices.size();
    vector<vector<int>> dp(2,vector<int>(n+1,-1));
    return solve(0,n,1,prices,dp);
}
*/

int maxProfit(vector<int>& prices)
{
    int n=prices.size();
    vector<vector<int>> dp(2,vector<int>(n+1,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<2;j++)
        {
             if(j==1)
            {
                int Buy=dp[0][i+1]-prices[i];
                int dontBuy=dp[1][i+1];
                dp[j][i]=max(Buy,dontBuy);
            }
            else
            {
                int Sell=dp[1][i+1]+prices[i];
                int dontSell=dp[0][i+1];
                dp[j][i]=max(Sell,dontSell);
            }
        }
    }

    return dp[1][0];
}

int main()
{
    vector<int> prices={7,1,5,3,6,4};
    cout<<maxProfit(prices);
    return 0;
}
