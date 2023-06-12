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

Node *buildTree(int in[], int post[], int n)
{
    if(n<=0){return NULL;}
    Node* root=new Node(post[n-1]);
    int j=-1;
    for(int i=0;i<n;i++){if(in[i]==post[n-1]){j=i;break;}}
    root->left=buildTree(in,post,j);
    root->right=buildTree(in+j+1,post+j,n-j-1);
    return root;
}

int main()
{
    int in[1001]={7,3,11,1,17,3,18},post[1001]={1,3,7,11,3,17,18},n=7;
    Node *root=buildTree(in,post,n);
    disp_level_order_traversal(root);
}


