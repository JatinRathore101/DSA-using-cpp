#include<bits/stdc++.h>
using namespace std;

void BFS_util(int i,vector<vector<int>> &adj,vector<int> &ans,unordered_map<int,bool> &notVisited)
{
    queue<int> q;
    q.push(i);notVisited[i]=false;

    while(!q.empty())
    {
        i=q.front();q.pop();
        ans.push_back(i);

        int n=adj[i].size();
        for(int j=0;j<n;j++)
        {
            if(notVisited[adj[i][j]])
            {
                q.push(adj[i][j]);notVisited[adj[i][j]]=false;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<vector<int>> adj(vertex);

    for(auto it:edges)
    {
        adj[it.first].push_back(it.second);
        adj[it.second].push_back(it.first);
    }

    unordered_map<int,bool> notVisited;
    for(int i=0;i<vertex;i++)
    {
        notVisited[i]=true;
        sort(adj[i].begin(),adj[i].end());
    }

    vector<int> ans;
    for(int i=0;i<vertex;i++)
    {
        if(notVisited[i])
        {
            BFS_util(i,adj,ans,notVisited);
        }
    }

    return ans;
}

int main()
{
    int vertex=4;
    vector<pair<int, int>> edges{{0,1},{0,3},{1,2},{2,3}};
    vector<int> ans=BFS(vertex,edges);
    for(auto it:ans){cout<<it<<"  ";}
    return 0;
}

