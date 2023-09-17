#include<bits/stdc++.h>
using namespace std;

/*
int solve(int i,int n,int k,int canBuy,vector<int>& prices)
{
    if(i>=n||k<=0){return 0;}

    // dont do k-1 in Buy. it gives wrong answer //
    // do k-1 at sell as transaction completes at sell //
    if(canBuy)
    {
        int Buy=solve(i+1,n,k,0,prices)-prices[i];
        int dontBuy=solve(i+1,n,k,1,prices);
        return max(Buy,dontBuy);
    }
    else
    {
        int Sell=solve(i+1,n,k-1,1,prices)+prices[i];
        int dontSell=solve(i+1,n,k,0,prices);
        return max(Sell,dontSell);
    }
}

int maxProfit(int k, vector<int>& prices)
{
    int n=prices.size();
    return solve(0,n,k,1,prices);
}
*/

/* // memoisation
int solve(int i,int n,int k,int canBuy,vector<int>& prices,vector<vector<vector<int>>>& dp)
{
    if(i>=n||k<=0){return 0;}
    if(dp[i][canBuy][k]!=-1){return dp[i][canBuy][k];}

    if(canBuy)
    {
        int Buy=solve(i+1,n,k,0,prices,dp)-prices[i];
        int dontBuy=solve(i+1,n,k,1,prices,dp);
        return dp[i][canBuy][k]=max(Buy,dontBuy);
    }
    else
    {
        int Sell=solve(i+1,n,k-1,1,prices,dp)+prices[i];
        int dontSell=solve(i+1,n,k,0,prices,dp);
        return dp[i][canBuy][k]=max(Sell,dontSell);
    }
}

int maxProfit(int k, vector<int>& prices)
{
    int n=prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
    return solve(0,n,k,1,prices,dp);
}
*/

/* // tabulation
int maxProfit(int k, vector<int>& prices)
{
    int n=prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));

    for(int i=n-1;i>=0;i--)
    {
        for(int j=1;j<=k;j++)
        {
            for(int b=0;b<2;b++)
            {
                if(b==1)
                {
                    int Buy=dp[i+1][0][j]-prices[i];
                    int dontBuy=dp[i+1][1][j];
                    dp[i][b][j]=max(Buy,dontBuy);
                }
                else
                {
                    int Sell=dp[i+1][1][j-1]+prices[i];
                    int dontSell=dp[i+1][0][j];
                    dp[i][b][j]=max(Sell,dontSell);
                }
            }
        }
    }

    return dp[0][1][k];
}
*/

// tabulation with space optimization
int maxProfit(int k, vector<int>& prices)
{
    int n=prices.size();

    vector<vector<int>> dpi1(2,vector<int>(k+1,0));
    vector<vector<int>> dpi0(2,vector<int>(k+1,0));

    for(int i=n-1;i>=0;i--)
    {
        for(int j=1;j<=k;j++)
        {
            for(int b=0;b<2;b++)
            {
                if(b==1)
                {
                    int Buy=dpi1[0][j]-prices[i];
                    int dontBuy=dpi1[1][j];
                    dpi0[b][j]=max(Buy,dontBuy);
                }
                else
                {
                    int Sell=dpi1[1][j-1]+prices[i];
                    int dontSell=dpi1[0][j];
                    dpi0[b][j]=max(Sell,dontSell);
                }
            }
        }
        dpi1=dpi0;
    }

    return dpi0[1][k];
}

int main()
{
    int k=2;
    vector<int> prices={3,2,6,5,0,3};
    cout<<maxProfit(k,prices);
    return 0;
}

