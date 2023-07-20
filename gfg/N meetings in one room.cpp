#include<bits/stdc++.h>
using namespace std;

int maxMeetings(int start[], int end[], int n)
{
    multimap<int,int> Map;
    for(int i=0;i<n;i++)
    {
        Map.insert({end[i],start[i]});
    }

    vector<pair<int,int>> v;
    for(auto it:Map)
    {
        v.push_back({it.second,it.first});
    }

    int e=v[0].second,count=1,i=0;

    for(auto it:v)
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
    int start[100]={21,37,75,47,67,52,24,82,85,89,36,34,99,25,79,81,86,96,44,3,14,34,38,16,16,41,53,46,43,81,84,55,45,72,52,11,85,84,43,53,16};
    int end[100]={128,107,118,74,71,90,50,114,141,140,40,123,137,114,128,129,121,109,85,32,38,106,121,150,136,108,119,142,60,113,150,144,143,123,75,123,90,128,81,74,120};
    int n=41;

    cout<<maxMeetings(start,end,n);

    return 0;
}
