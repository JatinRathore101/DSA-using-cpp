#include<bits/stdc++.h>
using namespace std;

void dfsUtil(int i,stack<int> &s,vector<bool> &notVisited,vector<vector<int>> &adj)
{
    notVisited[i]=false;

    for(auto it:adj[i])
    {
        if(notVisited[it])
        {
            dfsUtil(it,s,notVisited,adj);
        }
    }

    s.push(i);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    vector<vector<int>> adj(v);
    for(auto it:edges)
    {
        adj[it[0]].push_back(it[1]);
    }

    vector<bool> notVisited(v);
    for(int i=0;i<v;i++){notVisited[i]=true;}

    stack<int> s;
    for(int i=0;i<v;i++)
    {
        if(notVisited[i])
        {
            dfsUtil(i,s,notVisited,adj);
        }
    }

    vector<int> ans;

    while(!s.empty()){ans.push_back(s.top());s.pop();}
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
