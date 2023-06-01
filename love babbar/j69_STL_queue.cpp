#include<bits/stdc++.h>
using namespace std;

void print_queue(queue<int> q)
{
    while(!q.empty())
    {
        cout<<q.front()<<"  ";q.pop();
    }
    cout<<endl;
}


int main()
{
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);

    cout << "The first queue is : ";
    print_queue(q1);

    queue<int> q2;
    q2.push(4);
    q2.push(5);
    q2.push(6);

    cout << "The second queue is : ";
    print_queue(q2);

    cout<<::boolalpha<<q1.empty();  //returns false since q1 is not empty

    cout << "\nq1.size() : " << q1.size();
    cout << "\nq1.front() : " << q1.front();
    cout << "\nq1.back() : " << q1.back();
    cout << "\nq1.pop() : "<<endl;q1.pop();
    print_queue(q1);

    q1.swap(q2);

    cout << "After swapping, the first queue is : ";
    print_queue(q1);
    cout << "After swapping the second queue is : ";
    print_queue(q2);

    return 0;
}
