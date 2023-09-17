#include<bits/stdc++.h>
using namespace std;

/* // TLE //
int solve(vector<int> &num,int x)
{
    if(x<0){return INT_MAX;}
    if(x==0){return 0;}

    int ans=INT_MAX-1;
    for(auto it:num){ans=min(ans,solve(num,x-it));}
    return ans+1;
}

int minimumElements(vector<int> &num,int x)
{
    int ans=solve(num,x);
    if(ans==INT_MAX){return -1;}
    return ans;
}
*/

/*
int solve(vector<int> &num,int x,vector<int> &dp)
{
    if(x<0){return INT_MAX;}
    if(x==0){return 0;}

    if(dp[x]!=-1){return dp[x];}

    dp[x]=INT_MAX-1;
    for(auto it:num)
    {
        dp[x]=min(dp[x],solve(num,x-it,dp));
    }

    return ++dp[x];
}

int minimumElements(vector<int> &num,int x)
{
    vector<int> dp(x+1,-1);
    int ans=solve(num,x,dp);
    if(ans==INT_MAX){return -1;}
    return ans;
}
*/

int minimumElements(vector<int> &num,int x)
{
    vector<int> dp(x+1,-1);
    dp[0]=0;
    for(int i=1;i<=x;i++)
    {
        dp[i]=INT_MAX-1;
        for(auto it:num)
        {
            if(i-it>=0)
            {
                dp[i]=min(dp[i],dp[i-it]);
            }
        }
        dp[i]++;
    }

    if(dp[x]==INT_MAX){return -1;}
    return dp[x];
}

int main()
{
    vector<int> num={12,1,3};
    int x=4;

    cout<<minimumElements(num,x);
    return 0;
}

