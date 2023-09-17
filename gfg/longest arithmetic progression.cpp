#include<bits/stdc++.h>
using namespace std;

/* //TLE
int solve(int i,int j,int n,int A[])
{
    if(j>=n-1){return 0;}
    for(int k=j+1;k<n;k++)
    {
        if(A[k]+A[i]==2*A[j])
        {
            return 1+solve(j,k,n,A);
        }
    }
    return 0;
}

int lengthOfLongestAP(int A[], int n)
{
    if(n<3){return n;}

    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            ans=max(ans,solve(i,j,n,A));
        }
    }
    return ans+2;
}
*/

/* // memoisation // TLE
int solve(int i,int j,int n,int A[],vector<vector<int>>& dp)
{
    if(j>=n-1){return 0;}
    if(dp[i][j]!=-1){return dp[i][j];}

    for(int k=j+1;k<n;k++)
    {
        if(A[k]+A[i]==2*A[j])
        {
            return dp[i][j]=1+solve(j,k,n,A,dp);
        }
    }
    return dp[i][j]=0;
}

int lengthOfLongestAP(int A[], int n)
{
    if(n<3){return n;}

    vector<vector<int>> dp(n-1,vector<int>(n,-1));
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            ans=max(ans,solve(i,j,n,A,dp));
        }
    }
    return ans+2;
}
*/

/* // tabulation TLE
int lengthOfLongestAP(int A[], int n)
{
    if(n<3){return n;}

    vector<vector<int>> dp(n-1,vector<int>(n,0));
    int ans=0;
    for(int i=n-3;i>=0;i--)
    {
        for(int j=n-2;j>i;j--)
        {
            for(int k=j+1;k<n;k++)
            {
                if(A[k]+A[i]==2*A[j])
                {
                    dp[i][j]=1+dp[j][k];
                }
            }
            ans=max(ans,dp[i][j]);
        }
    }
    return ans+2;
}
*/

//-----------------------------------------------------------------------

// ALL SOLUTIONS GIVING TLE

int main()
{
    int A[]={1, 7, 10, 13, 14, 19};
    int n=6;
    cout<<lengthOfLongestAP(A,n);
    return 0;
}

