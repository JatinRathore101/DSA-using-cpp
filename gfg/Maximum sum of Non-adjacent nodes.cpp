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

/* // TLE
int gSum(Node* parent,bool parent_taken,int current_sum)
{
    if(parent==NULL){return current_sum;}

    if(parent_taken==true)
    {
        int a=gSum(parent->left,false,current_sum);
        int b=gSum(parent->right,false,current_sum);
        return a+b-current_sum;
    }
    else
    {
        int a=0,b=0,c=0,d=0;
        if(parent->left!=NULL){a=gSum(parent->left,true,current_sum+parent->left->data);}
        b=gSum(parent->left,false,current_sum);
        if(parent->right!=NULL){c=gSum(parent->right,true,current_sum+parent->right->data);}
        d=gSum(parent->right,false,current_sum);
        return max(max(a+c,b+d),max(b+c,a+d))-current_sum;
    }
}

int getMaxSum(Node *root)
{
    if(root->left==NULL&&root->right==NULL){return root->data;}
    Node* parent=root;
    return max(gSum(parent,true,parent->data),gSum(parent,false,0));
}
*/

pair<int,int> gms(Node* root)
{
    if(root==NULL){return {0,0};}
    pair<int,int> p1=gms(root->left);
    pair<int,int> p2=gms(root->right);
    pair<int,int> p3={max(p1.first,p1.second)+max(p2.first,p2.second),p1.first+p2.first+root->data};
    return p3;
}

int getMaxSum(Node *root)
{
    if(root==NULL){return 0;}
    else if(root->left==NULL&&root->right==NULL){return root->data;}
    return max(gms(root).first,gms(root).second);
}

int main()
{
    Node* root=build_binary_tree_recursive();
    disp_level_order_traversal(root);
    cout<<" -> "<<getMaxSum(root);
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
