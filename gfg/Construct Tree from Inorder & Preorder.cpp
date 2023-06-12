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

/* // passed all test cases but TC is higher,though SC is lower

Node* buildTree(int in[],int pre[],int n)
{
    if(n<=0){return NULL;}
    Node* root=new Node(pre[0]);
    int j=-1;
    for(int i=0;i<n;i++){if(in[i]==pre[0]){j=i;break;}}

    if(j>0){root->left=buildTree(in,pre+1,j);}
    if(j!=-1&&j<n-1){root->right=buildTree(in+j+1,pre+j+1,n-j-1);}
    return root;
}
*/

struct Node* build(int pre[],int i,int j,int n,unordered_map<int,int> &M)
{
    // if inorder has duplicate elements than mapping is overwritten for some elements, as map will only keep unique keys, hence mapping may not work
    // finally the code that passes 54 cases is correct given input inorder has all elements unique
    if(n<=0){return NULL;}
    Node* root=new Node(pre[j]);
    if(n==1){return root;}

    int k=M[pre[j]];
    if(k<i||k>i+n-1){return NULL;}

    root->left=build(pre,i,j+1,k-i,M);
    root->right=build(pre,k+1,k-i+j+1,i+n-k-1,M);
    return root;
}

struct Node* buildTree(int in[],int pre[],int n)
{
    unordered_map<int,int> M;
    for(int i=0;i<n;i++){M[in[i]]=i;}
    return build(pre,0,0,n,M);
}


int main()
{
    int in[1001]={7,3,11,1,17,3,18},pre[1001]={1,3,7,11,3,17,18},n=7; // error cases, as elements duplicate // 3 repeated
    Node* root=buildTree(in,pre,n);
    disp_level_order_traversal(root);
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

