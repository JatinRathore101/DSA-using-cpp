#include <deque>
#include <iostream>

using namespace std;

void showdq(deque<int> dq)
{
    /*
    deque<int>::iterator it;
    for (it = dq.begin(); it != dq.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
    */
    for (auto it:dq){cout<<it<<"  ";}cout<<endl;
}

int main()
{
    deque<int> dq;
    dq.push_back(1);
    dq.push_front(2);
    dq.push_back(3);
    dq.push_front(5);
    showdq(dq);

    cout << "dq.size() : " << dq.size()<<endl;
    cout << "dq.max_size() : " << dq.max_size()<<endl;
    cout << "dq.at(1) : " << dq.at(1)<<endl;
    cout << "dq.front() : " << dq.front()<<endl;
    cout << "dq.back() : " << dq.back()<<endl;

    dq.pop_front();showdq(dq);

    dq.pop_back();showdq(dq);

    return 0;
}
