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

void inorder_recur(Node* root)
{
    if(root==NULL){return;}
    inorder_recur(root->left);
    cout<<root->data<<"  ";
    inorder_recur(root->right);
}

void inorder_iter(Node* root)
{
    if(root==NULL){return;}
    stack<Node*> s;
    Node* temp=root;

    while(!s.empty()||temp!=NULL)
    {
        while(temp!=NULL)
        {
            s.push(temp);
            temp=temp->left;
        }

        temp=s.top();
        s.pop();
        cout<<temp->data<<"  ";

        temp=temp->right;
    }
}

int main()
{
    Node* root=NULL;
    root=build_BT();
    cout<<endl;
    inorder_recur(root);
    cout<<endl;
    inorder_iter(root);
    return 0;
}

