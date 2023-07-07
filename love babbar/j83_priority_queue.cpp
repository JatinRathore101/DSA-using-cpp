#include<bits/stdc++.h>
using namespace std;

// priority queues are implemented over heap

void disp_max_heap(priority_queue<int> pq_max_heap)
{
    cout<<"max heap => ";
    while(!pq_max_heap.empty())
    {
        cout<<pq_max_heap.top()<<"  ";
        pq_max_heap.pop();
    }
    cout<<endl;
}

void disp_min_heap(priority_queue <int,vector<int>,greater<int>> pq_min_heap)
{
    cout<<"min heap => ";
    while(!pq_min_heap.empty())
    {
        cout<<pq_min_heap.top()<<"  ";
        pq_min_heap.pop();
    }
    cout<<endl;
}

int main()
{
    unordered_set<int> s;
    while(s.size()<20){s.insert(rand()%100-50);}

    priority_queue<int> pq_max_heap;
    for(auto it:s){pq_max_heap.push(it);}
    disp_max_heap(pq_max_heap);

    // root element => .top() // insertion => .push(data) // deletion => .pop() // heapify => already implemented //
    cout<<endl;

    priority_queue <int,vector<int>,greater<int>> pq_min_heap;
    for(auto it:s){pq_min_heap.push(it);}
    disp_min_heap(pq_min_heap);
    return 0;
}


/*
Note: priority_queue <int,vector<int>,greater<int>>

The min heap syntax may be difficult to remember,
so in case of numeric values, we can multiply the
values with -1 and use max heap to get the effect
of min heap. Not only that we can use custom sorting
method by replacing greater with custom comparator
function.
*/
