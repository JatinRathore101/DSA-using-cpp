#include<bits/stdc++.h>
using namespace std;

// C(n,r) = C(n-1,r) + C(n-1,r-1)

/* // recurrsive
int solve(int n,int r)
{
    if(r==n){return 1;}
    if(r>n||r<0||n<0){return 0;}

    return solve(n-1,r)+solve(n-1,r-1);
}

int Combination(int n,int r)
{
    return solve(n,r);
}
*/

/* // memoisation
int solve(int n,int r,vector<vector<int>>& dp)
{
    if(r>n||r<0||n<0){return 0;}
    if(r==n||r==0){return 1;}
    if(dp[n][r]!=-1){return dp[n][r];}

    return dp[n][r]=solve(n-1,r,dp)+solve(n-1,r-1,dp);
}

int Combination(int n,int r)
{
    vector<vector<int>> dp(n+1,vector<int>(r+1,-1));
    return solve(n,r,dp);
}
*/

/* // tabulation
int Combination(int n,int r)
{
    if(n<r||r<0||n<0){return 0;}
    if(r==n){return 1;}
    if(r==0){return n;}

    vector<vector<int>> dp(n+1,vector<int>(r+1,0));
    for(int i=0;i<=r;i++){dp[i][i]=1;}
    for(int i=0;i<=n;i++){dp[i][0]=1;}

    for(int j=1;j<=r;j++)
    {
        for(int i=j+1;i<=n;i++)
        {
            dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
        }
    }

    return dp[n][r];
}
*/

// space optimized tabulation
int Combination(int n,int r)
{
    if(n<r||r<0||n<0){return 0;}
    if(r==n){return 1;}
    if(r==0){return n;}

    vector<int> dpim1(r+1,0);dpim1[0]=1;
    vector<int> dpi(r+1,0);dpi[0]=dpi[1]=1;

    for(int i=1;i<=n;i++)
    {
        int J=min(i,r);
        for(int j=1;j<=J;j++)
        {
            dpi[j]=dpim1[j]+dpim1[j-1];
        }
        dpim1=dpi;
    }

    return dpi[r];
}

// submitted solution // gfg nCr 1019
int m=1000000007;
int nCr(int n,int r)
{
    if(n<r||r<0||n<0){return 0;}
    if(r==n){return 1;}
    if(r==0){return n;}

    vector<int> dpim1(r+1,0);dpim1[0]=1;
    vector<int> dpi(r+1,0);dpi[0]=dpi[1]=1;

    for(int i=1;i<=n;i++)
    {
        int J=min(i,r);
        for(int j=1;j<=J;j++)
        {
            dpi[j]=(dpim1[j]%m+dpim1[j-1]%m)%m;
        }
        dpim1=dpi;
    }

    return dpi[r];
}

int main()
{
    cout<<Combination(6,3);
    return 0;
}

