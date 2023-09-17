#include<bits/stdc++.h>
using namespace std;

/*// TLE
int cutSegmentsRecur(int n, int x, int y, int z)
{
	if(n==0){return 0;}
	if(n<0){return -2147483648;}

	return 1+max(cutSegmentsRecur(n-x,x,y,z),max(cutSegmentsRecur(n-y,x,y,z),cutSegmentsRecur(n-z,x,y,z)));
}

int cutSegments(int n, int x, int y, int z)
{
	return max(cutSegmentsRecur(n,x,y,z),0);
}
*/

/* // memoisation //
int cutSegmentsRecur(int n, int x, int y, int z,vector<int> &dp)
{
	if(n==0){return 0;}
	if(n<0){return -2147483648;}
	if(dp[n]!=-1){return dp[n];}

	return dp[n]=1+max(cutSegmentsRecur(n-x,x,y,z,dp),max(cutSegmentsRecur(n-y,x,y,z,dp),cutSegmentsRecur(n-z,x,y,z,dp)));
}

int cutSegments(int n, int x, int y, int z)
{
    vector<int> dp(n+1,-1);
	return max(cutSegmentsRecur(n,x,y,z,dp),0);
}
*/

int cutSegments(int n, int x, int y, int z)
{
    vector<int> dp(n+1,-1);
    dp[0]=0;

    for(int i=1;i<=n;i++)
    {
        int X=INT_MIN;
        int Y=INT_MIN;
        int Z=INT_MIN;

        if(i-x>=0){X=dp[i-x];}
        if(i-y>=0){Y=dp[i-y];}
        if(i-z>=0){Z=dp[i-z];}

        dp[i]=max(X,max(Y,Z))+1;
    }

    return max(dp[n],0);
}

int main()
{
    int n=58,x=7,y=9,z=11;
    cout<<cutSegments(n,x,y,z);
    return 0;
}
