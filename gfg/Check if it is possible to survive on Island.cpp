#include<bits/stdc++.h>
using namespace std;

int minimumDays(int S, int N, int M)
{
    if(N<M){return -1;}
        else if(S>6&&(N*6)/M<7){return -1;}

        S*=M;
        if(S%N==0){M=0;}
        else{M=1;}

        return S/N+M;
}

int main()
{
    int S=10,N=16,M=2;
    cout<<minimumDays(S,N,M);
    return 0;
}

