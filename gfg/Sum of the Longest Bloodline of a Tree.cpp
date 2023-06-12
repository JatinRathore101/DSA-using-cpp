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
        left=NULL;
        right=NULL;
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

pair<int,int> heightSum(Node* root)
{
    if(root==NULL){return {0,0};}
    else if(root->left==NULL&&root->right==NULL){return {1,root->data};}

    pair<int,int> a,b=heightSum(root->left),c=heightSum(root->right);
    if(b.first>c.first)
    {
        a.first=1+b.first;
        a.second=root->data+b.second;
    }
    else
    {
        a.first=1+c.first;
        a.second=root->data+c.second;
    }

    return a;
}

int sumOfLongRootToLeafPath(Node *root)
{
    return heightSum(root).second;
}

int main()
{
    Node* root=build_binary_tree_recursive();
    disp_level_order_traversal(root);
    cout<<endl<<sumOfLongRootToLeafPath(root);
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
