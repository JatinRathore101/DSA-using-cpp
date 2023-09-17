#include<bits/stdc++.h>
using namespace std;

/* // inclusion exclusion // recursive // TLE // based on end value not on index
int solve(int n, int a[],int end)
{
    if(n<=0){return 0;}

    int incl=0,excl=0;
    if(a[0]>end){incl=1+solve(n-1,a+1,a[0]);}
    excl=solve(n-1,a+1,end);
    return max(incl,excl);
}

int longestSubsequence(int n, int a[])
{
    int incl=1+solve(n-1,a+1,a[0]);
    int excl=solve(n-1,a+1,-1);
    return max(incl,excl);
}
*/

/* // TLE // recursive // based on end index
int solve(int n,int i,int end,int a[])
{
    if(i>=n){return 0;}

    int incl=0,excl=0;
    if(end==-1||a[i]>a[end]){incl=1+solve(n,i+1,i,a);}
    excl=solve(n,i+1,end,a);
    return max(incl,excl);
}

int longestSubsequence(int n, int a[])
{
    int incl=1+solve(n,1,0,A);
    int excl=solve(n,1,-1,A);
    return max(incl,excl);
}
*/

/* // memoisation // still TLE
int solve(int n,int i,int end,int a[],vector<vector<int>> &dp)
    {
        if(i>=n){return 0;}

        if(dp[i][end+1]!=-1){return dp[i][end+1];}

        int incl=0,excl=0;
        if(end==-1||a[i]>a[end]){incl=1+solve(n,i+1,i,a,dp);}
        excl=solve(n,i+1,end,a,dp);
        return dp[i][end+1]=max(incl,excl);
    }

    int longestSubsequence(int n, int a[])
    {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int incl=1+solve(n,1,0,a,dp);
        int excl=solve(n,1,-1,a,dp);
        return max(incl,excl);
    }
*/

/* // tabulation // TLE
int longestSubsequence(int n, int a[])
{
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    for(int i=n-1;i>=0;i--)
    {
        for(int end=n-1;end>=-1;end--)
        {
            int incl=0,excl=0;
            if(end==-1||a[i]>a[end]){incl=1+dp[i+1][i+1];}
            excl=dp[i+1][end+1];

            dp[i][end+1]=max(incl,excl);
        }
    }

    return dp[0][0];
}
*/

/* // Space Optimized  Tabulation // TLE
int longestSubsequence(int n, int a[])
{
    vector<int> dpi0(n+1,0);
    vector<int> dpi1(n+1,0);

    for(int i=n-1;i>=0;i--)
    {
        for(int end=n-1;end>=-1;end--)
        {
            int incl=0,excl=0;
            if(end==-1||a[i]>a[end]){incl=1+dpi1[i+1];}
            excl=dpi1[end+1];

            dpi0[end+1]=max(incl,excl);
        }
        dpi1=dpi0;
    }

    return dpi0[0];
}
*/

/* // incl-excl // time optimised // space optimised // tabulation // TLE
int longestSubsequence(int n, int a[])
{
    vector<int> dpi0(n+1,0);
    vector<int> dpi1(n+1,0);

    for(int i=n-1;i>=0;i--)
    {
        for(int end=i-1;end>=-1;end--)
        {
            int incl=0,excl=0;
            if(end==-1||a[i]>a[end]){incl=1+dpi1[i+1];}
            excl=dpi1[end+1];

            dpi0[end+1]=max(incl,excl);
        }
        dpi1=dpi0;
    }

    return dpi0[0];
}
*/

int longestSubsequence(int n, int a[]) // LIS algorithm // Russian dolls
{
    if(n<2){return n;}
    vector<int> lis(1);lis[0]=a[0];

    int j=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]>lis[j])
        {
            lis.push_back(a[i]);
            j++;
        }
        else
        {
            int k=j;
            while(k>0)
            {
                if(lis[k-1]<a[i])
                {
                    break;
                }
                k--;
            }
            lis[k]=a[i];
        }
    }
    return lis.size();
}

int main()
{
    int n=16;
    int a[]={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    cout<<longestSubsequence(n,a);
    return 0;
}

