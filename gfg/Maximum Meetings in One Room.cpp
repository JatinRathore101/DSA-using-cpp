#include<bits/stdc++.h>
using namespace std;

vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F)
{
    multimap<int,pair<int,int>> Map;
    for(int i=0;i<N;i++)
    {
        Map.insert({F[i],{S[i],i+1}});
    }

    vector<vector<int>> vec;
    for(auto it:Map)
    {
        vector<int> entry(3);
        entry[0]=it.second.second;
        entry[1]=it.second.first;
        entry[2]=it.first;
        vec.push_back(entry);
    }

    int e=0;
    vector<int> ans;

    for(auto it:vec)
    {
        if(e<it[1])
        {
            ans.push_back(it[0]);
            e=it[2];
        }
    }

    sort(ans.begin(),ans.end());

    return ans;
}

int main()
{
    return 0;
}

