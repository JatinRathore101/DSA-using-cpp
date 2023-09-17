#include<bits/stdc++.h>
using namespace std;

long long int houseRobber(vector<int>& valueInHouse)
{
    long long int n=valueInHouse.size();
    long long int dp0=valueInHouse[0];
    long long int dp1=max(valueInHouse[0],valueInHouse[1]);

    for(int i=2;i<n-1;i++)
    {
        long long int dp2=max(dp0+valueInHouse[i],dp1);
        dp0=dp1;
        dp1=dp2;
    }

    long long int dp3=dp1;

    dp0=valueInHouse[1];
    dp1=max(valueInHouse[1],valueInHouse[2]);

    for(int i=3;i<n;i++)
    {
        long long int dp2=max(dp0+valueInHouse[i],dp1);
        dp0=dp1;
        dp1=dp2;
    }

    return max(dp1,dp3);
}

int main()
{
    vector<int> valueInHouse={1,5,1,2,6};
    cout<<houseRobber(valueInHouse);
    return 0;
}

