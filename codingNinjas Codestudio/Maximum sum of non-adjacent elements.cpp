#include<bits/stdc++.h>
using namespace std;

/* // TLE //
int solve(int arr[],int n)
{
    if(n==1){return arr[0];}
    if(n==2){return max(arr[0],arr[1]);}
    return max(solve(arr+1,n-1),arr[0]+solve(arr+2,n-2));
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int arr[1001];int n=nums.size();
    for(int i=0;i<n;i++){arr[i]=nums[i];}
    return solve(arr,n);
}

/////////////////////////////////////////////////////////

int solve(vector<int> &nums,int i,int n)
{
    if(i==n-1){return nums[i];}
    if(i==n-2){return max(nums[i],nums[i+1]);}
    return max(solve(nums,i+1,n),nums[i]+solve(nums,i+2,n));
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    return solve(nums,0,nums.size());
}
*/

/* // Memoisation //
int solve(vector<int> &nums,int i,int n,vector<int> &dp)
{
    if(i==n-1){return nums[i];}
    if(i==n-2){return max(nums[i],nums[i+1]);}
    if(dp[n-1-i]!=-1){return dp[n-1-i];}

    return dp[n-1-i]=max(solve(nums,i+1,n,dp),nums[i]+solve(nums,i+2,n,dp));
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n=nums.size();
    vector<int> dp(n,-1);
    return solve(nums,0,n,dp);
}
*/

/*
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n=nums.size();
    vector<int> dp(n,-1);
    dp[0]=nums[0];dp[1]=max(nums[0],nums[1]);

    for(int i=2;i<n;i++){dp[i]=max(dp[i-1],dp[i-2]+nums[i]);}
    return dp[n-1];
}
*/

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n=nums.size();
    int dp0=nums[0],dp1=max(nums[0],nums[1]);

    for(int i=2;i<n;i++)
    {
        int dp2=max(dp1,dp0+nums[i]);
        dp0=dp1;dp1=dp2;
    }
    return dp1;
}

int main()
{
    vector<int> nums={1,2,3,1,3,5,8,1,9};
    cout<<maximumNonAdjacentSum(nums);
    return 0;
}

