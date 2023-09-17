#include<bits/stdc++.h>
using namespace std;

/* // TLE
int solve(int i,int d,int n,vector<int>& arr)
{
    int next=arr[i]+d;
    for(int j=i+1;j<n;j++)
    {
        if(arr[j]==next)
        {
            return 1+solve(j,d,n,arr);
        }
    }
    return 0;
}

int longestSubsequence(vector<int>& arr, int difference)
{
    int n=arr.size();
    if(n==1){return n;}

    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        ans=max(ans,1+solve(i,difference,n,arr));
    }
    return ans;
}
*/

/* // memoization // TLE
int solve(int i,int d,int n,vector<int>& arr,vector<int>& dp)
{
    if(i>=n-1){return 0;}
    if(dp[i]!=-1){return dp[i];}

    int next=arr[i]+d;
    for(int j=i+1;j<n;j++)
    {
        if(arr[j]==next)
        {
            return dp[i]=1+solve(j,d,n,arr,dp);
        }
    }
    return dp[i]=0;
}

int longestSubsequence(vector<int>& arr, int difference)
{
    int n=arr.size();
    if(n==1){return n;}
    vector<int> dp(n,-1);

    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        ans=max(ans,1+solve(i,difference,n,arr,dp));
    }
    return ans;
}
*/

/* // tabulation // TLE
int longestSubsequence(vector<int>& arr, int difference)
{
    int n=arr.size();
    if(n==1){return n;}
    vector<int> dp(n,0);

    int ans=0;
    for(int i=n-2;i>=0;i--)
    {
        int next=arr[i]+difference;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]==next)
            {
                dp[i]=1+dp[j];
                break;
            }
        }
        ans=max(ans,dp[i]);
    }
    return 1+ans;
}
*/

int main()
{
    vector<int> arr={1,5,7,8,5,3,4,2,1};
    int difference=-2;
    cout<<longestSubsequence(arr,difference);
    return 0;
}

