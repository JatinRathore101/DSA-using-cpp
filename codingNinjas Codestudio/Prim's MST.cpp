#include<bits/stdc++.h>
using namespace std;

vector<pair<pair<int,int>,int>> calculatePrimsMST(int n,int m,vector<pair<pair<int,int>,int>> &g)
{
    vector<vector<pair<int,int>>> adj(n+1);
    for(auto it:g)
    {
        adj[it.first.first].push_back({it.first.second,it.second});
        adj[it.first.second].push_back({it.first.first,it.second});
    }

    vector<int> parent(n+1,-1);
    vector<bool> MST(n+1,false);MST[0]=true;
    vector<int> key(n+1,INT_MAX);key[0]=-1;key[1]=0;

    for(int i=1;i<=n;i++)
    {
        int dist=INT_MAX;
        int index;

        for(int j=1;j<=n;j++)
        {
            if(MST[j]==false&&key[j]<dist)
            {
                dist=key[j];
                index=j;
            }
        }

        MST[index]=true;

        for(auto it:adj[index])
        {
            if(MST[it.first]==false&&key[it.first]>it.second)
            {
                parent[it.first]=index;
                key[it.first]=it.second;
            }
        }
    }

    g.clear();

    for(int i=2;i<=n;i++)
    {
        g.push_back({{parent[i],i},key[i]});
    }

    return g;
}

int main()
{
    int n=5,m=15;
    vector<pair<pair<int,int>,int>> g={{{1,2},21},{{1,4},16},{{2,1},12},{{2,3},13},{{2,4},18},{{2,5},15},{{3,2},13},{{3,5},17},{{4,1},16},{{4,2},18},{{4,5},19},{{5,1},18},{{5,2},15},{{5,3},17},{{5,4},19}};

    vector<pair<pair<int,int>,int>> ans=calculatePrimsMST(n,m,g);
    for(auto it:ans)
    {
        cout<<it.first.first<<"  "<<it.first.second<<"  "<<it.second<<endl;
    }

    return 0;
}


