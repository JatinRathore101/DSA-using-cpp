#include<bits/stdc++.h>
using namespace std;

/*
int solve(int i,int j,int n,int m,int &max_ans,vector<vector<int>>&mat)
{
    if(i>=n||j>=m){return 0;}

    int ans_left=solve(i,j+1,n,m,max_ans,mat);
    int ans_down=solve(i+1,j,n,m,max_ans,mat);
    int ans_diag=solve(i+1,j+1,n,m,max_ans,mat);

    if(mat[i][j]==1)
    {
        int ans=1+min(ans_diag,min(ans_down,ans_left));
        max_ans=max(ans,max_ans);
        return ans;
    }

    return 0;
}

int maxSquare(int n,int m,vector<vector<int>> mat)
{
    int max_ans=0;
    int ans=solve(0,0,n,m,max_ans,mat);
    return max_ans;
}
*/

/* // memoisation
int solve(int i,int j,int n,int m,int &max_ans,vector<vector<int>>&mat,vector<vector<int>>&dp)
{
    if(i>=n||j>=m){return 0;}
    if(dp[i][j]!=-1){return dp[i][j];}

    int ans_left=solve(i,j+1,n,m,max_ans,mat,dp);
    int ans_down=solve(i+1,j,n,m,max_ans,mat,dp);
    int ans_diag=solve(i+1,j+1,n,m,max_ans,mat,dp);

    if(mat[i][j]==1)
    {
        int ans=1+min(ans_diag,min(ans_down,ans_left));
        max_ans=max(ans,max_ans);
        return dp[i][j]=ans;
    }

    return dp[i][j]=0;
}

int maxSquare(int n,int m,vector<vector<int>> mat)
{
    int max_ans=0;vector<vector<int>> dp(n,vector<int>(m,-1));
    int ans=solve(0,0,n,m,max_ans,mat,dp);
    return max_ans;
}
*/

int maxSquare(int n,int m,vector<vector<int>> mat)
{
    if(n==1||m==1)
    {
        for(auto it:mat)
        {
            for(auto gt:it)
            {
                if(gt==1)
                {
                    return 1;
                }
            }
        }

        return 0;
    }

    int ans=0;

    for(int i=n-2;i>=0;i--)
    {
        for(int j=m-2;j>=0;j--)
        {
            if(mat[i][j]==1)
            {
                mat[i][j]+=min(mat[i][j+1],min(mat[i+1][j],mat[i+1][j+1]));
                ans=max(mat[i][j],ans);
            }
        }
    }

    return ans;
}

/*
int maxSquare(int n,int m,vector<vector<int>> mat)
{
    vector<vector<int>> dp(n,vector<int>(m,-1));
    int ans=0;

    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(mat[i][j]==1)
            {
                if(i!=n-1&&j!=m-1)
                {
                    mat[i][j]+=min(mat[i][j+1],min(mat[i+1][j],mat[i+1][j+1]));
                }
                ans=max(mat[i][j],ans);
            }
        }
    }

    return ans;
}
*/

int main()
{
    int n=rand()%5+4,m=rand()%4+5;
    vector<vector<int>> mat(n,vector<int>(m,0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            mat[i][j]=rand()%2;
            cout<<mat[i][j]<<"  ";
        }
        cout<<endl;
        cout<<endl;
    }

    cout<<maxSquare(n,m,mat);
    return 0;
}
