#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // use stack and traverse stack array from end to begin
    stack<int> st;st.push(-1);
    while(n>0)
    {
        while(st.top()>=arr[n-1]){st.pop();}
        int x=st.top();
        st.push(arr[n-1]);
        arr[n-1]=x;
        n--;
    }
    return arr;
}

int main()
{
    vector<int> arr={3,3,1,1}; // ans => {1,1,-1,-1} // given -> arr[i] >= 0
    for(auto it:arr)cout<<it<<"  ";cout<<endl;
    arr=nextSmallerElement(arr,arr.size());
    for(auto it:arr)cout<<it<<"  ";cout<<endl;
    return 0;
}

