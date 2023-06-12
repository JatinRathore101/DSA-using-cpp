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

Node* build_from_level_order_traversal()
{
    cout<<"Enter data for node ";
    int data;cin>>data;
    Node* root=new Node(data);

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        data=temp->data;

        cout<<"Enter data for left of "<<data<<" Node , enter -1 for NULL"<<endl;
        int data2;
        cin>>data2;
        if(data2==-1){temp->left=NULL;}
        else{temp->left=new Node(data2);q.push(temp->left);}

        cout<<"Enter data for right of "<<data<<" Node , enter -1 for NULL"<<endl;
        cin>>data2;
        if(data2==-1){temp->right=NULL;}
        else{temp->right=new Node(data2);q.push(temp->right);}
    }
    return root;
}

void inorder_traversal(Node* root) // using recursion // LNR
{
    if(root==NULL){return;}
    inorder_traversal(root->left);
    cout<<root->data<<"  ";
    inorder_traversal(root->right);
    return;
}

void inorder_traversal2(Node* root) // using iteration // LNR
{
    if(root==NULL){return;}
    stack<Node*> s;
    Node* temp=root;

    while(!s.empty()||temp!=NULL)
    {
        while(temp!=NULL)
        {
            s.push(temp);
            temp=temp->left;
        }

        temp=s.top();
        s.pop();
        cout<<temp->data<<"  ";

        temp=temp->right;
    }
    cout<<endl;
}



void preorder_traversal(Node* root) // using recursion // NLR
{
    if(root==NULL){return;}
    cout<<root->data<<"  ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
    return;
}

void preorder_traversal2(Node* root) // using iteration // NLR
{
    if(root==NULL){return;}

    stack<Node*> s;
    s.push(root);
    Node* temp=NULL;

    while(!s.empty())
    {
        temp=s.top();
        s.pop();
        cout<<temp->data<<"  ";

        if(temp->right!=NULL){s.push(temp->right);}
        if(temp->left!=NULL){s.push(temp->left);}
    }
    cout<<endl;
}

void preorder_traversal3(Node* root) // using iteration // NLR
{
    if(root==NULL){return;}
    stack<Node*> s;
    Node* temp=root;

    while(!s.empty()||temp!=NULL)
    {
        while(temp!=NULL)
        {
            s.push(temp);
            cout<<temp->data<<"  ";
            temp=temp->left;
        }

        temp=s.top();
        s.pop();

        temp=temp->right;
    }
    cout<<endl;
}



void postorder_traversal(Node* root) // using recursion // LRN
{
    if(root==NULL){return;}
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout<<root->data<<"  ";
    return;
}

void postorder_traversal2(Node* root) // using iteration // LRN
{
    if(root==NULL){return;}
    stack<Node*> s1,s2;
    s1.push(root);

    Node* temp=NULL;
    while(!s1.empty())
    {
        temp=s1.top();
        s1.pop();
        s2.push(temp);

        if(temp->left!=NULL){s1.push(temp->left);}
        if(temp->right!=NULL){s1.push(temp->right);}
    }

    while(!s2.empty())
    {
        temp=s2.top();
        s2.pop();
        cout<<temp->data<<"  ";
    }
    cout<<endl;
}



void disp_reverse_order_traversal(Node* root) // using iteration
{
    if(root==NULL){return;}
    vector<Node*> v;
    v.push_back(root);
    v.push_back(NULL);

    int i=0;Node* temp=NULL;

    while(i!=v.size()-1)
    {
        temp=v[i];
        if(temp==NULL)
        {
            v.push_back(NULL);
        }
        else
        {
            if(temp->right!=NULL){v.push_back(temp->right);}
            if(temp->left!=NULL){v.push_back(temp->left);}
        }
        i++;
    }

    for(i=v.size()-1;i>=0;i--)
    {
        if(v[i]!=NULL){cout<<v[i]->data<<"  ";}
        else{cout<<endl;}
    }

    v.clear();
    cout<<endl;
}

int main()
{
    Node* root=build_binary_tree_recursive();/*
    disp_level_order_traversal(root);
    disp_reverse_order_traversal(root);

    Node* root2=build_from_level_order_traversal();
    disp_level_order_traversal(root2);
    disp_reverse_order_traversal(root2);*/

    cout<<endl<<"Inorder traversal"<<endl;
    inorder_traversal(root);cout<<endl;
    inorder_traversal2(root);

    cout<<endl<<"Preorder traversal"<<endl;
    preorder_traversal(root);cout<<endl;
    preorder_traversal2(root);
    preorder_traversal3(root);

    cout<<endl<<"Postorder traversal"<<endl;
    postorder_traversal(root);cout<<endl;
    postorder_traversal2(root);

    return 0;
}

/*
1 2 4 -1 -1 5 -1 7 8 -1 -1 9 -1 -1 3 -1 6 -1 -1
1 2 3 4 5 -1 6 -1 -1 -1 7 -1 -1 8 9 -1 -1 -1 -1
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
