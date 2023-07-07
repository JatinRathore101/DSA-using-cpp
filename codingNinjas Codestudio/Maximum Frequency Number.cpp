#include<bits/stdc++.h>
using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    int maxFreq=0;
    unordered_map<int,int> m;

    for(auto it:arr)
    {
        m[it]++;
        if(m[it]>=maxFreq){maxFreq=m[it];}
    }

    for(auto it:arr)
    {
        if(m[it]==maxFreq){return it;}
    }
}

int main()
{
    vector<int> arr={59,64,59,54,53,50,56,54,58,51,64,54,63,65,50,61,61,63,65,58,50,52,55,60,64};
    cout<<maximumFrequency(arr,0);
    return 0;
}

