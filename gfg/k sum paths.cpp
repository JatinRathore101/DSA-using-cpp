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

/* //  at 4th case
int countpathsFromThisNode(Node* root,int k)
{
    if(root!=NULL){if(root->data==k){return 1;}}
    else if(root==NULL){return 0;}

    int pt1=countpathsFromThisNode(root->left,k-root->data);
    int pt2=countpathsFromThisNode(root->right,k-root->data);
    return pt1+pt2;
}

int sumK(Node *root,int k)
{
    if(root==NULL){return 0;}
    int p1=sumK(root->left,k);
    int p2=countpathsFromThisNode(root,k);
    int p3=sumK(root->right,k);
    return p1+p2+p3;
}
*/

int inorder(Node* root,int k,vector<int> v)  // TLE at 18th case
{
    if(root==NULL){return 0;}
    v.push_back(root->data);
    int a1=inorder(root->left,k,v);

    int j=k,a2=0;
    for(int i=v.size()-1;i>=0;i--)
    {
        j-=v[i];if(j==0){a2++;}
    }

    int a3=inorder(root->right,k,v);

    return a1+a2+a3;
}

int sumK(Node *root,int k)
{
    vector<int> v;
    return inorder(root,k,v);
}

/* // love babbar's code // this also gives TLE at 18th case
void solve(Node* root, int k, int &count, vector<int> path)
{
    if(root == NULL){return;}
    path.push_back(root->data);
    solve(root->left, k, count, path);
    solve(root->right, k, count, path);

    int size = path.size();
    int sum = 0;
    for(int i = size-1; i>=0; i--)
    {
        sum += path[i];
        if(sum == k){count++;}
    }
    path.pop_back();
}

int sumK(Node *root,int k)
{
    vector<int> path;
    int count = 0;
    solve(root, k, count, path);
    return count;
}
*/

int main()
{
    Node* root=build_binary_tree_recursive();
    disp_level_order_traversal(root);
    cout<<" -> "<<sumK(root,5);
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
