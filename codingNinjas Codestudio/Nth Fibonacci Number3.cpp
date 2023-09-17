#include<bits/stdc++.h>
using namespace std;

// dynamic programming // O(1) space //

int main()
{
    int n;
    cin>>n;

    int pre1=0,pre2=1,curr=n;

    if(n>1){for(int i=2;i<=n;i++){curr=pre1+pre2;pre1=pre2;pre2=curr;}}
    cout<<curr;

    return 0;
}

