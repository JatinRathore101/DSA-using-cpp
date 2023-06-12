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

void flatten(Node *root)
{
    if(root==NULL){return;}
    Node* current=root;

    while(current!=NULL)
    {
        if(current->left!=NULL)
        {
            Node* temp=current->left;

            while(temp->right!=NULL)
            {
                temp=temp->right;
            }
            temp->right=current->right;
            current->right=current->left;
            temp=current;
            current=current->left;
            temp->left=NULL;
        }
        else
        {
            current=current->right;
        }
    }

    //cout<<endl;while(root!=NULL){cout<<root->data<<"  ";root=root->right;}
}

void preorder_traversal(Node* root)
{
    if(root==NULL){return;}
    cout<<root->data<<"  ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
    return;
}

int main()
{
    Node* root=build_binary_tree_recursive();
    disp_level_order_traversal(root);
    preorder_traversal(root);
    flatten(root);
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
*/


