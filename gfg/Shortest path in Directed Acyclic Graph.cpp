#include<bits/stdc++.h>
using namespace std;

/* //without topological sort//
vector<int> shortestPath(int N,int M,vector<vector<int>>& edges)
{
    vector<vector<pair<int,int>>> adj(N);
    for(auto it:edges){adj[it[0]].push_back({it[1],it[2]});}

    vector<int> dist(N,-1);dist[0]=0;

    for(int i=0;i<N;i++)
    {
        if(dist[i]==-1){continue;}
        for(auto it:adj[i])
        {
            if(dist[it.first]==-1){dist[it.first]=dist[i]+it.second;}
            else{dist[it.first]=min(dist[it.first],dist[i]+it.second);}
        }
    }

    return dist;
}
*/

// with topological sort
vector<int> topologicalSort(int N,vector<vector<pair<int,int>>> &adj)
{
    vector<int> indegree(N);
    for(auto it:adj)
    {
        for(auto gt:it)
        {
            indegree[gt.first]++;
        }
    }

    queue<int> q;
    for(int i=0;i<N;i++){if(indegree[i]==0)q.push(i);}

    vector<int> ans;
    while(!q.empty())
    {
        for(auto it:adj[q.front()])
        {
            indegree[it.first]--;
            if(indegree[it.first]==0)
            {
                q.push(it.first);
            }
        }
        ans.push_back(q.front());
        q.pop();
    }

    return ans;
}

vector<int> shortestPath(int N,int M,vector<vector<int>>& edges)
{
    vector<vector<pair<int,int>>> adj(N);
    for(auto it:edges){adj[it[0]].push_back({it[1],it[2]});}

    vector<int> topoOrder=topologicalSort(N,adj);

    vector<int> dist(N,-1);dist[0]=0;

    int i=0;while(topoOrder[i]!=0){i++;}

    while(i<N)
    {
        int j=topoOrder[i];
        if(dist[j]!=-1)
        {
            for(auto it:adj[j])
            {
                if(dist[it.first]==-1){dist[it.first]=dist[j]+it.second;}
                else{dist[it.first]=min(dist[it.first],dist[j]+it.second);}
            }
        }
        i++;
    }

    return dist;
}

int main()
{
    int N=10,M=24;
    vector<vector<int>> edges={{0,2,6},{0,3,7},{0,4,9},{0,6,8},{0,7,6},{1,2,6},{1,3,7},{1,5,10},{1,6,1},{1,7,4},{2,3,3},{2,6,10},{2,8,8},{2,9,10},{3,5,3},{3,6,10},{3,7,5},{5,6,9},{5,7,7},{6,7,7},{6,8,8},{6,9,8},{7,9,1},{8,9,6}};

    vector<int> ans=shortestPath(N,M,edges);
    for(auto it:ans){cout<<it<<"  ";}

    return 0;
}
