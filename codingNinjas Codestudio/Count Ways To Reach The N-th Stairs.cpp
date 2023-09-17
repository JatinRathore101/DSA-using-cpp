#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
int countDistinctWays(int nStairs)
{
    vector<int>dp(nStairs+1,-1);
    dp[0]=1;dp[1]=1;dp[2]=2;

    int m = 1000000007;

    for(int i=3;i<=nStairs;i++)
    {
        dp[i]=(dp[i-1]%m+dp[i-2]%m)%m;
    }
    return dp[nStairs];
}

int main()
{
    int n;cin>>n;cout<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<countDistinctWays(i)<<endl;
    }
    return 0;
}

