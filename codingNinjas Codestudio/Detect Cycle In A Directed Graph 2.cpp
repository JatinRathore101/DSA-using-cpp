#include<bits/stdc++.h>
using namespace std;

// BFS // Kahn's inverse approach // if cycle possible => topological sort not possible

int detectCycleInDirectedGraph(int n,vector<pair<int,int>> &edges)
{
    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1,0);
    indegree[0]=-1;
    for(auto it:edges)
    {
        adj[it.first].push_back(it.second);
        indegree[it.second]++;
    }

    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }

    int count=0;
    while(!q.empty())
    {
        for(auto it:adj[q.front()])
        {
            indegree[it]--;
            if(indegree[it]==0)
            {
                q.push(it);
            }
        }
        q.pop();
        count++;
    }

    if(count==n){return false;}
    return true;
}

int main()
{
    int n=5;
    vector<pair<int,int>> edges={{1,2},{4,1},{2,4},{3,4},{5,2},{1,3}};
    cout<<detectCycleInDirectedGraph(n,edges);
    return 0;
}

