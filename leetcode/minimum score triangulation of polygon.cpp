#include<bits/stdc++.h>
using namespace std;

/* // TLE
int minSTutil(int i,int j,vector<int>&values)
{
    if(i==j-1){return 0;}

    if(i==j-2){return values[i]*values[i+1]*values[i+2];}

    int ans=INT_MAX;
    for(int k=i+1;k<j;k++)
    {
        int temp=values[i]*values[j]*values[k];
        temp+=minSTutil(i,k,values);
        temp+=minSTutil(k,j,values);

        ans=min(ans,temp);
    }

    return ans;
}

int minScoreTriangulation(vector<int>& values)
{
    return minSTutil(0,values.size()-1,values);
}
*/

/* // memoisation //
int minSTutil(int i,int j,vector<int>&values,vector<vector<int>>&dp)
{
    if(i==j-1){return 0;}
    if(i==j-2){return values[i]*values[i+1]*values[i+2];}

    if(dp[i][j]!=-1){return dp[i][j];}

    int ans=INT_MAX;
    for(int k=i+1;k<j;k++)
    {
        int temp=values[i]*values[j]*values[k];
        temp+=minSTutil(i,k,values,dp);
        temp+=minSTutil(k,j,values,dp);

        ans=min(ans,temp);
    }

    return  dp[i][j]=ans;
}

int minScoreTriangulation(vector<int>& values)
{
    int n=values.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return minSTutil(0,values.size()-1,values,dp);
}
*/

/*
int minScoreTriangulation(vector<int>& values)
{
    int n=values.size();
    vector<vector<int>> dp(n,vector<int>(n,0));

    for(int i=n-1;i>=0;i--)
    {
        for(int j=i+2;j<n;j++)
        {
            if(j>=n){break;}

            int ans=INT_MAX;
            for(int k=i+1;k<j;k++)
            {
                int temp=values[i]*values[j]*values[k]+dp[i][k]+dp[k][j];
                ans=min(ans,temp);
            }

            dp[i][j]=ans;
        }
    }

    return dp[0][n-1];
}
*/

int minScoreTriangulation(vector<int>& values)
{
    int n=values.size(),ans;

    for(int i=n-1;i>=0;i--)
    {
        vector<int> dp(n,0);

        for(int j=i+2;j<n;j++)
        {
            if(j>=n){break;}

            ans=INT_MAX;
            for(int k=i+1;k<j;k++)
            {
                int temp=values[i]*values[j]*values[k]+dp[i][k]+dp[k][j];
                ans=min(ans,temp);
            }

            dp[j]=ans;ans=dp[n-1];
        }
    }

    return ans;
}

int main()
{
    vector<int> values={1,3,1,4,1,5};
    cout<<minScoreTriangulation(values);
    return 0;
}

