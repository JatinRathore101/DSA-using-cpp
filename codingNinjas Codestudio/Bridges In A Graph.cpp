#include<bits/stdc++.h>
using namespace std;

void dfs(int i,int timer,vector<vector<int>> &adj,vector<vector<int>> &ans,vector<int> &disc,vector<int> &low,int parent,vector<bool> &visited)
{
    visited[i]=true;disc[i]=low[i]=timer;

    for(auto it:adj[i])
    {
        if(!visited[it])
        {
            dfs(it,timer+1,adj,ans,disc,low,i,visited);
            low[i]=min(low[i],low[it]);

            if(low[it]>disc[i])
            {
                ans.push_back({min(i,it),max(i,it)});
            }
        }
        else if(it!=parent) // back edge
        {
            low[i]=min(low[i],disc[it]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges,int v,int e)
{
    vector<vector<int>> adj(v);
    for(auto it:edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    int timer=0;
    vector<int> disc(v,-1);
    vector<int> low(v,-1);
    vector<bool> visited(v,false);

    vector<vector<int>> ans;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            int parent=-1;
            dfs(i,timer,adj,ans,disc,low,parent,visited);
        }
    }

    return ans;
}

int main()
{
    int v=6,e=7;
    vector<vector<int>> edges={{1,2},{1,0},{0,2},{0,4},{5,4},{5,3},{3,4}};

    vector<vector<int>> ans=findBridges(edges,v,e);
    for(auto it:ans)
    {
        for(auto gt:it)
        {
            cout<<gt<<"  ";
        }
        cout<<endl;
    }

    return 0;
}

