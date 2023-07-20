#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    vector<vector<int>> adj(v);
    vector<int> indegree(v,0);
    for(auto it:edges)
    {
        indegree[it[1]]++;
        adj[it[0]].push_back(it[1]);
    }

    queue<int> q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0){q.push(i);}
    }

    vector<int> ans;
    while(!q.empty())
    {
        ans.push_back(q.front());
        for(auto it:adj[q.front()])
        {
            indegree[it]--;
            if(indegree[it]==0)
            {
                q.push(it);
            }
        }
        q.pop();
    }

    return ans;
}

int main()
{
    vector<vector<int>> edges={{0,1},{0,3},{1,2},{3,2}};
    int v=4,e=4;

    vector<int> ans=topologicalSort(edges,v,e);
    for(auto it:ans){cout<<it<<"  ";}
    return 0;
}
