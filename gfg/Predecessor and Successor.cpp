#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node* left;
    struct Node* right;

    Node(int x)
    {
        key = x;
        left = right = NULL;
    }
};

Node* build_BST()
{
    int x;
    cout<<"enter Node key for BST : enter -1 to stop  ";
    cin>>x;
    if(x==-1){return NULL;}

    Node* root=new Node(x);

    cout<<"enter Node key for BST : enter -1 to stop  ";
    cin>>x;

    while(x!=-1)
    {
        Node* temp=root;
        Node* pre=NULL;

        while(temp!=NULL)
        {
            pre=temp;
            if(temp->key<x)
            {
                temp=temp->right;
            }
            else
            {
                temp=temp->left;
            }
        }
        if(pre->key<x){pre->right=new Node(x);}
        else{pre->left=new Node(x);}

        cout<<"enter Node key for BST : enter -1 to stop  ";
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
            cout<<temp->key<<"  ";
            if(temp->left!=NULL){q.push(temp->left);}
            if(temp->right!=NULL){q.push(temp->right);}
        }
    }
    cout<<endl;
}

void inorder(Node* root, Node*& pre, Node*& suc, int key)
{
    if(root==NULL){return;}
    inorder(root->left,pre,suc,key);
    if(root->key<key){pre=root;}
    if(root->key>key&&suc==NULL){suc=root;}
    inorder(root->right,pre,suc,key);
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    inorder(root,pre,suc,key);
}
// 1 3 2 6 4 7 8 6 9 0 -1
int main()
{
    Node* root=build_BST();
    disp_level_order_traversal(root);

    Node* pre=NULL;
    Node* suc=NULL;
    int key=7;
    findPreSuc(root,pre,suc,key);
    if(pre!=NULL){cout<<"pre = "<<pre->key<<endl;}else{cout<<"pre = -1"<<endl;}
    if(pre!=NULL){cout<<"suc = "<<suc->key<<endl;}else{cout<<"suc = -1"<<endl;}

    return 0;
}


