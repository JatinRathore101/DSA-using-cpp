#include<bits/stdc++.h>
using namespace std;

/* // recurssion
int solve(int i,int n,bool preSwap,vector<int>& nums1,vector<int>& nums2)
{
    if(i==n){return 0;}

    int pre1=nums1[i-1];
    int pre2=nums2[i-1];

    if(preSwap){swap(pre1,pre2);}

    int ans=INT_MAX;

    if(nums1[i]>pre1&&nums2[i]>pre2)
    {
        ans=min(ans,solve(i+1,n,false,nums1,nums2));
    }

    if(nums1[i]>pre2&&nums2[i]>pre1)
    {
        ans=min(ans,1+solve(i+1,n,true,nums1,nums2));
    }

    return ans;
}

int minSwap(vector<int>& nums1, vector<int>& nums2)
{
    nums1.insert(nums1.begin(),-1);
    nums2.insert(nums2.begin(),-1);

    int n=nums1.size();

    return solve(1,n,false,nums1,nums2);
}
*/

/* // memoisation
int solve(int i,int n,int preSwap,vector<int>& nums1,vector<int>& nums2,vector<vector<int>>& dp)
{
    if(i==n){return 0;}
    if(dp[preSwap][i]!=-1){return dp[preSwap][i];}

    int pre1=nums1[i-1];
    int pre2=nums2[i-1];

    if(preSwap==1){swap(pre1,pre2);}

    int ans=INT_MAX;

    if(nums1[i]>pre1&&nums2[i]>pre2)
    {
        ans=min(ans,solve(i+1,n,0,nums1,nums2,dp));
    }

    if(nums1[i]>pre2&&nums2[i]>pre1)
    {
        ans=min(ans,1+solve(i+1,n,1,nums1,nums2,dp));
    }

    return dp[preSwap][i]=ans;
}

int minSwap(vector<int>& nums1, vector<int>& nums2)
{
    nums1.insert(nums1.begin(),-1);
    nums2.insert(nums2.begin(),-1);

    int n=nums1.size();

    vector<vector<int>> dp(2,vector<int>(n+1,-1));
    return solve(1,n,0,nums1,nums2,dp);
}
*/

/* // tabulation
int minSwap(vector<int>& nums1, vector<int>& nums2)
{
    nums1.insert(nums1.begin(),-1);
    nums2.insert(nums2.begin(),-1);

    int n=nums1.size();

    vector<vector<int>> dp(2,vector<int>(n+1,0));

    for(int i=n-1;i>=1;i--)
    {
        for(int j=1;j>=0;j--)
        {
            int pre1=nums1[i-1];
            int pre2=nums2[i-1];

            if(j==1){swap(pre1,pre2);}

            int ans=INT_MAX;

            if(nums1[i]>pre1&&nums2[i]>pre2)
            {
                ans=min(ans,dp[0][i+1]);
            }

            if(nums1[i]>pre2&&nums2[i]>pre1)
            {
                ans=min(ans,1+dp[1][i+1]);
            }

            dp[j][i]=ans;
        }
    }

    return dp[0][1];
}
*/

int minSwap(vector<int>& nums1, vector<int>& nums2)
{
    nums1.insert(nums1.begin(),-1);
    nums2.insert(nums2.begin(),-1);

    int n=nums1.size();

    int dp00=0,dp01=0,dp10=0,dp11=0;
    // constant space solution, no dp array created, only 4 variables created

    for(int i=n-1;i>=1;i--)
    {   // inner loop removed as it runs only 2 times for each i
        // those 2 cases written saperately

        // inner loop case j=1
        int pre1=nums1[i-1];
        int pre2=nums2[i-1];
        swap(pre1,pre2);
        int ans=INT_MAX;
        if(nums1[i]>pre1&&nums2[i]>pre2)
        {ans=min(ans,dp01);}
        if(nums1[i]>pre2&&nums2[i]>pre1)
        {ans=min(ans,1+dp11);}
        dp10=ans;

        // inner loop case j=0
        pre1=nums1[i-1];
        pre2=nums2[i-1];
        ans=INT_MAX;
        if(nums1[i]>pre1&&nums2[i]>pre2)
        {ans=min(ans,dp01);}
        if(nums1[i]>pre2&&nums2[i]>pre1)
        {ans=min(ans,1+dp11);}
        dp00=ans;

        dp01=dp00;
        dp11=dp10;
    }

    return dp01;
}

int main()
{
    vector<int> nums1={1,3,5,4};
    vector<int> nums2={1,2,3,7};
    cout<<minSwap(nums1,nums2);
    return 0;
}

