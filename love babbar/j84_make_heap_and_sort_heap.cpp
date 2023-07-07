#include<bits/stdc++.h>
using namespace std;

void disp(vector<int> &arr)
{
    for(auto it:arr){cout<<it<<"  ";}
    cout<<endl;cout<<endl;
}

int main()
{
    vector<int> arr={-85,-22,19,17,7,71,-71,100,-3,60};
    disp(arr);

    make_heap(arr.begin(),arr.end());
    disp(arr);
    sort_heap(arr.begin(),arr.end()); // sort_heap does not work without make_heap //
    disp(arr);

    return 0;
}

