#include<bits/stdc++.h>
using namespace std;

// in cycle detection of directed graph we don't need parent data structure

bool dfs_util(int i,unordered_map<int,bool> &notVisited,unordered_map<int,bool> &activeCall,vector<vector<int>> &adj)
{
    notVisited[i]=false;

    for(auto it:adj[i])
    {
        if(notVisited[it])
        {
            activeCall[it]=true;
            if(dfs_util(it,notVisited,activeCall,adj))
            {
                return true;
            }
            activeCall[it]=false;
        }
        else if(activeCall[it])
        {
            return true;
        }
    }

    return false;
}

int detectCycleInDirectedGraph(int n,vector<pair<int,int>> &edges)
{
    vector<vector<int>> adj(n+1);
    for(auto it:edges)
    {
        adj[it.first].push_back(it.second);
    }

    unordered_map<int,bool> notVisited;
    unordered_map<int,bool> activeCall;


    for(int i=1;i<=n;i++)
    {
        notVisited[i]=true;
        activeCall[i]=false;
    }

    for(int i=1;i<=n;i++)
    {
        if(notVisited[i])
        {
            activeCall[i]=true;
            if(dfs_util(i,notVisited,activeCall,adj))
            {
                return true;
            }
            activeCall[i]=false;
        }
    }
    return false;
}

int main()
{
    int n=5;
    vector<pair<int,int>> edges={{1,2},{4,1},{2,4},{3,4},{5,2},{1,3}};
    cout<<detectCycleInDirectedGraph(n,edges);
    return 0;
}

