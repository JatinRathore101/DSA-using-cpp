#include<bits/stdc++.h>
using namespace std;

/* // TLE
int solve(int i,int n1,string&text1,int j,int n2,string&text2)
{
    if(i>=n1||j>=n2){return 0;}
    if(text1[i]==text2[j])
    {
        return 1+solve(i+1,n1,text1,j+1,n2,text2);
    }

    int ans1=solve(i+1,n1,text1,j,n2,text2);
    int ans2=solve(i,n1,text1,j+1,n2,text2);

    return max(ans1,ans2);
}

int longestCommonSubsequence(string text1, string text2)
{
    return solve(0,text1.size(),text1,0,text2.size(),text2);
}
*/

/* // memoisation
int solve(int i,int n1,string&text1,int j,int n2,string&text2,vector<vector<int>>& dp)
{
    if(i>=n1||j>=n2){return 0;}
    if(dp[i][j]!=-1){return dp[i][j];}

    if(text1[i]==text2[j])
    {
        return dp[i][j]=1+solve(i+1,n1,text1,j+1,n2,text2,dp);
    }

    int ans1=solve(i+1,n1,text1,j,n2,text2,dp);
    int ans2=solve(i,n1,text1,j+1,n2,text2,dp);

    return dp[i][j]=max(ans1,ans2);
}

int longestCommonSubsequence(string text1, string text2)
{
    int n1=text1.size(),n2=text2.size();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
    return solve(0,text1.size(),text1,0,text2.size(),text2,dp);
}
*/

/* // tabulation
int longestCommonSubsequence(string text1, string text2)
{
    int n1=text1.size(),n2=text2.size();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

    for(int i=n1-1;i>=0;i--)
    {
        for(int j=n2-1;j>=0;j--)
        {
            if(text1[i]==text2[j])
            {
                dp[i][j]=1+dp[i+1][j+1];
            }
            else
            {
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }

    return dp[0][0];
}
*/

// tabulation with space optimization
int longestCommonSubsequence(string text1, string text2)
{
    int n1=text1.size(),n2=text2.size();

    vector<int> dpi0(n2+1,0);
    vector<int> dpi1(n2+1,0);

    for(int i=n1-1;i>=0;i--)
    {
        for(int j=n2-1;j>=0;j--)
        {
            if(text1[i]==text2[j])
            {
                dpi0[j]=1+dpi1[j+1];
            }
            else
            {
                dpi0[j]=max(dpi1[j],dpi0[j+1]);
            }
        }
        dpi1=dpi0;
    }

    return dpi0[0];
}

int main()
{
    string text1="abcde";
    string text2="ace";
    cout<<longestCommonSubsequence(text1,text2);
    return 0;
}

