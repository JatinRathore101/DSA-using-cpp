#include<bits/stdc++.h>
using namespace std;

#define m 1000000007

int numberOfWays(int n, int k)
{
    long long int pre1=k%m,pre2=(pre1*pre1)%m;
    if(n==1){return pre1;}
    if(n==2){return pre2;}

    for(int i=3;i<=n;i++)
    {
        long long int ans=(((pre1%m + pre2%m)%m)*((k-1)%m))%m;
        pre1=pre2;
        pre2=ans;
    }
    return pre2;
}

int numberOfWays2(int n, int k)
{
    long long same=0,diff=k,ans;
    for(int i=1;i<=n;i++)
    {
        ans=(same%m+diff%m)%m;
        same=diff%m;
        diff=((ans%m)*((k-1)%m))%m;
    }
    return ans;
}

int main()
{
    /*
    int n=4,k=2;
    cout<<numberOfWays(n,k);
    */

    for(int i=0;i<10;i++)
    {
        int n=5+rand()%11,k=7+rand()%9;
        cout<<numberOfWays(n,k)<<"  "<<numberOfWays2(n,k)<<endl;
    }
    return 0;
}

