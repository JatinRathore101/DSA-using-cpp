#include<bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m)
{
    sort(a.begin(),a.end());

    long long ans=1000000000;
    long long i=0,j=m-1;

    while(j<n)
    {
        ans=min(ans,a[j]-a[i]);
        i++;j++;
    }

    return ans;
}

int main()
{
    return 0;
}

