#include<bits/stdc++.h>
using namespace std;

/*
#define m 1000000007
long long int countDerangements(int n)
{
    if(n==1){return 0;}
    if(n==2){return 1;}
    return (((n-1)%m)*((countDerangements(n-1)%m)+(countDerangements(n-2)%m)))%m;
}
*/

/* // memoisation //
#define m 1000000007
long long int countDerangementsRecur(int n,vector<int> &dp)
{
    if(n==1){return 0;}
    if(n==2){return 1;}
    if(dp[n]!=-1){return dp[n];}

    return dp[n] = (((n-1)%m)*((countDerangementsRecur(n-1,dp)%m)+(countDerangementsRecur(n-2,dp)%m)))%m;
}

long long int countDerangements(int n)
{
    vector<int> dp(n+1,-1);
    return countDerangementsRecur(n,dp);
}
*/

/*
#define m 1000000007
long long int countDerangements(int n)
{
    vector<long long int> dp(n+1,-1);
    dp[1]=0;dp[2]=1;
    for(int i=3;i<=n;i++)
    {
        dp[i]=(((i-1)%m)*((dp[i-1]%m)+(dp[i-2]%m)))%m;
    }
    return dp[n];
}
*/

#define m 1000000007
long long int countDerangements(int n)
{
    long long int dp1=0,dp2=1;
    for(int i=3;i<=n;i++)
    {
        long long int dp3=(((i-1)%m)*((dp2%m)+(dp1%m)))%m;
        dp1=dp2;
        dp2=dp3;
    }

    return dp2;
}

int main()
{
    int n=4;
    cout<<countDerangements(n);
    return 0;
}

