
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
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

pair<int,bool> height(Node* root)
{
    pair<int,bool> a;
    if(root==NULL){a.first=0;a.second=true;return a;}
    pair<int,bool> b=height(root->left);
    pair<int,bool> c=height(root->right);
    a.first=1+max(b.first,c.first);
    a.second=false;
    if(abs(b.first-c.first)<=1&&b.second==true&&c.second==true){a.second=true;}
    return a;
}

bool isIdentical(Node *r1, Node *r2)
{
    if(r1==NULL&&r2==NULL){return true;}
    else if(r1==NULL||r2==NULL){return false;}
    else if(r1->data!=r2->data){return false;}

    return isIdentical(r1->left,r2->left)&isIdentical(r1->right,r2->right);
}

int main()
{
    Node* root=build_binary_tree_recursive();
    disp_level_order_traversal(root);
    cout<<::boolalpha<<isBalanced(root)<<endl;
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

