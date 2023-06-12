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

Node* find_Parent(Node* root, int key)
{
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp=q.front();q.pop();

        if(temp->left!=NULL)
        {
            if(temp->left->data==key){return temp;}
            q.push(temp->left);
        }

        if(temp->right!=NULL)
        {
            if(temp->right->data==key){return temp;}
            q.push(temp->right);
        }
    }
    return NULL;
}

struct Node* deleteNode(struct Node* root, int key)
{
    if(root->data==key)
    {
        if(root->left==NULL&&root->right==NULL)
        {
            root=NULL;
        }
        else if(root->left!=NULL)
        {
            Node* temp=root->left;

            if(temp->right==NULL)
            {
                root->left=temp->left;
            }
            else
            {
                Node* parent=temp;
                temp=temp->right;
                while(temp->right!=NULL)
                {
                    parent=parent->right;
                    temp=temp->right;
                }
                parent->right=temp->left;
            }
            root->data=temp->data;
            temp->left=NULL;
        }
        else
        {
            Node* temp=root->right;

            if(temp->left==NULL)
            {
                root->right=temp->right;
            }
            else
            {
                Node* parent=temp;
                temp=temp->left;
                while(temp->left!=NULL)
                {
                    parent=parent->left;
                    temp=temp->left;
                }
                parent->left=temp->right;
            }
            root->data=temp->data;
            temp->right=NULL;
        }
    }
    else
    {
        Node* parent=find_Parent(root,key);
        if(parent!=NULL)
        {
            if(parent->left!=NULL&&parent->left->data==key)
            {
                parent->left=deleteNode(parent->left,key);
            }
            else
            {
                parent->right=deleteNode(parent->right,key);
            }
        }
    }
    return root;
};

int main()
{
    Node* root=build_BST();
    disp_level_order_traversal(root);
    inorder(root);
    return 0;
}


