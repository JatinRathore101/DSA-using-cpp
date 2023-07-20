#include<bits/stdc++.h>
using namespace std;

// using BFS // BFS has no recurrsive calls => parent datastructure is necessary

bool BFS_util(int i,unordered_map<int,int> &parent,unordered_map<int,bool> &notVisited,vector<vector<int>> &adj)
{

    queue<int> q;q.push(i);notVisited[i]=false;

    while(!q.empty())
    {
        i=q.front();q.pop();

        for(auto it:adj[i])
        {
            if(notVisited[it])
            {
                q.push(it);
                notVisited[it]=false;
                parent[it]=i;
            }
            else
            {
                if(parent[it]!=-1&&parent[it]!=i&&parent[i]!=it)
                {
                    return true;
                }
            }
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
            if(BFS_util(i,parent,notVisited,adj))
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
    vector<vector<int>> edges={{4,3},{1,4},{4,3},{3,1}};
    int n=4,m=3;

    cout<<cycleDetection(edges,n,m);
    return 0;
}

