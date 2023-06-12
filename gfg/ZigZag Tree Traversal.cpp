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

vector<int> zigZagTraversal(Node* root)
{
    vector<int> a;
    if(root==NULL){return a;}

    vector<Node*> v1;v1.push_back(root);
    vector<Node*> v2;

    bool lTr=true;
    int i,n=v1.size();

    while(n>0)
    {
        i=0;
        while(i<n)
        {
            if(lTr==true){a.push_back(v1[i]->data);}
            else{a.push_back(v1[n-1-i]->data);}

            if(v1[i]->left!=NULL){v2.push_back(v1[i]->left);}
            if(v1[i]->right!=NULL){v2.push_back(v1[i]->right);}
            i++;
        }
        v1.clear();
        v1=v2;
        v2.clear();
        n=v1.size();

        if(lTr==true){lTr=false;}else{lTr=true;}
    }
    return a;
}

int main()
{
    Node* root=build_binary_tree_recursive();
    disp_level_order_traversal(root);
    vector<int> a=zigZagTraversal(root);
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
*/

