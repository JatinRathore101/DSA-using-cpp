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

int time(unordered_map<Node*,Node*> &parent,unordered_map<Node*,bool> &burned,int current_time,Node* Target)
{
    if(Target->right==NULL||burned[Target->right]==true)
    {
        if(Target->left==NULL||burned[Target->left]==true)
        {
            if(parent[Target]==NULL||burned[parent[Target]]==true)
            {
                return current_time;
            }
        }
    }

    if(Target->right!=NULL){burned[Target->right]=true;}
    if(Target->left!=NULL){burned[Target->left]=true;}
    if(parent[Target]!=NULL){burned[parent[Target]]=true;}
    current_time++;

    int t1=0,t2=0,t3=0;
    if(Target->left!=NULL){t1=time(parent,burned,current_time,Target->left);}
    if(Target->right!=NULL){t2=time(parent,burned,current_time,Target->right);}
    if(parent[Target]!=NULL){t3=time(parent,burned,current_time,parent[Target]);}

    return max(t1,max(t2,t3));
}

int minTime(Node* root, int target)
{
    unordered_map<Node*,Node*> parent;
    unordered_map<Node*,bool> burned;
    parent[root]=NULL;
    queue<Node*> s;s.push(root);

    Node* Target=NULL;

    while(!s.empty())
    {
        Node* temp=s.front();
        s.pop();
        burned[temp]=false;
        if(temp->data==target){Target=temp;}
        if(temp->left!=NULL){parent[temp->left]=temp;s.push(temp->left);}
        if(temp->right!=NULL){parent[temp->right]=temp;s.push(temp->right);}
    }

    burned[Target]=true;
    return time(parent,burned,0,Target);
}

int main()
{
    Node* root=build_binary_tree_recursive();
    disp_level_order_traversal(root);
    int target=10;
    cout<<endl<<minTime(root,target);
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












