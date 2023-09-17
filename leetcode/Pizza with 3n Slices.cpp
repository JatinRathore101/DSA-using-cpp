#include<bits/stdc++.h>
using namespace std;

/* // TLE
int solve(int i,int j,int k,vector<int>& slices)
{
    if(i>j||k<=0){return 0;}

    int eat=slices[i]+solve(i+2,j,k-1,slices);
    int dontEat=solve(i+1,j,k,slices);

    return max(eat,dontEat);
}

int maxSizeSlices(vector<int>& slices)
{
    int n=slices.size();
    int k=n/3;

    int eat=slices[0]+solve(2,n-2,k-1,slices);
    int dontEat=solve(1,n-1,k,slices);

    return max(eat,dontEat);
}
*/

/* // memoisation
int solve(int i,int j,int k,vector<int>& slices,vector<vector<int>>& dp)
{
    if(i>j||k<=0){return 0;}

    if(dp[i][k]!=-1){return dp[i][k];}

    int eat=slices[i]+solve(i+2,j,k-1,slices,dp);
    int dontEat=solve(i+1,j,k,slices,dp);

    return dp[i][k]=max(eat,dontEat);
}

int maxSizeSlices(vector<int>& slices)
{
    int n=slices.size();
    int k=n/3;

    vector<vector<int>> dp1(n,vector<int>(k+1,-1));
    int eat=slices[0]+solve(2,n-2,k-1,slices,dp1);

    vector<vector<int>> dp2(n,vector<int>(k+1,-1)); // wrong answer was comming due to using same dp matrix
    int dontEat=solve(1,n-1,k,slices,dp2);

    return max(eat,dontEat);
}
*/

/* // tabulation
int maxSizeSlices(vector<int>& slices)
{
    int n=slices.size();
    int k=n/3;

    vector<vector<int>> dp1(n+1,vector<int>(k+1,0));

    for(int i=n-2;i>=2;i--)
    {
        for(int j=1;j<k;j++)
        {
            int eat=slices[i]+dp1[i+2][j-1];
            int dontEat=dp1[i+1][j];
            dp1[i][j]=max(eat,dontEat);
        }
    }


    vector<vector<int>> dp2(n+2,vector<int>(k+1,0)); // wrong answer was comming due to using same dp matrix

    for(int i=n-1;i>=1;i--)
    {
        for(int j=1;j<=k;j++)
        {
            int eat=slices[i]+dp2[i+2][j-1];
            int dontEat=dp2[i+1][j];
            dp2[i][j]=max(eat,dontEat);
        }
    }

    return max(slices[0]+dp1[2][k-1],dp2[1][k]);
}
*/

// space optimized tabulation
int maxSizeSlices(vector<int>& slices)
{
    int n=slices.size();
    int k=n/3;

    vector<int> dp1i2(k+1,0);
    vector<int> dp1i1(k+1,0);
    vector<int> dp1i0(k+1,0);

    for(int i=n-2;i>=2;i--)
    {
        for(int j=1;j<k;j++)
        {
            int eat=slices[i]+dp1i2[j-1];
            int dontEat=dp1i1[j];
            dp1i0[j]=max(eat,dontEat);
        }
        dp1i2=dp1i1;dp1i1=dp1i0;
    }


    vector<int> dp2i2(k+1,0);
    vector<int> dp2i1(k+1,0);
    vector<int> dp2i0(k+1,0);

    for(int i=n-1;i>=1;i--)
    {
        for(int j=1;j<=k;j++)
        {
            int eat=slices[i]+dp2i2[j-1];
            int dontEat=dp2i1[j];
            dp2i0[j]=max(eat,dontEat);
        }
        dp2i2=dp2i1;dp2i1=dp2i0;
    }

    return max(slices[0]+dp1i0[k-1],dp2i0[k]);
}

int main()
{
    vector<int> slices={8,9,8,6,1,1};
    cout<<maxSizeSlices(slices);
    return 0;
}

