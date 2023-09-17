#include<bits/stdc++.h>
using namespace std;

/* // TLE
int SJrecur(int i,int l,int n,vector<int>& obstacles)
{
    if(i>=n-1){return 0;}

    if(obstacles[i+1]!=l)
    {
        return SJrecur(i+1,l,n,obstacles);
    }
    else
    {
        int l2=2,l3=3;
        if(l==2){l2=1;}
        else if(l==3){l3=1;}

        if(obstacles[i]==l2)
        {
            return 1+SJrecur(i+1,l3,n,obstacles);
        }
        else if(obstacles[i]==l3)
        {
            return 1+SJrecur(i+1,l2,n,obstacles);
        }
        else
        {
            return 1+min(SJrecur(i+1,l2,n,obstacles),SJrecur(i+1,l3,n,obstacles));
        }
    }
}

int minSideJumps(vector<int>& obstacles)
{
    int lane=2,n=obstacles.size()-1;
    return SJrecur(0,2,n,obstacles);
}
*/

/* //memoization
int SJrecur(int i,int l,int n,vector<int>& obstacles,vector<vector<int>> &dp)
{
    if(i>=n-1){return dp[i][l]=0;}

    if(dp[i][l]!=-1){return dp[i][l];}

    if(obstacles[i+1]!=l)
    {
        if(dp[i+1][l]==-1){dp[i+1][l]=SJrecur(i+1,l,n,obstacles,dp);}
        return dp[i][l]=dp[i+1][l];
    }
    else
    {
        int l2=2,l3=3;
        if(l==2){l2=1;}
        else if(l==3){l3=1;}

        if(obstacles[i]==l2)
        {
            if(dp[i+1][l3]==-1){dp[i+1][l3]=SJrecur(i+1,l3,n,obstacles,dp);}
            return dp[i][l]=1+dp[i+1][l3];
        }
        else if(obstacles[i]==l3)
        {
            if(dp[i+1][l2]==-1){dp[i+1][l2]=SJrecur(i+1,l2,n,obstacles,dp);}
            return dp[i][l]=1+dp[i+1][l2];
        }
        else
        {
            if(dp[i+1][l2]==-1){dp[i+1][l2]=SJrecur(i+1,l2,n,obstacles,dp);}
            if(dp[i+1][l3]==-1){dp[i+1][l3]=SJrecur(i+1,l3,n,obstacles,dp);}
            return dp[i][l]=1+min(dp[i+1][l2],dp[i+1][l3]);
        }
    }
}

int minSideJumps(vector<int>& obstacles)
{
    int lane=2,n=obstacles.size()-1;
    vector<vector<int>> dp(n+1,vector<int>(4,-1));
    return SJrecur(0,2,n,obstacles,dp);
}
*/

/*

int minSideJumps(vector<int>& obstacles)
{
    int n=obstacles.size()-1;
    vector<vector<int>> dp(n+1,vector<int>(4,-1));

    dp[n][1]=dp[n][2]=dp[n][3]=0;

    for(int i=n-1;i>=0;i--)
    {
        for(int l=1;l<=3;l++)
        {
            if(obstacles[i]==l)
            {
                continue;
            }
            else if(obstacles[i+1]!=l)
            {
                dp[i][l]=dp[i+1][l];
            }
            else
            {
                int l2=2,l3=3;
                if(l==2){l2=1;}
                else if(l==3){l3=1;}

                if(obstacles[i]==l2)
                {
                    dp[i][l]=1+dp[i+1][l3];
                }
                else if(obstacles[i]==l3)
                {
                    dp[i][l]=1+dp[i+1][l2];
                }
                else
                {
                    dp[i][l]=1+min(dp[i+1][l2],dp[i+1][l3]);
                }
            }
        }
    }

    return dp[0][2];
}
*/

// space optimization
int minSideJumps(vector<int>& obstacles)
{
    int n=obstacles.size()-1;
    vector<vector<int>> dp(2,vector<int>(4,-1));

    dp[1][1]=dp[1][2]=dp[1][3]=0;

    for(int i=n-1;i>=0;i--)
    {
        for(int l=1;l<=3;l++)
        {
            if(obstacles[i]==l)
            {
                continue;
            }
            else if(obstacles[i+1]!=l)
            {
                dp[0][l]=dp[1][l];
            }
            else
            {
                int l2=2,l3=3;
                if(l==2){l2=1;}
                else if(l==3){l3=1;}

                if(obstacles[i]==l2)
                {
                    dp[0][l]=1+dp[1][l3];
                }
                else if(obstacles[i]==l3)
                {
                    dp[0][l]=1+dp[1][l2];
                }
                else
                {
                    dp[0][l]=1+min(dp[1][l2],dp[1][l3]);
                }
            }
        }
        dp[1]=dp[0];
    }

    return dp[0][2];
}

int main()
{
    vector<int> obstacles={0,2,1,0,3,0};
    cout<<minSideJumps(obstacles);
    return 0;
}

