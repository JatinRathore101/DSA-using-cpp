#include<bits/stdc++.h>
using namespace std;

/* // memory limit exceeded
int solve(int i,int n1,string&s,int j,int n2,string&p)
{
    if(i==n1)
    {
        while(j<n2)
        {
            //if(p[j]!='?'&&p[j]!='*')
            if(p[j]!='*') // according to condition given only '*' can replace empty spaces
            {
                return 0;
            }
            j++;
        }
        if(j==n2){return 1;}
        return 0;
    }

    int ans=0;
    if(s[i]==p[j]||p[j]=='?')
    {
        ans=solve(i+1,n1,s,j+1,n2,p);
    }
    else if(p[j]=='*')
    {
        int ans1=solve(i+1,n1,s,j,n2,p);
        int ans2=solve(i,n1,s,j+1,n2,p);

        ans=ans1|ans2;
    }

    return ans;
}

bool isMatch(string s, string p)
{
    if(solve(0,s.size(),s,0,p.size(),p)==1)
    {
        return true;
    }
    return false;
}
*/

/* // memoisation // include string too by reference to save time
int solve(int i,int n1,string&s,int j,int n2,string&p,vector<vector<int>>&dp)
{
    if(i==n1)
    {
        while(j<n2)
        {
            if(p[j]!='*')
            {
                return 0;
            }
            j++;
        }
        if(j==n2){return 1;}
        return 0;
    }

    if(dp[i][j]!=-1){return dp[i][j];}

    int ans=0;
    if(s[i]==p[j]||p[j]=='?')
    {
        ans=solve(i+1,n1,s,j+1,n2,p,dp);
    }
    else if(p[j]=='*')
    {
        int ans1=solve(i+1,n1,s,j,n2,p,dp);
        int ans2=solve(i,n1,s,j+1,n2,p,dp);

        ans=ans1|ans2;
    }

    return dp[i][j]=ans;
}

bool isMatch(string s, string p)
{
    int n1=s.size(),n2=p.size();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));

    if(solve(0,n1,s,0,n2,p,dp)==1)
    {
        return true;
    }
    return false;
}
*/

/* // tabulation
bool isMatch(string s, string p)
{
    int n1=s.size(),n2=p.size();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

    dp[n1][n2]=1;

    int j=n2-1;
    while(j>=0&&p[j]=='*'){dp[n1][j]=1;j--;}

    for(int i=n1-1;i>=0;i--)
    {
        for(int j=n2-1;j>=0;j--)
        {
            int ans=0;
            if(s[i]==p[j]||p[j]=='?')
            {
                ans=dp[i+1][j+1];
            }
            else if(p[j]=='*')
            {
                if(dp[i+1][j]==1||dp[i][j+1]==1)
                {
                    ans=1;
                }
            }

            dp[i][j]=ans;
        }
    }

    if(dp[0][0]==1)
    {
        return true;
    }
    return false;
}
*/

///space optimization
bool isMatch(string s, string p)
{
    int n1=s.size(),n2=p.size();
    vector<int> dpi1(n2+1,0);//i = n1
    vector<int> dpi0(n2+1,0);//i = n1-1

    dpi1[n2]=1;

    int j=n2-1;
    while(j>=0&&p[j]=='*'){dpi1[j]=1;j--;}

    if(n1==0) // exception handling
    {
        if(n2==0||j<0){return true;}
        return false;
    }

    for(int i=n1-1;i>=0;i--)
    {
        for(int j=n2-1;j>=0;j--)
        {
            int ans=0;
            if(s[i]==p[j]||p[j]=='?')
            {
                ans=dpi1[j+1];
            }
            else if(p[j]=='*')
            {
                if(dpi1[j]==1||dpi0[j+1]==1)
                {
                    ans=1;
                }
            }

            dpi0[j]=ans;
        }
        dpi1=dpi0;
    }

    if(dpi0[0]==1)
    {
        return true;
    }
    return false;
}

int main()
{
    string s="";
    string p="*";
    cout<<::boolalpha<<isMatch(s,p);
    return 0;
}

