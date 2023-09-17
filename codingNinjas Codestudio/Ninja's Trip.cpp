#include<bits/stdc++.h>
using namespace std;

/*
int minimumCoinsRecur(int n,int i,vector<int> &days,vector<int> &cost)
{
    if(i>=n){return 0;}

    int j=i;
    while(days[j]<=days[i]){j++;}
    int cost1=cost[0]+minimumCoinsRecur(n,j,days,cost);

    j=i;
    while(days[j]<=days[i]+6){j++;}
    int cost7=cost[1]+minimumCoinsRecur(n,j,days,cost);

    j=i;
    while(days[j]<=days[i]+29){j++;}
    int cost30=cost[2]+minimumCoinsRecur(n,j,days,cost);

    return min(min(cost1,cost7),cost30);
}

int minimumCoins(int n,vector<int> days,vector<int> cost)
{
    return minimumCoinsRecur(n,0,days,cost);
}
*/

/* // memoisation //
int minimumCoinsRecur(int n,int i,vector<int> &days,vector<int> &cost,vector<int> &dp)
{
    if(i>=n){return 0;}
    if(dp[i]!=-1){return dp[i];}

    int j=i;
    while(days[j]<=days[i]){j++;}
    int cost1=cost[0]+minimumCoinsRecur(n,j,days,cost,dp);

    j=i;
    while(days[j]<=days[i]+6){j++;}
    int cost7=cost[1]+minimumCoinsRecur(n,j,days,cost,dp);

    j=i;
    while(days[j]<=days[i]+29){j++;}
    int cost30=cost[2]+minimumCoinsRecur(n,j,days,cost,dp);

    return dp[i]=min(min(cost1,cost7),cost30);
}

int minimumCoins(int n,vector<int> days,vector<int> cost)
{
    vector<int> dp(n,-1);
    return minimumCoinsRecur(n,0,days,cost,dp);
}
*/

/*
int minimumCoins(int n,vector<int> days,vector<int> cost)
{
    vector<int> dp(n);
    dp[n-1]=min(cost[0],min(cost[1],cost[2]));

    for(int i=n-2;i>=0;i--)
    {
        int j=i;
        while(days[j]<=days[i]){j++;}
        int cost1=cost[0];
        if(j<n){cost1+=dp[j];}

        j=i;
        while(days[j]<=days[i]+6){j++;}
        int cost7=cost[1];
        if(j<n){cost7+=dp[j];}

        j=i;
        while(days[j]<=days[i]+29){j++;}
        int cost30=cost[2];
        if(j<n){cost30+=dp[j];}

        dp[i]=min(cost1,min(cost7,cost30));
    }

    return dp[0];
}
*/

/*
int minimumCoins(int n,vector<int> days,vector<int> cost)
{
    vector<int> dp(n+1);
    dp[n]=0;

    for(int i=n-1;i>=0;i--)
    {
        int j=i;
        while(days[j]<=days[i]){j++;}
        int cost1=cost[0];
        if(j<=n){cost1+=dp[j];}

        j=i;
        while(days[j]<=days[i]+6){j++;}
        int cost7=cost[1];
        if(j<=n){cost7+=dp[j];}

        j=i;
        while(days[j]<=days[i]+29){j++;}
        int cost30=cost[2];
        if(j<=n){cost30+=dp[j];}

        dp[i]=min(cost1,min(cost7,cost30));
    }

    return dp[0];
}
*/

int minimumCoins(int n,vector<int> days,vector<int> cost)
{
    int ans=0;
    queue<pair<int,int>> day;
    queue<pair<int,int>> week;
    queue<pair<int,int>> month;

    for(auto it:days)
    {
        while(!day.empty() && day.front().first+1<=it){day.pop();}
        while(!week.empty() && week.front().first+7<=it){week.pop();}
        while(!month.empty() && month.front().first+30<=it){month.pop();}

        day.push({it,ans+cost[0]});
        week.push({it,ans+cost[1]});
        month.push({it,ans+cost[2]});

        ans=min(day.front().second,min(week.front().second,month.front().second));
    }

    return ans;
}

int main()
{
    int n=7;
    vector<int> days={1,3,4,5,7,8,10};
    vector<int> cost={2,7,20};


    cout<<minimumCoins(n,days,cost);
    return 0;
}

