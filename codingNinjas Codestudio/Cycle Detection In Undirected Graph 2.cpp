#include<bits/stdc++.h>
using namespace std;

// in both codes alternatively we can pass parent as integer each time in DFS_util and BFS_util

// using DFS

/*
bool DFS_util(int i,unordered_map<int,int> &parent,unordered_map<int,bool> &notVisited,vector<vector<int>> &adj)
{
    notVisited[i]=false;

    for(auto it:adj[i])
    {
        if(notVisited[it])
        {
            parent[it]=i;
            if(DFS_util(it,parent,notVisited,adj))
            {
                return true;
            }
        }
        else if(parent[it]!=-1&&parent[it]!=i&&parent[i]!=it)
        {
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> adj(n+1);
    for(auto it:edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    unordered_map<int,int> parent;
    unordered_map<int,bool> notVisited;
    for(int i=1;i<=n;i++)
    {
        parent[i]=-1;
        notVisited[i]=true;
    }

    string ans="No";
    for(int i=1;i<=n;i++)
    {
        if(notVisited[i])
        {
            if(DFS_util(i,parent,notVisited,adj))
            {
                ans="Yes";
                break;
            }
        }
    }

    return ans;
}
*/

bool DFS_util(int i,int parent,unordered_map<int,bool> &notVisited,vector<vector<int>> &adj)
{
    notVisited[i]=false;

    for(auto it:adj[i])
    {
        if(notVisited[it])
        {
            if(DFS_util(it,i,notVisited,adj))
            {
                return true;
            }
        }
        else if(parent!=it)
        {
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> adj(n+1);
    for(auto it:edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    unordered_map<int,bool> notVisited;
    for(int i=1;i<=n;i++)
    {
        notVisited[i]=true;
    }

    string ans="No";
    for(int i=1;i<=n;i++)
    {
        if(notVisited[i])
        {
            if(DFS_util(i,-1,notVisited,adj))
            {
                ans="Yes";
                break;
            }
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> edges={{2,6},{2,3},{2,4},{1,5},{5,7},{6,7},{3,7}};
    int n=7,m=7;

    cout<<cycleDetection(edges,n,m);
    return 0;
}

