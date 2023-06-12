#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
}; // 1 2 3 -1 -1 4 -1 -1 5 -1 -1

Node* build_BT()
{
    cout<<"enter data for node : enter -1 for exiting insertion"<<endl;
    int x;cin>>x;if(x==-1){return NULL;}
    Node* root=new Node(x);

    cout<<endl<<"left node of "<<x<<" -> ";
    root->left=build_BT();
    cout<<endl<<"right node of "<<x<<" -> ";
    root->right=build_BT();

    return root;
}

void postorder_recur(Node* root)
{
    if(root==NULL){return;}
    postorder_recur(root->left);
    postorder_recur(root->right);
    cout<<root->data<<"  ";
}

void postorder_iter(Node* root)
{
    if(root==NULL){return;}
    stack<Node*> s1,s2;
    s1.push(root);

    Node* temp=NULL;
    while(!s1.empty())
    {
        temp=s1.top();
        s1.pop();
        s2.push(temp);

        if(temp->left!=NULL){s1.push(temp->left);}
        if(temp->right!=NULL){s1.push(temp->right);}
    }

    while(!s2.empty())
    {
        temp=s2.top();
        s2.pop();
        cout<<temp->data<<"  ";
    }
    cout<<endl;
}

int main()
{
    Node* root=NULL;
    root=build_BT();
    cout<<endl;
    postorder_recur(root);
    cout<<endl;
    postorder_iter(root);
    return 0;
}


