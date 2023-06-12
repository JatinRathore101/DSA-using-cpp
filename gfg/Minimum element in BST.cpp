#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

Node* build_BST()
{
    int x;
    cout<<"enter Node data for BST : enter -1 to stop  ";
    cin>>x;
    if(x==-1){return NULL;}

    Node* root=new Node(x);

    cout<<"enter Node data for BST : enter -1 to stop  ";
    cin>>x;

    while(x!=-1)
    {
        Node* temp=root;
        Node* pre=NULL;

        while(temp!=NULL)
        {
            pre=temp;
            if(temp->data<x)
            {
                temp=temp->right;
            }
            else
            {
                temp=temp->left;
            }
        }
        if(pre->data<x){pre->right=new Node(x);}
        else{pre->left=new Node(x);}

        cout<<"enter Node data for BST : enter -1 to stop  ";
        cin>>x;
    }

    return root;
}

void disp_level_order_traversal(Node* root) // using iteration
{
    if(root==NULL){return;}
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();

        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<"  ";
            if(temp->left!=NULL){q.push(temp->left);}
            if(temp->right!=NULL){q.push(temp->right);}
        }
    }
    cout<<endl;
}

void inorder(Node *root)
{
    if(root==NULL){return;}
    inorder(root->left);
    cout<<root->data<<"  ";
    inorder(root->right);
}

int minValue(struct Node *root)
{
    if(root==NULL){return -1;}
    struct Node *temp=root;
    while(temp->left!=NULL){temp=temp->left;}
    return temp->data;
}

int maxValue(struct Node *root)
{
    if(root==NULL){return -1;}
    struct Node *temp=root;
    while(temp->right!=NULL){temp=temp->right;}
    return temp->data;
}

int main()
{
    struct Node *root=build_BST();
    disp_level_order_traversal(root);
    inorder(root);
    cout<<endl<<"min = "<<minValue(root);
    cout<<endl<<"max = "<<maxValue(root);
    return 0;
}



