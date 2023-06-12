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
vector<int> diagonal(Node *root)
{
    vector<int> a;
    if(root==NULL){return a;}
    map<int,vector<int>> m;
    queue<pair<pair<int,int>,Node*>> q;
    q.push({{0,0},root});
    pair<pair<int,int>,Node*> temp={{0,0},NULL};

    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        m[-1*(temp.first.first+temp.first.second)].push_back(temp.second->data);
        if(temp.second->left!=NULL){q.push({{temp.first.first-1,temp.first.second-1},temp.second->left});}
        if(temp.second->right!=NULL){q.push({{temp.first.first+1,temp.first.second-1},temp.second->right});}
    }

    for(auto it:m)
    {
        for(auto i:it.second){a.push_back(i);}
    }

    return a;
}
*/

vector<int> diagonal(Node *root)
{
    vector<int> a;
    if(root==NULL){return a;}

    queue<Node*> q;q.push(root);
    Node* temp=NULL;

    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        while(temp!=NULL)
        {
            if(temp->left!=NULL){q.push(temp->left);}
            a.push_back(temp->data);
            temp=temp->right;
        }
    }
    return a;
}

int main()
{
    Node* root=build_binary_tree_recursive();
    disp_level_order_traversal(root);
    vector<int> a=diagonal(root);
    cout<<endl;for(auto it:a){cout<<it<<"  ";}
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
//////////////////////////////////////////////////////

8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1
input
                   8
          3                    10
    1           6         -1       14
 -1   -1      4   7             13   -1
            -1-1 -1-1          -1-1

output

*/

