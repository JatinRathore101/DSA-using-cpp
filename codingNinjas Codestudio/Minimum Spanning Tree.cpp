#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
int getParent(vector<int> &parent,int i)
{
    if(parent[i]==i){return i;}
    return parent[i]=getParent(parent,parent[i]);
}

void unionSet(int u,int v,vector<int> &parent,vector<int> &rank)
{
    u=getParent(parent,u);
    v=getParent(parent,v);

    if(rank[u]<rank[v])
    {
        parent[u]=v;
    }
    else if(rank[u]>rank[v])
    {
        parent[v]=u;
    }
    else
    {
        parent[u]=v;
        rank[v]++;
    }
}

// whole code was giving TLE because & empersand
// ie.. call by refrence was not used in cmp function
bool cmp(vector<int> &a,vector<int> &b)
{
    return a[2]<b[2];
}

int minimumSpanningTree(vector<vector<int>>& edges,int n)
{
    sort(edges.begin(),edges.end(),cmp);

    vector<int> parent(n);
    vector<int> rank(n);
    for(int i=0;i<n;i++){parent[i]=i;rank[i]=0;}

    int w=0,m=edges.size();
    for(int i=0;i<m;i++)
    {

        if(getParent(parent,edges[i][0])!=getParent(parent,edges[i][1]))
        {
            unionSet(edges[i][0],edges[i][1],parent,rank);
            w+=edges[i][2];
        }
    }

    return w;
}

int main()
{
    vector<vector<int>> edges={{1,2,6},{2,3,2},{1,3,2},{1,0,2}};
    int n=4;
    cout<<minimumSpanningTree(edges,n);
    return 0;
}

