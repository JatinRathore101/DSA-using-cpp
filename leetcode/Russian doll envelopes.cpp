#include<bits/stdc++.h>
using namespace std;

static bool _Compare(vector<int> E1,vector<int> E2)
{
    if(E1[0]==E2[0]){return E1[1]>E2[1];}
    return E1[0]<E2[0];
}

int maxEnvelopes(vector<vector<int>>& envelopes)
{
    sort(envelopes.begin(),envelopes.end(),_Compare);
    vector<int> lis(1);lis[0]=envelopes[0][1];

    int j=0,n=envelopes.size();
    for(int i=1;i<n;i++)
    {
        if(lis[j]<envelopes[i][1])
        {
            lis.push_back(envelopes[i][1]);
            j++;
        }
        else
        {
            int k=j;
            while(k>0)
            {
                if(lis[k-1]<envelopes[i][1])
                {
                    break;
                }
                k--;
            }
            lis[k]=envelopes[i][1];
        }
    }
    return lis.size();
}

int main()
{
    vector<vector<int>> envelopes={{5,4},{6,4},{6,7},{2,3}};
    cout<<maxEnvelopes(envelopes);
    return 0;
}


