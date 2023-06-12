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

/*
bool checkPresence(Node* root ,int n1 ,int n2)
{
    if(root==NULL){return false;}

    bool c1=checkPresence(root->left,n1,n2);
    bool c2=false;
    if(root->data==n1||root->data==n2){c2=true;}
    bool c3=checkPresence(root->right,n1,n2);

    if(c1==true||c2==true||c3==true){return true;}
    return false;
}

Node* lca(Node* root ,int n1 ,int n2 )
{
    if(root==NULL){return NULL;}
    else if(root->data==n1||root->data==n2){return root;}

    Node* temp=root;

    while(temp!=NULL)
    {
        if(temp->data==n1||temp->data==n2){return temp;}

        bool b1=checkPresence(temp->left,n1,n2);
        bool b2=checkPresence(temp->right,n1,n2);

        if(b1==true&&b2==true){return temp;}
        else if(b1==true){temp=temp->left;}
        else if(b2==true){temp=temp->right;}
        else{return NULL;}
    }
    return NULL;
}
*/

Node* lca(Node* root ,int n1 ,int n2 )
{
    if(root==NULL){return NULL;}
    else if(root->data==n1||root->data==n2){return root;}

    Node* leftAns=lca(root->left,n1,n2);
    Node* rightAns=lca(root->right,n1,n2);

    if(leftAns!=NULL&&rightAns!=NULL){return root;}
    else if(leftAns!=NULL){return leftAns;}
    else if(rightAns!=NULL){return rightAns;}
    else{return NULL;}
}

int main()
{
    Node* root=build_binary_tree_recursive();
    disp_level_order_traversal(root);
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
