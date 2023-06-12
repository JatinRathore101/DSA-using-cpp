#include<bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
    public :
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

TreeNode<int>* buildBST()
{
    int x=0;
    cout<<"enter data : -1 to stop"<<endl;
    cin>>x;if(x==-1){return NULL;}
    TreeNode<int>* root=new TreeNode<int>(x);

    cout<<"enter data : -1 to stop"<<endl;
    cin>>x;if(x==-1){return root;}
    while(x!=-1)
    {
        TreeNode<int>* temp=root;
        while(temp!=NULL)
        {
            if(temp->data>x)
            {
                if(temp->left==NULL)
                {
                    temp->left=new TreeNode<int>(x);
                    break;
                }
                temp=temp->left;
            }
            else
            {
                if(temp->right==NULL)
                {
                    temp->right=new TreeNode<int>(x);
                    break;
                }
                temp=temp->right;
            }
        }
        cout<<"enter data : -1 to stop"<<endl;
        cin>>x;
    }
    return root;
}

/* // partially accepted // TLE
TreeNode<int>* flatten(TreeNode<int>* root)
{
    if(root==NULL){return NULL;}
    else if(root->left==NULL&&root->right==NULL){return root;}

    TreeNode<int>* Left=flatten(root->left);
    TreeNode<int>* Right=flatten(root->right);
    TreeNode<int>* temp=root;

    if(Left!=NULL)
    {
        root=Left;
        while(Left->right!=NULL)
        {
            Left=Left->right;
        }
        Left->right=temp;
    }
    temp->right=Right;

    temp=root;
    while(temp!=NULL){temp->left=NULL;temp=temp->right;}

    return root;
}
*/

/* // solved using morris traversals still TLE //
TreeNode<int>* flatten(TreeNode<int>* root)
{
    if(root==NULL){return NULL;}

    TreeNode<int>* current=root;
    vector<int> inorder;

    while(current!=NULL)
    {
        if(current->left==NULL)
        {
            inorder.push_back(current->data);
            current=current->right;
        }
        else
        {
            TreeNode<int>* temp=current->left;
            while(temp->right!=NULL&&temp->right!=current)
            {
                temp=temp->right;
            }
            if(temp->right==current){temp->right=NULL;inorder.push_back(current->data);current=current->right;}
            else{temp->right=current;current=current->left;}
        }
    }

    current=root;
    while(current!=NULL)
    {
        if(current->left!=NULL)
        {
            TreeNode<int>* temp=current->left;
            while(temp->right!=NULL)
            {
                temp=temp->right;
            }
            temp->right=current->right;
            current->right=current->left;
        }
        current=current->right;
    }

    current=root;int i=0;
    while(current!=NULL)
    {
        current->data=inorder[i++];
        current->left=NULL;
        current=current->right;
    }

    return root;
}
*/

TreeNode<int>* flatten(TreeNode<int>* root)
{
    if(root==NULL){return NULL;}

    TreeNode<int>* current=root;
    TreeNode<int>* temp=new TreeNode<int>(-1);
    TreeNode<int>* tail=temp;

    while(current!=NULL)
    {
        if(current->left==NULL)
        {
            tail->right=new TreeNode<int>(current->data);
            tail=tail->right;
            current=current->right;
        }
        else
        {
            TreeNode<int>* temp=current->left;
            while(temp->right!=NULL&&temp->right!=current)
            {
                temp=temp->right;
            }
            if(temp->right==current)
            {
                temp->right=NULL;
                tail->right=new TreeNode<int>(current->data);
                tail=tail->right;
                current=current->right;
            }
            else{temp->right=current;current=current->left;}
        }
    }

    root=temp->right;
    temp->right=NULL;
    tail=NULL;
    delete temp;
    return root;
}

// 1 3 4 0 5 6 8 2 9 7 -1
int main()
{
    TreeNode<int>* root=buildBST();
    TreeNode<int>* root2=flatten(root);

    while(root2!=NULL){cout<<root2->data<<"  ";root2=root2->right;}
    return 0;
}

