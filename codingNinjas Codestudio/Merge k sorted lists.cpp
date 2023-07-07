#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
    public:
    T data;
    Node* next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

class comparator
{
    public:
    bool operator()(Node<int>* a,Node<int>* b)
    {
        return a->data > b->data;
    }
};

Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    priority_queue<Node<int>*,vector<Node<int>*>,comparator> pq;

    int k=listArray.size();
    for(int i=0;i<k;i++)
    {
        Node<int>* temp=listArray[i];
        if(temp!=NULL){pq.push(temp);}
    }

    Node<int>* root=new Node<int>(-1);
    Node<int>* tail=root;

    while(!pq.empty())
    {
        tail->next=pq.top();pq.pop();
        tail=tail->next;
        if(tail->next!=NULL)
        {
            pq.push(tail->next);
        }
        tail->next=NULL;
    }

    tail=root;
    root=root->next;
    tail->next=NULL;
    delete tail;
    return root;
}

int main()
{
    Node<int>* root1=new Node<int>(1);
    root1->next=new Node<int>(3);
    root1->next->next=new Node<int>(8);

    Node<int>* root2=new Node<int>(2);
    root2->next=new Node<int>(11);
    root2->next->next=new Node<int>(12);
    root2->next->next->next=new Node<int>(13);
    root2->next->next->next->next=new Node<int>(19);

    Node<int>* root3=new Node<int>(7);
    root3->next=new Node<int>(17);

    vector<Node<int>*> listArray={root1,root2,root3};
    Node<int>* root4=mergeKLists(listArray);
    while(root4!=NULL){cout<<root4->data<<"  ";root4=root4->next;}

    return 0;
}

