#include<bits/stdc++.h>
using namespace std;

void DFS_util(int i,unordered_map<int,bool>& notVisited,vector<vector<int>> &adj,vector<int> &subAns)
{
    subAns.push_back(i);
    notVisited[i]=false;

    for(auto it:adj[i])
    {
        if(notVisited[it])
        {
            DFS_util(it,notVisited,adj,subAns);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    for(auto it:edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    unordered_map<int,bool> notVisited;
    for(int i=0;i<V;i++)
    {
        sort(adj[i].begin(),adj[i].end());
        notVisited[i]=true;
    }

    vector<vector<int>> ans;
    for(int i=0;i<V;i++)
    {
        if(notVisited[i])
        {
            vector<int> subAns;
            DFS_util(i,notVisited,adj,subAns);
            ans.push_back(subAns);
        }
    }

    return ans;
}

int main()
{
    int V=9,E=7;
    vector<vector<int>> edges={{0,1},{0,2},{0,5},{3,6},{7,4},{4,8},{7,8}};
    vector<vector<int>> ans=depthFirstSearch(V,E,edges);

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

