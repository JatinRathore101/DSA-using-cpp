#include<bits/stdc++.h>
using namespace std;

// based on Best Time to Buy and Sell Stock 2

int maxProfit(vector<int>& prices,int fee)
{
    int n=prices.size();
    vector<vector<int>> dp(2,vector<int>(n+1,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<2;j++)
        {
             if(j==1)
            {
                int Buy=dp[0][i+1]-prices[i]-fee;
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
