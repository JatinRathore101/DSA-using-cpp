#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> printAdjacency(int n,int m,vector<vector<int>> &edges)
{
    vector<vector<int>> ans(n);
    for(int i=0;i<n;i++){ans[i].push_back(i);}

    for(auto it:edges)
    {
        ans[it[0]].push_back(it[1]);
        ans[it[1]].push_back(it[0]);
    }

    return ans;
}

int main()
{
    return 0;
}

