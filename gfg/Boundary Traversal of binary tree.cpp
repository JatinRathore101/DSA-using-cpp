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

void leftPart(Node* root,vector<int> &a)
{
    if((root==NULL)||(root->left==NULL&&root->right==NULL)){return;}

    a.push_back(root->data);

    if(root->left!=NULL){leftPart(root->left,a);}
    else{leftPart(root->right,a);}

    return;
}

void leafNodes(Node* root,vector<int> &a)
{
    if(root==NULL){return;}

    leafNodes(root->left,a);

    if(root->left==NULL&&root->right==NULL){a.push_back(root->data);}

    leafNodes(root->right,a);

    return;
}

void rightpart(Node* root,vector<int> &a)
{
    if((root==NULL)||(root->left==NULL&&root->right==NULL)){return;}

    if(root->right!=NULL){rightpart(root->right,a);}
    else{rightpart(root->left,a);}

    a.push_back(root->data);

    return;
}

vector <int> boundary(Node *root) // by recursion
{
    vector<int> a;
    if(root==NULL){return a;}

    a.push_back(root->data);
    if(root->left==NULL&&root->right==NULL){return a;}

    leftPart(root->left,a);

    leafNodes(root,a);

    rightpart(root->right,a);

    return a;
}

/*
vector <int> boundary(Node *root) // wrong
{
    vector<int> a;
    if(root==NULL){return a;}

    a.push_back(root->data);
    if(root->left==NULL&&root->right==NULL){return a;}

    Node* temp=root->left;
    while(temp!=NULL)
    {
        if(temp->left==NULL&&temp->right==NULL){break;}
        a.push_back(temp->data);
        temp=temp->left;
    }

    stack<Node*> s;temp=root;
    while(!s.empty()||temp!=NULL)
    {
        while(temp!=NULL)
        {
            s.push(temp);
            temp=temp->left;
        }
        temp=s.top();
        s.pop();
        if(temp->left==NULL&&temp->right==NULL){a.push_back(temp->data);}
        temp=temp->right;
    }

    int i=a.size();
    temp=root->right;
    while(temp!=NULL)
    {
        if(temp->left==NULL&&temp->right==NULL){break;}
        a.push_back(temp->data);
        temp=temp->right;
    }
    if(i<a.size()){reverse(a.begin()+i,a.end());}

    return a;
}
*/

int main()
{
    Node* root=build_binary_tree_recursive();
    disp_level_order_traversal(root);
    vector<int> a=boundary(root);
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

