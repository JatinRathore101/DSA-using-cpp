#include<bits/stdc++.h>
using namespace std;

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    if(n>m)
    {
        for(auto it:b)
        {
            a.push_back(it);
            int i=n;n++;
            while(i>0)
            {
                int j=(i-1)/2;
                if(a[i]>a[j])
                {
                    swap(a[i],a[j]);
                    i=j;
                }
                else
                {
                    break;
                }
            }
        }
        return a;
    }
    else
    {
        for(auto it:a)
        {
            b.push_back(it);
            int i=m;m++;
            while(i>0)
            {
                int j=(i-1)/2;
                if(b[i]>b[j])
                {
                    swap(b[i],b[j]);
                    i=j;
                }
                else
                {
                    break;
                }
            }
        }
        return b;
    }
}

int main()
{
    return 0;
}

