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

Node* build_binary_tree_recursive()
{
    int data;
    cout<<"Enter data for Node"<<endl;
    cin>>data;

    if(data == -1)// => this Node is NULL can't have branches
    {
        return NULL;
    }

    Node* root=new Node(data);
    cout<<"Enter data for left of "<<data<<" Node , enter -1 for NULL"<<endl;
    root->left=build_binary_tree_recursive();
    cout<<"Enter data for right of "<<data<<" Node , enter -1 for NULL "<<endl;
    root->right=build_binary_tree_recursive();

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

/*
bool isAncestor(Node *root,int k, int node)
{
    if(root==NULL){return false;}
    queue<Node*> q;q.push(root);q.push(NULL);

    while(k>=0&&!q.empty())
    {
        Node* temp=q.front();
        q.pop();

        if(temp->data==node&&k==0){return true;}

        if(temp==NULL)
        {
            q.push(NULL);k--;
        }
        else
        {
            if(temp->left!=NULL){q.push(temp->left);}
            if(temp->right!=NULL){q.push(temp->right);}
        }
    }

    return false;
}
*/

/*
bool isAncestor(Node *root,int k, int node)
{
    if(root==NULL){return false;}
    if(k==0){if(root->data==node){return true;}else{return false;}}

    if(isAncestor(root->left,k-1,node)){return true;}
    else if(isAncestor(root->right,k-1,node)){return true;}
    return false;
}

int kthAncestor(Node *root, int k, int node)
{
    if(root==NULL){return -1;}

    int a=-1;

    if(isAncestor(root,k,node)){a=root->data;}

    int b=kthAncestor(root->left,k,node);
    int c=kthAncestor(root->right,k,node);

    if(a!=-1){return a;}
    else if(b!=-1){return b;}
    else if(c!=-1){return c;}
    else{return -1;}
}
*/

int Ancestor(Node *root,vector<int> v,int k,int node)
{
    if(root==NULL){return -1;}
    v.push_back(root->data);
    if(v.size()>=k+1){if(v[v.size()-1]==node){return v[v.size()-1-k];}}
    int a=Ancestor(root->left,v,k,node);
    int b=Ancestor(root->right,v,k,node);
    if(a!=-1){return a;}
    else{return b;}
}

int kthAncestor(Node *root, int k, int node)
{
    vector<int> v;
    return Ancestor(root,v,k,node);
}

int main()
{
    Node* root=build_binary_tree_recursive();
    disp_level_order_traversal(root);
    cout<<kthAncestor(root,2,4);
    return 0;
}

/*
1 2 4 -1 -1 5 -1 7 8 -1 -1 9 -1 -1 3 -1 6 -1 -1
input
                 1
          2                    3
    4           5         -1       6
 -1   -1     -1   7             -1   -1
                 8   9

output
1
2  3
4  5  6
7
8  9





1 2 4 -1 -1 5 -1 7 8 -1 -1 9 -1 -1 3 -1 6 -1 -1
input
                     1
          2                    3
    4           5         -1       -1

output
1
2  3
4  5
*/


