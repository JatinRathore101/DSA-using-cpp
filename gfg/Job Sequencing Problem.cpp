#include<bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int dead;
    int profit;
};

static bool comp(Job J1,Job J2)
{
    return J1.profit>J2.profit;
}

vector<int> JobScheduling(Job arr[],int n)
{
    sort(arr,arr+n,comp);
    vector<bool> bookedDay(100001,false);

    vector<int> ans={0,0};

    for(int i=0;i<n;i++)
    {
        int m=arr[i].dead;
        while(m>0)
        {
            if(bookedDay[m]==false)
            {
                ans[0]++;
                ans[1]+=arr[i].profit;
                bookedDay[m]=true;
                break;
            }
            m--;
        }
    }

    return ans;
}

/* // TLE
vector<int> JobScheduling(Job arr[],int n)
{
    multimap<int,Job> Map;
    map<int,bool> bookedDay;
    for(int i=0;i<n;i++)
    {
        Map.insert({-1*arr[i].profit,arr[i]});
    }

    vector<int> ans={0,0};
    for(auto it:Map)
    {
        int n=it.second.dead;
        while(n>0)
        {
            if(bookedDay[n]==false)
            {
                ans[0]++;
                ans[1]+=it.second.profit;
                bookedDay[n]=true;
                break;
            }
            n--;
        }
    }

    return ans;
}
*/

int main()
{
    return 0;
}

