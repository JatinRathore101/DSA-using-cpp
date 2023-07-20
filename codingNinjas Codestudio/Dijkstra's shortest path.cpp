#include<bits/stdc++.h>
using namespace std;

/*
class cmp
{
public:
    bool operator()(pair<int,int> a,pair<int,int> b)
    {
        return a.first>b.first;
    }
};
*/

vector<int> dijkstra(vector<vector<int>> &vec,int vertices,int edges,int source)
{
    vector<vector<pair<int,int>>> adj(vertices);
    for(auto it:vec)
    {
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }

    vector<int> ans(vertices,INT_MAX);ans[source]=0;
    set<pair<int,int>> distNode;distNode.insert({0,source});
    while(!distNode.empty())
    {
        auto nt=distNode.begin();
        pair<int,int> it=*nt;
        distNode.erase(nt);

        for(auto gt:adj[it.second])
        {
            if(ans[gt.first]>it.first+gt.second)
            {
                distNode.erase({ans[gt.first],gt.first});
                ans[gt.first]=it.first+gt.second;
                distNode.insert({ans[gt.first],gt.first});
            }
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> vec={{0,1,4},{0,7,8},{1,2,8},{1,7,11},{2,3,7},{2,5,4},{2,8,2},{3,4,9},{3,5,14},{4,5,10},{5,6,2},{6,7,1},{6,8,6},{7,8,7}};
    int vertices=9,edges=14,source=0;

    vector<int> ans=dijkstra(vec,vertices,edges,source);
    for(auto it:ans){cout<<it<<"  ";}

    return 0;
}




