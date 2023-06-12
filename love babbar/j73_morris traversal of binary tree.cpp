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

void preorder_traversal(Node* root) // using recursion // NLR
{
    if(root==NULL){return;}
    cout<<root->data<<"  ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
    return;
}

void postorder_traversal(Node* root) // using recursion // LRN
{
    if(root==NULL){return;}
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout<<root->data<<"  ";
    return;
}

void inorder_morris_traversal(Node* root)
{
    if(root==NULL){return;}
    Node* current=root;
    while(current!=NULL)
    {
        if(current->left==NULL)
        {
            cout<<current->data<<"  ";
            current=current->right;
        }
        else
        {
            Node* temp=current->left;

            while(temp->right!=NULL&&temp->right!=current)
            {
                temp=temp->right;
            }

            if(temp->right==NULL)
            {
                temp->right=current;
                current=current->left;
            }
            else //if(temp->right==current)
            {
                temp->right=NULL;
                cout<<current->data<<"  ";
                current=current->right;
            }
        }
    }
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

    cout<<endl<<"Preorder traversal"<<endl;
    preorder_traversal(root);cout<<endl;

    cout<<endl<<"Postorder traversal"<<endl;
    postorder_traversal(root);cout<<endl;

    cout<<endl<<"Inorder Morris traversal"<<endl;
    morris_traversal(root);cout<<endl;

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
