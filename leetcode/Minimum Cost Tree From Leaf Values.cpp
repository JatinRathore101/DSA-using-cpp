#include<bits/stdc++.h>
using namespace std;

/* // TLE
int Max(int i,int j,vector<int>& arr)
{
    int ans=0;
    while(i<=j)
    {
        ans=max(ans,arr[i]);
        i++;
    }
    return ans;
}

int solve(int i,int j,int n,vector<int>& arr)
{
    if(i<0||j>=n||i>=j){return 0;}
    if(i==j-1){return arr[i]*arr[j];}

    int ans=INT_MAX;

    for(int k=i;k<j;k++)
    {
        int currVal=Max(i,k,arr)*Max(k+1,j,arr);
        int leftVal=solve(i,k,n,arr);
        int rightVal=solve(k+1,j,n,arr);
        ans=min(ans,leftVal+currVal+rightVal);
    }
    return ans;
}

int mctFromLeafValues(vector<int>& arr)
{
    int n=arr.size();
    int i=0,j=n-1;
    return solve(i,j,n,arr);
}
*/

/* // memoisation
int Max(int i,int j,vector<int>& arr)
{
    int ans=0;
    while(i<=j)
    {
        ans=max(ans,arr[i]);
        i++;
    }
    return ans;
}

int solve(int i,int j,int n,vector<int>& arr,vector<vector<int>>& dp)
{
    if(i<0||j>=n||i>=j){return 0;}

    if(dp[i][j]!=-1){return dp[i][j];}

    int ans=INT_MAX;

    for(int k=i;k<j;k++)
    {
        int currVal=Max(i,k,arr)*Max(k+1,j,arr);
        int leftVal=solve(i,k,n,arr,dp);
        int rightVal=solve(k+1,j,n,arr,dp);
        ans=min(ans,leftVal+currVal+rightVal);
    }
    return dp[i][j]=ans;
}

int mctFromLeafValues(vector<int>& arr)
{
    int n=arr.size();
    int i=0,j=n-1;
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return solve(i,j,n,arr,dp);
}
*/

int Max(int i,int j,vector<int>& arr)
{
    int ans=0;
    while(i<=j)
    {
        ans=max(ans,arr[i]);
        i++;
    }
    return ans;
}

int mctFromLeafValues(vector<int>& arr)
{
    int n=arr.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<n;j++)
        {
            int ans=INT_MAX;

            for(int k=i;k<j;k++)
            {
                int currVal=Max(i,k,arr)*Max(k+1,j,arr);
                int leftVal=dp[i][k];
                int rightVal=dp[k+1][j];
                ans=min(ans,leftVal+currVal+rightVal);
            }
            if(ans>=0&&ans<INT_MAX)
            { //only this assigning was creating error due to condition not being applied
                dp[i][j]=ans;
            }
        }
    }

    return dp[0][n-1];
}

int main()
{
    vector<int> arr={6,2,4};
    cout<<mctFromLeafValues(arr);
    return 0;
}
