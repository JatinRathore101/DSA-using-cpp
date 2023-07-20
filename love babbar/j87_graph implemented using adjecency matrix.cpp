#include<bits/stdc++.h>
using namespace std;

template<typename T>
class graph
{
    vector<vector<int>> adj;
public:
    void addEdge(int u,int v,bool directed)
    {
        while(u>=adj.size())
        {vector<int> vec;adj.push_back(vec);}
        adj[u].push_back(v);

        if(!directed)
        {
            while(v>=adj.size())
            {vector<int> vec;adj.push_back(vec);}
            adj[v].push_back(u);
        }
    }

    void dispGraph()
    {
        cout<<"     ";int n=adj.size()-1;
        for(int i=0;i<=n;i++){cout<<"  "<<i;}
        cout<<endl<<"     ";
        for(int i=0;i<=n;i++){cout<<"  -";}


        for(int i=0;i<=n;i++)
        {
            cout<<endl;
            cout<<" "<<i<<" | ";
            int j=0;
            for(auto it:adj[i])
            {
                while(j<it){cout<<"  "<<0;j++;}
                cout<<"  "<<1;j++;
            }
            while(j<=n){cout<<"  "<<0;j++;}
        }
    }

};

int main()
{
    graph<int> grp;

    grp.addEdge(0,1,false);
    grp.addEdge(0,2,true);
    grp.addEdge(3,1,true);
    grp.addEdge(3,4,false);
    grp.addEdge(0,3,true);

    grp.dispGraph();
    return 0;
}

/*
GRAPHS
node, edges
directed/undirected
degree, indegree, outdegree
weighted/unweighted
path
cyclic graph   a1 -> a2 ->  .......  -> an -> a1 // cyclic/acyclic
*/
