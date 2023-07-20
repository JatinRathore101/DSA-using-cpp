#include<bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

double fractionalKnapsack(int W, Item arr[], int n)
{
    multimap<double,Item> worth;
    for(int i=0;i<n;i++)
    {
        double cost=double(arr[i].value)/(arr[i].weight);
        cost*=-1;
        worth.insert({cost,arr[i]});
    }

    double ans=0;
    for(auto it:worth)
    {
        if(W<it.second.weight)
        {
            ans-=W*it.first;
            W=0;
        }
        else
        {
            ans+=it.second.value;
            W-=it.second.weight;
        }

        if(W==0){break;}
    }

    return ans;
}

int main()
{
    return 0;
}

