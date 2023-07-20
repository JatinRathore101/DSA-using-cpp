#include<bits/stdc++.h>
using namespace std;

int activitySelection(vector<int> start, vector<int> end, int n)
{
    if(n==1){return n;}
    multimap<int,int> Map;
    for(int i=0;i<n;i++)
    {
        Map.insert({end[i],start[i]});
    }
    vector<pair<int,int>> vec;

    for(auto it:Map)
    {
        vec.push_back({it.second,it.first});
    }

    int e=vec[0].second,count=1;

    for(auto it:vec)
    {
        if(e<it.first)
        {
            count++;
            e=it.second;
        }
    }

    return count;
}

int main()
{
    return 0;
}

