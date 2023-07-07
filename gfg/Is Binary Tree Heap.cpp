#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

bool isHeap(struct Node* tree)
{
    if(tree->left==NULL&&tree->right==NULL){return true;}
    queue<Node*> q;
    q.push(tree);
    vector<int> v;v.push_back(tree->data);

    while(!q.empty())
    {
        struct Node* temp=q.front();q.pop();

        if(temp->left!=NULL)
        {
            q.push(temp->left);
            v.push_back(temp->left->data);
        }
        else
        {
            v.push_back(-1);
        }

        if(temp->right!=NULL)
        {
            q.push(temp->right);
            v.push_back(temp->right->data);
        }
        else
        {
            v.push_back(-1);
        }
    }

    int i=v.size()-1;
    while(v[i]==-1)
    {
        i--;
    }
    while(i>0)
    {
        if(v[i]>v[(i-1)/2]||v[i]==-1){return false;}
        i--;
    }
    return true;
}

int main()
{
    return 0;
}
