#include<bits/stdc++.h>
using namespace std;

// BFS and parent array approach

vector<int> shortestPath(vector<pair<int,int>> edges,int n,int m,int s,int t)
{
	vector<vector<int>> adj(n+1);
    for(auto it:edges)
    {
        adj[it.first].push_back(it.second);
        adj[it.second].push_back(it.first);
    }

    vector<bool> notVisited(n+1);
    notVisited[0]=false;
    vector<int> parent(n+1);
    parent[0]=-1;
    for(int i=1;i<=n;i++)
    {
        notVisited[i]=true;
        parent[i]=-1;
    }

    queue<int> q;q.push(s);
    notVisited[s]=false;
    while(!q.empty())
    {
        int i=q.front();q.pop();

        for(auto it:adj[i])
        {
            if(notVisited[it])
            {
                q.push(it);
                parent[it]=i;
                notVisited[it]=false;
            }
        }
    }

    stack<int> stk;
    int i=t;stk.push(i);
    while(i!=s)
    {
        i=parent[i];
        stk.push(i);
    }

    vector<int> ans;
    while(!stk.empty())
    {
        ans.push_back(stk.top());
        stk.pop();
    }

    return ans;
}

int main()
{
    vector<pair<int,int>> edges={{1,2},{1,3}};
    int n=3,m=2,s=3,t=1;

    vector<int> ans=shortestPath(edges,n,m,s,t);
    for(auto it:ans){cout<<it<<"  ";}

    return 0;
}
