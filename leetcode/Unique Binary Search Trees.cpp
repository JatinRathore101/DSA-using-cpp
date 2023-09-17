#include<bits/stdc++.h>
using namespace std;

/* // TLE
int solve(int n)
{
    if(n==0||n==1){return 1;}
    if(n==2){return 2;}

    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=solve(i)*solve(n-1-i);
    }
    return ans;
}

int numTrees(int n)
{
    return solve(n);
}
*/

// tabulation
int numTrees(int n)
{
    if(n==0||n==1){return 1;}
    if(n==2){return 2;}

    vector<int> dp(n+1,0);
    dp[0]=dp[1]=1;dp[2]=2;

    for(int i=3;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            dp[i]+=dp[j]*dp[i-1-j];
        }
    }

    return dp[n];
}

// actually the solution is catalan numbers
// formula => f(n) = [C(2n,n)]/(n+1) = prod((n+k)/k) for k in [2,n]

int main()
{
    int n=3;
    cout<<numTrees(n);
    return 0;
}

