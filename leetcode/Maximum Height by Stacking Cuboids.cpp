#include<bits/stdc++.h>
using namespace std;

/* // memoisation // all cases passed

bool check(int i,int j,vector<vector<int>>& cuboids)
{
    if(cuboids[j][0]<=cuboids[i][0])
    {
        if(cuboids[j][1]<=cuboids[i][1])
        {
            if(cuboids[j][2]<=cuboids[i][2])
            {
                return true;
            }
        }
    }
    return false;
}

int solve(int i,int j,int n,vector<vector<int>>& cuboids,vector<vector<int>>& dp)
{
    if(i>=n){return 0;}

    if(dp[i][j+1]!=-1){return dp[i][j+1];}

    int incl=0,excl=0;

    if(j==-1||check(i,j,cuboids))
    {
        incl=cuboids[i][2]+solve(i+1,i,n,cuboids,dp);
    }
    excl=solve(i+1,j,n,cuboids,dp);

    return dp[i][j+1]=max(incl,excl);
}

int LIS(vector<vector<int>>& cuboids)
{
    int n=cuboids.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

    int incl=cuboids[0][2]+solve(1,0,n,cuboids,dp);
    int excl=solve(1,-1,n,cuboids,dp);

    return max(incl,excl);
}

int maxHeight(vector<vector<int>>& cuboids)
{
    int n=cuboids.size();
    for(int i=0;i<n;i++)
    {
        sort(cuboids[i].begin(),cuboids[i].end());
    }
    if(n==1){return cuboids[0][2];}

    sort(cuboids.begin(),cuboids.end()); // sorted wrto lengths

    return LIS(cuboids);
}

*/

/* // tabulation

bool check(int i,int j,vector<vector<int>>& cuboids)
{
    if(cuboids[j][0]<=cuboids[i][0])
    {
        if(cuboids[j][1]<=cuboids[i][1])
        {
            if(cuboids[j][2]<=cuboids[i][2])
            {
                return true;
            }
        }
    }
    return false;
}

int maxHeight(vector<vector<int>>& cuboids)
{
    int n=cuboids.size();
    for(int i=0;i<n;i++)
    {
        sort(cuboids[i].begin(),cuboids[i].end());
    }
    if(n==1){return cuboids[0][2];}

    sort(cuboids.begin(),cuboids.end()); // sorted wrto lengths

   // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i-1;j>=-1;j--)
        {
            int incl=0,excl=0;

            if(j==-1||check(i,j,cuboids))
            {
                incl=cuboids[i][2]+dp[i+1][i+1];
            }
            excl=dp[i+1][j+1];

            dp[i][j+1]=max(incl,excl);
        }
    }

    return dp[0][0];
}

*/

// space optimized tabulation
bool check(int i,int j,vector<vector<int>>& cuboids)
{
    if(cuboids[j][0]<=cuboids[i][0])
    {
        if(cuboids[j][1]<=cuboids[i][1])
        {
            if(cuboids[j][2]<=cuboids[i][2])
            {
                return true;
            }
        }
    }
    return false;
}

int maxHeight(vector<vector<int>>& cuboids)
{
    int n=cuboids.size();
    for(int i=0;i<n;i++)
    {
        sort(cuboids[i].begin(),cuboids[i].end());
    }
    if(n==1){return cuboids[0][2];}

    sort(cuboids.begin(),cuboids.end()); // sorted wrto lengths

    vector<int> dpi0(n+1,0);
    vector<int> dpi1(n+1,0);

    for(int i=n-1;i>=0;i--)
    {
        for(int j=i-1;j>=-1;j--)
        {
            int incl=0,excl=0;

            if(j==-1||check(i,j,cuboids))
            {
                incl=cuboids[i][2]+dpi1[i+1];
            }
            excl=dpi1[j+1];

            dpi0[j+1]=max(incl,excl);
        }
        dpi1=dpi0;
    }

    return dpi0[0];
}

int main()
{
    vector<vector<int>> cuboids={{7,11,17},{7,17,11},{11,7,17},{11,17,7},{17,7,11},{17,11,7}};
    cout<<maxHeight(cuboids);
    return 0;
}

