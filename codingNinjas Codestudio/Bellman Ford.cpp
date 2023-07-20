#include<bits/stdc++.h>
using namespace std;

// algorithm is used because of negatively weighted edges, Dijkstra's algo fails in case of negative weights
// bellmon ford can be used to detect presence of negative cycle in graph
// if negative cycle is not present in the graph, only then we can find the shortest path

int bellmonFord(int n,int m,int src,int dest,vector<vector<int>> &edges)
{
    vector<int>dist(n+1,1e9);dist[src]=0;

    for(int i=1;i<n;i++)
    {
        for(auto it:edges)
        {
            if(dist[it[0]]!=1e9 && dist[it[0]]+it[2]<dist[it[1]]) // dist[it[0]]!=1e9 // this condition is must
            {
                dist[it[1]]=dist[it[0]]+it[2];
            }
        }
    }

    for(auto it:edges)
    {
        if(dist[it[0]]!=1e9 && dist[it[0]]+it[2]<dist[it[1]])
        {
            // negative cycle detected
            return -1;
        }
    }

    return dist[dest];
}

int main()
{
    int n=4,m=4,src=1,dest=4;
    vector<vector<int>> edges={{1,2,4},{1,3,3},{2,4,7},{3,4,-2}};

    cout<<bellmonFord(n,m,src,dest,edges);
    return 0;
}

