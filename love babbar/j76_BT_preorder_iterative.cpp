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

void preorder_recur(Node* root)
{
    if(root==NULL){return;}
    cout<<root->data<<"  ";
    preorder_recur(root->left);
    preorder_recur(root->right);
}

/*
void preorder_iter(Node* root)
{
    if(root==NULL){return;}

    stack<Node*> s;
    s.push(root);
    Node* temp=NULL;

    while(!s.empty())
    {
        temp=s.top();
        s.pop();
        cout<<temp->data<<"  ";

        if(temp->right!=NULL){s.push(temp->right);}
        if(temp->left!=NULL){s.push(temp->left);}
    }
    cout<<endl;
}
*/

void preorder_iter(Node* root)
{
    if(root==NULL){return;}
    stack<Node*> s;
    Node* temp=root;

    while(!s.empty()||temp!=NULL)
    {
        while(temp!=NULL)
        {
            s.push(temp);
            cout<<temp->data<<"  ";
            temp=temp->left;
        }

        temp=s.top();
        s.pop();

        temp=temp->right;
    }
    cout<<endl;
}

int main()
{
    Node* root=NULL;
    root=build_BT();
    cout<<endl;
    preorder_recur(root);
    cout<<endl;
    preorder_iter(root);
    return 0;
}

