#include<bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K)
{
    queue<long long> q;
    vector<long long> v;
    long long i=0,j=0;
    while(i<N)
    {

        while(j<K&&(i+j<N))
        {
            if(A[i+j]<0)
            {
                q.push(A[i+j]);
            }
            j++;
        }
        if(q.empty()){q.push(0);}
        v.push_back(q.front());

        if(q.front()==A[i]||q.front()==0){q.pop();}
        j=K-1;i++;
        if(i+j==N){break;}  // very critical line // why break?
    }
    return v;
}

int main()
{
    long long int A[100001];
    long long int N,K,i=0;
    cin>>N>>K;
    while(i<N){cin>>A[i];i++;}
    vector<long long> v=printFirstNegativeInteger(A,N,K);
    cout<<endl;
    for(auto it:v){cout<<it<<"  ";}
    cout<<endl;
    return 0;
}

