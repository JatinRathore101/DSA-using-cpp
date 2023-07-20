#include<bits/stdc++.h>
using namespace std;

void dfs(int i,int timer,vector<vector<int>> &adj,vector<bool> &ans,vector<int> &disc,vector<int> &low,int parent,vector<bool> &visited)
{
    visited[i]=true;disc[i]=low[i]=timer;
    int child=0;

    for(auto it:adj[i])
    {
        if(!visited[it])
        {
            dfs(it,timer+1,adj,ans,disc,low,i,visited);
            low[i]=min(low[i],low[it]);

            if(low[it]>=disc[i]&&parent!=-1)
            {
                ans[i]=true;
            }
            child++;
        }
        else if(it!=parent) // back edge
        {
            low[i]=min(low[i],disc[it]);
        }
    }

    if(parent==-1&&child>1){ans[i]=true;}
}

vector<bool> findArticulationPoints(vector<vector<int>> &edges,int v,int e)
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

    vector<bool> ans(v,false);
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

    vector<bool> ans=findArticulationPoints(edges,v,e);
    for(int i=0;i<v;i++)
    {
        if(ans[i]){cout<<i<<"  ";}
    }

    return 0;
}

