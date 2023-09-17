#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices)
{
    int profit=0;
    int cost=INT_MAX;
    for(auto it:prices)
    {
        cost=min(cost,it);
        profit=max(profit,it-cost);
    }
    return profit;
}

int main()
{
    vector<int> prices={7,1,5,3,6,4};
    cout<<maxProfit(prices);
    return 0;
}
