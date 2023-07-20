#include<bits/stdc++.h>
using namespace std;

template<typename T>
class graph
{
    map<T,set<T>> adj;
    map<T,bool> visited;
public:
    void addEdge(T u,T v,bool isDirected)
    {
        visited[u]=false;
        visited[v]=false;
        if(u==v){return;}

        adj[u].insert(v);
        if(!isDirected)
        {
            adj[v].insert(u);
        }
    }

    void dispGraph()
    {
        for(auto it:adj)
        {
            cout<<it.first<<"  ->   ";
            for(auto gt:it.second)
            {
                cout<<gt<<"  ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    graph<int> g;

    g.addEdge(1,2,false);
    g.addEdge(1,0,false);
    g.addEdge(1,3,true);
    g.addEdge(3,4,false);
    g.addEdge(1,1,false);
    g.addEdge(4,2,true);
    g.addEdge(0,2,true);
    cout<<endl<<endl;

    g.dispGraph();
    return 0;
}

