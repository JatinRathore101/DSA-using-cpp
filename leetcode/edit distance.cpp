#include<bits/stdc++.h>
using namespace std;

/* // memory limit exceeded
int solve(int i,int n1,string word1,int j,int n2,string word2)
{
    if(i==n1&&j==n2){return 0;}
    if(i==n1&&j<n2){return n2-j;}
    if(i<n1&&j==n2){return n1-i;}

    int ans=0;

    if(word1[i]==word2[j])
    {
        ans=solve(i+1,n1,word1,j+1,n2,word2);
    }
    else
    {
        int Insert=1+solve(i,n1,word1,j+1,n2,word2);
        int Delete=1+solve(i+1,n1,word1,j,n2,word2);
        int Replace=1+solve(i+1,n1,word1,j+1,n2,word2);
        ans=min(Insert,min(Delete,Replace));
    }
    return ans;
}

int minDistance(string word1, string word2)
{
    return solve(0,word1.size(),word1,0,word2.size(),word2);
}
*/

/* // memoisation
int solve(int i,int n1,string word1,int j,int n2,string word2,vector<vector<int>>&dp)
{
    if(i==n1&&j==n2){return 0;}
    if(i==n1&&j<n2){return n2-j;}
    if(i<n1&&j==n2){return n1-i;}

    if(dp[i][j]!=-1){return dp[i][j];}

    int ans=0;

    if(word1[i]==word2[j])
    {
        ans=solve(i+1,n1,word1,j+1,n2,word2,dp);
    }
    else
    {
        int Insert=1+solve(i,n1,word1,j+1,n2,word2,dp);
        int Delete=1+solve(i+1,n1,word1,j,n2,word2,dp);
        int Replace=1+solve(i+1,n1,word1,j+1,n2,word2,dp);
        ans=min(Insert,min(Delete,Replace));
    }
    return dp[i][j]=ans;
}

int minDistance(string word1, string word2)
{
    int n1=word1.size();
    int n2=word2.size();

    vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
    return solve(0,n1,word1,0,n2,word2,dp);
}
*/

/* // tabulation
int minDistance(string word1, string word2)
{
    int n1=word1.size();
    int n2=word2.size();

    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
    for(int j=0;j<n2;j++){dp[n1][j]=n2-j;}
    for(int i=0;i<n1;i++){dp[i][n2]=n1-i;}

    for(int i=n1-1;i>=0;i--)
    {
        for(int j=n2-1;j>=0;j--)
        {
            int ans=0;

            if(word1[i]==word2[j])
            {
                ans=dp[i+1][j+1];
            }
            else
            {
                int Insert=1+dp[i][j+1];
                int Delete=1+dp[i+1][j];
                int Replace=1+dp[i+1][j+1];
                ans=min(Insert,min(Delete,Replace));
            }
            dp[i][j]=ans;
        }
    }

    return dp[0][0];
}
*/

// space optimized tabulation
int minDistance(string word1, string word2)
{
    int n1=word1.size();
    int n2=word2.size();

    if(n1==0){return n2;}
    if(n2==0){return n1;}

    vector<int> dpi0(n2+1,0);
    vector<int> dpi1(n2+1,0);

    // base case
    for(int j=0;j<n2;j++){dpi1[j]=n2-j;}

    for(int i=n1-1;i>=0;i--)
    {
        // base case
        dpi0[n2]=n1-i;

        for(int j=n2-1;j>=0;j--)
        {
            int ans=0;

            if(word1[i]==word2[j])
            {
                ans=dpi1[j+1];
            }
            else
            {
                int Insert=1+dpi0[j+1];
                int Delete=1+dpi1[j];
                int Replace=1+dpi1[j+1];
                ans=min(Insert,min(Delete,Replace));
            }
            dpi0[j]=ans;
        }
        dpi1=dpi0;
    }

    return dpi0[0];
}

int main()
{
    string word1="horse";
    string word2="ros";
    cout<<minDistance(word1,word2);
    return 0;
}

