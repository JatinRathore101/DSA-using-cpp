#include<bits/stdc++.h>
using namespace std;

/* // recursion TLE //
int findWays(vector<int> &num,int tar)
{
    if(tar==0){return 1;}
    if(tar<0){return 0;}

    int ans=0;
    for(auto it:num)
    {
        ans+=findWays(num,tar-it);
    }
    return ans;
}
*/

/* // 2d dp // memoisation // TLE
int findWaysRecur(vector<int> &num,int val,int tar,vector<vector<int>> &dp)
{
    if(tar==0){return 1;}
    if(tar<0){return 0;}

    if(dp[val][tar]!=-1){return dp[val][tar];}

    dp[val][tar]=0;
    for(auto it:num)
    {
        dp[val][tar]+=findWaysRecur(num,it,tar-it,dp);
    }
    return dp[val][tar];
}

int findWays(vector<int> &num,int tar)
{
    int maxi=0;
    for(auto it:num){maxi=max(maxi,it);}
    vector<vector<int>> dp(maxi+1,vector<int>(tar+1,-1));
    return findWaysRecur(num,0,tar,dp);
}
*/

/* // 1d dp // memoisation
int findWaysRecur(vector<int> &num,int tar,vector<int> &dp)
{
    if(tar==0){return 1;}
    if(tar<0){return 0;}

    if(dp[tar]!=-1){return dp[tar];}

    dp[tar]=0;
    for(auto it:num)
    {
        dp[tar]+=findWaysRecur(num,tar-it,dp);
    }
    return dp[tar];
}

int findWays(vector<int> &num,int tar)
{
    vector<int> dp(tar+1,-1);
    return findWaysRecur(num,tar,dp);
}
*/

int findWays(vector<int> &num,int tar)
{
    vector<int> dp(tar+1,-1);dp[0]=1;
    for(int i=1;i<=tar;i++)
    {
        dp[i]=0;
        for(auto it:num)
        {
            if(i>=it){dp[i]+=dp[i-it];}
        }
    }

    return dp[tar];
}

int main()
{
    vector<int> num={1,2,5};
    int tar=5;
    cout<<findWays(num,tar);
    return 0;
}

