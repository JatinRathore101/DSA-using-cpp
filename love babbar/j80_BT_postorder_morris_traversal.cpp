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

void postorder_morris(Node* root)
{
    if(root==NULL){return;}
    stack<int> s;
    Node* current=root;

    while(current!=NULL)
    {
        if(current->right==NULL)
        {
            s.push(current->data);
            current=current->left;
        }
        else
        {
            Node* temp=current->right;
            while(temp->left!=NULL&&temp->left!=current)
            {
                temp=temp->left;
            }
            if(temp->left==NULL)
            {
                s.push(current->data);
                temp->left=current;
                current=current->right;
            }
            else
            {
                temp->left=NULL;
                current=current->left;
            }
        }
    }

    while(!s.empty())
    {
        cout<<s.top()<<"  ";
        s.pop();
    }
}

int main()
{
    Node* root=NULL;
    root=build_BT();
    cout<<endl;
    postorder_recur(root);
    cout<<endl;
    postorder_morris(root);
    return 0;
}


